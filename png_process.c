#include "png_process.h"
#include <stddef.h>
#include <stdlib.h>
#include "config.h"
#include "lzw.h"
#include "coder.h"


void png_print_image(png_bytepp image, int height, int width)
{
    int x, y;

    for (x = 0; x < height; x++) {
        printf("Row: ");
        for ( y = 0; y < width; y++)
        {
        printf("%u ", image[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}


void free_png_bytepp(png_bytepp image, int height) 
{
    int i;
    if (image == NULL) {
        return;
    }

    for ( i = 0; i < height; i++) {
        if (image[i] != NULL) {
            free(image[i]);
            image[i] = NULL;
        }
    }

    free(image);
}

png_bytep *read_png_file(const char *file_name, int *width, int *height, int *color_type)
{
    png_bytep *image;
    FILE *fp = fopen(file_name, "rb");
    png_structp png;
    png_infop info;
    int y;

    if (!fp)
    {
        perror("Ошибка при открытии файла\n");
        return NULL;
    }

    png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png)
    {
        fclose(fp);
        perror("Ошибка при создании структуры чтения PNG\n");
        return NULL;
    }

    info = png_create_info_struct(png);
    if (!info)
    {
        png_destroy_read_struct(&png, NULL, NULL);
        fclose(fp);
        perror("Ошибка при создании информационной структуры PNG");
        return NULL;
    }

    if (setjmp(png_jmpbuf(png)))
    {
        png_destroy_read_struct(&png, &info, NULL);
        fclose(fp);
        perror("Ошибка при чтении PNG файла");
        exit(POSKOZEN);
    }

    png_init_io(png, fp);

    png_read_info(png, info);

    *width = png_get_image_width(png, info);
    *height = png_get_image_height(png, info);
    *color_type = png_get_color_type(png, info);


    image = (png_bytepp)malloc(sizeof(png_bytep) * (*height));

    for (y = 0; y < *height; y++)
    {
        image[y] = (png_byte *)malloc(png_get_rowbytes(png, info));
    }

    png_read_image(png, image);

    png_destroy_read_struct(&png, &info, NULL);
    fclose(fp);

    return image;
}

void write_png_file(const char *file_name, png_bytep *row_pointers, int width, int height, int color_type)
{
    FILE *fp = fopen(file_name, "wb");
    png_structp png;
    png_infop info;
    if (!fp)
    {
        perror("Ошибка при открытии файла для записи");
        return;
    }

    png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png)
    {
        fclose(fp);
        perror("Ошибка при создании структуры записи PNG");
        return;
    }

    info = png_create_info_struct(png);
    if (!info)
    {
        png_destroy_write_struct(&png, NULL);
        fclose(fp);
        perror("Ошибка при создании информационной структуры PNG");
        return;
    }

    if (setjmp(png_jmpbuf(png)))
    {
        png_destroy_write_struct(&png, &info);
        fclose(fp);
        perror("Ошибка при записи PNG файла");
        exit(WRONG_FORMAT);
    }

    png_init_io(png, fp);

    png_set_IHDR(
        png,
        info,
        width, height,
        8,
        color_type,
        PNG_INTERLACE_NONE,
        PNG_COMPRESSION_TYPE_DEFAULT,
        PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);

    png_write_image(png, row_pointers);

    png_write_end(png, NULL);

    png_destroy_write_struct(&png, &info);

    fclose(fp);
}

void print_png_pixels(png_bytep *image, int height, int width)
{
    int x, y;
    if (image == NULL) {
        return;
    }

    for ( x = 0; x < height; x++) {

        for ( y = 0; y < width; y++)
        {
            printf("%u ", image[x][y]);
        }

        printf("\n");
    }
}

void code_png(char *png_name, char *data_name)
{
    FILE *file = fopen(png_name, "rb");
    png_structp pngp = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    png_infop info = png_create_info_struct(pngp);
    int width;
    int height;
    png_byte color_type;
    png_byte bit_depth;
    png_bytepp image;
    int i;
    char *buffer;
    int buffer_size;
    short *data;
    size_t data_count;

    if (!file)
    {
        printf("cannot open file\n");
        fclose(file);
        png_destroy_read_struct(&pngp, &info, NULL);
        exit(EXIT_FAILURE);
    }
    if (!pngp)
    {
        printf("Cannot create pngp\n");
        fclose(file);
        png_destroy_read_struct(&pngp, &info, NULL);
        exit(EXIT_FAILURE);
    }
    if (!info)
    {
        printf("Cannot create info\n");
        fclose(file);
        png_destroy_read_struct(&pngp, &info, NULL);
        exit(EXIT_FAILURE);
    }

    if (setjmp(png_jmpbuf(pngp)))
    {
        printf("Setjmp err ***\n");
        fclose(file);
        png_destroy_read_struct(&pngp, &info, NULL);
        exit(WRONG_FORMAT);
    }

    png_init_io(pngp, file);

    png_read_info(pngp, info);

    width = png_get_image_width(pngp, info);
    height = png_get_image_height(pngp, info);

    color_type = png_get_color_type(pngp, info);
    bit_depth = png_get_bit_depth(pngp, info);

    printf("Width: %d, Height: %d\n", width, height);
    printf("Color type: %d, Bit depth: %d\n", color_type, bit_depth);

    if (color_type != PNG_COLOR_TYPE_RGB)
    {
        printf("Picture is not RGB.\n");
        exit(WRONG_FORMAT);
    }

    printf("Malloc pointers\n");

    image = (png_bytepp)malloc(sizeof(png_bytep) * height);

    for (i = 0; i < height; i++) {
        image[i] = (png_bytep)malloc(png_get_rowbytes(pngp, info));
    }

    png_read_image(pngp, image);


    buffer_size = (height * width) / 3;

    buffer = malloc(buffer_size);

    read_file(data_name, buffer, buffer_size);

    data = encoding(buffer, &data_count);

    insert_into_png(image, data, width, height, data_count);

    write_png_file("new_file.png", image, width, height, color_type);


    /*FREE BLOCK*/

    free_png_bytepp(image, height);

    png_destroy_info_struct(pngp, &info);

    png_destroy_read_struct(&pngp, &info, NULL);

    free(buffer);

    free(data);

    fclose(file);
}

void decode_png(char *file_name, char *output_file_name)
{
    png_bytep *image;
    int width, height, color_type;
    size_t size;
    short *data;

    printf("Reading PNG\n");

    image = read_png_file(file_name, &width, &height, &color_type);

    data = extract_png_data(image, width, &size);

    decoding(data, output_file_name, size);

    free(data);

    free_png_bytepp((png_bytepp) image, height);
}

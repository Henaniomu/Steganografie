#ifndef CODER_C_
#define CODER_C_
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "coder.h"
#include "config.h"

void read_file(char *file_name, char *buffer, size_t size)
{
    FILE *file;
    size_t bytesRead;

    file = fopen(file_name, "r");

    if (file == NULL)
    {
        printf("Cant open file");
        return;
    }

    bytesRead = fread(buffer, 1, size, file);

    printf("Read from file: %ld byte\n", bytesRead);

    fclose(file);
}

long int calculate_file_size(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    long int size;
    if (file == NULL)
    {
        perror("Cant open file\n");
        return -1;
    }

    fseek(file, 0, SEEK_END);
    size = ftell(file);

    fclose(file);

    return size;
}

void write_bit(unsigned char *byte, char bit_data)
{
    /* printf("Before : %d", *byte); */
    *byte = (*byte & 0xfe) | (char)bit_data;
    /* printf(" after : %d\n", *byte); */
}

int insert_into_bmp(BMPFile *file, short *data, size_t data_count)
{
    short temp;

    int i;
    size_t j, k;

    if (!file)
    {
        printf("No file\n");
        return EXIT_FAILURE;
    }
    if (!data)
    {
        printf("No data\n");
        return EXIT_FAILURE;
    }

    file->bhdr.unused = data_count; /*Vlajka kod*/

    for (j = 0, k = 0; j < data_count; j++)
    {
        for (i = BITS_IN_DATA; i >= 0; i--)
        {
            temp = (*(data + j) >> i) & 1;

            if (temp == 0)
            {
                write_bit(file->data + k, 0);
            }
            else
            {
                write_bit(file->data + k, 1);
            }
            k += 3;
        }
    }

    return EXIT_SUCCESS;
}

short *extract_bmp_data(char *bmpf_name, size_t *size)
{
    BMPFile *bmpf;
    size_t data_size, i = 0, k;
    int j;
    short *buffer;
    short temp = 0;
    short data;

    printf("%s\n", bmpf_name);

    bmpf = load_BMPFile(bmpf_name);

    if (!bmpf)
    {
        printf("!bmpf //extract_bmp_data");
        return NULL;
    }

    data_size = bmpf->bhdr.unused;

    if (!data_size)
    {
        printf("bmp is *empty*\n");
        exit(EMPTY);
    }
    

    buffer = malloc(data_size * sizeof(short));
    if (!buffer)
    {
        printf("!buffer //extract_bmp_data");
        return NULL;
    }

    for (k = 0; k < data_size; k++)
    {
        for (j = BITS_IN_DATA; j >= 0; j--)
        {
            data = bmpf->data[i];
            data = (data & 0x1) << j;
            temp = temp | data;
            i += 3;
        }
        buffer[k] = temp;
        temp = 0;
    }

    *size = data_size;
    free_BMPFile(bmpf);

    return buffer;
}

int insert_into_png(png_bytepp image, short *data, int width, int height, size_t data_count)
{
    short temp;
    unsigned short *ptr;
    size_t i = 0;

    int x = 0, y = 0;
    int k;

    if ((size_t)(((width * height) / 3)) < data_count)
    {
        printf("data_count > possible to code\n");
        exit(PHOTO_TOO_SMALL);
    }

    ptr = (unsigned short *)&image[0][1];
    *ptr = data_count;

    k = BITS_IN_DATA;

    while (1)
    {

        if (i > data_count)
        {
            break;
        }

        temp = (*(data + i) >> k) & 1;

        if (temp == 0)
        {
            write_bit(&image[y][x], 0);
        }
        else
        {
            write_bit(&image[y][x], 1);
        }

        k--;
        if (k < 0)
        {
            k = BITS_IN_DATA;
            i++;
        }

        x += 3;

        if (x > width)
        {
            y++;
            x = 0;
        }
    }

    return EXIT_SUCCESS;
}

short *extract_png_data(png_bytep *image, int width, size_t *size)
{
    short *buffer;
    short temp = 0;
    short data;
    int x = 0, y = 0;
    int j;
    size_t k;
    unsigned short *ptr;

    ptr = (unsigned short *)&image[0][1];
    *size = *ptr;

    buffer = malloc(*size * sizeof(short));

    if (!buffer)
    {
        printf("!buffer //extract_png_data");
        return NULL;
    }

    j = BITS_IN_DATA;
    k = 0;
    while (1)
    {
        data = image[y][x];
        data = (data & 0x1) << j;
        temp = temp | data;

        j--;
        if (j < 0)
        {
            buffer[k] = temp;
            temp = 0;
            k++;
            j = BITS_IN_DATA;
        }

        if (k > *size)
        {
            break;
        }

        x += 3;

        if (x > width)
        {
            y++;
            x = 0;
        }
    }

    return buffer;
}

#endif

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "bmp.h"
#include "config.h"
#include "lzw.h"
#include "coder.h"
#include <png.h>
#include "png_process.h"

/**
 * @brief Vypočítá kapacitu obrázku BMP pro skrytí dat.
 *
 * @param bmpf Ukazatel na strukturu BMPFile.
 * @return Velikost kapacity v bytech.
 */
size_t calculate_capacity(BMPFile *bmpf)
{
    return (((bmpf->bhdr.filesize - bmpf->bhdr.pixel_offset) / 3) / 8);
}

void code_bmp(char *bmp_name, char *data_name)
{
    BMPFile *bmpf;
    size_t buffer_size, data_count;
    char *buffer, *new_file_name = "new_file.bmp";
    short *data;

    bmpf = load_BMPFile(bmp_name);

    if (bmpf->dhdr.bits_per_pixel != 24)
    {
        printf("Bits per pixel != 24\n");
        exit(WRONG_FORMAT);
    }

    buffer_size = calculate_file_size(bmp_name);

    buffer = malloc(buffer_size);
    *buffer = '\0';

    read_file(data_name, buffer, buffer_size);

    data = encoding(buffer, &data_count);

    if (data_count > calculate_capacity(bmpf))
    {
        printf("Photo is too small\n");
        exit(PHOTO_TOO_SMALL);
    }

    insert_into_bmp(bmpf, data, data_count);

    write_BMPFile(new_file_name, bmpf);

    free_BMPFile(bmpf);
}

int file_type(char *file_name)
{
    size_t len = strlen(file_name);

    if (len == 0)
    {
        printf("No fila name\n");
        exit(2);
    }

    if (len >= 4 && strcmp(file_name + len - 4, ".png") == 0)
    {
        return 1;
    }
    else if (len >= 4 && strcmp(file_name + len - 4, ".bmp") == 0)
    {
        return 2;
    }
    else
    {
        exit(WRONG_FILE);
    }
}

/**
 * @brief Hlavní funkce programu pro skrývání a odhalování dat v obrazech.
 *
 * @param argc Počet argumentů příkazové řádky.
 * @param argv Pole ukazatelů na argumenty příkazové řádky.
 * @return EXIT_SUCCESS v případě úspěchu, jinak EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{

    if (argc < 4)
    {
        printf("Syntax: stegano <file (PNG | BMP)> <-action> <filename (txt)>\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[2], "-h") == 0)
    {
        switch (file_type(argv[1]))
        {
        case 1:
            code_png(argv[1], argv[3]);
            break;
        case 2:
            code_bmp(argv[1], argv[3]);
            break;
        }
    }

    if (strcmp(argv[2], "-x") == 0)
    {
        short *buffer;
        size_t data_size;

        switch (file_type(argv[1]))
        {
        case 1:
            decode_png(argv[1], argv[3]);
            break;
        case 2:
            buffer = extract_bmp_data(argv[1], &data_size);
            printf("decoding\n");
            decoding(buffer, argv[3], data_size);
            free(buffer);
            break;
        }
    }

    return EXIT_SUCCESS;
}

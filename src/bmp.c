#ifndef BMP_C
#define BMP_C
#include <stdlib.h>
#include <stdio.h>
#include "bmp.h"




BMPFile *load_BMPFile(char *fname)
{
    unsigned int data_size;
    BMPFile *bmp_file;
    FILE *fp = fopen(fname, "r");
    if (!fp)
    {
        printf("Can`t load file %s \n", fname);
        exit(0);
    }

    bmp_file = malloc(sizeof(BMPFile));
    fread(&(bmp_file->bhdr), sizeof(BMPHeader), 1, fp);
    fread(&(bmp_file->dhdr), sizeof(DIBHeader), 1, fp);

    bmp_file->dhdr.data_size = bmp_file->bhdr.filesize - bmp_file->bhdr.pixel_offset;

    data_size = bmp_file->dhdr.width * bmp_file->dhdr.height * bmp_file->dhdr.bits_per_pixel / 8;

    /* printf("data_size: %d \n", data_size); */

    bmp_file->data = malloc(data_size);
    if (!bmp_file->data)
    {
        printf("Malloc error");
        return NULL;
    }

    fseek(fp, bmp_file->bhdr.pixel_offset, SEEK_SET);
    fread(bmp_file->data, data_size, 1, fp);

    /*fread(bmp_file, sizeof(BMPFile), 1, fp);   wrong*/

    fclose(fp);
    return bmp_file;
}

void free_BMPFile(BMPFile *bmp_file)
{
    if (bmp_file)
    {
        free(bmp_file);
    }
}

void print_BMPPixels(BMPFile *bmpf)
{
    unsigned int i;
    for (i = 0; i < 200; i++)
    {
        if (i % 16 == 0)
        {
            printf("\n%04x: ", i);
        }
        printf("%02x ", bmpf->data[i]);
    }
    printf("\n");
}

void print_BMPHeaders(BMPFile *bmpf)
{
    /*Випис даних про файл (ігнорувати)................................................................*/
    printf("ID[2] = %X\nfilesize = %d\npixel_offset = %d\n",
           bmpf->bhdr.ID[1], bmpf->bhdr.filesize, bmpf->bhdr.pixel_offset);

    printf("\nheader_size = %d\nwidth = %d\nheight = %d\ncolor_planes = %d\nbits_per_pixel = %d\ncomp = %d\ndata_size = %d\npwidth = %d\npheight = %d\ncolors_count = %d\nimp_colors_count = %d\n",
           bmpf->dhdr.header_size, bmpf->dhdr.width, bmpf->dhdr.height, bmpf->dhdr.color_planes, bmpf->dhdr.bits_per_pixel, bmpf->dhdr.comp,
           bmpf->dhdr.data_size, bmpf->dhdr.pwidth, bmpf->dhdr.pheight, bmpf->dhdr.colors_count, bmpf->dhdr.imp_colors_count);
    /*кінець виписа даних..............................................................................*/
}


void write_BMPFile(char *fname, BMPFile *bmpf)
{
    FILE *file = fopen(fname, "w");

    bmpf->dhdr.data_size = 0;

    printf("Writing to file bhdr\n");
    fwrite(&(bmpf->bhdr), sizeof(BMPHeader), 1, file);

    printf("Writing to file dhdr\n");
    fwrite(&(bmpf->dhdr), sizeof(DIBHeader), 1, file);

    printf("Writing to file data\n");
    fseek(file, bmpf->bhdr.pixel_offset, SEEK_SET);
    fwrite(bmpf->data, sizeof(unsigned char), bmpf->bhdr.filesize - bmpf->bhdr.pixel_offset, file);


    fclose(file);
}

#endif

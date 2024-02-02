#ifndef CODER_H_
#define CODER_H_

#include "bmp.h"
#include <stddef.h>
#include <png.h>

/**
 * @brief Vloží data do BMP souboru.
 *
 * @param file Ukazatel na strukturu BMPFile.
 * @param data Ukazatel na data, která mají být vložena.
 * @param data_count Počet prvků v poli dat.
 * @return 0 při úspěchu, jinak nenulová chybová hodnota.
 */
int insert_into_bmp(BMPFile *file, short *data, size_t data_count);

/**
 * @brief Extrahuje data z BMP souboru.
 *
 * @param bmpf_name Název BMP souboru.
 * @param size Ukazatel na proměnnou, do které bude uložena velikost extrahovaných dat.
 * @return Ukazatel na pole extrahovaných dat, nebo NULL v případě chyby.
 */
short *extract_bmp_data(char *bmpf_name, size_t *size);

/**
 * @brief Vloží data do PNG obrázku.
 *
 * @param image Ukazatel na pole bytů představující PNG obrázek.
 * @param data Ukazatel na data, která mají být vložena.
 * @param width Šířka obrázku.
 * @param height Výška obrázku.
 * @param data_count Počet prvků v poli dat.
 * @return 0 při úspěchu.
 */
int insert_into_png(png_bytepp image, short *data, int width, int height, size_t data_count);


/**
 * @brief Extrahuje data z PNG obrázku.
 *
 * @param image Ukazatel na pole ukazatelů na řádky obrázku.
 * @param width Šířka obrázku.
 * @param size Ukazatel na proměnnou, do které bude uložena velikost extrahovaných dat.
 * @return Ukazatel na pole extrahovaných dat, nebo NULL v případě chyby.
 */
short *extract_png_data(png_bytep *image, int width, size_t *size);

/**
 * @brief Spočítá velikost souboru.
 *
 * @param file_name Název souboru.
 * @return Velikost souboru v bytech, nebo -1 v případě chyby.
 */
long int calculate_file_size(char *file_name);

/**
 * @brief Přečte obsah souboru do bufferu.
 *
 * @param file_name Název souboru.
 * @param buffer Ukazatel na buffer, do kterého se má číst.
 * @param size Velikost dat, která mají být přečtena.
 */
void read_file(char *file_name, char *buffer, size_t size);

#endif

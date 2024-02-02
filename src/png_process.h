#ifndef PNG_PROCESS_H_
#define PNG_PROCESS_H_

#include <png.h>


/**
 * @brief Vytiskne obsah PNG obrázku na standardní výstup.
 *
 * @param image Ukazatel na pole ukazatelů na řádky obrázku.
 * @param height Výška obrázku.
 * @param width Šířka obrázku.
 */
void png_print_image(png_bytepp image, int height, int width);

/**
 * @brief Uvolní paměť alokovanou pro PNG obrázek.
 *
 * @param image Ukazatel na pole ukazatelů na řádky obrázku.
 * @param height Výška obrázku.
 */
void free_png_bytepp(png_bytepp image, int height);

/**
 * @brief Přečte PNG soubor a vrátí potřebné informace.
 *
 * @param file_name Název PNG souboru.
 * @param width Ukazatel na proměnnou, do které bude uložena šířka obrázku.
 * @param height Ukazatel na proměnnou, do které bude uložena výška obrázku.
 * @param color_type Ukazatel na proměnnou, do které bude uložen barevný typ obrázku.
 * @return Ukazatel na pole ukazatelů na řádky obrázku.
 */
png_bytep *read_png_file(const char *file_name, int *width, int *height, int *color_type);

/**
 * @brief Zapíše PNG obrázek na disk.
 *
 * @param file_name Cesta, kam má být PNG obrázek zapsán.
 * @param row_pointers Pole ukazatelů na řádky obrázku.
 * @param width Šířka obrázku.
 * @param height Výška obrázku.
 * @param color_type Barevný typ obrázku.
 */
void write_png_file(const char *file_name, png_bytep *row_pointers, int width, int height, int color_type);

/**
 * @brief Vytiskne obsah pixelů PNG obrázku na standardní výstup.
 *
 * @param image Ukazatel na pole ukazatelů na řádky obrázku.
 * @param height Výška obrázku.
 * @param width Šířka obrázku.
 */
void print_png_pixels(png_bytep *image, int height, int width);

/**
 * @brief Zakóduje data do PNG obrázku.
 *
 * @param png_name Název PNG souboru.
 * @param data_name Název souboru s daty k zakódování.
 */
void code_png(char *png_name, char *data_name);

/**
 * @brief Dekóduje data z PNG obrázku.
 *
 * @param file_name Název PNG souboru.
 * @param output_file_name Název výstupního souboru pro dekódovaná data.
 */
void decode_png(char *file_name, char *output_file_name);


#endif

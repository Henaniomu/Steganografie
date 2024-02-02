#ifndef BMP_H_
#define BMP_H_

#define ID_LENGTH 2

#pragma pack(push, 1)


/**
 * @brief Struktura reprezentující hlavičku BMP souboru.
 */

typedef struct bmp_header
{
    unsigned char ID[ID_LENGTH]; /**< Identifikátor formátu BMP. */
    unsigned int filesize;       /**< Celková velikost souboru v bytech. */
    unsigned int unused;         /**< Nepoužívaný prostor v hlavičce. */
    unsigned int pixel_offset;   /**< Offset, kde začínají data pixelů. */
} BMPHeader;


/**
 * @brief Struktura reprezentující hlavičku DIB (Device Independent Bitmap) BMP souboru.
 */
typedef struct dib_header
{
    unsigned int header_size;       /**< Velikost této hlavičky. */
    int width;                      /**< Šířka obrazu v pixelech. */
    int height;                     /**< Výška obrazu v pixelech. */
    unsigned short color_planes;    /**< Počet barevných rovin. */ 
    unsigned short bits_per_pixel;  /**< Počet bitů na pixel. */
    unsigned short comp;            /**< Typ komprese. */
    unsigned int data_size;         /**< Velikost datového bloku. */
    unsigned int pwidth;            /**< Rozlišení obrazu v pixelech na jednotku délky (vodorovné). */
    unsigned int pheight;           /**< Rozlišení obrazu v pixelech na jednotku délky (svislé). */
    unsigned int colors_count;      /**< Počet použitých barev v palete. */
    unsigned int imp_colors_count;  /**< Počet důležitých barev v palete. */
} DIBHeader;


/**
 * @brief Struktura reprezentující celý BMP soubor.
 */
typedef struct bmp_file
{
    BMPHeader bhdr;         /**< Hlavička BMP souboru. */
    DIBHeader dhdr;         /**< Hlavička DIB souboru. */
    unsigned char *data;    /**< Ukazatel na samotná data pixelů. */
} BMPFile;

#pragma pack(pop)

/**
 * @brief Načte BMP soubor z disku.
 *
 * @param fname Cesta k BMP souboru.
 * @return Ukazatel na strukturu BMPFile, nebo NULL v případě chyby.
 */
BMPFile* load_BMPFile (char *fname);

/**
 * @brief Uvolní paměť alokovanou pro BMP soubor.
 *
 * @param bmp_file Ukazatel na strukturu BMPFile.
 */
void free_BMPFile(BMPFile *bmp_file);

/**
 * @brief Vytiskne obsah pixelů BMP souboru na standardní výstup.
 *
 * @param bmpf Ukazatel na strukturu BMPFile.
 */
void print_BMPPixels(BMPFile *bmpf);

/**
 * @brief Vytiskne obsah hlaviček BMP souboru na standardní výstup.
 *
 * @param bmpf Ukazatel na strukturu BMPFile.
 */
void print_BMPHeaders(BMPFile *bmpf);

/**
 * @brief Zapíše BMP soubor na disk.
 *
 * @param fname Cesta, kam má být BMP soubor zapsán.
 * @param bmpf Ukazatel na strukturu BMPFile.
 */
void write_BMPFile(char *fname, BMPFile *bmpf);


#endif

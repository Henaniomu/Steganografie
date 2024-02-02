#ifndef LZW_H_
#define LZW_H_

#include <stddef.h>

#define INDEX_NOT_FOUND -1   /**< Hodnota pro označení, že index není nalezen. */

#define START_CAPACITY 255   /**< Počáteční kapacita tabulky. */


/**
 * @brief Struktura představující položku v tabulce.
 */
typedef struct input
{
    int indexValue;     /**< Index hodnoty v tabulce. */
    char *word;         /**< Ukazatel na slovo v tabulce. */
} Table;


/**
 * @brief Alokujte paměť pro tabulku.
 *
 * @return Ukazatel na alokovanou tabulku.
 */
Table *allocate_table(void);

/**
 * @brief Inicializuje tabulku s předem definovanou kapacitou.
 *
 * @param table Ukazatel na ukazatel na tabulku.
 * @return 0 při úspěchu, jinak nenulová chybová hodnota.
 */
int initialize_table(Table **table);

/**
 * @brief Hledá index pro zadaný klíč v tabulce.
 *
 * @param table Ukazatel na tabulku.
 * @param key Klíč, který se má hledat v tabulce.
 * @param capacity Kapacita tabulky.
 * @return Index klíče v tabulce nebo hodnota INDEX_NOT_FOUND, pokud není nalezen.
 */
int search_index(Table *table, char *key, unsigned short capacity);


/**
 * @brief Přidá klíč do tabulky.
 *
 * @param table Ukazatel na tabulku.
 * @param key Klíč, který se má přidat do tabulky.
 * @param capacity Ukazatel na kapacitu tabulky (aktualizovanou po potřebě).
 * @return 0 při úspěchu, jinak nenulová chybová hodnota.
 */
int add_to_table(Table *table, char *key, unsigned short *capacity);


/**
 * @brief Uvolní paměť alokovanou pro tabulku.
 *
 * @param table Ukazatel na ukazatel na tabulku.
 * @param capacity Kapacita tabulky.
 */
void free_table(Table **table, unsigned short capacity);



/**
 * @brief Hledá slovo v tabulce podle zadaného kódu.
 *
 * @param table Ukazatel na tabulku.
 * @param code Kód, podle kterého se má hledat slovo.
 * @param capacity Kapacita tabulky.
 * @return Ukazatel na nalezené slovo nebo NULL, pokud není nalezeno.
 */
char* search_word(Table *table, short code, unsigned short capacity);


/**
 * @brief Kóduje vstupní sekvenci pomocí LZW algoritmu.
 *
 * @param seq Vstupní sekvence dat.
 * @param data_count Ukazatel na proměnnou, do které bude uložena velikost zakódovaných dat.
 * @return Ukazatel na pole zakódovaných dat.
 */
short *encoding(char *seq, size_t *data_count);


/**
 * @brief Dekóduje data zakódovaná pomocí LZW algoritmu a zapisuje je do souboru.
 *
 * @param data Pole zakódovaných dat.
 * @param filename Název souboru, kam mají být dekódovaná data zapsána.
 * @param data_size Velikost zakódovaných dat.
 */
void decoding(short *data, char* filename, size_t data_size);

#endif

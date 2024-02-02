#ifndef LZW_C_
#define LZW_C_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lzw.h"
#include "config.h"

#define CHAR 2

Table *allocate_table(void)
{
    Table *new = malloc(TABLE_SIZE * sizeof(Table));

    if (!new)
    {
        printf("Cannot allocate mem for Table \n");
        return NULL;
    }

    return new;
}

int initialize_table(Table **table)
{
    size_t i;

    *table = allocate_table();
    if (!table)
    {
        printf("!table //init_table");
        return EXIT_FAILURE;
    }

    for (i = 0; i < START_CAPACITY + 1; i++)
    {
        (*table + i)->indexValue = i;
        (*table + i)->word = malloc(sizeof(char) + 1);
        *((*table + i)->word) = i;
        *((*table + i)->word + sizeof(char)) = '\0';
    }

    return START_CAPACITY;
}

int search_index(Table *table, char *key, unsigned short capacity)
{
    size_t i;

    if (!table)
    {
        printf("No table to search in\n");
        return INDEX_NOT_FOUND;
    }

    for (i = 0; i <= capacity; i++)
    {
        if (strncmp(key, (table + i)->word, strlen(key)) == 0)
        {
            return i;
        }
    }

    return INDEX_NOT_FOUND;
}

int add_to_table(Table *table, char *key, unsigned short *capacity)
{
    if (!table)
    {
        printf("cannot add to empty table\n");
        return EXIT_FAILURE;
    }
    if (!key)
    {
        printf("there is no key\n");
        return EXIT_FAILURE;
    }

    (*capacity)++;

    (table + *capacity)->word = malloc(strlen(key) + 1);

    if (!(table + *capacity)->word)
    {
        printf("cannot malloc for word %d", *capacity);
        return EXIT_FAILURE;
    }

    strcpy((table + *capacity)->word, key);

    (table + *capacity)->indexValue = *capacity;

    return EXIT_SUCCESS;
}

void free_table(Table **table, unsigned short capacity)
{
    size_t i;
    if (!*table || !table)
    {
        printf("table is empty");
        return;
    }

    for (i = 0; i <= capacity; i++)
    {
        free((*table + i)->word);
    }

    free(*table);
    table = NULL;
}

char *search_word(Table *table, short index, unsigned short capacity)
{
    size_t i;

    if (!table)
    {
        printf("No table to search in\n");
        return NULL;
    }

    for (i = 0; i <= capacity; i++)
    {
        if (table[i].indexValue == index)
        {
            return table[i].word;
        }
    }

    return NULL;
}

short *encoding(char *seq, size_t *data_count)
{
    Table *table = NULL;
    char *cur = NULL, *temp = NULL;
    size_t i = 0 /* , j */;
    short *arr = malloc(TABLE_SIZE);
    unsigned short capacity;
    int index_in_table;
    int cur_length = 2;
    char last_iteration = 0;

    if (!arr)
    {
        printf("arr is empty");
        return NULL;
    }

    if (!seq)
    {
        printf("sequence is empty");
        return NULL;
    }

    capacity = initialize_table(&table);

    while (1)
    {
        cur = realloc(cur, cur_length);
        if (!cur)
        {
            printf("cant reallocate mem for current string");
            return NULL;
        }

        strncpy(cur, seq, cur_length - 1);
        *(cur + cur_length - 1) = '\0';

        index_in_table = search_index(table, cur, capacity);
        if (index_in_table == INDEX_NOT_FOUND)
        {
            temp = malloc(strlen(cur));
            strncpy(temp, cur, strlen(cur) - 1);
            *(temp + strlen(cur) - 1) = '\0';
            *(arr + i) = search_index(table, temp, capacity);
            i++;
            add_to_table(table, cur, &capacity);
            seq += strlen(temp);
            cur_length = 2;
        }

        cur_length++;
        if (last_iteration)
        {
            index_in_table = search_index(table, cur, capacity);
            *(arr + i) = index_in_table;
            i++;
            *data_count = i;
            free(cur);
            free(temp);
            free_table(&table, capacity);
            break;
        }

        if (strlen(seq) <= strlen(cur))
        {
            last_iteration = 1;
        }
    }

    /* for (j = 0; j < i; j++)
    {
        printf("%d ", *(arr + j));
    }
    printf("\n"); */

    return arr;
}

void decoding(short *data, char *filename, size_t data_size)
{
    Table *table = NULL;
    size_t i = 1;
    short old_code, new_code;
    unsigned short capacity;
    char *word;
    char *prefix, *temp, *test;
    size_t entity_len, word_len;
    FILE *new_file;

    prefix = malloc(CHAR);
    prefix[1] = '\0';

    new_file = fopen(filename, "w");

    printf("File opened\n");

    capacity = initialize_table(&table);

    word = malloc(CHAR);

    if (!table)
    {
        printf("Table is not initialized");
        return;
    }
    if (!word)
    {
        printf("Word is not initialized");
        return;
    }
    word[1] = '\0';

    temp = malloc(0);

    old_code = *data;

    strcpy(word, search_word(table, old_code, capacity));

    fwrite(word, strlen(word), 1, new_file);

    while (i < data_size)
    {
        new_code = data[i];

        if (search_word(table, new_code, capacity) == NULL)
        {
            word_len = strlen(search_word(table, old_code, capacity)) + 1;
            test = realloc(word, word_len + strlen(prefix));
            if (!test)
            {
                printf("!Realloc word\n");
                return;
            }

            strcpy(word, search_word(table, old_code, capacity));
            strcat(word, prefix);
            word[word_len + strlen(prefix)] = '\0';
        }
        else
        {
            test = realloc(word, strlen(search_word(table, new_code, capacity)) + 1);
            if (!test)
            {
                printf("!Realloc word\n");
                return;
            }
            strcpy(word, search_word(table, new_code, capacity));
        }

        fwrite(word, strlen(word), 1, new_file);

        strncpy(prefix, word, 1);

        entity_len = strlen(prefix) + strlen(search_word(table, old_code, capacity)) + 1;

        test = realloc(temp, entity_len);
        if (!test)
        {
            printf("!Realloc word\n");
            return;
        }
        strcpy(temp, search_word(table, old_code, capacity));
        strcat(temp, prefix);

        add_to_table(table, temp, &capacity);
        old_code = new_code;
        i++;
    }

    free(word);
    free(prefix);
    free(temp);
    free(test);

    fclose(new_file);

    free_table(&table, capacity);
}

#endif

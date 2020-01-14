/*
** EPITECH PROJECT, 2019
** tree
** File description:
** tree
*/

#include <stddef.h>
#include <stdlib.h>

#include <stddef.h>
#include <stdlib.h>

char *middle(int col_size, char const *last_one);

int checking_col(int size)
{
    int i = 0;
    int col_size = 1;

    while (i < size) {
        col_size += 2;
        i++;
    }
    return col_size;
}

char *high_down(int col_size)
{
    char *str = malloc(sizeof(char) * (col_size));
    int i = 0;

    if (str == NULL)
        return NULL;
    while (i < col_size) {
        str[i] = '*';
        i++;
    }
    str[i] = '\0';
    return str;
}

char **generate_matches(int size, char **tab)
{
    int i = 0;
    int col_size = checking_col(size);

    while (i < size + 2) {
        if (i == 0 || i == (size + 1))
            tab[i] = high_down(col_size);
        else
            tab[i] = middle(col_size, tab[i - 1]);
        i++;
    }
    tab[size + 3] = NULL;
    return tab;
}

char **pyramid(int size)
{
    char **tab = NULL;

    if (!size)
        return NULL;
    tab = malloc(sizeof(char *) * (size + 3));
    if (tab == NULL)
        return NULL;
    if (size > 0) {
        tab = generate_matches(size, tab);
    }
    return tab;
}
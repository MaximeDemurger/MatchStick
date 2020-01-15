/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** modify_map.c
*/

#include <stddef.h>
#include <stdlib.h>

char *my_strdup(char const *str);

int tab_size(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return i;
}

int select_first_one(char **tab, long int line)
{
    int col = 0;

    while (tab[line][col] != '|')
        col++;
    return col;
}

int last_on_line(char **tab, long int line)
{
    int i = select_first_one(tab, line);

    if (i < 0)
        return -1;
    while (tab[line][i] != '\0') {
        if (tab[line][i] != '|')
            return i - 1;
        i++;
    }
    return 0;
}

char *modify_map(char **tab, long int line, long int stick_taken)
{
    int last_stick = last_on_line(tab, line);
    char **new_tab = malloc(sizeof(char *) * tab_size(tab));

    if (!last_stick || !new_tab)
        return NULL;
    new_tab[line] = my_strdup(tab[line]);
    while (stick_taken > 0) {
        if (new_tab[line][last_stick] == '|')
            new_tab[line][last_stick] = ' ';
        last_stick--;
        stick_taken--;
    }
    return new_tab[line];
}
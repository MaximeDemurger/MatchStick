/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** check_end.c
*/

#include <stdbool.h>
#include <stddef.h>

bool check_end_game(char **tab)
{
    int i = 0;
    int j = 0;
    bool end_game = false;

    while (tab[i] != NULL) {
        j = 0;
        while (tab[i][j] != '\0') {
            if (tab[i][j] == '|')
                return end_game;
            j++;
        }
        i++;
    }
    end_game = true;
    return end_game;
}
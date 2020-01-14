/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** game_loop.c
*/

#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include "matchstick.h"

int print_actual_map(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        my_printf("%s\n", tab[i++]);
    if (!(write(1, "\n", 1)))
        return 84;
    return 0;
}

int in_loop(char **tab, int size, int maxStick)
{
    bool end_game = false;
    int turn = 0;

    while (end_game == false) {
        if (print_actual_map(tab) < 0)
            return 84;
        if (turn == 0)
            tab = player_move(tab, size, maxStick, &turn);
        else
            tab = ai_move(tab, size, maxStick, &turn);
        end_game = check_end_game(tab);
    }
    return 0;
}

int game_loop(int size, int maxStick)
{
    char **tab = NULL;

    tab = pyramid(size);
    if (tab == NULL)
        return -1;
    if (in_loop(tab, size, maxStick) < 0)
        return -1;
    return 0;
}

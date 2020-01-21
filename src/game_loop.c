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

int print_actual_map(char **tab, bool end)
{
    int i = 0;

    while (tab[i] != NULL)
        my_printf("%s\n", tab[i++]);
    if (end == false) {
        if (!(write(1, "\n", 1)))
            return 84;
    }
    return 0;
}

int in_loop(char **tab, int size, int maxStick)
{
    bool end_game = false;
    int turn = 0;

    while (end_game == false) {
        end_game = check_end_game(tab);
        if (print_actual_map(tab, end_game) < 0)
            return 84;
        if (turn == 0 && end_game == false) {
            if (!(tab = player_move(tab, size, maxStick, &turn)))
                return 0;
        } else if (turn == 1 && end_game == false)
            tab = ai_move(tab, size, maxStick, &turn);
    }
    if (turn == 1) {
        my_putstr("You lost, too bad...\n");
        return 2;
    }
    my_putstr("I lost... snif... but I'll get you next time!!\n");
    return 1;
}

int game_loop(int size, int maxStick)
{
    char **tab = NULL;
    int return_loop = 0;

    tab = pyramid(size);
    if (tab == NULL)
        return -1;
    if ((return_loop = in_loop(tab, size, maxStick)) < 0)
        return -1;
    return return_loop;
}

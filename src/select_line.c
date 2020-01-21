/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** select_line.c
*/

#include <stddef.h>
#include "matchstick.h"
#include <stdlib.h>
#include <stdio.h>

int check_all_line(game_t *game, int size, char *line)
{
    if (my_str_isnum(line) == 1) {
        my_printf("Error: invalid input (positive number expected)\n");
        select_line(size, game);
    }
    game->line = my_atoi(modify_str(line));
    if (game->line > size || game->line < 1) {
        my_putstr("Error: this line is out of range\n");
        select_line(size, game);
    }
    return 0;
}

int select_line(int size, game_t *game)
{
    char *line = NULL;
    size_t size_line = 0;
    int get_line = 0;

    game->line = 0;
    my_putstr("Line: ");
    while ((get_line = getline(&line, &size_line, stdin)) > 0) {
        if (get_line < 0)
            return 1;
        check_all_line(game, size, line);
        return 0;
    }
    return 1;
}
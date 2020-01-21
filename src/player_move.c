/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** player_move.c
*/

#include "matchstick.h"

int check_matches(char **tab, long int line, long int stick)
{
    long int nbr_stick = 0;
    int i = 0;

    if (tab == NULL)
        return 84;
    while (tab[line][i] != '\0') {
        if (tab[line][i] == '|')
            nbr_stick++;
        i++;
    }
    if (stick > nbr_stick) {
        my_putstr("Error: not enough matches on this line\n");
        return -1;
    }
    return 0;
}

int playing(game_t *game, int size, int maxStick, char **tab)
{
    if (select_line(size, game) == 1 || check_stick(maxStick, size, game))
        return 1;
    game->return_check = check_matches(tab, game->line, game->stick_taken);
    return 0;
}

char **player_move(char **tab, int size, int maxStick, int *turn)
{
    bool good_match = false;
    game_t *game = malloc(sizeof(game_t *));

    my_putstr("Your turn...\n");
    while (good_match == false) {
        if (playing(game, size, maxStick, tab) == 1)
            return NULL;
        if (game->return_check != -1)
            good_match = true;
    }
    tab[game->line] = modify_map(tab, game->line, game->stick_taken);
    my_printf("Player removed %d match(es) from line %d\n", game->stick_taken,
            game->line);
    *turn = 1;
    return tab;
}
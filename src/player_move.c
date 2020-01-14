/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** player_move.c
*/

#include "matchstick.h"

int check_matches(char **tab, int line, int stick)
{
    int nbr_stick = 0;
    int i = 0;

    while (tab[line][i]) {
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

char **player_move(char **tab, int size, int maxStick, int *turn)
{
    int line = 0;
    int stick_taken = 0;
    int return_check = 0;
    bool good_match = false;

    while (good_match == false) {
        line = select_line(size);
        stick_taken = check_stick(maxStick);
        return_check = check_matches(tab, line, stick_taken);
        if (return_check != -1)
            good_match = true;
    }
    tab[line] = modifyMap(tab, line, stick_taken);
    *turn = 1;
    return tab;
}
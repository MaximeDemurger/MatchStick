/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main.c
*/

#include "matchstick.h"

int main(int ac, char **av)
{
    int return_matchstick = 0;

    if (ac < 3 || ac > 3)
        return 84;
    if ((return_matchstick = matchstick(av)) < 0)
        return 84;
    return return_matchstick;
}
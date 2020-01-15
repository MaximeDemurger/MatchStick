/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.c
*/

#include <stddef.h>
#include <unistd.h>
#include "matchstick.h"

int game_check(int size, int maxStick)
{
    if (size < 1 || size > 100) {
        write(1, "Size not Correct\n", 17);
        return -1;
    } else if (maxStick <= 0) {
        write(1, "Stick not Correct\n", 18);
        return -1;
    }
    return 0;
}

int matchstick(char **av)
{
    int size = 0;
    int stick_take = 0;
    int return_loop = 0;

    if (av[1] == NULL || av[2] == NULL)
        return 84;
    if (!(size = my_atoi(av[1])) || !(stick_take = my_atoi(av[2])))
        return 84;
    if (game_check(size, stick_take) < 0)
        return 84;
    if ((return_loop = game_loop(size, stick_take)) < 0)
        return 84;
    return return_loop;
}


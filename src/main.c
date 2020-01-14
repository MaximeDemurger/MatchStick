/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** main.c
*/

#include "matchstick.h"

int main(int ac, char **av)
{
    if (ac < 3 || ac > 3)
        return 84;
    if (matchstick(av) != 0)
        return 84;
    return 0;
}
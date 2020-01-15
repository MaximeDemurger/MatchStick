/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** ai_move.c
*/

#include <stdlib.h>
#include <stdio.h>

int my_printf(char *str, ...);

char *modify_map(char **tab, long int line, long int stick_taken);

int my_putstr(char const *str);

long int choose_stick(int maxStick)
{
    long int stickTaken = 0;

    stickTaken = random() % (maxStick + 2);
    if (stickTaken == 0)
        choose_stick(maxStick);
    return stickTaken;
}

long int choose_line(int size)
{
    long int line = 0;

    line = random() % size;
    return line;
}

char **ai_move(char **tab, int size, int maxStick, int *turn)
{
    long int line = 0;
    long int stickTaken = 0;

    my_putstr("AI's turn...\n");
    line = choose_line(size);
    stickTaken = choose_stick(maxStick);
    tab[line] = modify_map(tab, line, stickTaken);
    my_printf("AI removed %d match(es) from line %d\n", stickTaken, line);
    *turn = 0;
    return tab;
}
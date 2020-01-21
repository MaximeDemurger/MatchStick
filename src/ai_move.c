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

long int check_ai(char **tab, long int line)
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
    return nbr_stick;
}

long int choose_stick(int maxStick, char **tab, long int line)
{
    long int stickTaken = 0;

    stickTaken = random() % (maxStick + 2);
    if (stickTaken == 0)
        choose_stick(maxStick, tab, line);
    if (check_ai(tab, line) == 0)
        choose_stick(maxStick, tab, line);
    return stickTaken;
}

long int choose_line(int size, char **tab)
{
    long int line = 0;

    line = random() % size;
    if (check_ai(tab, line) == 0)
        choose_line(size, tab);
    return line;
}

char **ai_move(char **tab, int size, int maxStick, int *turn)
{
    long int line = 0;
    long int stickTaken = 0;

    my_putstr("AI's turn...\n");
    line = choose_line(size, tab);
    stickTaken = choose_stick(maxStick, tab, line);
    tab[line] = modify_map(tab, line, stickTaken);
    my_printf("AI removed %d match(es) from line %d\n", stickTaken, line);
    *turn = 0;
    return tab;
}
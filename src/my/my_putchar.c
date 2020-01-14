/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    if (!write (1, &c, 1))
        return;
}

/*
** EPITECH PROJECT, 2019
** my atoi
** File description:
** my_atoi
*/

#include <stddef.h>

int check_char(char const *stack)
{
    int i = 0;

    if (stack == NULL)
        return -1;
    while (stack[i]) {
        if (stack[i] < '0' || stack[i] > '9')
            return 1;
        i++;
    }
    return 0;
}

int my_atoi(char const *stack)
{
    int printer = 0;
    int n = 0;

    if (stack == NULL)
        return 0;
    if (check_char(stack) != 0)
        return 0;
    while (stack[n] != '\0') {
        if (stack[n] >= '0' && stack[n] <= '9')
            printer = printer + (stack[n] - 48);
        if (stack[n + 1] == '\n')
            return (printer);
        if (stack[n + 1] != '\0')
            printer = printer * 10;
        n++;
    }
    return (printer);
}
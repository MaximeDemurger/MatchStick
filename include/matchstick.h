/*
** EPITECH PROJECT, 2019
** CPE_matchstick_2019
** File description:
** matchstick.h
*/

#ifndef CPE_MATCHSTICK_2019_MATCHSTICK_H
#define CPE_MATCHSTICK_2019_MATCHSTICK_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct s_struct {
    int line;
    int stick_taken;
    int return_check;
} game_t;

int my_putstr(char const *str);

int matchstick(char **av);

int my_atoi(char const *stack);

char **pyramid(int size);

int game_loop(int size, int maxStick);

int my_str_isnum(char const *str);

int my_strlen(char const *str);

int select_line(int size, game_t *game);

int my_printf(char const *str, ...);

int check_stick(int maxStick, int size, game_t *game);

char *modify_str(char *str);

char *modify_map(char **tab, long int line, long int stick_taken);

bool check_end_game(char **tab);

char **player_move(char **tab, int size, int maxStick, int *turn);

char **ai_move(char **tab, int size, int maxStick, int *turn);

int playing(game_t *game, int size, int maxStick, char **tab);

#endif //CPE_MATCHSTICK_2019_MATCHSTICK_H

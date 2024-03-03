#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include "config.h"

extern void spawn_apple(int apple_index);

void game_over(const char phrase[], int phrase_len)
{
    attron(COLOR_PAIR(3));
    int xpos = (WIDTH - phrase_len) / 2;
    mvprintw(HEIGHT / 2, xpos > 0 ? xpos : 1, phrase);
    refresh();
    timeout(-1);
    getch();
}

void escape()
{
    free(snake);
    free(apples);
    endwin();
    exit(0);
}

void game_init()
{
    snake_len = 4;
    snake_maxlen = 10;
    snake_dir = UP;
    snake_pdir = RIGHT;
    snake_rise = false;
    snake = malloc(sizeof(struct snake_tail) * snake_maxlen);
    snake[0] = (struct snake_tail){5, 2};
    snake[1] = (struct snake_tail){4, 2};
    snake[2] = (struct snake_tail){3, 2};
    snake[3] = (struct snake_tail){2, 2};

    apples = malloc(sizeof(struct apple) * APPLES_COUNT);
    for (int a = 0; a < APPLES_COUNT; a++) {
        spawn_apple(a);
    }

    score = 0;
}
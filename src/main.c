// Snake game

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include "config.h"
#include "snaketools.h"
#include "gametools.h"
#include "input.h"

void display()
{
    move(0, 0);
    attron(COLOR_PAIR(3));
    // Top border
    for (int x = 0; x < WIDTH; x++) {
        printw("%c", BORDER);
    }
    printw("\n");

    // Side borders
    for (int y = 1; y < HEIGHT - 1; y++) {
        printw("%c", BORDER);

        for (int x = 1; x < WIDTH - 1; x++) {
            printw(" ");
        }
        printw("%c\n", BORDER);
    }

    // Bottom border
    for (int x = 0; x < WIDTH; x++) {
        printw("%c", BORDER);
    }
    printw("\n");

    // Score
    char score_ch[20];
    snprintf(score_ch, sizeof(score_ch), "%d", score);
    mvprintw(2, WIDTH + 2, score_ch);

    // Snake
    attron(COLOR_PAIR(1));
    for (int s = 0; s < snake_len; s++) {
        mvaddch(snake[s].y, snake[s].x, SNAKE);
    }

    // Apples
    attron(COLOR_PAIR(2));
    for (int a = 0; a < APPLES_COUNT; a++) {
        mvaddch(apples[a].y, apples[a].x, APPLE);
    }
    
    refresh();
}

void spawn_apple(int apple_index)
{
    struct apple new_apple;

    while (1) 
    {
        new_apple = (struct apple){rand() % (WIDTH - 2) + 1, rand() % (HEIGHT - 2) + 1};
        int s;
        for (s = 0; s < snake_len; s++)
        {
            if (snake[s].x == new_apple.x && snake[s].y == new_apple.y) {
                break;
            } 
        }
        int a;
        for (a = 0; a < APPLES_COUNT; a++)
        {
            if (a == apple_index) {
                continue;
            }
            if (apples[a].x == new_apple.x && apples[a].y == new_apple.y) {
                break;
            }
        }
        if (s == snake_len && a == APPLES_COUNT) {
            break;
        }
    }
    apples[apple_index] = new_apple;
}

int main()
{
    srand(time(NULL));
    initscr();
    timeout(0);
    curs_set(0);
    start_color();

    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);

    game_init();

    display();
    napms(DELAYMS);

    while (1)
    {
        input();
        snake_move();
        snake_eat_apple();
        display();
        if (is_snake_eatself()) {
            game_over(LOSE_PHRASE, LOSE_PHRASE_LEN);
            escape();
        }
        else if (is_snake_win()) {
            game_over(WIN_PHRASE, WIN_PHRASE_LEN);
            escape();
        }
        napms(DELAYMS);
    }
}
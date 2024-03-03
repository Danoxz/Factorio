#include <stdlib.h>
#include <stdbool.h>
#include "config.h"

extern void spawn_apple();

void snake_move()
{
    snake_pdir = snake_dir;
    struct snake_tail prev_segm = snake[0];

    if (snake_dir == UP) {
        snake[0].y--;
    } else if (snake_dir == LEFT) {
        snake[0].x--;
    } else if (snake_dir == DOWN) {
        snake[0].y++;
    } else {
        snake[0].x++;
    }
    int s;
    for (s = 1; s < snake_len; s++) {
        struct snake_tail temp_segm = snake[s];
        snake[s] = prev_segm;
        prev_segm = temp_segm;
    }
    if (snake_rise) {
        if (s >= snake_maxlen) {
            snake_maxlen *= 2;
            snake = realloc(snake, sizeof(struct snake_tail) * snake_maxlen);
        }
        snake[s] = prev_segm;
        snake_len++;
        snake_rise = false;
    }

    for (int s = 0; s < snake_len; s++) {
        struct snake_tail *snake_curtail = &snake[s];
        if (snake_curtail->x < 1) {
            snake_curtail->x = WIDTH - 2;
        } 
        else if (snake_curtail->x > WIDTH - 2) {
            snake_curtail->x = 1;
        }
        else if (snake_curtail->y < 1) {
            snake_curtail->y = HEIGHT - 2;
        }
        else if (snake_curtail->y > HEIGHT - 2) {
            snake_curtail->y = 1;
        }
    }
}

void snake_eat_apple()
{
    for (int a = 0; a < APPLES_COUNT; a++) {
        // Comparison with the head only
        if (apples[a].x == snake->x && apples[a].y == snake->y) {
            spawn_apple(a);
            snake_rise = true;
            score++;
        }
    }
}

bool is_snake_eatself()
{
    for (int s = 0; s < snake_len - 1; s++) {
        for (int s2 = s + 1; s2 < snake_len; s2++) {
            if (snake[s].x == snake[s2].x && snake[s].y == snake[s2].y) {
                return true;
            }
        }
    }
    return false;
}

bool is_snake_win()
{
    return snake_len + APPLES_COUNT >= (WIDTH - 2) * (HEIGHT - 2);
}
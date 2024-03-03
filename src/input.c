#include <ncurses.h>
#include "config.h"

extern void escape();

char get_last_ch()
{
    char key = getch();
    while (1) {
        char next_key = getch();
        if (next_key != ERR) {
            key = next_key;
        } else {
            return key;
        }
    }
}

void input()
{
    char key = get_last_ch();
    if (key == ERR) {
        return;
    }
    
    if (key == 'w' && snake_pdir != DOWN) {
        snake_dir = UP;
    } else if (key == 'a' && snake_pdir != RIGHT) {
        snake_dir = LEFT;
    } else if (key == 's' && snake_pdir != UP) {
        snake_dir = DOWN;
    } else if (key == 'd' && snake_pdir != LEFT) {
        snake_dir = RIGHT;
    } else if (key == 'x') {
        escape();
    } else if (key == 'r') {
        snake_rise = true;
    }
}
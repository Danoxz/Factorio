#ifndef CONFIG_H
#define CONFIG_H

extern const int WIDTH;
extern const int HEIGHT;
extern const int DELAYMS;
extern const char BORDER;
extern const char SNAKE;

extern const char LOSE_PHRASE[];
extern const int LOSE_PHRASE_LEN;
extern const char WIN_PHRASE[];
extern const int WIN_PHRASE_LEN;

struct snake_tail {
    int x;
    int y;
};

struct apple {
    int x;
    int y;
};

extern const char APPLE;
extern int APPLES_COUNT;

enum DIR {
    LEFT,
    UP,
    RIGHT,
    DOWN
};

extern struct snake_tail *snake;
extern int snake_len;
extern int snake_maxlen;
extern bool snake_rise;
extern enum DIR snake_dir;
extern enum DIR snake_pdir;
extern struct apple *apples;
extern int score;

#endif
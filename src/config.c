#include <stdbool.h>
#include "config.h"

const int WIDTH = 100;
const int HEIGHT = 20;

const int DELAYMS = 500;

const char BORDER = '#';
const char SNAKE = '8';
const char APPLE = 'O';

const char LOSE_PHRASE[] = "GAY OVER!!!";
const int LOSE_PHRASE_LEN = 11;
const char WIN_PHRASE[] = "OMFG YOU WIN!!";
const int WIN_PHRASE_LEN = 14;

int APPLES_COUNT = 30;

struct snake_tail *snake;
int snake_len;
int snake_maxlen;
bool snake_rise;
enum DIR snake_dir;
enum DIR snake_pdir;
struct apple *apples;
int score;

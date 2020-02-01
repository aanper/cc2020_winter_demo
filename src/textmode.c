#include <stdint.h>
#include "config.h"

#define CHAR_WIDTH 6
#define CHAR_HEIGHT 8

#define DISPLAY_CHAR_WIDTH DISPLAY_WIDTH / CHAR_WIDTH
#define DISPLAY_CHAR_HEIGHT DISPLAY_HEIGHT / CHAR_HEIGHT

uint8_t text[DISPLAY_CHAR_WIDTH * DISPLAY_CHAR_HEIGHT + 1] = "0123456789ABCDE";

uint8_t render_char(uint8_t x, uint8_t y, uint8_t ch) {
    if(x >= CHAR_WIDTH || y >= CHAR_HEIGHT) {
        return 0;
    }

    return ch;
}

uint8_t render_textmode(uint8_t x, uint8_t y) {
    uint8_t char_pos_x = x / CHAR_WIDTH;
    uint8_t char_pos_y = y / CHAR_HEIGHT;

    uint8_t ch = text[char_pos_y * DISPLAY_CHAR_WIDTH + char_pos_x];

    return render_char(x % CHAR_WIDTH, y % CHAR_HEIGHT, ch);
}

void update_text(uint32_t t) {
    if(t % 1000 == 0) {
        text[1]++;
        if(text[1] == 'z') {
            text[1] = '1';
        }
    }
}
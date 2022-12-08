#include "souris.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>

void cursor_position(souris_t *souris) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    souris->pos_x = x;
    souris->pos_y = y;
    printf("x : %d, y : %d\n", souris->pos_x, souris->pos_y);
}

void init_souris(souris_t *souris) {
    souris->pos_x = 0;
    souris->pos_y = 0;
    souris->is_active = false;
    souris->hover = false;
}
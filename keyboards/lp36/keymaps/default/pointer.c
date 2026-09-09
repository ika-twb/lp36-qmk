// Copyright 2026 ika-twb
// SPDX-License-Identifier: MIT

#include "features.h"

typedef struct {
    bool active;
    uint16_t started;
} mouse_move_state_t;

static mouse_move_state_t mouse_moves[4];
static uint16_t mouse_move_timer;

static uint8_t mouse_move_step(uint8_t index) {
    uint16_t elapsed = timer_elapsed(mouse_moves[index].started);
    if (elapsed >= 500) {
        return 38;
    }
    return 1 + ((uint32_t)elapsed * 37U) / 500U;
}

static void clear_mouse_moves(void) {
    memset(mouse_moves, 0, sizeof(mouse_moves));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (!layer_state_cmp(state, MOUSE)) {
        clear_mouse_moves();
    }
    return state;
}

bool pointer_process_record(uint16_t keycode, keyrecord_t *record) {
    if (keycode < MM_LEFT || keycode > MM_RIGHT) {
        return true;
    }

    uint8_t move_index = keycode - MM_LEFT;
    if (record->event.pressed) {
        mouse_moves[move_index] = (mouse_move_state_t){
            .active = true,
            .started = timer_read(),
        };
        mouse_move_timer = timer_read() - 16;
    } else {
        mouse_moves[move_index].active = false;
    }
    return false;
}

void pointer_task(void) {
    bool moving = mouse_moves[0].active || mouse_moves[1].active ||
                  mouse_moves[2].active || mouse_moves[3].active;
    if (!moving || timer_elapsed(mouse_move_timer) < 16) {
        return;
    }

    report_mouse_t report = mousekey_get_report();
    report.x = (mouse_moves[3].active ? mouse_move_step(3) : 0) -
               (mouse_moves[0].active ? mouse_move_step(0) : 0);
    report.y = (mouse_moves[1].active ? mouse_move_step(1) : 0) -
               (mouse_moves[2].active ? mouse_move_step(2) : 0);
    report.v = 0;
    report.h = 0;
    host_mouse_send(&report);
    mouse_move_timer = timer_read();
}


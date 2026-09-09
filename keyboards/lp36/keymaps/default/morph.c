// Copyright 2026 ika-twb
// SPDX-License-Identifier: MIT

#include "features.h"

typedef struct {
    bool active;
    uint16_t output;
    uint8_t suppressed_mods;
} morph_state_t;

static morph_state_t morph_states[3];

static uint8_t effective_shifts(void) {
    uint8_t shifts = get_mods() & MOD_MASK_SHIFT;
    for (uint8_t i = 0; i < 3; ++i) {
        shifts |= morph_states[i].suppressed_mods;
    }
    return shifts;
}

static void press_morph(uint8_t index, uint16_t output, uint8_t suppressed_mods) {
    morph_state_t *state = &morph_states[index];
    *state = (morph_state_t){
        .active = true,
        .output = output,
        .suppressed_mods = suppressed_mods,
    };
    unregister_mods(suppressed_mods);
    register_code16(output);
}

static void release_morph(uint8_t index) {
    morph_state_t *state = &morph_states[index];
    if (!state->active) {
        return;
    }
    unregister_code16(state->output);
    uint8_t restore = state->suppressed_mods;
    *state = (morph_state_t){0};
    for (uint8_t i = 0; i < 3; ++i) {
        restore &= ~morph_states[i].suppressed_mods;
    }
    register_mods(restore);
}

static void note_shift_release(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        return;
    }

    uint8_t released = 0;
    if (keycode == KC_LSFT || (keycode == HM_F && record->tap.count == 0) ||
        (keycode == HM_J && record->tap.count == 0)) {
        released = MOD_BIT(KC_LSFT);
    } else if (keycode == KC_RSFT) {
        released = MOD_BIT(KC_RSFT);
    }

    for (uint8_t i = 0; i < 3; ++i) {
        morph_states[i].suppressed_mods &= ~released;
    }
}

bool morph_process_record(uint16_t keycode, keyrecord_t *record) {
    uint8_t shifts = effective_shifts();
    note_shift_release(keycode, record);

    switch (keycode) {
        case CM_MORPH:
            if (record->event.pressed) {
                press_morph(0, shifts ? KC_SCLN : KC_COMM, shifts);
            } else {
                release_morph(0);
            }
            return false;
        case DT_MORPH:
            if (record->event.pressed) {
                press_morph(1, shifts ? S(KC_SCLN) : KC_DOT, shifts);
            } else {
                release_morph(1);
            }
            return false;
        case QEXCL:
            if (record->event.pressed) {
                press_morph(2, shifts ? S(KC_1) : S(KC_SLSH), shifts);
            } else {
                release_morph(2);
            }
            return false;
    }

    return true;
}

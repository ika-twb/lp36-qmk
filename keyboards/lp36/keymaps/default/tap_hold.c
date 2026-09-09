// Copyright 2026 ika-twb
// SPDX-License-Identifier: MIT

#include "features.h"

/*
 * QMK's Flow Tap + Chordal Hold + Permissive Hold combination implements the
 * same invariants as urob's "timeless" HRMs: prior-idle taps, bilateral holds,
 * same-hand rolls, balanced nested presses, and a finite timeout fallback.
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    (void)record;
    return IS_QK_MOD_TAP(keycode) ? 280 : 200;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    (void)record;
    return (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) ? 175 : 0;
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    (void)record;
    return IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode);
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    (void)record;
    (void)prev_keycode;
    return IS_QK_MOD_TAP(keycode) ? 150 : 0;
}

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    "LLLLLRRRRR",
    "LLLLLRRRRR",
    "LLLLLRRRRR",
    "**********",
};


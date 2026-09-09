// Copyright 2026 ika-twb
// SPDX-License-Identifier: MIT

#include "quantum.h"
#include "keyboards/lp36/keymaps/default/features.h"

#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)

const uint16_t PROGMEM sd_combo[] = {HM_S, HM_D, COMBO_END};
const uint16_t PROGMEM xv_combo[] = {KC_X, KC_V, COMBO_END};
combo_t key_combos[] = {
    COMBO(sd_combo, KC_TAB),
    COMBO(xv_combo, C(KC_X)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!morph_process_record(keycode, record)) {
        return false;
    }
    return pointer_process_record(keycode, record);
}

void matrix_scan_user(void) {
    pointer_task();
}

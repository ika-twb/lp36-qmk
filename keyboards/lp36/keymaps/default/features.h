// Copyright 2026 ika-twb
// SPDX-License-Identifier: MIT

#pragma once

#include "quantum.h"

enum layers {
    BASE,
    NAV,
    MOUSE,
    MEDIA,
    NUM,
    SYM,
    FUNC,
};

enum custom_keycodes {
    CM_MORPH = SAFE_RANGE,
    DT_MORPH,
    QEXCL,
    MM_LEFT,
    MM_DOWN,
    MM_UP,
    MM_RIGHT,
};

#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J LSFT_T(KC_J)
#define HM_K LCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_QUOT LGUI_T(KC_QUOT)

#ifdef __cplusplus
extern "C" {
#endif

bool morph_process_record(uint16_t keycode, keyrecord_t *record);
bool pointer_process_record(uint16_t keycode, keyrecord_t *record);
void pointer_task(void);

#ifdef __cplusplus
}
#endif

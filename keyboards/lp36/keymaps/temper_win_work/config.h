// Copyright 2026 ika-twb
// SPDX-License-Identifier: MIT

#pragma once

/* Temper win_work timings. */
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 175
#define QUICK_TAP_TERM_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150

/* ZMK combos use strict first-to-last timing and per-combo terms. */
#define COMBO_TERM 18
#define COMBO_TERM_PER_COMBO
#define COMBO_SHOULD_TRIGGER
#define COMBO_STRICT_TIMER
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_KEY_BUFFER_LENGTH 12
#define COMBO_BUFFER_LENGTH 8

/* Close equivalents of the Temper pointer settings: 16 ms updates,
 * linear acceleration to roughly 2400 px/s over 500 ms. */
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MOVE_DELTA 1
#define MOUSEKEY_MAX_SPEED 40
#define MOUSEKEY_TIME_TO_MAX 31
#define MOUSEKEY_WHEEL_DELAY 0
#define MOUSEKEY_WHEEL_INTERVAL 40
#define MOUSEKEY_WHEEL_DELTA 1
#define MOUSEKEY_WHEEL_MAX_SPEED 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 1

/* Match Temper's 8 ms scan debounce in both directions. */
#define DEBOUNCE 8

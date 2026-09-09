// Copyright 2026 ika-twb
// SPDX-License-Identifier: MIT

#include QMK_KEYBOARD_H

/*
 * Exact physical ordering used by Temper and by the LP36's embedded Vial
 * definition:
 *
 *  0  1  2  3  4       5  6  7  8  9
 * 10 11 12 13 14      15 16 17 18 19
 * 20 21 22 23 24      25 26 27 28 29
 *       30 31 32      33 34 35
 */
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
    NV_LEFT,
    NV_DOWN,
    NV_UP,
    NV_RIGHT,
    NV_BSPC,
    NV_DEL,
};

#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_J LSFT_T(KC_J)
#define HM_K LCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_QUOT LGUI_T(KC_QUOT)

#define TH_ESC LT(MEDIA, KC_ESC)
#define TH_TAB LT(NAV, KC_TAB)
#define TH_SPC LT(MOUSE, KC_SPC)
#define TH_BSPC LT(SYM, KC_BSPC)
#define TH_ENT LT(NUM, KC_ENT)
#define TH_DEL LT(FUNC, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,          KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        HM_A,    HM_S,    HM_D,    HM_F,    KC_G,          KC_H,     HM_J,     HM_K,     HM_L,     HM_QUOT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,          KC_N,     KC_M,     CM_MORPH, DT_MORPH, QEXCL,
                          TH_ESC,  TH_TAB,  TH_SPC,        TH_BSPC,  TH_ENT,   TH_DEL
    ),

    [NAV] = LAYOUT(
        KC_NO,   KC_NO,   LCTL(LSFT(KC_LBRC)), LCTL(LSFT(KC_RBRC)), KC_NO,
                                                         KC_AGAIN, NV_BSPC, NV_DEL,   KC_CUT,  KC_UNDO,
        LALT(KC_F4), LALT(KC_TAB), LCTL(LGUI(KC_LEFT)), LCTL(LGUI(KC_RGHT)), KC_NO,
                                                         NV_LEFT,  NV_DOWN, NV_UP,    NV_RIGHT, KC_CAPS,
        KC_LSFT, KC_NO,   LGUI(LSFT(KC_LBRC)), LGUI(LSFT(KC_RBRC)), KC_NO,
                                                         KC_HOME,  KC_PGDN, KC_PGUP,  KC_END,  KC_INS,
                          KC_NO,   KC_TRNS, KC_NO,        LCTL(KC_SPC), KC_BSPC, KC_DEL
    ),

    [MOUSE] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_AGAIN, KC_PASTE, KC_COPY, KC_CUT, KC_UNDO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                MS_LEFT,  MS_DOWN,  MS_UP,   MS_RGHT, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                MS_WHLL,  MS_WHLD,  MS_WHLU, MS_WHLR, KC_NO,
                      KC_NO, KC_NO, KC_NO,                MS_BTN1,  MS_BTN2,  MS_BTN3
    ),

    [MEDIA] = LAYOUT(
        QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_TRNS, KC_NO, KC_NO,              KC_MSTP, KC_MPLY, KC_NO
    ),

    [NUM] = LAYOUT(
        KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                       KC_MINS, KC_0, KC_DOT,             KC_NO, KC_NO, KC_NO
    ),

    [SYM] = LAYOUT(
        S(KC_LBRC), S(KC_7), S(KC_8), S(KC_9), S(KC_RBRC), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        S(KC_SCLN), S(KC_4), S(KC_5), S(KC_6), S(KC_EQL),  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        S(KC_GRV),  S(KC_1), S(KC_2), S(KC_3), S(KC_BSLS), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             S(KC_9), S(KC_0), S(KC_MINS), KC_TRNS, KC_NO, KC_NO
    ),

    [FUNC] = LAYOUT(
        KC_NO, KC_F7, KC_F8, KC_F9, KC_F10,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F4, KC_F5, KC_F6, KC_F11,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                      KC_NO, KC_NO, KC_NO,                 KC_NO, KC_NO, KC_TRNS
    ),
};

/* ---------- Temper combo definitions ---------- */

enum combo_events {
    C_ESC,
    C_TAB,
    C_CUT,
    C_COPY,
    C_PASTE,
    C_BSPC,
    C_DEL,
    C_LPAR,
    C_RPAR,
    C_LT,
    C_GT,
    C_LBKT,
    C_RBKT,
    C_LBRC,
    C_RBRC,
    C_AT,
    C_HASH,
    C_DLR,
    C_PERC,
    C_GRV,
    C_BSLS,
    C_SLSH,
    C_TILD,
    C_CIRC,
    C_PLUS,
    C_ASTR,
    C_AMPR,
    C_UNDS,
    C_MINS,
    C_EQL,
    C_PIPE,
    COMBO_LENGTH
};

const uint16_t PROGMEM cb_esc[]   = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cb_tab[]   = {HM_S, HM_D, COMBO_END};
const uint16_t PROGMEM cb_cut[]   = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM cb_copy[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cb_paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cb_bspc[]  = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cb_del[]   = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cb_lpar[]  = {HM_J, HM_K, COMBO_END};
const uint16_t PROGMEM cb_rpar[]  = {HM_K, HM_L, COMBO_END};
const uint16_t PROGMEM cb_lbkt[]  = {KC_M, CM_MORPH, COMBO_END};
const uint16_t PROGMEM cb_rbkt[]  = {CM_MORPH, DT_MORPH, COMBO_END};

const uint16_t PROGMEM cb_at[]    = {KC_W, HM_S, COMBO_END};
const uint16_t PROGMEM cb_hash[]  = {KC_E, HM_D, COMBO_END};
const uint16_t PROGMEM cb_dlr[]   = {KC_R, HM_F, COMBO_END};
const uint16_t PROGMEM cb_perc[]  = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM cb_grv[]   = {HM_S, KC_X, COMBO_END};
const uint16_t PROGMEM cb_bsls[]  = {HM_D, KC_C, COMBO_END};
const uint16_t PROGMEM cb_slsh[]  = {HM_F, KC_V, COMBO_END};
const uint16_t PROGMEM cb_tild[]  = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM cb_circ[]  = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM cb_plus[]  = {KC_U, HM_J, COMBO_END};
const uint16_t PROGMEM cb_astr[]  = {KC_I, HM_K, COMBO_END};
const uint16_t PROGMEM cb_ampr[]  = {KC_O, HM_L, COMBO_END};
const uint16_t PROGMEM cb_unds[]  = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM cb_mins[]  = {HM_J, KC_M, COMBO_END};
const uint16_t PROGMEM cb_eql[]   = {HM_K, CM_MORPH, COMBO_END};
const uint16_t PROGMEM cb_pipe[]  = {HM_L, DT_MORPH, COMBO_END};

combo_t key_combos[] = {
    [C_ESC]   = COMBO(cb_esc, KC_ESC),
    [C_TAB]   = COMBO_ACTION(cb_tab),
    [C_CUT]   = COMBO(cb_cut, LCTL(KC_X)),
    [C_COPY]  = COMBO(cb_copy, LCTL(KC_C)),
    [C_PASTE] = COMBO(cb_paste, LCTL(KC_V)),
    [C_BSPC]  = COMBO(cb_bspc, KC_BSPC),
    [C_DEL]   = COMBO(cb_del, KC_DEL),
    [C_LPAR]  = COMBO_ACTION(cb_lpar),
    [C_RPAR]  = COMBO_ACTION(cb_rpar),
    [C_LT]    = COMBO(cb_lpar, S(KC_COMM)),
    [C_GT]    = COMBO(cb_rpar, S(KC_DOT)),
    [C_LBKT]  = COMBO(cb_lbkt, KC_LBRC),
    [C_RBKT]  = COMBO(cb_rbkt, KC_RBRC),
    [C_LBRC]  = COMBO(cb_lbkt, S(KC_LBRC)),
    [C_RBRC]  = COMBO(cb_rbkt, S(KC_RBRC)),
    [C_AT]    = COMBO(cb_at, S(KC_2)),
    [C_HASH]  = COMBO(cb_hash, S(KC_3)),
    [C_DLR]   = COMBO(cb_dlr, S(KC_4)),
    [C_PERC]  = COMBO(cb_perc, S(KC_5)),
    [C_GRV]   = COMBO(cb_grv, KC_GRV),
    [C_BSLS]  = COMBO(cb_bsls, KC_BSLS),
    [C_SLSH]  = COMBO(cb_slsh, KC_SLSH),
    [C_TILD]  = COMBO(cb_tild, S(KC_GRV)),
    [C_CIRC]  = COMBO(cb_circ, S(KC_6)),
    [C_PLUS]  = COMBO(cb_plus, S(KC_EQL)),
    [C_ASTR]  = COMBO(cb_astr, S(KC_8)),
    [C_AMPR]  = COMBO(cb_ampr, S(KC_7)),
    [C_UNDS]  = COMBO(cb_unds, S(KC_MINS)),
    [C_MINS]  = COMBO(cb_mins, KC_MINS),
    [C_EQL]   = COMBO(cb_eql, KC_EQL),
    [C_PIPE]  = COMBO(cb_pipe, S(KC_BSLS)),
};

typedef struct {
    uint8_t first;
    uint8_t second;
    uint8_t layers;
    uint8_t prior_idle_ms;
} combo_rule_t;

#define LBIT(layer) (1U << (layer))
#define L_DEF_NAV_NUM (LBIT(BASE) | LBIT(NAV) | LBIT(NUM))
#define L_DEF_NUM (LBIT(BASE) | LBIT(NUM))

static const combo_rule_t combo_rules[COMBO_LENGTH] = {
    [C_ESC]   = {1, 2, L_DEF_NAV_NUM, 150},
    [C_TAB]   = {11, 12, L_DEF_NAV_NUM, 150},
    [C_CUT]   = {21, 23, L_DEF_NAV_NUM, 150},
    [C_COPY]  = {21, 22, L_DEF_NAV_NUM, 150},
    [C_PASTE] = {22, 23, L_DEF_NAV_NUM, 150},
    [C_BSPC]  = {6, 7, L_DEF_NAV_NUM, 150},
    [C_DEL]   = {7, 8, L_DEF_NAV_NUM, 150},
    [C_LPAR]  = {16, 17, L_DEF_NUM, 150},
    [C_RPAR]  = {17, 18, L_DEF_NUM, 150},
    [C_LT]    = {16, 17, LBIT(NAV), 150},
    [C_GT]    = {17, 18, LBIT(NAV), 150},
    [C_LBKT]  = {26, 27, L_DEF_NUM, 150},
    [C_RBKT]  = {27, 28, L_DEF_NUM, 150},
    [C_LBRC]  = {26, 27, LBIT(NAV), 150},
    [C_RBRC]  = {27, 28, LBIT(NAV), 150},
    [C_AT]    = {1, 11, L_DEF_NAV_NUM, 50},
    [C_HASH]  = {2, 12, L_DEF_NAV_NUM, 50},
    [C_DLR]   = {3, 13, L_DEF_NAV_NUM, 50},
    [C_PERC]  = {4, 14, L_DEF_NAV_NUM, 50},
    [C_GRV]   = {11, 21, L_DEF_NAV_NUM, 50},
    [C_BSLS]  = {12, 22, L_DEF_NAV_NUM, 50},
    [C_SLSH]  = {13, 23, L_DEF_NAV_NUM, 50},
    [C_TILD]  = {14, 24, L_DEF_NAV_NUM, 50},
    [C_CIRC]  = {5, 15, L_DEF_NAV_NUM, 50},
    [C_PLUS]  = {6, 16, L_DEF_NAV_NUM, 50},
    [C_ASTR]  = {7, 17, L_DEF_NAV_NUM, 50},
    [C_AMPR]  = {8, 18, L_DEF_NAV_NUM, 50},
    [C_UNDS]  = {15, 25, L_DEF_NAV_NUM, 50},
    [C_MINS]  = {16, 26, L_DEF_NAV_NUM, 50},
    [C_EQL]   = {17, 27, L_DEF_NAV_NUM, 50},
    [C_PIPE]  = {18, 28, L_DEF_NAV_NUM, 50},
};

static bool physical_pressed[36];
static uint16_t idle_before_press[36];
static uint32_t press_sequence[36];
static uint32_t last_physical_press;
static uint32_t next_press_sequence;

static int8_t physical_index(keypos_t key) {
    if (key.row < 3 && key.col < 10) {
        return key.row * 10 + key.col;
    }
    if (key.row == 3 && key.col >= 2 && key.col <= 7) {
        return 30 + key.col - 2;
    }
    return -1;
}

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    (void)combo;
    return combo_index >= C_AT ? 30 : 18;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    (void)combo;
    (void)keycode;
    (void)record;
    if (combo_index >= COMBO_LENGTH) {
        return false;
    }

    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    const combo_rule_t *rule = &combo_rules[combo_index];
    if (layer > FUNC || !(rule->layers & LBIT(layer))) {
        return false;
    }

    if (!physical_pressed[rule->first] || !physical_pressed[rule->second]) {
        return true;
    }

    uint8_t first_pressed = press_sequence[rule->first] < press_sequence[rule->second]
                                ? rule->first
                                : rule->second;
    return idle_before_press[first_pressed] >= rule->prior_idle_ms;
}

/* ---------- Combo hold-taps ---------- */

typedef enum {
    CHT_NONE,
    CHT_TAB,
    CHT_LPAR,
    CHT_RPAR,
} combo_hold_tap_kind_t;

typedef struct {
    combo_hold_tap_kind_t kind;
    uint16_t timer;
    uint8_t added_mods;
    bool held;
} combo_hold_tap_state_t;

static combo_hold_tap_state_t combo_hold_tap;

static void tap_with_suppressed_mods(uint8_t suppressed, uint16_t keycode) {
    uint8_t saved_mods = get_mods();
    if (suppressed) {
        set_mods(saved_mods & ~suppressed);
        send_keyboard_report();
    }
    tap_code16(keycode);
    if (suppressed) {
        set_mods(saved_mods);
        send_keyboard_report();
    }
}

static void tap_combo_hold_tap(combo_hold_tap_kind_t kind) {
    uint8_t shifts = get_mods() & MOD_MASK_SHIFT;
    switch (kind) {
        case CHT_TAB:
            tap_code(KC_TAB);
            break;
        case CHT_LPAR:
            tap_with_suppressed_mods(shifts, shifts ? S(KC_COMM) : S(KC_9));
            break;
        case CHT_RPAR:
            tap_with_suppressed_mods(shifts, shifts ? S(KC_DOT) : S(KC_0));
            break;
        default:
            break;
    }
}

static uint8_t combo_hold_mods(combo_hold_tap_kind_t kind) {
    switch (kind) {
        case CHT_TAB:
            return MOD_BIT(KC_LSFT) | MOD_BIT(KC_LALT);
        case CHT_LPAR:
            return MOD_BIT(KC_RSFT) | MOD_BIT(KC_LCTL);
        case CHT_RPAR:
            return MOD_BIT(KC_RSFT) | MOD_BIT(KC_LALT);
        default:
            return 0;
    }
}

static void hold_combo_hold_tap(void) {
    uint8_t wanted = combo_hold_mods(combo_hold_tap.kind);
    combo_hold_tap.added_mods = wanted & ~get_mods();
    register_mods(combo_hold_tap.added_mods);
    combo_hold_tap.held = true;
}

static bool combo_hold_trigger(combo_hold_tap_kind_t kind, uint8_t pos) {
    bool thumb = pos >= 30;
    bool left = pos < 30 && pos % 10 < 5;
    bool right = pos < 30 && pos % 10 >= 5;
    return thumb || (kind == CHT_TAB ? right : left);
}

static void interrupt_combo_hold_tap(uint8_t pos) {
    if (combo_hold_tap.kind == CHT_NONE || combo_hold_tap.held) {
        return;
    }
    if (combo_hold_trigger(combo_hold_tap.kind, pos)) {
        hold_combo_hold_tap();
    } else {
        tap_combo_hold_tap(combo_hold_tap.kind);
        combo_hold_tap.kind = CHT_NONE;
    }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    combo_hold_tap_kind_t kind = CHT_NONE;
    if (combo_index == C_TAB) {
        kind = CHT_TAB;
    } else if (combo_index == C_LPAR) {
        kind = CHT_LPAR;
    } else if (combo_index == C_RPAR) {
        kind = CHT_RPAR;
    }

    if (pressed) {
        combo_hold_tap = (combo_hold_tap_state_t){
            .kind = kind,
            .timer = timer_read(),
        };
    } else if (combo_hold_tap.kind != CHT_NONE) {
        if (combo_hold_tap.held) {
            unregister_mods(combo_hold_tap.added_mods);
        } else {
            tap_combo_hold_tap(combo_hold_tap.kind);
        }
        combo_hold_tap = (combo_hold_tap_state_t){0};
    }
}

/* ---------- Navigation tap-preferred hold-taps ---------- */

typedef enum {
    NAV_PENDING,
    NAV_TAPPED,
    NAV_HELD,
} nav_resolution_t;

typedef struct {
    bool active;
    bool quick_tap;
    uint16_t timer;
    uint16_t last_tap;
    uint16_t keycode;
    uint8_t suppressed_ctrl;
    nav_resolution_t resolution;
    keypos_t position;
} nav_hold_tap_state_t;

static nav_hold_tap_state_t nav_states[6];

static int8_t nav_index(uint16_t keycode) {
    if (keycode >= NV_LEFT && keycode <= NV_DEL) {
        return keycode - NV_LEFT;
    }
    return -1;
}

static uint16_t nav_tap_keycode(uint8_t index) {
    static const uint16_t taps[] = {KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_BSPC, KC_DEL};
    return taps[index];
}

static uint16_t nav_hold_keycode(uint8_t index) {
    static const uint16_t holds[] = {
        KC_HOME, LCTL(KC_END), LCTL(KC_HOME), KC_END, LCTL(KC_BSPC), LCTL(KC_DEL)
    };
    return holds[index];
}

static void resolve_nav_tap(uint8_t index) {
    tap_code16(nav_tap_keycode(index));
    nav_states[index].last_tap = timer_read();
    nav_states[index].resolution = NAV_TAPPED;
}

static void resolve_nav_hold(uint8_t index) {
    nav_hold_tap_state_t *state = &nav_states[index];
    if (index == 0 || index == 3) {
        state->suppressed_ctrl = get_mods() & MOD_MASK_CTRL;
        unregister_mods(state->suppressed_ctrl);
    }
    register_code16(nav_hold_keycode(index));
    state->resolution = NAV_HELD;
}

static void interrupt_nav_hold_taps(keypos_t position) {
    for (uint8_t i = 0; i < 6; ++i) {
        nav_hold_tap_state_t *state = &nav_states[i];
        if (state->active && state->resolution == NAV_PENDING &&
            (state->position.row != position.row || state->position.col != position.col)) {
            resolve_nav_tap(i);
        }
    }
}

/* ---------- QMK tap-hold policy matching the ZMK behaviors ---------- */

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

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    (void)keycode;
    int8_t pos = physical_index(record->event.key);
    if (pos < 0) {
        return true;
    }

    if (record->event.pressed) {
        uint32_t elapsed = timer_elapsed32(last_physical_press);
        idle_before_press[pos] = elapsed > UINT16_MAX ? UINT16_MAX : (uint16_t)elapsed;
        last_physical_press = timer_read32();
        press_sequence[pos] = ++next_press_sequence;
        physical_pressed[pos] = true;

        interrupt_nav_hold_taps(record->event.key);
        interrupt_combo_hold_tap(pos);
    } else {
        physical_pressed[pos] = false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t shifts = get_mods() & MOD_MASK_SHIFT;
    uint8_t ctrls = get_mods() & MOD_MASK_CTRL;

    switch (keycode) {
        case CM_MORPH:
            if (record->event.pressed) {
                if (!shifts) {
                    tap_code(KC_COMM);
                } else if (ctrls) {
                    /* Both nested ZMK mod-morphs mask their trigger mods. */
                    tap_with_suppressed_mods(shifts | ctrls, S(KC_COMM));
                } else {
                    tap_with_suppressed_mods(shifts, KC_SCLN);
                }
            }
            return false;
        case DT_MORPH:
            if (record->event.pressed) {
                if (!shifts) {
                    tap_code(KC_DOT);
                } else if (ctrls) {
                    tap_with_suppressed_mods(shifts | ctrls, S(KC_DOT));
                } else {
                    tap_with_suppressed_mods(shifts, S(KC_SCLN));
                }
            }
            return false;
        case QEXCL:
            if (record->event.pressed) {
                tap_with_suppressed_mods(shifts, shifts ? S(KC_1) : S(KC_SLSH));
            }
            return false;
    }

    int8_t index = nav_index(keycode);
    if (index >= 0) {
        nav_hold_tap_state_t *state = &nav_states[index];
        if (record->event.pressed) {
            uint16_t previous_tap = state->last_tap;
            *state = (nav_hold_tap_state_t){
                .active = true,
                .quick_tap = previous_tap && timer_elapsed(previous_tap) < 220,
                .timer = timer_read(),
                .last_tap = previous_tap,
                .keycode = keycode,
                .resolution = NAV_PENDING,
                .position = record->event.key,
            };
        } else if (state->active) {
            if (state->resolution == NAV_PENDING) {
                resolve_nav_tap(index);
            } else if (state->resolution == NAV_HELD) {
                unregister_code16(nav_hold_keycode(index));
                register_mods(state->suppressed_ctrl);
            }
            state->active = false;
        }
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    if (combo_hold_tap.kind != CHT_NONE && !combo_hold_tap.held &&
        timer_elapsed(combo_hold_tap.timer) >= 280) {
        hold_combo_hold_tap();
    }

    for (uint8_t i = 0; i < 6; ++i) {
        nav_hold_tap_state_t *state = &nav_states[i];
        if (state->active && state->resolution == NAV_PENDING && !state->quick_tap &&
            timer_elapsed(state->timer) >= 220) {
            resolve_nav_hold(i);
        }
    }
}

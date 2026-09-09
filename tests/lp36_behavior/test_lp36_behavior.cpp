// Copyright 2026 ika-twb
// SPDX-License-Identifier: MIT

#include "keyboard_report_util.hpp"
#include "mouse_report_util.hpp"
#include "test_common.hpp"
#include "test_fixture.hpp"
#include "test_keymap_key.hpp"
#include "keyboards/lp36/keymaps/default/features.h"

using testing::InSequence;
using testing::_;

class Lp36Behavior : public TestFixture {};

TEST_F(Lp36Behavior, plain_combo_participant_stays_held) {
    TestDriver driver;
    InSequence sequence;
    auto v = KeymapKey(0, 3, 2, KC_V);
    auto x = KeymapKey(0, 1, 2, KC_X);
    set_keymap({v, x});
    idle_for(1); // The combo engine uses zero as its "no timer" sentinel.

    EXPECT_NO_REPORT(driver);
    v.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_V));
    idle_for(COMBO_TERM + 1);
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    idle_for(500);
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    v.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(Lp36Behavior, home_row_tap_then_hold_stays_on_tap_key) {
    TestDriver driver;
    InSequence sequence;
    auto s = KeymapKey(0, 1, 1, LALT_T(KC_S));
    auto d = KeymapKey(0, 2, 1, LCTL_T(KC_D));
    set_keymap({s, d});

    EXPECT_NO_REPORT(driver);
    s.press();
    run_one_scan_loop();
    idle_for(COMBO_TERM + 1);
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_S));
    EXPECT_EMPTY_REPORT(driver);
    s.release();
    run_one_scan_loop();
    idle_for(QUICK_TAP_TERM - COMBO_TERM - 10);
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_S));
    s.press();
    run_one_scan_loop();
    idle_for(COMBO_TERM + 1);
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    idle_for(TAPPING_TERM + 1);
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    s.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(Lp36Behavior, dedicated_arrow_stays_held) {
    TestDriver driver;
    InSequence sequence;
    auto left = KeymapKey(0, 5, 1, KC_LEFT);
    set_keymap({left});

    EXPECT_REPORT(driver, (KC_LEFT));
    left.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    idle_for(500);
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    left.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(Lp36Behavior, morph_stays_held_and_preserves_shifted_choice) {
    TestDriver driver;
    InSequence sequence;
    auto comma = KeymapKey(0, 7, 2, CM_MORPH);
    auto shift = KeymapKey(0, 0, 3, KC_LSFT);
    set_keymap({comma, shift});

    EXPECT_REPORT(driver, (KC_COMM));
    comma.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_NO_REPORT(driver);
    idle_for(500);
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    comma.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_LSFT));
    shift.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    EXPECT_REPORT(driver, (KC_SCLN));
    comma.press();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    EXPECT_REPORT(driver, (KC_LSFT));
    comma.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);

    EXPECT_EMPTY_REPORT(driver);
    shift.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(Lp36Behavior, each_mouse_direction_starts_its_own_acceleration) {
    TestDriver driver;
    auto left = KeymapKey(0, 5, 1, MM_LEFT);
    auto right = KeymapKey(0, 8, 1, MM_RIGHT);
    set_keymap({left, right});

    EXPECT_MOUSE_REPORT(driver, (-1, 0, 0, 0, 0));
    left.press();
    run_one_scan_loop();
    pointer_task();
    VERIFY_AND_CLEAR(driver);

    EXPECT_MOUSE_REPORT(driver, (-38, 0, 0, 0, 0));
    idle_for(500);
    pointer_task();
    VERIFY_AND_CLEAR(driver);

    // Left is at full speed, while newly pressed Right starts from speed 1.
    EXPECT_MOUSE_REPORT(driver, (-37, 0, 0, 0, 0));
    right.press();
    run_one_scan_loop();
    pointer_task();
    VERIFY_AND_CLEAR(driver);

    right.release();
    left.release();
    run_one_scan_loop();
}

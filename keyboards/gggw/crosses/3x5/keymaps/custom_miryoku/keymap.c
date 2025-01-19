// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action_layer.h"
#include QMK_KEYBOARD_H

#include "lib/crosses.h"

enum CROSSES_LAYERS {
    _BASE,
    _MEDIA,
    _NAV,
    _MOUS,
    _MOUSRIGHT,
    _NUM,
    _FUNC,
};

enum my_keycodes {
    VIMS = SAFE_RANGE,
    LARR,
    FARR,
    EPIP,
    LVBC,
    RVBC,
    BARR,
    MSE_INC,
    MSE_DEC,
    DRAG_SCROLL,
};


enum combos {
    WY_TAB,
    DH_CAPS,
    HCOMA_MINS,
    WSPC_VIM,
    FU_QUOTE,
    PL_DQUOTE,
    CCOM_LARR,
    XDOT_FARR,
    GM_EPIP,
    COMD_UNDERS,
    ZDOT_BARR,
};

const uint16_t PROGMEM wy_combo[]     = {KC_W, KC_Y, COMBO_END};
const uint16_t PROGMEM dh_combo[]     = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM hcomma_combo[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM wspc_combo[]   = {KC_W, KC_SPC, COMBO_END};
const uint16_t PROGMEM fu_combo[]     = {KC_F, KC_U, COMBO_END};
const uint16_t PROGMEM pl_combo[]     = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM ccom_combo[]   = {KC_C, KC_COMM, COMBO_END};
const uint16_t PROGMEM xdot_combo[]   = {KC_X, KC_DOT, COMBO_END};
const uint16_t PROGMEM gm_combo[]     = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM comd_combo[]   = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM zdot_combo[]   = {KC_Z, KC_DOT, COMBO_END};

// clang-format off
//
combo_t key_combos[] = {
    [WY_TAB] = COMBO(wy_combo, KC_TAB),
    [DH_CAPS] = COMBO(dh_combo, CW_TOGG),
    [HCOMA_MINS] = COMBO(hcomma_combo, KC_MINS),
    [WSPC_VIM] = COMBO(wspc_combo, VIMS),
    [FU_QUOTE] = COMBO(fu_combo, KC_QUOT),
    [PL_DQUOTE] = COMBO(pl_combo, S(KC_QUOT)),
    [CCOM_LARR] = COMBO(ccom_combo, LARR),
    [XDOT_FARR] = COMBO(xdot_combo, FARR),
    [GM_EPIP] = COMBO(gm_combo, EPIP),
    [COMD_UNDERS] = COMBO(comd_combo, S(KC_MINS)),
    [ZDOT_BARR] = COMBO(zdot_combo, BARR),
};

/*
 * Keymaps!
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_default(
        KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,                KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,
        LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      KC_G,                KC_H,              RSFT_T(KC_J),      RCTL_T(KC_K),      RALT_T(KC_L),      RGUI_T(KC_QUOT),
        KC_Z,              ALGR_T(KC_X),      KC_C,              KC_V,              KC_B,                KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    KC_SLSH,
                                              LT(1, KC_ESC),     LT(2, KC_SPC),     LT(3, KC_TAB),       LT(4, KC_ENT),     LT(5, KC_BSPC),    LT(6, KC_DEL)
    ),

    [_MEDIA] = LAYOUT_default(
        KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,               KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,
        KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_NO,               KC_NO,             KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,
        KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,               KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,
                                              KC_NO,             KC_NO,             KC_NO,               KC_MSTP,           KC_MPLY,           KC_MUTE
    ),

    [_NAV] = LAYOUT_default(
        KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,               KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,
        KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_NO,               KC_CAPS,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,
        KC_NO,             KC_NO,             KC_COPY,           KC_PSTE,           KC_NO,               KC_INS,             KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,
                                              KC_NO,             KC_NO,             KC_NO,               KC_ENT,            KC_BSPC,           KC_DEL
    ),

    [_MOUS] = LAYOUT_default(
        KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,               KC_NO,             MSE_INC,           MSE_DEC,           KC_NO,             KC_NO,
        KC_BTN3,           KC_BTN1,           KC_BTN2,           DRAG_SCROLL,       KC_NO,               KC_NO,             KC_RSFT,           KC_RCTL,           KC_RALT,           KC_RGUI,
        KC_UNDO,           KC_CUT,            KC_COPY,           KC_PASTE,          KC_NO,               KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,
                                              KC_NO,             KC_NO,             KC_NO,               KC_BTN2,           KC_BTN1,           KC_BTN2
    ),

    [_MOUSRIGHT] = LAYOUT_default(
        KC_NO,             KC_NO,             MSE_DEC,           MSE_INC,           KC_NO,               KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,
        KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           KC_NO,               KC_NO,             DRAG_SCROLL,       KC_BTN2,           KC_BTN1,           KC_BTN3,
        KC_NO,             KC_NO,             KC_NO,             KC_NO,             KC_NO,               KC_NO,             KC_PASTE,          KC_COPY,           KC_CUT,            KC_UNDO,
                                              KC_BTN3,           KC_BTN1,           KC_BTN2,             KC_NO,             KC_NO,             KC_NO
    ),

    [_NUM] = LAYOUT_default(
        KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,            KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,
        KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,             KC_NO,              KC_LSFT,           KC_LCTL,             KC_LALT,            KC_LGUI,
        KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,            KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,
                                              KC_DOT,            KC_0,              KC_MINS,            KC_NO,              KC_NO,              KC_NO
    ),

    [_FUNC] = LAYOUT_default(
        KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,            KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,
        KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,            KC_NO,              KC_LSFT,            KC_LCTL,            KC_LALT,            KC_LGUI,
        KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,            KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,
                                              KC_APP,            KC_SPC,            KC_TAB,             KC_NO,              KC_NO,              KC_NO
    )
};


// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case MSE_INC:
            if (record->event.pressed) {
                change_pointer_dpi(&global_user_config, true);
                debug_config_to_console(&global_user_config);

                return false;
            }
            break;
        case MSE_DEC:
            if (record->event.pressed) {
                change_pointer_dpi(&global_user_config, false);
                debug_config_to_console(&global_user_config);

                return false;
            }
            break;
        case DRAG_SCROLL:
            set_scrolling = record->event.pressed;
            break;
    }

    return true;
}

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();

    const char* layer_names[] = {
        [_BASE] = ">> BASE ", [_NUM] = ">> PROG ", [_NAV] = ">> NAVI ", [_MEDIA] = ">>> MEDIA ", [_FUNC] = ">>> FUNC ", [_MOUS] = ">>> MOUSE ",
    };

    oled_write_P(PSTR(layer_names[get_highest_layer(layer_state)]), false);

    return false;
}
#endif /* ifdef OLED_ENABLE */

void keyboard_post_init_user(void) {
    global_user_config.raw = eeconfig_read_user();
    update_pointer_cpi(&global_user_config);
    write_config_to_eeprom(&global_user_config);
}

// void pointing_device_init_user(void) {
//     set_auto_mouse_layer(_MOUS);
//     set_auto_mouse_enable(true);
// }

#include QMK_KEYBOARD_H
#include "oled.c"
#include "combos.c"

// enum sofle_layers {
//     /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
//     _BASE,
//     _LOWER,
//     _RAISE,
//     _ADJUST,
// };

// enum custom_keycodes {
//     KC_PRVWD = QK_USER,
//     KC_NXTWD,
//     KC_LSTRT,
//     KC_LEND
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * 0 - BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LOpt | LCmd |LOWER | /Space  /       \Enter \  |RAISE | RCmd | ROpt | RCTR |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[0] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
  KC_CAPS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_MUTE,     XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                    KC_LCTL, KC_LOPT, KC_LCMD, TL_LOWR, KC_SPC,      KC_ENT,  TL_UPPR, KC_RCMD, KC_ROPT, KC_RCTL
),

/* 1 - LOWER
 * ,--------------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  F1  |  F2  |   F3   |   F4  |  F5  |                    |      |      |      |      |      |   =  |
 * |------+------+------+--------+-------+------|                    |------+------+------+------+------+------|
 * | TAB  |  F6  |  F7  |   F8   |   F9  |  F10 |                    |   (  |   )  |   +  |      |      |      |
 * |------+------+------+--------+-------+------|                    |------+------+------+------+------+------|
 * | CAPS |  F11 |  F12 | LSA(D) |       |      |-------.    ,-------|   [  |   ]  |   =  |      |      |   |  |
 * |------+------+------+--------+-------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift| Undo |  Cut |  Copy  | Paste |      |-------|    |-------|   {  |   }  |   ;  |   :  |   \  | Shift|
 * `--------------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR |  LOpt |  LCmd | LOWER | /Space  /       \Enter \  |RAISE | RCmd | ROpt | RCTR |
 *            |      |       |       |       |/       /         \      \ |      |      |      |      |
 *            `--------------------------------------'           '------''---------------------------'
 */
[1] = LAYOUT(
  KC_ESC,  KC_F1,      KC_F2,      KC_F3,        KC_F4,      KC_F5,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQUAL,
  _______, KC_F6,      KC_F7,      KC_F8,        KC_F9,      KC_F10,                        KC_LPRN, KC_RPRN, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, KC_F11,     KC_F12,     LSA(KC_DOWN), XXXXXXX,    XXXXXXX,                       KC_LBRC, KC_RBRC, KC_EQL,  XXXXXXX, XXXXXXX, KC_PIPE,
  _______, LCMD(KC_Z), LCMD(KC_X), LCMD(KC_C),   LCMD(KC_V), XXXXXXX, _______,     _______, KC_LCBR, KC_RCBR, KC_SCLN, KC_COLN, KC_BSLS, _______,
                       _______,    _______,      _______,    _______, _______,     _______, _______, _______, _______, _______
),

/* 2 - RAISE
 * ,--------------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |        | PrtScr|      |                    |      |      |      |      |      | LnDel|
 * |------+------+------+--------+-------+------|                    |------+------+------+------+------+------|
 * | TAB  |LCG(A)|      |        |       |      |                    | PgUp |      |  UP  |      |      |  DEL |
 * |------+------+------+--------+-------+------|                    |------+------+------+------+------+------|
 * | CAPS |      |      | LSA(D) |       |      |-------.    ,-------| PgDn | LEFT | DOWN | RIGHT|      |   |  |
 * |------+------+------+--------+-------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift| Undo |  Cut |  Copy  | Paste |      |-------|    |-------|      | Scr_L| Scr_D| Scr_R|      | Shift|
 * `--------------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR |  LOpt |  LCmd | LOWER | /Space  /       \Enter \  |RAISE | RCmd | ROpt | RCTR |
 *            |      |       |       |       |/       /         \      \ |      |      |      |      |
 *            `--------------------------------------'           '------''---------------------------'
 */
[2] = LAYOUT(
  KC_ESC,  XXXXXXX,    XXXXXXX,    XXXXXXX,      LCSG(KC_4), XXXXXXX,                       XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX, LSFT(KC_DEL),
  _______, LCG(KC_A),  XXXXXXX,    XXXXXXX,      XXXXXXX,    XXXXXXX,                       KC_PGUP, XXXXXXX,       KC_UP,         XXXXXXX,       XXXXXXX, KC_DEL,
  _______, XXXXXXX,    XXXXXXX,    LSA(KC_DOWN), XXXXXXX,    XXXXXXX,                       KC_PGDN, KC_LEFT,       KC_DOWN,       KC_RGHT,       XXXXXXX, KC_PIPE,
  _______, LCMD(KC_Z), LCMD(KC_X), LCMD(KC_C),   LCMD(KC_V), XXXXXXX, _______,     _______, XXXXXXX, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RGHT), XXXXXXX, _______,
                       _______,    _______,      _______,    _______, _______,     _______, _______, _______,       _______,       _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[3] = LAYOUT(
  LCG(KC_Q), UG_NEXT, UG_HUEU, UG_SATU, UG_VALU, UG_SPDU,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, UG_PREV, UG_HUED, UG_SATD, UG_VALD, UG_SPDD,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG,     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
)
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(MS_WHLR, MS_WHLL) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif


// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case KC_PRVWD:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 }
//             }
//             break;
//         case KC_NXTWD:
//              if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     register_mods(mod_config(MOD_LALT));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LALT));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 }
//             }
//             break;
//         case KC_LSTRT:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                      //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_LEFT);
//                 } else {
//                     register_code(KC_HOME);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_LEFT);
//                 } else {
//                     unregister_code(KC_HOME);
//                 }
//             }
//             break;
//         case KC_LEND:
//             if (record->event.pressed) {
//                 if (keymap_config.swap_lctl_lgui) {
//                     //CMD-arrow on Mac, but we have CTL and GUI swapped
//                     register_mods(mod_config(MOD_LCTL));
//                     register_code(KC_RIGHT);
//                 } else {
//                     register_code(KC_END);
//                 }
//             } else {
//                 if (keymap_config.swap_lctl_lgui) {
//                     unregister_mods(mod_config(MOD_LCTL));
//                     unregister_code(KC_RIGHT);
//                 } else {
//                     unregister_code(KC_END);
//                 }
//             }
//             break;
//     }
//     return true;
// }

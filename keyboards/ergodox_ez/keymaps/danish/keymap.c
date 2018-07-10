#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_danish.h"

#define BASE 0 // default layer
#define PRGM 1 // programming layer
#define MDIA 2 // mouse and media keys
#define NUMP 3 // numpad for numbers
#define SYMB 4 // numpad for numbers

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  CIRC,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    <   |   1  |   2  |   3  |   4  |   5  |  <-  |           |  ->  |   6  |   7  |   8  |   9  |   0  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   DEL  |   Q  |   W  |   E  |   R  |   T  |  ^   |           |   $  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  SHIFT | A/L1 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | Æ/L2 | Ø/Shift|
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * |  Ctrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |-/ctrl|   DEL  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |alt/esc|  <  |   ?  |  <-  |  ->  |                                       |  UP  | Down |   #  |   $  | LT_nump|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | Home | Super|       |Insert|  esc  |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | Home |       |Alt Gr|       |      |
 *                                 | Space| Back |------|       |------| Tab   | Enter|
 *                                 |      |      | Alt  |       | Super|       |      |
 *                                 `--------------------'       `---------------------'
 */
[BASE] = LAYOUT_ergodox(
        // left hand
        KC_NUBS,      KC_1,         KC_2,    KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_DEL,      KC_Q,         KC_W,    KC_E,   KC_R,   KC_T,   CIRC,
        KC_LSHIFT,    LT(PRGM, KC_A),  KC_S,    KC_D,   KC_F,   KC_G,
        KC_LCTRL,     CTL_T(KC_Z),  KC_X,    KC_C,   KC_V,   KC_B,   ALL_T(KC_NO),
		ALT_T(KC_ESC),KC_NUBS,      DA_QUES,  KC_LEFT, KC_RIGHT,
                                                      KC_HOME, KC_LGUI,
                                                               KC_HOME,
                                          KC_SPACE, KC_BSPACE, KC_LALT,
        // right hand
        KC_RIGHT,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    DA_PLUS,
        DA_DLR,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    DA_AA,
        KC_H,        KC_J,    KC_K,    KC_L,    LT(MDIA, DA_AE),     LSFT_T(DA_OE),
        MEH_T(KC_NO),KC_N,    KC_M,    KC_COMMA,KC_DOT,  DA_MINUS,KC_DEL,
		                      KC_UP,   KC_DOWN, LSFT(KC_3),ALGR(KC_4),TG(NUMP),
                                                 KC_INSERT,  KC_ESC,
                                                 KC_RALT,
                                                 KC_LGUI, KC_TAB, KC_ENTER
),

/* Keymap 1: Layer for programming
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  (   |  )   |  "   |   '  |  TG  |           |      |   ~  |   <  |   >  |   #  |   %  |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | TRNS |  {   |  }   |  ?   |   !  |------|           |------|   @  |   $  |   &  |   |  |   =  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  [   |  ]   |  :   |   ;  |      |           |      |   +  |   -  |   *  |   /  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[PRGM] = LAYOUT_ergodox(
    // left hand
	_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,
    _______, _______, DA_LPRN, DA_RPRN, DA_DQT, DA_QUOT, KC_TRNS,
    _______, KC_TRNS, DA_LCBR, DA_RCBR, DA_QUES,DA_EXLM,
    _______, _______, DA_LBRC, DA_RBRC, DA_COLN, LSFT(KC_COMM), _______,
    _______, _______, _______, _______, _______,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
    // right hand
    _______,  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,
    _______,  DA_TILD, KC_NUBS, LSFT(KC_NUBS), DA_HASH, DA_PERC, KC_F12,
	DA_AT, DA_DLR, DA_AMPR, DA_PIPE, DA_EQUAL, _______,
    _______,  DA_PLUS, DA_MINS, DA_ASTR, DA_SLASH, RALT(KC_NUBS), _______,
                  _______, _______, _______, _______, _______,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),

/* Keymap 2: Layer for mouse and media keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | M_UP |      |      |      |           | TRNS |      |Audio-|Audio+| Mute |alt+f4|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | M_LE | M_DN | M_RI |      |------|           |------| Play | SN<- |->SN  |M_ACEL| TRNS |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Mouse| Mouse|      |       |      |Scroll|Scroll|
 *                                 | Left | Right|------|       |------| Down |  Up  |
 *                                 | Click| Click|      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[MDIA] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_MS_UP, _______, _______, _______,
    _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,
    _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                         _______, _______,
                                                _______,
                                  KC_MS_BTN1, KC_MS_BTN2, _______,
    // right hand
    _______, _______, _______, _______, _______, _______,_______,
    KC_TRNS, _______, KC_VOLD, KC_VOLU, KC_MUTE, LALT(KC_F4), _______,
	         KC_MPLY, KC_MPRV, KC_MNXT, KC_ACL0, KC_TRNS, _______,
    _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, KC_TRNS,
        _______, _______,
        _______,
        _______, KC_WH_D, KC_WH_U
),

/* Keymap 1: Numpad Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      | LEFT |  UP  | DOWN |RIGHT |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   *  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |   .  |   ,  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |       |     |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Numpad 
[NUMP] = LAYOUT_ergodox(
       // left hand
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,_______,_______,
       _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               _______,_______,_______,
       // right hand
       _______, _______,   KC_LEFT,  KC_UP,   KC_DOWN,   KC_RIGHT,  _______,
       _______, _______,   KC_7,   KC_8,    KC_9,    KC_ASTR, _______,
                _______, KC_4,   KC_5,    KC_6,    KC_PLUS, _______,
       _______, _______, KC_1,   KC_2,    KC_3,    KC_BSLS, _______,
                         KC_0,KC_DOT,  KC_COMM,    KC_EQL,  _______,
       _______, _______,
       _______,
       _______, _______, _______ 
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case CIRC:
      if (record->event.pressed) {
        SEND_STRING (SS_LSFT("}")" ");
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};

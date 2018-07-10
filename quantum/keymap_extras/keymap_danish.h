#ifndef KEYMAP_NORWEGIAN_H
#define KEYMAP_NORWEGIAN_H
#include "keymap_nordic.h"
#endif

//set the default æøå keys
#define DA_OE KC_QUOT // ø
#define DA_AE KC_SCLN // æ
#define DA_AA KC_LBRC // å

//default keybindings (english vs. da keys)
#define DA_PLUS KC_MINUS // + => - (plus key on DK is minus on EN)

//single quote (nordic style)
#define DA_QUOT KC_NONUS_HASH // '
#define DA_QUOTE DA_QUOT

#define DA_MINS KC_SLASH // - => / (minus key on DK is slash on EN)
#define DA_MINUS DA_MINS

/*
- // PLUS
\ // SINGLE QUOTE
] // tilde fuck
., //should we override?
/ // BINDESTREG
<> //should we override
= // GREEN BACKSLASH TOP RIGHT
` //random key I never user to the left, weird ass symbol
*/

//shifted rows
#define DA_EXLM LSFT(KC_1) // !
#define DA_EXCLAIM DA_EXLM

#define DA_DQT LSFT(KC_2) // "
#define DA_DOUBLE_QUOTE DA_DQT
#define DA_DQUO DA_DQT
#define DA_QUOTE2 DA_DQT

#define DA_HASH LSFT(KC_3) // #

#define DA_CURR LSFT(KC_4) // ¤
#define DA_CURRENCY DA_CUR

#define DA_PERC LSFT(KC_5) // %
#define DA_PERCENT DA_PER

#define DA_AMPR LSFT(KC_6) // &
#define DA_AMPERSAND DA_AMPR

#define DA_SLASH LSFT(KC_7) // /

#define DA_LPRN LSFT(KC_8) // (
#define DA_LEFT_PAREN DA_LPRN

#define DA_RPRN LSFT(KC_9) // )
#define DA_RIGHT_PAREN DA_RPRN

#define DA_EQUAL LSFT(KC_0) // =

#define DA_QUES LSFT(KC_MINUS) // ?
#define DA_QUESTION DA_QUES

//needs quote (english equal on keyboard)

//#define DA_PIPE LSFT(KC_EQUAL) // |

#define DA_ASTR LSFT(KC_NONUS_HASH) // *
#define DA_ASTERISK DA_ASTR

#define DA_CIRC LSFT(KC_RBRC) // ^
#define DA_CIRCUMFLEX DA_CIRC

#define DA_GT LSFT(KC_BSLASH) // >
#define DA_RABK DA_GT
#define DA_RIGHT_ANGLE_BRACKET DA_GT

#define DA_UNDS LSFT(DA_MINUS) // _
#define DA_UNDERSCORE DA_UNDS

#define DA_COLN LSFT(KC_DOT) // :
#define DA_COLON DA_COLN

//altgr
#define DA_TILD ALGR(KC_RBRC) // ~
#define DA_TILDE DA_TILD

#define DA_AT ALGR(KC_2) // @

#define DA_DLR ALGR(KC_4) // $
#define DA_DOLLAR DA_DLR
  
#define DA_LCBR ALGR(KC_7) // {
#define DA_LEFT_CURLY_BRACE DA_LCBR

#define DA_LBRC ALGR(KC_8) // [
#define DA_LBRACKET DA_LBRC

#define DA_RBRC ALGR(KC_9) // ]
#define DA_RBRACKET DA_RBRC

#define DA_RCBR ALGR(KC_0) // }
#define DA_RIGHT_CURLY_BRACE DA_RCBR

#define DA_PIPE ALGR(KC_EQUAL) // |




  
/*
  
// There are slight differrences in the keyboards in the nordic contries

// Norwegian redifinitions from the nordic keyset
#undef NO_AE
#define NO_AE	KC_QUOT  // æ
#undef NO_BSLS
#define NO_BSLS ALGR(KC_BSLS)  // '\'
#undef NO_CIRC
#define NO_CIRC LSFT(KC_RBRC)  // ^
#undef NO_GRV
#define NO_GRV	LSFT(NO_BSLS)  //
#undef NO_PIPE
#define NO_PIPE KC_GRV  // |

#undef NO_QUOT
#define NO_QUOT KC_NONUS_HASH

// Additional norwegian keys not defined in the nordic keyset
#define NO_AA	KC_LBRC  // å
#define NO_OE   KC_SCLN // ø
#define NO_ASTR LSFT(KC_BSLS)  // *

// Norwegian unique MAC characters
#define NO_ACUT_MAC KC_EQL  // =
#define NO_APOS_MAC KC_NUBS  // '
#define NO_AT_MAC   KC_BSLS  // @
#define NO_BSLS_MAC ALGR(LSFT(KC_7)) // '\'
#define NO_DLR_MAC  LSFT(KC_4) // $
#define NO_GRV_MAC ALGR(NO_BSLS) // `
#define NO_GRTR_MAC LSFT(KC_GRV)  // >
#define NO_LCBR_MAC ALGR(LSFT(KC_8))  // }
#define NO_LESS_MAC KC_GRV  // >
#define NO_PIPE_MAC ALGR(KC_7)  // |
#define NO_RCBR_MAC ALGR(LSFT(KC_9))  // }

#endif
*/

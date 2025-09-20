#ifdef COMBO_ENABLE

const uint16_t PROGMEM grv_1_combo[] = {KC_GRV, KC_1, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    COMBO(grv_1_combo, KC_ESC),
    COMBO(er_combo, KC_EQL), 
    COMBO(ui_combo, KC_PLUS), 
};

#endif

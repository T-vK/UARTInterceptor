// debug.h
#ifndef DEBUG_H
#define DEBUG_H

#include <map>
#include <string>
#include <Arduino.h>
#include "constants.h"

template <typename T>
void printRawPacket(const char* message, T *packet) {
    Serial.printf("%s: ", message);
    auto rawBytes = reinterpret_cast<uint8_t *>(packet);
    for (int i = 4 /* skip vtable */; i < sizeof(T); i++) {
        Serial.printf("%02X ", rawBytes[i]);
    }
    Serial.println();
}

void printRawPacket(const char* message, uint8_t* raw_packet) {
    Serial.printf("%s", message);
    uint8_t size = raw_packet[3] + 7;
    for (int i = 0; i < size; i++) {
        Serial.printf("%02X ", raw_packet[i]);
    }
    Serial.println();
}

std::unordered_map<packet_type, std::string> packet_type_to_string = {
    {ACK, "ACK"},
    {ENTITY, "ENTITY"},
    {UNKNOWN_04, "UNKNOWN_04"},
    {UNKNOWN_05, "UNKNOWN_05"},
    {DATA_REQUEST, "DATA_REQUEST"},
    {UNKNOWN_15, "UNKNOWN_15"},
    {UNKNOWN_16, "UNKNOWN_16"},
    {TUNER_TOGGLE, "TUNER_TOGGLE"},
    {TUNER_FEEDBACK, "TUNER_FEEDBACK"},
    {SNAPSHOT, "SNAPSHOT"},
    {SD_CARD_EVENT, "SD_CARD_EVENT"},
    {HEARTBEAT, "HEARTBEAT"}
};

std::unordered_map<entity_data_type, std::string> entity_data_type_to_string = {
    {BOOL, "BOOL"},
    {UINT8, "UINT8"},
    {FLOAT, "FLOAT"},
};

std::unordered_map<entity_id, std::string> entity_id_to_string = {
    {FRONT_LED, "FRONT_LED"},
    {FEEDBACK_ELIM, "FEEDBACK_ELIM"},
    {AMP_PA_MODE, "AMP_PA_MODE"},
    {LOCATION_MODE, "LOCATION_MODE"},
    {INPUT1_GAIN, "INPUT1_GAIN"},
    {INPUT1_VOLUME, "INPUT1_VOLUME"},
    {INPUT1_MUTE, "INPUT1_MUTE"},
    {INPUT1_CLIP_OL_PRE, "INPUT1_CLIP_OL_PRE"},
    {INPUT1_CLIP_OL_POST, "INPUT1_CLIP_OL_POST"},
    {INPUT1_EFFECT_1_MUTE, "INPUT1_EFFECT_1_MUTE"},
    {INPUT1_EFFECT_1_AMOUNT, "INPUT1_EFFECT_1_AMOUNT"},
    {INPUT1_EFFECT_2_MUTE, "INPUT1_EFFECT_2_MUTE"},
    {INPUT1_EFFECT_2_AMOUNT, "INPUT1_EFFECT_2_AMOUNT"},
    {INPUT1_EQ_ENABLE, "INPUT1_EQ_ENABLE"},
    {INPUT1_EQ_LOW_GAIN, "INPUT1_EQ_LOW_GAIN"},
    {INPUT1_EQ_MID_GAIN, "INPUT1_EQ_MID_GAIN"},
    {INPUT1_EQ_HIGH_GAIN, "INPUT1_EQ_HIGH_GAIN"},
    {INPUT1_COMPRESSOR_ENABLE, "INPUT1_COMPRESSOR_ENABLE"},
    {INPUT1_COMPRESSOR_AMOUNT, "INPUT1_COMPRESSOR_AMOUNT"},
    {INPUT1_EXT_FX_MUTE, "INPUT1_EXT_FX_MUTE"},
    {INPUT1_EXT_FX_SENDS, "INPUT1_EXT_FX_SENDS"},
    {INPUT2_GAIN, "INPUT2_GAIN"},
    {INPUT2_VOLUME, "INPUT2_VOLUME"},
    {INPUT2_MUTE, "INPUT2_MUTE"},
    {INPUT2_CLIP_OL_PRE, "INPUT2_CLIP_OL_PRE"},
    {INPUT2_CLIP_OL_POST, "INPUT2_CLIP_OL_POST"},
    {INPUT2_EFFECT_1_MUTE, "INPUT2_EFFECT_1_MUTE"},
    {INPUT2_EFFECT_1_AMOUNT, "INPUT2_EFFECT_1_AMOUNT"},
    {INPUT2_EFFECT_2_MUTE, "INPUT2_EFFECT_2_MUTE"},
    {INPUT2_EFFECT_2_AMOUNT, "INPUT2_EFFECT_2_AMOUNT"},
    {INPUT2_EQ_ENABLE, "INPUT2_EQ_ENABLE"},
    {INPUT2_EQ_LOW_GAIN, "INPUT2_EQ_LOW_GAIN"},
    {INPUT2_EQ_MID_GAIN, "INPUT2_EQ_MID_GAIN"},
    {INPUT2_EQ_HIGH_GAIN, "INPUT2_EQ_HIGH_GAIN"},
    {INPUT2_COMPRESSOR_ENABLE, "INPUT2_COMPRESSOR_ENABLE"},
    {INPUT2_COMPRESSOR_AMOUNT, "INPUT2_COMPRESSOR_AMOUNT"},
    {INPUT2_EXT_FX_MUTE, "INPUT2_EXT_FX_MUTE"},
    {INPUT2_EXT_FX_SENDS, "INPUT2_EXT_FX_SENDS"},
    {INPUT3_GAIN, "INPUT3_GAIN"},
    {INPUT3_VOLUME, "INPUT3_VOLUME"},
    {INPUT3_MUTE, "INPUT3_MUTE"},
    {INPUT3_CLIP_OL_PRE, "INPUT3_CLIP_OL_PRE"},
    {INPUT3_CLIP_OL_POST, "INPUT3_CLIP_OL_POST"},
    {INPUT3_EFFECT_1_MUTE, "INPUT3_EFFECT_1_MUTE"},
    {INPUT3_EFFECT_1_AMOUNT, "INPUT3_EFFECT_1_AMOUNT"},
    {INPUT3_EFFECT_2_MUTE, "INPUT3_EFFECT_2_MUTE"},
    {INPUT3_EFFECT_2_AMOUNT, "INPUT3_EFFECT_2_AMOUNT"},
    {INPUT3_EQ_ENABLE, "INPUT3_EQ_ENABLE"},
    {INPUT3_EQ_LOW_GAIN, "INPUT3_EQ_LOW_GAIN"},
    {INPUT3_EQ_MID_GAIN, "INPUT3_EQ_MID_GAIN"},
    {INPUT3_EQ_HIGH_GAIN, "INPUT3_EQ_HIGH_GAIN"},
    {INPUT3_COMPRESSOR_ENABLE, "INPUT3_COMPRESSOR_ENABLE"},
    {INPUT3_COMPRESSOR_AMOUNT, "INPUT3_COMPRESSOR_AMOUNT"},
    {INPUT3_EXT_FX_MUTE, "INPUT3_EXT_FX_MUTE"},
    {INPUT3_EXT_FX_SENDS, "INPUT3_EXT_FX_SENDS"},
    {INPUT4_GAIN, "INPUT4_GAIN"},
    {INPUT4_VOLUME, "INPUT4_VOLUME"},
    {INPUT4_MUTE, "INPUT4_MUTE"},
    {INPUT4_CLIP_OL_PRE, "INPUT4_CLIP_OL_PRE"},
    {INPUT4_CLIP_OL_POST, "INPUT4_CLIP_OL_POST"},
    {INPUT4_EFFECT_1_MUTE, "INPUT4_EFFECT_1_MUTE"},
    {INPUT4_EFFECT_1_AMOUNT, "INPUT4_EFFECT_1_AMOUNT"},
    {INPUT4_EFFECT_2_MUTE, "INPUT4_EFFECT_2_MUTE"},
    {INPUT4_EFFECT_2_AMOUNT, "INPUT4_EFFECT_2_AMOUNT"},
    {INPUT4_EQ_ENABLE, "INPUT4_EQ_ENABLE"},
    {INPUT4_EQ_LOW_GAIN, "INPUT4_EQ_LOW_GAIN"},
    {INPUT4_EQ_MID_GAIN, "INPUT4_EQ_MID_GAIN"},
    {INPUT4_EQ_HIGH_GAIN, "INPUT4_EQ_HIGH_GAIN"},
    {INPUT4_COMPRESSOR_ENABLE, "INPUT4_COMPRESSOR_ENABLE"},
    {INPUT4_COMPRESSOR_AMOUNT, "INPUT4_COMPRESSOR_AMOUNT"},
    {INPUT4_EXT_FX_MUTE, "INPUT4_EXT_FX_MUTE"},
    {INPUT4_EXT_FX_SENDS, "INPUT4_EXT_FX_SENDS"},
    {STEREO_INPUT1_VOLUME, "STEREO_INPUT1_VOLUME"},
    {STEREO_INPUT1_MUTE, "STEREO_INPUT1_MUTE"},
    {STEREO_INPUT1_CLIP_OL_PRE, "STEREO_INPUT1_CLIP_OL_PRE"},
    {STEREO_INPUT1_CLIP_OL_POST, "STEREO_INPUT1_CLIP_OL_POST"},
    {STEREO_INPUT1_EQ_ENABLE, "STEREO_INPUT1_EQ_ENABLE"},
    {STEREO_INPUT1_EQ_LOW_GAIN, "STEREO_INPUT1_EQ_LOW_GAIN"},
    {STEREO_INPUT1_EQ_MID_GAIN, "STEREO_INPUT1_EQ_MID_GAIN"},
    {STEREO_INPUT1_EQ_HIGH_GAIN, "STEREO_INPUT1_EQ_HIGH_GAIN"},
    {EFFECT11_TYPEID, "EFFECT11_TYPEID"},
    {EFFECT12_TYPEID, "EFFECT12_TYPEID"},
    {EFFECT13_TYPEID, "EFFECT13_TYPEID"},
    {EFFECT14_TYPEID, "EFFECT14_TYPEID"},
    {EFFECT21_TYPEID, "EFFECT21_TYPEID"},
    {EFFECT22_TYPEID, "EFFECT22_TYPEID"},
    {MAIN_HEADPHONE_GAIN, "MAIN_HEADPHONE_GAIN"},
    {MAIN_MASTER_GAIN, "MAIN_MASTER_GAIN"},
    {MAIN_MUTE, "MAIN_MUTE"},
    {MAIN_CLIP_OL, "MAIN_CLIP_OL"},
    {LOOPER_LEVEL, "LOOPER_LEVEL"},
    {LOOPER_STATE, "LOOPER_STATE"},
    {FX_BYPASS, "FX_BYPASS"}
};

std::unordered_map<uint8_t, std::string> looper_state_to_string = {
    {RECORD_INITIAL_LOOP, "RECORD_INITIAL_LOOP"},
    {PLAY, "PLAY"},
    {STOP_PLAYING, "STOP_PLAYING"},
    {RECORD_OVERDUB, "RECORD_OVERDUB"},
    {DELETE, "DELETE"}
};

namespace master_gain {
    constexpr float POSITION_16 = 6.0;
    constexpr float POSITION_15 = 4.112315;
    constexpr float POSITION_14 = 2.084685;
    constexpr float POSITION_13 = -0.10532999;
    constexpr float POSITION_12 = -2.48601365;
    constexpr float POSITION_11 = -5.093745;
    constexpr float POSITION_10 = -7.97647;
    constexpr float POSITION_9 = -11.1990757;
    constexpr float POSITION_8 = -14.85257;
    constexpr float POSITION_7 = -19.0702229;
    constexpr float POSITION_6 = -24.0586376;
    constexpr float POSITION_5 = -30.1639671;
    constexpr float POSITION_4 = -38.0351067;
    constexpr float POSITION_3 = -49.12886;
    constexpr float POSITION_2 = -68.09374;
    constexpr float POSITION_1 = -120.0;
}

std::map<float, std::string> master_gain_to_string = {
    {master_gain::POSITION_16, "16/16"},
    {master_gain::POSITION_15, "15/16"},
    {master_gain::POSITION_14, "14/16"},
    {master_gain::POSITION_13, "13/16"},
    {master_gain::POSITION_12, "12/16"},
    {master_gain::POSITION_11, "11/16"},
    {master_gain::POSITION_10, "10/16"},
    {master_gain::POSITION_9, "9/16"},
    {master_gain::POSITION_8, "8/16"},
    {master_gain::POSITION_7, "7/16"},
    {master_gain::POSITION_6, "6/16"},
    {master_gain::POSITION_5, "5/16"},
    {master_gain::POSITION_4, "4/16"},
    {master_gain::POSITION_3, "3/16"},
    {master_gain::POSITION_2, "2/16"},
    {master_gain::POSITION_1, "1/16"},
};

#endif // DEBUG_H
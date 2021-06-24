#include "KeyboardListner.hpp"
#include "Suspender.hpp"

#include <iostream>

//uncomment to not play sounds
#define PlaySoundOnEvents

DWORD KeyboardListner::sleep_duration = 500;
int KeyboardListner::grace_period = 5;

void KeyboardListner::listen() {
    SHORT keys[162];

    /*
    left ctrl = 17
    left shift = 160
    letters follow ascii
    */

    int pattern_shift_p_o_a_s[] = { 160, 80, 79, 65, 83 };
    int pattern_shift_w_e_k_l[] = { 160, 87, 69, 75 };

    int counter = 0; //after a successful pause/resume do nothing for the next few loops so that you accidentally dont toggle anything on again.

    while (true) {
        Sleep(sleep_duration);

        if (counter > 0) {
            counter--;
            std::cout << "grace period running\n";
            continue;
        }

        for (int i = 17; i < 162; i++) {
            keys[i] = GetKeyState(i);
            // lowest usable key 17 and highest is 162
        }

        if (check_pattern(keys, pattern_shift_p_o_a_s, sizeof(pattern_shift_p_o_a_s) / sizeof(pattern_shift_p_o_a_s[0]))) {
            std::cout << "key pattern matched lets goooo\n";
            #ifdef PlaySoundOnEvents
                PlaySoundA((LPCSTR)"C:\\Windows\\Media\\Windows Notify.wav", NULL, SND_FILENAME | SND_ASYNC);
            #endif // PlaySoundOnEvents
            Suspender::toggle();
            counter = grace_period;
        }

        if (check_pattern(keys, pattern_shift_w_e_k_l, sizeof(pattern_shift_w_e_k_l) / sizeof(pattern_shift_w_e_k_l[0]))) {
            std::cout << "closing program\n";
            #ifdef PlaySoundOnEvents
                PlaySoundA((LPCSTR)"C:\\Windows\\Media\\Speech Off.wav", NULL, SND_FILENAME | SND_ASYNC);
                Sleep(1000); //so we can hear the sound
            #endif // PlaySoundOnEvents
            break;
        }

        //display_keys(keys);
    }
}

bool KeyboardListner::check_pattern(SHORT *keys, int *pattern, int pattern_size) {
    bool success = true;
    for (int i = 0; i < pattern_size; i++) {
        if (keys[pattern[i]] < 0) {

        }
        else {
            return false;
        }
    }
    return success;
}

void KeyboardListner::display_keys(SHORT *keys) {
    for (int i = 17; i < 162; i++) {
        if (keys[i] < 0) {
            std::cout << "O" << "\n" << i << "\n";
        }
        else {
            std::cout << "#";
        }
    }
    std::cout << std::endl;
}
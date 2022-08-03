#ifndef CLFW_ARDUINODIY_H
#define CLFW_ARDUINODIY_H

#include "../Classes/Pinout.h"

class CLFWController {
public:
    CLFWController() {
        original_Pinout.up           =   8;
        original_Pinout.down         =   A1;
        original_Pinout.left         =   A2;
        original_Pinout.right        =   A3;
        original_Pinout.modX         =   A4;
        original_Pinout.modY         =   A5;
        original_Pinout.start        =   2;
        original_Pinout.select       =   255;
        original_Pinout.home         =   255;
        original_Pinout.a            =   11;
        original_Pinout.b            =   1;
        original_Pinout.x            =   3;
        original_Pinout.y            =   255;
        original_Pinout.l1           =   255;
        original_Pinout.r1           =   4; // GCC Z button
        original_Pinout.l2           =   13; // GCC L button
        original_Pinout.r2           =   0; // GCC R button
        original_Pinout.lightshield  =   5;
        original_Pinout.midshield    =   7;
        original_Pinout.cUp          =   9;
        original_Pinout.cDown        =   12;
        original_Pinout.cLeft        =   10;
        original_Pinout.cRight       =   6;

        multiplexer  = 255;
        consoleData  = 255;

        current_Pinout   = original_Pinout;

        defaultMUX = false;

        #if defined(HAS_USB)
            hasUSB = true;
        #else
            hasUSB = false;
        #endif
    }

    pinout current_Pinout;
    pinout original_Pinout;

    int multiplexer;
    int consoleData;

    pinout current_Keymap;

    bool defaultMUX;
    bool hasUSB;
};

#endif

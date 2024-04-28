/***********************************************************
FILE:       AS5611.cpp
VERSION:    0.0.1
PURPOSE:    7-Segment Display for Arduino

DATASHEET: http://www.electronicoscaldas.com/datasheet/GNS-5611-Series_G-NOR.pdf

***********************************************************/


#include "AS5611.h"

void segment::init(int* setup) {
    for (int i = 0; i < 8; i++) {
        ports[i] = setup[i];
    }
}

void segment::clearAll() {
    for (int i = 0; i < 8; i++) {
        pinMode(ports[i], OUTPUT);
        digitalWrite(ports[i], LOW);
    }

    turnOffDot();
}

void segment::setNum(int num) {
    int patterns[10][8] = {
        {1,1,1,1,1,1,0,0},
        {0,1,1,0,0,0,0,0},
        {1,1,0,1,1,0,1,0},
        {1,1,1,1,0,0,1,0},
        {0,1,1,0,0,1,1,0},
        {1,0,1,1,0,1,1,0},
        {1,0,1,1,1,1,1,0},
        {1,1,1,0,0,0,0,0},
        {1,1,1,1,1,1,1,0},
        {1,1,1,1,0,1,1,0}
    };

    for (int i = 0; i < 8; i++) {
        pinMode(ports[i], OUTPUT);
        if (patterns[num][i]==1) {
            digitalWrite(ports[i], HIGH);
        }
        else {
            digitalWrite(ports[i], LOW);
        }
    }
}


void segment::turnOnDot() {
    pinMode(ports[7], OUTPUT);
    digitalWrite(ports[7], HIGH);
}

void segment::turnOffDot() {
    pinMode(ports[7], OUTPUT);
    digitalWrite(ports[7], LOW);
}

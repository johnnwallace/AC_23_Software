#include <Arduino.h>
#include "states.h"

enum FlightState state;

void setup() {
    // put your setup code here, to run once:
    state = IDLE1;
}

void loop() {
    // put your main code here, to run repeatedly:
    enum FlightState state = IDLE1;

    switch (state) {
        case IDLE1:
            break;
        case CALIB:
            break;
        case COUNT:
            break;
        case POWER:
            break;
        case UNPWR:
            break;
        case DESC:
            break;
        case LAND:
            break;
        case IDLE2:
            break;
    }

}
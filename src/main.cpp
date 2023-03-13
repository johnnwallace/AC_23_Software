#include <Arduino.h>
#include "states.h"

enum FlightState state;

void setup() {
    // put your setup code here, to run once:
    state = PRELAUNCH;
}

void loop() {
    // put your main code here, to run repeatedly:
    enum FlightState state = PRELAUNCH;

    switch (state) {
        case PRELAUNCH:
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
        case POSTFLIGHT:
            break;
    }

}
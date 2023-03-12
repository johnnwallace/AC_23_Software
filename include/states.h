#include <Arduino.h>
#include <ClickButton.h>
#include <Orientation.h>

#include "pid.h"

enum FlightState {
    PRELAUNCH,  // pre-launch idle
    CALIB,  // calibration
    COUNT,  // countdown
    POWER,  // powered flight
    UNPWR,  // unpowered flight
    DESC,   // descent
    LAND,   // landed
    POSTFLIGHT   // post-flight idle
};

/*
------------------------------------------------------------------------
Pre-Launch Idle:
------------------------------------------------------------------------
- Servos unpowered
- No sensing
- Transition with button
*/
enum FlightState handlePreLaunchState();

/*
------------------------------------------------------------------------
Calibration:
------------------------------------------------------------------------
- Servos sent tp zero position
- Button adjusts servo position, position stored on transition
- No sensing
- Transition with button
*/
enum FlightState handleCalibState();

/*
------------------------------------------------------------------------
Countdown:
------------------------------------------------------------------------
- Determine orientation with accelerometers; no other sensing
- Servos unpowered
- Indicate countdown with buzzer
*/
enum FlightState handleCountState();

/*
------------------------------------------------------------------------
Powered Flight:
------------------------------------------------------------------------
- Servos powered
- Full sensing and logging to flash chip
- Servos controlled by PID control loop
- Transition on negative vertical acceleration
*/
enum FlightState handlePowerState();

/*
------------------------------------------------------------------------
Unpowered Flight:
------------------------------------------------------------------------
- Servos unpowered
- Full sensing (for data collection) and logging to flash chip
- Transition on negative vertical velocity
*/
enum FlightState handleUnpwrState();

/*
------------------------------------------------------------------------
Descent:
------------------------------------------------------------------------
- Servos unpowered
- Full sensing and logging to flash chip
- Transition on zero vertical velocity
*/
enum FlightState handleDescState();

/*
------------------------------------------------------------------------
Landed:
------------------------------------------------------------------------
- Servos unpowered
- No sensing
- Tranfer all flight data from flash chip to SD card
- Transition on completion of data transfer
*/
enum FlightState handleLandState();

/*
------------------------------------------------------------------------
Post-Flight Idle:
------------------------------------------------------------------------
- Servos unpowered
- No sensing
- Periodically buzz to aid locating the rocket after launch
*/
enum FlightState handlePostFlightState();
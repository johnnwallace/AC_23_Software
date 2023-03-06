#pragma once

class PID{
    float gains[4];
    float limit[2];
    float setpoint;

    float error;
    float lastError;
    float cumulativeError;
    float derivativeError;
    float saturationError;

    float setpoint;
    float command;

public:

    void update(float value, float dt);
    float getCommand();
    PID(float setpoint, float p, float i, float d, float s);
};
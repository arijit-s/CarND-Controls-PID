#include "PID.h"
#include<iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
    Kp = Kp_in;
    Ki = Ki_in;
    Kd = Kd_in;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;

    prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
    p_error = cte;
    
    d_error = cte - prev_cte;
    i_error = i_error + cte;

    prev_cte = cte;
}

double PID::TotalError() {
    double steer = -Kp*p_error - Kd*d_error - Ki*i_error;
    return steer;
}


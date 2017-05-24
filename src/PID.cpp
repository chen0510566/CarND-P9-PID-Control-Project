#include "PID.h"

using namespace std;

PID::PID()
{
}

PID::~PID()
{
}

/**@brief initialize the pid controller;
 *
 * initialize the pid controller;
 * 1. set parameters kp, ki, kd;
 * 2. set error to 0.0;
 * @param Kp [IN]: the kp;
 * @param Ki [IN]: the ki;
 * @param Kd [IN]: the kd;
 */
void PID::Init(const double Kp, const double Ki, const double Kd)
{
    Kp_ = Kp;
    Ki_ = Ki;
    Kd_ = Kd;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
}

/**@brief set parameters for the pid controller;
 *
 * set parameters for the pid controller;
 * @param Kp [IN]: the kp;
 * @param Ki [IN]: the ki;
 * @param Kd [IN]: the kd;
 */
void PID::SetParms(const double Kp, const double Ki, const double Kd)
{
    Kp_ = Kp;
    Ki_ = Ki;
    Kd_ = Kd;
}

void PID::UpdateError(const double error)
{
    d_error = error - p_error;
    p_error = error;
    i_error += error;
}

double PID::TotalError()
{
    return -(Kp_ * p_error + Ki_ * i_error + Kd_ * d_error);
}


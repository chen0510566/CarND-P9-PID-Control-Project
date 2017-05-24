#ifndef PID_H
#define PID_H

class PID
{
public:
    /*
    * Errors
    */
    double p_error;

    double i_error;

    double d_error;

    /*
    * Coefficients
    */
    double Kp_;

    double Ki_;

    double Kd_;

    PID();

    virtual ~PID();

    void Init(double Kp, double Ki, double Kd);

    void SetParms(const double Kp, const double Ki, const double Kd);

    void UpdateError(double cte);

    double TotalError();
};

#endif /* PID_H */

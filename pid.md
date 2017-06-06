# PID Controller
## P - Proportional Controller
The P controller outputs control signal proportional to the error. A larger P coefficient makes the controller response faster to error. However, if the P coefficient is too large, the controller maybe unstable.

## I - Integral Controller
The I controller is proportional to the integral error. It is mainly used to eliminate steady state error.

## D -Derivative Controller
The D coefficient is responsible for the future change of the error. It could be used to avoid oscillation of the car.
## Hyper-parameters
Both steer controller and speed controller are implemented in the project. The hyper-parameters of these two pid controllers are manually tuned.
### Steer Controller
For steer controller, the P, I, D coefficients are set to 0.2, 0.0, 2.5 when the cross track error is larger than 2.0. If the cross tracker error is less than 2.0, the coefficients are set to 0.05, 0.0, 2.5. That is, the P coefficient are set to a larger value to enable fast response to deviation from the track if the cross track error is larger than 2.0. The D coefficient is set to avoid oscillation around the center line. Besides, the D coefficient makes the vehicle response faster to deviation. As the shape of the track is always changing, the distance to the center line is also changing. That is, there is no need to eliminate the non-existent steady state error. The I coefficient is set to 0.0.
### Speed Controller
Firstly, the desired speed is set according to the cross track error. That is, the minimum desired speed is set to 30. If the cross track error is larger than 1.0, the desired speed is set to 30. If the cross track error is less than 1.0, the desired speed is set to inverse proportional to the cross track error. Just like the human driver, if the cross track error is large, slow down the vehicle; if the error is small, speed up the vehicle. The parameters for slow down the vehicle is set to 1.0, 0.0, 0.2, the parameters for speed up the vehicle is set to 5.0, 0.0, 0.2. The controller favors in a fast slow down to pass turns in the track. The D coefficient does not have too much effect during the simulation. The parameter 0.2 is just ok for the vehicle to finish the track.

The final video of the controllers are pid.mp4.
#ifndef _MOTOR_H
#define _MOTOR_H


class Motor {
 public:
  Motor(unsigned char _port);
  ~Motor(void);

  void forward(void);
  void backward(void);
  void reverseDirection(void);

  void stop(void);
  void flt(void);

  int getTachoCount(void);
  void resetTachoCount(void);

  void setPower(int _power);

  /*

  These methods are for later development... the goal is to create the same
  API as in LEJOS.

  //  void setSmoothAcceleration(bool _smooth);

  //  void rotate(int angle,bool immRet=false);

  //  void setRegulated(bool _regulate);

  //  void setSpeed(int _speed);
  int getActualSpeed(void);
  int getLimitAngle(void);
  int getMode(void);
  int getPower(void);
  int getSpeed(void);
  int getStopAngle(void);
  bool isMoving(void);
  bool isRegulating(void);
  bool isRotating(void);
  void rotateTo(int angle,bool immRet=false);
  
  */

 private:
  unsigned char port;
  bool activated,isForward;
  int powerPercent;

};

#endif

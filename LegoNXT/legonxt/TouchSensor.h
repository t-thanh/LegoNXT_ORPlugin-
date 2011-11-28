

#ifndef _TOUCH_SENSOR_H
#define _TOUCH_SENSOR_H

class TouchSensor {
 public:
   TouchSensor(unsigned char _port);
  ~TouchSensor(void);

  bool isPressed(void);

  short int getRawValue(void);

 private:
  unsigned char port;
};

#endif

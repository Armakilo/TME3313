#ifndef CAT_H
#define CAT_H


enum class Button{
  Enter,
  Left,
  Right,
  None,
  Back
};

enum class State{
  Start,
  Play,
  Settings,
  SpdSet,
  NoiseSet,
  PatternSet, //might have to get rid of this, complicated
  MoCapSet, 
  CalibMen,
  CalibL,
  CalibR,
  CalibC,
};

#define LEFT_BTN 13
#define CENT_BTN 12
#define RIGHT_BTN 11
#define BACK_BTN 10


#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <string.h>

extern LiquidCrystal_I2C lcd;
extern Servo myservo;


uint8_t checkInput();
void Servo_move(unsigned int Position_angle);
void lcdwrite(const char* message);
uint8_t delay_in(uint32_t ms);

//not using class becuase stuff gets messed up when using function pointers
Button Startf();
Button Playf();
Button Settingsf();
Button SpdSetf();
Button NoiseSetf();
Button PatternSetf();
Button MoCapSetf();
Button CalibMenf();
Button CalibLf();
Button CalibRf();
Button CalibCf();


#endif
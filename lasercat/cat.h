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

#define PIN_Servo_z 9 //might be wrong
#define PIN_Servo_x 8 //might be wrong


#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <string.h>
#include "Arduino.h"

extern LiquidCrystal_I2C lcd;
extern Servo myservo;
extern State currentState;


Button checkInput();
void Servo_move(unsigned int Position_angle);
void lcdwrite(const char* message, const char* header = "CatSeeking Laser");
Button delay_in(uint32_t ms);
Button menuoptions(const char * menuName, const char * optionName, uint8_t quality);
Button wait_until();
void executeSM(void);

//not using class becuase stuff gets messed up when using function pointers
Button Startf(); //should probably add void to the params instead.
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
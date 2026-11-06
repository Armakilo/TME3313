#ifndef CAT_H
#define CAT_H


enum direction{

  enter,
  left,
  right,
  none,
  back
};

#define LEFT_BTN 13
#define CENT_BTN 12
#define RIGHT_BTN 11
#define BACK_BTN 10


#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <string.h>

extern LiquidCrystal_I2C lcd; //addr, w, h
extern Servo myservo;

uint8_t checkInput();
void Servo_move(unsigned int Position_angle);
void lcdwrite(const char* message);
uint8_t delay_in(uint32_t ms);
void StartMenu();
void Play();
void CalArea();
void Settings();


// class State{

//   public:
//     void StartMenu(); //Starting position
//     void Settings(); //Speed & noise control. Patterns and 
//     void CalArea(); 
//     void Play();

// };

#endif
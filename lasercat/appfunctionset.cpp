#include "cat.h"
#include "Arduino.h"

#define PIN_Servo_z 9
#define PIN_Servo_y //fix these


//globals that settings will change

enum class calibration{
  leftside,
  rightside,
  centside,
}

enum class Button{
  Left,
  Right
};

enum class Mpos{
  leftmenu,
  rightmenu,
  centmenu

  
};


map<pair<Mpos, Button>, state> stateTrans = {
  {{Mpos::leftmenu,Button::Left},Mpos::leftmenu}
  {{Mpos::leftmenu,Button::right},Mpos::centmenu}
  {{Mpos::centmenu,Button::Left},Mpos::leftmenu}
  {{Mpos::centmenu,Button::right},Mpos::rightmenu}
  {{Mpos::rightmenu,Button::Left},Mpos::centmenu}
  {{Mpos::rightmenu,Button::Right},Mpos::rightmenu}
  
};


class CalibMenu{
  public:

    init(){
      currentPg = centmenu;
    }
    void press(Button action){
      currentPg = stateTrans[{currentPg, action}];

    }

  private:
    Mpos currentPg
}


uint32_t speed = 10;
bool noise = false;
bool mocap = false;

calibration a = calibration::centside; //calibration starts at the center




void StartMenu(){
  lcdwrite("> Start Play?");
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);

  void (*funcArr[])(void) = {Play, CalArea, Settings}; //enter, left, right
  if(c_in != back){
    funcArr[c_in]();
  }

  
  

}

void Settings(){
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);

  void (*funcArr[])(void) = {Play, CalArea, Settings}; //enter, left, right
  if(c_in != back){
    funcArr[c_in]();
  }

}

void CalMenu(){ //calibration menu dialogue

  Calibrate Pos.

}

void Cal_Center(){

}

void Cal_Left(){

}

void Cal_Right(){

}

void Play(){
  lcdwrite("> Playing")
  uint32_t timestart = millis();
  uint8_t c_in
  while((c_in == none) && (millis() - timestart < 200000)){ //timeout is at a 3rd of a minute
    c_in = delay_in(100); //checking for user input

    //servo commands based on current selected calibration and settings
    //TODO write servo running function

  } 

  StartMenu()

  //servo routine in here


  }
  
}
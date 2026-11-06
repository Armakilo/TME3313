#include "cat.h"
#include "Arduino.h"

#define PIN_Servo_z 9
#define PIN_Servo_y //fix these


//globals that settings will change


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


//MAKE SURE funcArr AND State ARE IN THE SAME ORDER!!!!

void (*funcArr[])(){
  Startf(),
  Playf(),
  Settingsf(),
  SpdSetf(),
  NoiseSetf(),
  PatternSetf(),
  MoCapSetf(),
  CalibMenf(),
  CalibLf(),
  CalibRf(),
  CalibCf()
}


struct Transition {State from; Button event; State to};

static const Transition table[] = {
  {State::CalibMen, Button::Enter, State::CalibC},
  {State::CalibC, Button::Left, State::CalibL},
  {State::CalibC, Button::Right, State::CalibR},
  {State::CalibL, Button::Left, State::CalibR},
  {State::CalibL, Button::Right, State::CalibL},
  {State::rightmenu, Button::Right, State::leftmenu}
};

static const uint8_t trows = sizeof(table)/sizeof(table[0]); //evaluated at compile time

// State next(State now, Button btn){
//   for(uint8_t i = 0; i < trows; ++i)
//     if(table[i].from == now && table[i].ev == btn) return table[i].to;
//   return now;
// }


Transition const * table_begin(void)
{
    return &table[0];
}


Transition const * table_end(void)
{
    return &table[trows];
} 

static void exec_pg(State now){

  switch(now)
}

void executeSM(void){
  uint32_t currentState = 0;
    Button action = checkInput();
    Transition const * p_entry = table_begin();
    Transition const * p_end = table_end();
    bool statefound = false;
    while((!statefound) && p_entry != p_end)){
      if((p_entry->from == current_state) && (p_entry->event == transition_letter)){
        current_state = p_entry->to;
        state_found = true;
        break;
      }
      ++p_entry; //look for next state
    }
    if(!state_found){
      
      Serial.prinln("state not changed");

    else{
      funcArr[current_state]();
    }
  }
  
}



uint32_t speed = 10;
bool noise = false;
bool mocap = false;





void Startf(){
  lcdwrite("> Start Play?");
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);

  void (*funcArr[])(void) = {Play, CalArea, Settings}; //enter, left, right
  if(c_in != back){
    funcArr[c_in]();
  }

  
void Playf(){
  lcdwrite("> Playing")
  uint32_t timestart = millis();
  uint8_t c_in
  while((c_in == none) && (millis() - timestart < 300000)){ //timeout is at 30s
    c_in = delay_in(100); //checking for user input

    //servo commands based on current selected calibration and settings
    //TODO write servo running function

  } 

}

void Settingsf(){
  uint8_t c_in
  while(c_in == none) c_in = delay_in(5000);

  void (*funcArr[])(void) = {Play, CalArea, Settings}; //enter, left, right
  if(c_in != back){
    funcArr[c_in]();
  }

}


void SpdSetf(){

}

void NoiseSetf(){

}

void PatternSetf(){

}

void MoCapSetf(){

}

void CalibMenf(){

}

void CalibLf(){

}

void CalibRf(){

}

void CalibCf(){

}


#include "cat.h"


//MAKE SURE funcArr AND State (cat.h) ARE IN THE SAME ORDER!!!!

Button (*funcArr[])() = {
  Startf,
  Playf,
  Settingsf,
  SpdSetf,
  NoiseSetf,
  PatternSetf,
  MoCapSetf,
  CalibMenf,
  CalibLf,
  CalibRf,
  CalibCf // no parentases needed!
};

struct Transition { State from; Button event; State to;};


static const Transition table[] = { //used ai for the table, you would not catch me filling this out manually.
  // --- Start (Top Level) ---
  {State::Start,      Button::Enter, State::Play},
  {State::Start,      Button::Left,  State::CalibMen},
  {State::Start,      Button::Right, State::Settings},
  // NO Back key for Start

  // --- Play ---
  {State::Play,       Button::Enter, State::Start},
  {State::Play,       Button::Left,  State::Start}, 
  {State::Play,       Button::Right, State::Start}, 
  {State::Play,       Button::Back,  State::Start}, 

  // --- Settings (Top Level) ---
  {State::Settings,   Button::Enter, State::SpdSet},
  {State::Settings,   Button::Left,  State::Start},
  {State::Settings,   Button::Right, State::CalibMen},
  // NO Back key for Settings

  // --- Calibration Menu (Top Level) ---
  {State::CalibMen,   Button::Enter, State::CalibC},
  {State::CalibMen,   Button::Left,  State::Settings},
  {State::CalibMen,   Button::Right, State::CalibL},
  // NO Back key for CalibMen

  // --- Calibration Carousel (Sub-menus) ---
  {State::CalibC,     Button::Left,  State::CalibL},
  {State::CalibC,     Button::Right, State::CalibR},
  {State::CalibC,     Button::Back,  State::CalibMen},   

  {State::CalibL,     Button::Left,  State::CalibR},     // Carousel wrap
  {State::CalibL,     Button::Right, State::CalibC},     
  {State::CalibL,     Button::Back,  State::CalibMen},

  {State::CalibR,     Button::Left,  State::CalibC},
  {State::CalibR,     Button::Right, State::CalibL},     // Carousel wrap
  {State::CalibR,     Button::Back,  State::CalibMen},

  // --- Settings Carousel (Sub-menus) ---
  {State::SpdSet,     Button::Left,  State::MoCapSet},   // Carousel wrap
  {State::SpdSet,     Button::Right, State::NoiseSet},
  {State::SpdSet,     Button::Back,  State::Settings},   

  {State::NoiseSet,   Button::Left,  State::SpdSet},
  {State::NoiseSet,   Button::Right, State::PatternSet}, 
  {State::NoiseSet,   Button::Back,  State::Settings},

  {State::PatternSet, Button::Left,  State::NoiseSet},
  {State::PatternSet, Button::Right, State::MoCapSet},
  {State::PatternSet, Button::Back,  State::Settings},

  {State::MoCapSet,   Button::Left,  State::PatternSet},
  {State::MoCapSet,   Button::Right, State::SpdSet},     // Carousel wrap
  {State::MoCapSet,   Button::Back,  State::Settings},
};



//SM definitions and init
static const uint8_t trows = sizeof(table)/sizeof(table[0]); //evaluated at compile time
State currentState = State::Start;


State next(State now, Button btn){
  for(uint8_t i = 0; i < trows; ++i)
    if(table[i].from == now && table[i].event == btn) return table[i].to;
  return now;
}


void executeSM(void){
    
    Button b = funcArr[(uint8_t)currentState]();
    currentState = next(currentState, b);
  
}
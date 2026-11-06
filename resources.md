# Resources that are useful for project

https://www.geeksforgeeks.org/electronics-engineering/how-to-interface-i2c-lcd-display-with-arduino/

https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/

https://arduinogetstarted.com/tutorials/arduino-motion-sensor


https://stackoverflow.com/questions/14676709/c-code-for-state-machine

Code blocks (might be useful later):

void executeSM(void){
  uint32_t currentState = 0;
    Button action = checkInput();
    Transition const * p_entry = table_begin();
    Transition const * p_end = table_end();
    bool statefound = false;
    while((!statefound) && p_entry != p_end)){
      if((p_entry->from == current_state) && (p_entry->event == action)){
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

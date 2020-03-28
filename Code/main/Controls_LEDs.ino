//Input and LEDS

//Gets input from buttons
int8_t getInput6Button(){
  int8_t output = 0;
  //Check buttons
  if (digitalRead(BUTTON1_PIN)==HIGH){
    output = output|INPUTMASK_BUTTON1;
  }
  if (digitalRead(BUTTON2_PIN)==HIGH){
    output = output|INPUTMASK_BUTTON2;
  }
  if (digitalRead(UP_PIN)==HIGH){
    output = output|INPUTMASK_UP;
  }
  if (digitalRead(DOWN_PIN)==HIGH){
    output = output|INPUTMASK_DOWN;
  }
  if (digitalRead(LEFT_PIN)==HIGH){
    output = output|INPUTMASK_LEFT;
  }
  if (digitalRead(RIGHT_PIN)==HIGH){
    output = output|INPUTMASK_RIGHT;
  }
  return output;
}

//Gets input from buttons + joystick
/*
int8_t getInputJoystick(){
  int8_t output = 0;
  //Check buttons
  if (digitalRead(BUTTON1_PIN)==HIGH){
    output = output|INPUTMASK_BUTTON1;
  }
  if (digitalRead(BUTTON2_PIN)==HIGH){
    output = output|INPUTMASK_BUTTON2;
  }
  //Check joystick
  int16_t axis = analogRead(UD_PIN);
  if (axis < DEADZONE_LO){
    output = output|INPUTMASK_DOWN;
  } else if (axis > DEADZONE_HI) {
    output = output|INPUTMASK_UP;
  }
  axis = analogRead(LR_PIN);
  if (axis < DEADZONE_LO){
    output = output|INPUTMASK_LEFT;
  } else if (axis > DEADZONE_HI) {
    output = output|INPUTMASK_RIGHT;
  }
  return output;
}
*/

//Menus

//Handles drawing menu and getting inputs to make selection
//TODO: Make into task, so does not block GPS or NRF24
int8_t menu(char menuARR[], int8_t arrSize, int8_t textLength, int8_t prev) {
  bool updateScreen = false;
  bool selection = false;
  int8_t currSelection = prev;
  //Get input and handle
  int8_t input = getInput6Button();
  while(input == 0){input = getInput6Button();} //Waits for input before  advancing
  if (input & INPUTMASK_UP){
    currSelection--;
    updateScreen = true;
    if (selection < 0){
      currSelection = 0;
    }
  }
  if (input & INPUTMASK_DOWN){
    currSelection++;
    updateScreen = true;
    if (selection > (arrSize)){
      currSelection = (arrSize);
    }
  }
  if (input & INPUTMASK_BUTTON1||input & INPUTMASK_RIGHT){
    return currSelection;
  }
  if (input & INPUTMASK_BUTTON2||input & INPUTMASK_LEFT){
    return -1;
  }
  char title[textLength] = {currSelection*textLength};
  bool up = true;
  bool down = true;
  if (currSelection == 0){
    up = false;
  }
  if (currSelection == arrSize){
    down = false;
  }
  if (updateScreen){
    drawMenuScreen(title, up, down);
  }
}

//Used to set a boolean value
bool setBool(char item, bool setting){
  bool updateScreen = false;
  bool selection = setting;
  //Get input and handle
  int8_t input = getInput6Button();
  while(input == 0){input = getInput6Button();}
  if (input & INPUTMASK_UP){
    selection = false;
    updateScreen = true;
  }
  if (input & INPUTMASK_DOWN){
    selection = true;
    updateScreen = true;
  }
  if (input & INPUTMASK_BUTTON1||input & INPUTMASK_RIGHT){
    return selection; //Returns new value
  }
  if (input & INPUTMASK_BUTTON2||input & INPUTMASK_LEFT){
    return setting; //Returns previous value
  }
  //drawOption();
}

void mainMenu(int8_t prevSelection){
  char mainmenu = "P-2-P     "
                  "DRAG RACE "
                  "OPTIONS   ";
  int8_t output = menu(mainmenu,3,10,prevSelection);
  switch(output){
    case -1: //Reset menu
      output = menu(mainmenu,3,10,prevSelection);
      break;
    case 0:
      //go to point-to-point submenu
      break;
    case 1:
      //go to drag race submenu
      break;
    case 2:
      //go to options submenu
      break;
  }
}

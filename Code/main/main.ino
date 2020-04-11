/* Race.Net main 
 *  Ver: 0.0.0
 *  Author: Jeremy Stintzcum
 *  Date Modified: 4/11/20
*/

//Screen
#include "SSD1306Spi.h"
#define OLED_DC    2
#define OLED_CS    4
#define OLED_RESET 5
SSD1306Spi display(OLED_RESET, OLED_DC, OLED_CS);

//Inputs
#include "Button.h"
#define BUTTON1 0
#define BUTTON2 1
#define BUP 2
#define BDOWN 3
#define BLEFT 4
#define BRIGHT 5
Button button1(13,PULLUP);
Button button2(12,PULLUP);
//Button up/down/left/right
Button buttonUp(14,PULLUP);
Button buttonDown(27,PULLUP);
Button buttonLeft(26,PULLUP);
Button buttonRight(32,PULLUP);
//For Joystick up/down/left/right
//#define UD_PIN A0
//#define LR_PIN A1
//#define DEADZONE_HI 768
//#define DEADZONE_LO 256

//LEDs - common cathode, when pin set HIGH, led is OFF
#define LED_PIN_RED 9
#define LED_PIN_GRN 10
#define LED_PIN_BLU 11

// definitions
struct MenuItem {
  String title;
  String subtitle;
  void (*funcPtr)(String);
};

class Menu {
public:
  MenuItem *arr;
  Menu *prevMenu;
public:
  Menu(int8_t arrLen, String *titleArr, String *subArr, void (*ptr[])(String)){
    arr = new MenuItem[arrLen];
    for (int8_t i=0;i<arrLen;i++){
      arr[i].title = titleArr[i];
      arr[i].subtitle = subArr[i];
      arr[i].funcPtr = ptr[i];
    }
  }
  ~Menu(){
    delete[] arr;
  }
  void setParentMenu(){} //Used to return to a previous menu
  int8_t runMenu(){} //does what "notmenu" does.
};


//TEST CODE
void test(String blast){
  Serial.println(blast);
}
const int8_t mainArrLen = 3;
String arr1[3] = {"1","2","3"};
String arr2[3] = {"4","5","6"};
void (*ptr[3])(String) = {test,test,test};//CANNOT BE UNINITIALIZED
Menu m(mainArrLen,arr1,arr2,ptr);
//END TEST CODE

void setup() {
  Serial.begin(115200);
  if(!display.init()) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setContrast(255);
}

void loop() {
  //mainArr[0].runFunc();
  
  //drawMenuScreen("HELP",true,true);
  //menu(0,mainArr,mainArrLen);
  /*
  //Base state machine
  switch(state){
    case MENU:
      //try to grab NRF24 packets
      //If packet received, interpret and interupt menu if needed
      mainMenu(0); //Run menu command
      break;
  }*/
}

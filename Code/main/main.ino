/* Race.Net main 
 *  Ver: 0.0.0
 *  Author: Jeremy Stintzcum
 *  Date Modified: 3/27/20
*/

//Included default libraries
#include <SPI.h>
#include <Wire.h>

//External libraries
//Screen
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Defines
//Screen
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

//Display
#define TEXT_V_SMALL 8
#define TEXT_H_SMALL 21
#define TEXT_V_LARGE 16
#define TEXT_H_LARGE 10

//Inputs
#define INPUTMASK_BUTTON1 0x01
#define INPUTMASK_BUTTON2 0x02
#define INPUTMASK_UP      0x04
#define INPUTMASK_DOWN    0x08
#define INPUTMASK_LEFT    0x10
#define INPUTMASK_RIGHT   0x20
#define BUTTON1_PIN 3
#define BUTTON2_PIN 4
//Button up/down/left/right
#define UP_PIN 5
#define DOWN_PIN 6
#define LEFT_PIN 7
#define RIGHT_PIN 8
//For Joystick up/down/left/right
//#define UD_PIN A0
//#define LR_PIN A1
//#define DEADZONE_HI 768
//#define DEADZONE_LO 256

//State
#define MENU 0

//Initialization
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

//Globals
//Main
int8_t state = 0;
      
void setup() {
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC)) { // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
}

void loop() {
  //Base state machine
  switch(state){
    case MENU:
      //try to grab NRF24 packets
      //If packet received, interpret and interupt menu if needed
      mainMenu(0); //Run menu command
      break;
  }
}

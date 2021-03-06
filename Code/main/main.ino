/* Race.Net main 
 *  Ver: 0.0.0
 *  Author: Jeremy Stintzcum
 *  Date Modified: 5/16/20
*/

//Screen
#include "SSD1306Spi.h"
#include "bitmaps.h"
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

//Menu
#define BACK -1
#define SELECT -2

//Device-device communication
#include <esp_now.h>
#include <WiFi.h>
#define MAXPEERS 20 //Max number of participants
#define MAXRETRIES 10
#define CHANNEL 1 //TODO: Randomize channel? is there a reason ot pick one channel and stick with it?
#define MAXMSGSIZE 240 //Hard cap is 250 bytes, including other data
int totalPeers = 0;

//Race
#define MAXCHKCNT 20 //Max number of checkpoints that can be set in a race
#define RACE 1
#define DRIVER 2
#define CHKPNT 3
#define SCORE 4
#define SCOREBRD 5

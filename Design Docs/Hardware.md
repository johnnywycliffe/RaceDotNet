# Hardware
This file describes the hardware implementation, lists items used, pinouts, etc.

## Basic Functionality:
- Microcontroller (Inlcudes WiFi antenna)
- GPS: For positioning car
- Screen: For data display
- Control surface (Joystick + two buttons)

## Considered Addons:
- Walkie talkie mode: Microphone and either speaker or bluetooth
- RGB LEDs: For extra indication, primarily for Drag mode
- Accelerometer: For more precise data regarding launches, primarily for Drag mode 
- SD card reader: For storing times, scores, tracks, etc
- Touch screen: Replaces other screen, SD card slot, Joystick and buttons

## Parts list:
Prices of parts are rounded to the next highest US Dollar value, as of 2020-3-17

| Item | Cost per purchase | Purchase quantity | Price per unit |
| ---- | ----------------- | ----------------- | -------------- |
| [ESP32-WROOM-32](https://www.aliexpress.com/item/32864722159.html?aff_platform=product&sk=_dXcHSHv&aff_trace_key=7483e63b98614a10837beee0eaa4dcfa-1584414951423-06960-_dXcHSHv&tmLog=new_Detail_6220&terminal_id=07967cbaec35489d9be0da10ac681656&aff_request_id=7483e63b98614a10837beee0eaa4dcfa-1584414951423-06960-_dXcHSHv) | $4 | 1 | $4 |
| [Beitian BN-180 GPS Module](https://www.amazon.com/gp/product/B078Y4XZN9/ref=ox_sc_act_title_7?smid=A1GUQD3SRXOFFI&psc=1) | $15 | 1 | $15 |
| [3.3v Regulator](https://www.amazon.com/gp/product/B07CP4P5XJ/ref=ox_sc_act_title_1?smid=A323VFV6W4CN1S&psc=1) | $10 | 10 | $1 |
| [Cig. Lighter plug](https://www.amazon.com/gp/product/B07L9HQ25S/ref=ox_sc_act_title_1?smid=A2ET2G27273OWR&psc=1) | $10 | 2 | $5 |
| [Assorted PCBs](https://www.amazon.com/gp/product/B07P73X8WS/ref=ox_sc_act_title_5?smid=A2X3UMRR9X7102&psc=1) | $10 | 10 | ~$1 |
| [128x64 OLED SPI screen](https://www.amazon.com/gp/product/B08238DZDL/ref=ox_sc_act_title_6?smid=A4DIPBNTQGIGK&psc=1) | $20 | 4 | $5 |
| [Touchscreen LCD](https://www.amazon.com/gp/product/B07KPD4DHD/ref=ox_sc_saved_title_1?smid=A2KRDQ1AI5Y5G6&psc=1) | $26 | 1 | $26 | 
| [Joystick](https://www.amazon.com/gp/product/B01N59MK0U/ref=ox_sc_act_title_5?smid=A1EEONYNGVV4GN&psc=1) | $13 | 10 | $1.30 |
| [Buttons](https://www.amazon.com/gp/product/B07L1MTND7/ref=ox_sc_act_title_1?smid=A18HI9P9LIZCZS&psc=1) | $10 | 20 | $0.50 |
| [SD card slot](https://www.amazon.com/gp/product/B07BJ2P6X6/ref=ox_sc_act_title_8?smid=A30QSGOJR8LMXA&psc=1) | $7 | 5 | $1.40 |
| [SD card](https://www.amazon.com/gp/product/B07BFTQGSW/ref=ox_sc_act_title_1?smid=A27L9HV03JC4EJ&psc=1) | $28 | 10 | $2.80 |
| [Microhpone](https://www.amazon.com/Anmbest-Microphone-Sensitivity-Differential-Comparators/dp/B07CQZ93N4/ref=sr_1_2?keywords=microphone+arduino&qid=1584425335&s=industrial&sr=1-2&swrs=33BABF63DB9C530DE7199F0D24FE7983) | $8.50 | 6 | $1.42 |
| [Speaker](https://www.amazon.com/gp/product/B07GJ4GH67/ref=ox_sc_act_title_2?smid=A1NOQTMMT39TJ0&psc=1) | $10 | 2 | $5 |
| [RGB LEDs](https://www.amazon.com/gp/product/B01C19ENFK/ref=ox_sc_act_title_2?smid=A14FP9XIRL6C1F&psc=1) | $8 | 100 | $0.08 | 
| [Accelerometer](https://www.amazon.com/gp/product/B07PSCB75V/ref=ox_sc_act_title_1?smid=A2ZY5CARD1LVTF&psc=1) | $13 | 6 | $2.16 | 

Assorted parts are assumed to cost **less than $5** in total, including resistors, capacitors, solder, jumper wires, etc. Parts shall be added to the list once added to the design.

## Base configuration:
1. ESP12-WROOM-32 x 1
2. GPS unit x 1
3. 3.3v Regulator x 1
4. Cigarette lighter plug x 1
5. PCB x 1
6. Assorted parts (TBD)

This base package comes to a cost of ~$31.02

| Name of Config | OLED | Touch LCD | Joystick + buttons | SD package | Microphone/Speaker combo | RGB LEDs | Accelerometer | Total |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Addon cost | $5 | $26 | $1.80 | $4.20* | $6.42 | $0.08 ea | $2.16 | N/A |
| OLED Basic | x |  | x |  |  |  |  | $37.82 |
| OLED Drag | x |  | x |  |  | 10 | x | $40.78 |
| OLED Drag + SD | x |  | x | x |  | 10 | x | $44.98 |
| OLED All-in-One | x |  | x | x | x | 10 | x | $51.40 |
| LCD Basic |  | x |  |  |  |  |  |  | $57.02 |
| LCD Drag |  | x |  |  |  | 10 | x | $59.98 |
| LCD All-in-One |  | x |  | x | x | 10 | x | $69.20 |

*Touchscreen LCD comes with SD card reader, meaning it only costs as much as the SD card, or $2.80

## Configuration selection considerations:
- ESP32 is 3.3v ONLY. No 5v applications.
- With the unit requiring 3.3.v, a 3.7v LiPo could be used, but since almost every car has 12v socket or usb ports, a direct wire is cheaper. A liPo charger may be considered in the future.
- While up to 10 LEDs could be attached, pin count becomes a problem. Several may need to be on one circuit.
- In leau of a screen, the ESP32 has a WiFI/Bluetooth module built in that could be used to control device
- OLED, while inexpensive, is small. It's not supposed to provide massive amounts of information, but it could be inconvenient.
- LCD Touch screen is expensive, but is larger and touch functionality can be used to control the device.
- Joystick and buttons needed for efficient navigation of menus for OLED
- Keep hardware in the $30-$50 range if possible
- Might need to grab a multiplexer for the LEDs
- LEDs and screen should be dimmable, probably through pots.
- SD card reader turns out to be overkill, can't run on 5v. Had to hack the regulator off with pliers. Maybe just buy a solderable socket?

###A Note on wireless transmission
ESP32's can communicate directly to each other using the WiFi module. They can allow up to 20 simultaneus connections in multi-slave mode, making it easy to connect everything. Just can't be using the WiFi module at the same time.

## Current configuration being developed.
OLED Drag + SD

## ESP32 pinout
[Pinout and some basics](https://circuits4you.com/2018/12/31/esp32-devkit-esp32-wroom-gpio-pinout/)

## Circuit diagram/pinout
### SPI pinout
MOSI - 23  
MISO - 19  
CLK  - 18  

### SPI Screen pinout (Not final)
CS - 4  
D/C - 2  
RESET - 5  

### SD Card Reader Pinout (SPI) (Not Final)
CS - 15  







# Checklist
This document is to give a general idea of the statue of individual modules and sections of code. 

##Stage 1: Hardware and hardware test
2 units of part need to be ordered.

### Microcontroller
- [x] Selection of part
- [x] Part ordered
- [x] Part received
- [x] Part assembled
- [x] Libraries installed, communicating with programming computer
- [x] Sample code runs
- [x] Devices can send messages back and forth

### Screen
- [x] Selection of part
- [x] Part ordered
- [x] Part received
- [x] Part assembled
- [x] pinout defined
- [x] Libraries installed
- [x] Screen can display without issues

### GPS unit
- [x] Selection of part
- [x] Part ordered
- [x] Part received
- [ ] Part assembled
- [ ] pinout defined
- [ ] Libraries installed
- [ ] GPS data received and verified

### Accelerometer
- [x] Selection of part
- [x] Part ordered
- [x] Part received
- [x] Part assembled
- [ ] pinout defined
- [ ] Libraries installed
- [ ] Accelerometer data can be correctly read.

### SD Card reader
- [x] Selection of part
- [x] Part ordered
- [x] Part received
- [x] Part assembled
- [x] pinout defined
- [X] Libraries installed
- [x] Data can be written to SD card
- [x] Data can be read off of SD card

### Power supply
- [x] Selection of parts
- [x] Parts ordered
- [x] Parts received
- [ ] Parts assembled

## Stage 2: Module functionality
### Whiteboarding (high level description and pseudocode)
- [x] Define Mode - Point-to-Point
- [x] Define Mode - Course
- [x] Define Mode - Drag
- [x] Define Mode - Sprint
- [x] Define Mode - Random point
- [x] Define functionality - Cop ping
- [x] Define functionality - Driver stats
- [ ] Define data transmission structure
- [x] Define data file scheme
- [ ] Define classes/structs
- [ ] Define main functions
- [ ] Define WebApp/App

### Module functionality - Screen
- [ ] Screen displays properly
- [ ] Screen does not lag significantly
- [ ] Screen shows correct visual elements for each module.
- [ ] Screen does not leave garbage data visible for any length of time.
- [ ] Screen brightness can be controlled (???)

### Module functionality - Buttons and Joystick
- [ ] Joystick is properly read without blocking 
- [ ] Buttons are properly read without blocking
- [ ] Buttons have no appriciable lag
- [ ] Joystick and buttons are easy to control, I.E. doesn't skip over menu entries

### Module functionality - GPS
- [ ] GPS finds signal
- [ ] GPS accurately finds position
- [ ] GPS data can be stored in a timely manner

### Module functionality - NRF24 Communication
- [ ] NRF can send data to a specific device
- [ ] NRF can send data to a bunch of devices
- [ ] NRF can send all data in a timely manner.

### Module functionality - Accelerometer
- [ ] Accel. can be calibrated.
- [ ] Accel. provides accurate numbers
- [ ] Accel. noise does not cause false starts

### Module functionality - WiFi
- [ ] WiFi server is created and a device can connect to it
- [ ] Wifi server can send data to be displayed
- [ ] Data can be sent to device from laptop or phone

### Module functionality - SD Card
- [ ] Device will check if SD card is compatable
- [ ] Device will inform the user of how much space is available
- [ ] Files are generated properly
- [ ] Files have the correct data
- [ ] Files can be properly retreived.

### Module functionality - LEDs/Misc
- [ ] LEDs are able to be contrlled for Red, Yellow and Green
- [ ] LED brightness can be controlled easily

### Menu and controls
- [ ] All entries are available
- [ ] All entries are selectable/navagable 
- [ ] Access all mode from screen
- [ ] All modes return to here
- [ ] All visual elements are properly displayed

### Driver profiles
- [ ] Driver profiles can be generated, erased and swapped
- [ ] Driver profiles can be viewed 
- [ ] Driver profiles contain all relevant data

### Data Logging/Stats
- [ ] Data logging during non-events is able to be on or off
- [ ] Data collected is saved to a file
- [ ] Data can be viewed on screen
- [ ] Data can be viewed on a computer
- [ ] Data can be viewed on a phone

### Options
- [ ] Parameters can be set
- [ ] Parameters are saved between sessions.

### Security
- [ ] Passcode creation works
- [ ] Device doesn't allow driver profiles or other data to be seen until unlocked
- [ ] Device can be unlocked via phone
- [ ] Device can be unlocked via controls
- [ ] Device auto erases/scrambles if bad password entered too many times.

### Point-to-Point
- [ ] Initial and Final point saved correctly
- [ ] Other units are given time to respond
- [ ] Drivers can drop out during this period with no consequence
- [ ] Responses are properly recorded
- [ ] All units given driver list
- [ ] Setup time starts and nobody can join
- [ ] Drop outs earn a 'Withdrawl'
- [ ] Setup time completes properly
- [ ] False starts are broadcasted
- [ ] Countdown works
- [ ] Direction and distance to final destination are calculated continously
- [ ] Once final checkpoint is reached, check for scoreboard
- [ ] Generates scoreboard if first
- [ ] Receives scoreboard if not
- [ ] penalties earned are properly applied to time
- [ ] Scoreboard is populated properly
- [ ] Scoreboard and all data is saved properly

### Drag
- [ ] Drivers are allowed to set up until they press button
- [ ] GPS position is averaged to get most accurate position for start of race
- [ ] Start position is saved to SD card
- [ ] Light sequence lights up properly
- [ ] Go is at end of countdown
- [ ] GPS data is recorded during entire event
- [ ] After 1/4 mile, GPS stops logging
- [ ] Unit does math to calculate 0-60, 1/4 time, etc
- [ ] Unit saves data to SD properly

### Course
- [ ] Course creation can be initiated
- [ ] Checkpointss can be chosen at any time
- [ ] Checkpoint size can be adjusted
- [ ] Generation can be exited and creates a loop.
- [ ] Generated courses are saved with a name
- [ ] Courses can be edited to adjust Checkpoint size
- [ ] Courses can be viewed
- [ ] Courses can be erased
- [ ] Course can be overlaid on a map on a phone
- [ ] Course can be sent to other drivers
- [ ] Course allows drivers to setup
- [ ] Drivers are penalized for going before go signal
- [ ] Checkpoints can be hit
- [ ] All checkpoints must be hit to complete a lap
- [ ] All checkpoints must be hit in order
- [ ] Last checkpoint is start line, not checkpoint directly before start line
- [ ] Once last checkpoint is hit, create scoreboard with other users
- [ ] Save all relevant data

### Sprint
- [ ] Sprint creation can be initiated
- [ ] Checkpointss can be chosen at any time
- [ ] Checkpoint size can be adjusted
- [ ] Generation can be exited and creates a loop.
- [ ] Generated sprints are saved with a name
- [ ] Sprints can be edited to adjust Checkpoint size
- [ ] Sprints can be viewed
- [ ] Sprints can be erased
- [ ] Sprint can be overlaid on a map on a phone
- [ ] Sprint can be sent to other drivers
- [ ] Sprint allows drivers to setup
- [ ] Drivers are penalized for going before go signal
- [ ] Checkpoints can be hit
- [ ] All checkpoints must be hit in order
- [ ] Once last checkpoint is hit, create scoreboard with other users
- [ ] Save all relevant data

### Random point
- [ ] Initial and Destination point saved correctly
- [ ] Other units are given time to respond
- [ ] Drivers can drop out during this period with no consequence
- [ ] Responses are properly recorded
- [ ] All units given driver list
- [ ] Setup time starts and nobody can join
- [ ] Drop outs earn a 'Withdrawl'
- [ ] Setup time completes properly
- [ ] False starts are broadcasted
- [ ] Countdown works
- [ ] Direction and distance to first destination are calculated continously
- [ ] Once final checkpoint is reached or button is pressed, save time and distance penalty
- [ ] Direction and distance to final destination are calculated continously
- [ ] Once final checkpoint is reached, check for scoreboard
- [ ] Generates scoreboard if first
- [ ] Receives scoreboard if not
- [ ] penalties earned are properly applied to time
- [ ] Scoreboard is populated properly
- [ ] Scoreboard and all data is saved properly

## Stage 3: Integration
### Integration - GPS
- [ ] GPS does not interefere with other devices
- [ ] GPS is non-blocking
- [ ] GPS Setup time does not block device
- [ ] Functions that require GPS do not start up until GPS signal is found.

### Integration - NRF24
- [ ] NRF24 transceiver does not interefere with other devices
- [ ] NRF24 transceiver is non-blocking
- [ ] NRF24 transceiver correctly sends and receives data between devices.
- [ ] NRF24 transceiver sends data to all available units

### Integration - Screen
- [ ] Screen does not interefere with other devices
- [ ] Screen is non-blocking 
- [ ] Screen does not take forever to refresh.

### Integration - Controls
- [ ] Joysticks and buttons do not interefere with other devices
- [ ] Joystick and  buttons are non-blocking
- [ ] Controls respond to each mode properly.

### Integration - WiFi
- [ ] WiFi does not interefere with other devices
- [ ] WiFi mode is non-blocking

### Integration - Accelerometer
- [ ] Accelerometer does not interefere with other devices

### Integration - SD card
- [ ] SD card reader does not interefere with other devices
- [ ] SD Card reader is non-blocking

### Integration - LEDs/Misc
- [ ] LEDs do not interfere with other devices

### PCB Assembly + Power
- [ ] PCB laid out
- [ ] All components verified engaging without soldering
- [ ] Extra components soldered in place
- [ ] Power rail attached
- [ ] ESP32 attached
- [ ] Screen attached
- [ ] NRF attached
- [ ] SD Card reader attached
- [ ] GPS attached
- [ ] Accelerometer attached
- [ ] LEDs attached

## Stage 4: Testing
TODO

## Stage 5: WebApp/App development
TODO


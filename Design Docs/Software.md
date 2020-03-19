#Code
Description of code to aid in development
##Normal operation
###Menu
###Data logging mode
###Data view
###Data transfer
###Police ping

##Events
Types of events a driver may initiate.
###Goal
Sends a location to all participating drivers, and Keeps track of order of arrival. Only for multiple drivers.
####Description
First driver picks destination. Once destination is confirmed, broadcasts to all vehicles in vacinety. Includes start time, all devices should have same time with GPS clocks. Each driver is given the option to accept or opt out. Those who opt in are given set up time (screen shall read "Set up"), before LEDs turn red and the driver has to stop. Screen will switch to arrow mode. A start signal is given by the LEDs. False starts are recorded and penalties are applied. 

Once Arriving at destination, Signal is broadcast asking for scoreboard. If nobody is found, user is declared winner. Otherwise, request rank from leader. Exact arrival times are recorded in device for recordkeeping. Leader maintains a scoreboard until all participants check in or >67% of drivers have voted to close race (Someone drops out, crashes, pulled over, etc)

####Pseudo
Initiating driver:
1. Obtain Coordinates 
 1. Load from SD
 2. Load from Cell Phone (WiFI/Bluetooth)
 3. Load from Recents
2. Choose start time
3. Choose setup time
4. Choose participation (Initiating driver may opt out, in case of camera car or event organizer)
5. Broadcast location and start time to other drivers.
6. Listen for Acks from other drivers until setup time initiates. Timer displayed on screen to indicate time until setup starts.
 - Timer may be cancelled, and will send cancellation to all other units in area.
7. During Setup time car is allowed to move. Timer is displayed, indicating time until cars must stop moving.
 - Timer can be cancelled on an individual car basis. Broadcasts "Backed out" to other drivers for scoreboard purposes.
8. LEDs turn Red, indicating race is about to start. Car must not move or will earn false start. False starts are broadcasted. Screen transitions to arrow.
9. LEDs turn Yellow, then Green to start race.
10. Move to "All drivers (While racing)"

Receiving driver(s):
1. Once message is received, ask driver to accept or reject event
 1. On reject, return to normal operation
 2. On accept, continue
2. Send join message back to Initiator informing of intent to join
3. Timer continues to count down until setup time.
 - Timer may be cancelled, and will send cancellation to Initiator. 
4. During Setup time car is allowed to move. Timer is displayed, indicating time until cars must stop moving.
 - Timer can be cancelled on an individual car basis. Broadcasts "Backed out" to other drivers for scoreboard purposes.
5. LEDs turn Red, indicating race is about to start. Car must not move or will earn false start. False starts are broadcasted. Screen transitions to arrow.
6. LEDs turn Yellow, then Green to start race.
7. Move to "All drivers (While racing)"

All drivers (While racing):
1. Get GPS coordinates
2. Compare with destination
 - If at destination, move to "On Arrival"
3. Obtain current heading.
4. Display heading and distance remaining on screen
5. Allow driver to abort, returning to normal mode. Broadcast "Backed out" message.

On Arrival:
1. Send message asking for scoreboard
 1. If no scoreboard received within "reasonable" time/attempts, move to "First arrival"
 2. Otherwise, receive scoreobard and move to "All following drivers"

First arrival:
1. Create scoreboard
2. Calculate any penalties assigned, and set as time.
3. Wait for messages from other drivers asking for scoreboard.
4. Update times on screen as more drivers roll in.
5. Listen for "end race" votes. If more than 67% of all drivers initially in race, close race down. "Backed out" drivers are removed from number.
6. Once all drivers accounted for or vote succeeds, send close race signal.
7. Save race data (Optional)
8. Return to normal operation.

All following drivers:
1. On receipt of scoreboard, copy.
2. Calculate own time, add penalties, broadcast. Include any "backed out" messages received, penalties noticed.
3. Display scoreboard.
4. Update scorboard as required.
5. Enable "End Race" button. Broadcast vote is selected.
6. When "End race" signal received, continue.
7. Save race data (Optional)
8. Return to normal operation.

###Drag
Allows one or two drivers 
###Course
###Time trial
###Egg hunt (temp name)

##Functions by module
List of functions as implied above.
###Microcontroller (Higher level)
- onRoute(Waypoint): Runs until destination is reached
- getScoreboard(): Get scoreboard from other drivers
- getInput(): gtes button and joystick values
###GPS
- getCoords(): returns GPS data
- getVel(): Calculates velocity
- getTravelDir(): Calculates direction of travel
- getTargetDir(): Calculates direction to target
- getDist(): Calculate distance to waypoint
- getTime(): Uses GPS clock to retrieve time.
###Screen
- Arrow mode
 - updateArrow(TravelDir, TargetDir): Orient arrow on screen
 - updateDist(): Update distance on screen
###NRF24
- send(payload): Sends payload on NRF24 antenna. Might need to un-generalize for specific uses.
- nonBlockingRec(): Waiting for input, but not hindring other functions
- blockingRec(): waiting for input, will not continue until input received.
###SD card
- write(data)
- read(location)
###LEDs
- setColor(LED,r,g,b)
###Accelerometer
- readAccel():
- calibrate():
###WiFi
###Bluetooth

##Classes/Structs
###Waypoints
coordinates, name of location
###Drivers
nametag, ID, Car make/model, driver score
###Race Details (General or specific to race type?)
###Scoreboard
penalties, times, scores, nametags

##App
More of a webserver... probably.

==================================================

**Extra data to be used**

##Modes overview: (Remove once modes are better defined
- Goal: Send location to other drivers, gives out a rank.
- Course: Set up a course, and record times
- Drag: Record drag race statistics. Sync with other modules in area?
- Egg hunt: Grabs a random location within a radius and you have to get as close to it as possible before returning.
- Time trial

##Features: (remove once better defined)
- Driving stats (Max speed, avg speed, distance traveled, etc)
- Police ping: Notify other drivers of a cop
- Save locations, times, scores, ranks locally

###Hardware handlers
- GPS read
- Screen write
- LED write
- SD card read/write
- NRF24 Send/receive
- WiFi server (setup, upload, download)
- Button/joystick handlers

###Display
- GPS arrow + crow's flight distance: Updates as fast as feasable, up to 15 fps. Points to next waypoint
- Display coordinates
- Display rank
- Display score

###UI
- Usernames
- Accept/reject incoming race requests
- Saved locations
- Allow coordinate sets to be given names
- Opt in/out default toggle
- Adjust Race start timer
- Settings

###WiFi
- Allow phone to send coordinates
- Send data to phone for display

###SD Card
- Save all driving data
- Save waypoints, including names
- Save nametag, and other known users' nametags

###Accelerometer
- Find false starts
- More accurate off-the-line data





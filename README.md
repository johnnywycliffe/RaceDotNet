# Race.Net
Have you ever played Need For Speed Underground and wished you could pull up to that sweet muscle car you see on your morning commute and challenge him to a drag race? Now you can! With Race.Net (pronounced RaceNet) you can effortlessly engage with other drivers.

Utilizing a GPS receiver and an NRF24 transceiver mounted to a ESP32-WROOM-32 board, the Race.net is designed to draw minimal power while still providing several essential functions for car groups. The NRF antenna allows the vehicles to share data in a way not seen before, sharing waypoints and driver profiles at up to a 1/4 mile away, meaning everyone in a parking lot will be able to get the message without needing to text the address tons of times, or setting up a unique group each time.

The GPS allows Race.net to record accurate velocity and positional data, and when combined with the accelerometer, it allows for precise calculations of speed, acceleration, and items like 1/4 and 1/8 mile times. Race.net can also indicate directions to the driver.

Drivers are able to make profiles, save their best times, custom course, favorite locations, and other drivers to their Race.net to allow for the best moments to have a good data set behind them. Never again will there be an argument over who is a better driver or who has a faster car: it's all in the data! Score points for winning and for daily challenges to show just how much you drive.

Worried about unscrupulous people deleting your data or, worst case scenario, the police decide to grab your Race.net? The unit can be locked with a passcode that it requires on each boot! You can set a maximum guess attempts that will auto-erase all data once hit to avoid trial and error guessing.

Race.Net integrates with cellphones, allowing for exporting of data and selecting locations from the phone. In addition, most core functions can be accessed through the phone to provide easy viewing of the data from around the vehicle.

## Features
- Allows you to send a location to several drivers at once, without requiring you to be in the same group
- Tracks statistics like average velocity, top speed, 1/4, 1/8 mile time
- Can build courses and do timed laps, save and compare with others.
- Can generate point-to-point races on the fly, taking only three minutes to set up.
- After a race in concluded, Scoreboards are generated and can be saved for future record.

## Project Status
As of 2020-3-17, hardware has been ordered for two test units. See Checklist.md for more details.

As of 2020-3-20, software is veing defined in pseudocode

## Future considerations
- Once prototyping is done, a custom PCB could be printed an manufactured to allow for smaller form factor and reduced price.
- A case could be provided to protect the circuitry and clean up the look of Race.Net
- With the addition of a microphone, amp and speaker, Race.Net could be set up to transmit voice. 
- Instead of relying on vehicle power, a LiPo battery could be used to maintain power after vehicle is powered down, or even disconnected from the hevicle entirely for use with other things like skateboards, hoverboards, bikes, boats and more.

## Disclaimer
Street racing is illegal. Do not race on public roads. Use of Race.Net on public roads should be limited to Non-race functions.

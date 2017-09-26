# Online Particle Photon RGB Strip Controller
Controlling multiple LED Strips over the internet via a Particle Photon

## Description
this is a relatively polished, simple HTML GUI as well as a generic Particle Photon backend for controlling LED lights via Particle Functions. 
I created this as a way for my Roomates an I to easily control RGB lights in our kitchen as well as living room without breaking the bank (<$50 in total for 2 5m strips + Particle Photon). The HTML frontend is lightweight and is easy to use on smartphones, having large and simple buttons. The code running on the Particle is capable of being used for other RGB lighting tasks as it is not tied to the HTML website in any way. The website only passes standard RGB Hex values to the Photon.
#### Features:
* Smooth Fading between color inputs
* Website Color and status feedback 
* Automatic 2 hour timeout
* Evening/Rain automatic red "night-light" mode
* Easy IFTTT integration

## Quick Start
  1. Flash your Photon using the "particle.ino" file 
  2. Connect a **Common Anode** RGB Led Strip or controller to pins D0 (Red), D1 (Green), D2 (Blue). (If only using a single RGB LED, remember to use a current limiting resistor).
  3. Edit the "index.js" and "index.html" files to include your unique device ID as well as your Access token. There are 2 URLS to change in the js file, and 1 in the HTML file. The Device ID can be found by going to the Particle console, and the your Access token is found by going to the IDE -> settings. **Replace the angle brackets and everything betwen them <>**
  4. Clicking the buttons within the open HTML file should now control the LED(s)!
  
 ## IFTTT Integration
 To use the automatic sunset/rain night-light feature, the easiest way is to use [IFTTT](https://ifttt.com)'s Weather Underground Service. You must create the following 4 applets for the full integration:  

WU Function|Particle Function|Particle input (no quotes)
--- | ---|---
If Sunrise|led2|"sunrise"
If Sunset|led2|"sunset"
If Rain|led2|"rain"
If Clear|led2|"clear"

To use IFTTT to change the color, use the particle function "led" with the function input as a standard hex color code I.e #FF0000 will cause the LED to turn red at full brightness. (If you search "color picker" on google there is a nice tool to help you find any color value). 
* **Fast Google Home and Amazon Alexa integration can be achieved through IFTTT as well**

## Screenshot
![alt text](https://i.imgur.com/k1xAAWT.png "Screenshot with Aqua Background")

## Planned Additions
* Time-out based on motion in the room

# Known Issues
* **The particle device ID and access token are exposed in the HTML file so it is not advised to be used publicly yet**
* Occasionally night-light mode will be stuck on, this can be fixed with a hard reset of the Photon, it is very inconsistent and I have not found the cause yet
* The dimming feature still redirects to a Particle success page as I do not know how to integrate a slider in js yet.
* The dimming feature must be used twice before working

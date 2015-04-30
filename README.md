# Connect Arduino to Webpage with frontend Javascript only
Connect Arduino input to JS with joystick HID

##Why we need it
There are tons of ways to connect physical computing stuff to computer via Processing, NodeJs, etc. However there isn't much tutorial on connecting hardware to webpage without using backend scripts. This projects describes a way to provide one way communication from Arduino to browser without running additional scripts. 

##Pros and Cons of this method
Pros: Simple to deploy. No need to install anything on computer. No need to learn language other than Javascript.

Cons: One way communication only. Works well on Firefox, Buggy on Chrome, Not functional in Safari. 

##How this works?

Native [GamePad API](http://www.w3.org/TR/gamepad/) supports readonly access to GamePad. This low level API can access buttons, axes of a gamepad. Since axes are in float format within -1~1 and buttons are in boolean format. We can emulate a Gamepad with Arduino and send values by emulating axes and button actions. Then JavaScript in browser can extract values from the emulated gamepad.


As a demo I used Arduino Leonardo (Any ATmega32u4 based board including Micro/Micro Pro should work) because it has native USB support to emulate a gamepad. However, official Arduino IDE did not provide capability to emulate a gamepad. I found a project [Arduino HID Project](http://github.com/NicoHood/HID) by Nicohood that did all low level stuff on HID and makes this demo pretty simple.


You can either follow [NicoHood's tutorial](http://github.com/NicoHood/HID/wiki) on how to install the library or upload a pre-compiled hex file to Leonardo for a quick test.

###Write your own code

###Upload hex file directly

read more on http://deqingsun.github.io/Arduino_HID_frontendJS/

# Connect Arduino to Webpage with frontend Javascript only
Connect Arduino input to JS with joystick HID

##Why we need it
There are tons of ways to connect physical computing stuff to computer via Processing, NodeJs, etc. However there isn't much tutorial on connecting hardware to webpage without using backend scripts. This projects describes a way to provide one way communication from Arduino to browser without running additional scripts. 

##Pros and Cons of this method
Pros: Simple to deploy. No need to install anything on computer. No need to learn language other than Javascript.

Cons: One way communication only. Works well on Firefox, Buggy on Chrome, Not functional in Safari. 

##How this works?

Native GamePad API (http://www.w3.org/TR/gamepad/) supports readonly access to GamePad. This low level API can access buttons, axes of a gamepad. Since axes are in float format within -1~1 and buttons are in boolean format. We can emulate a Gamepad with Arduino and send values by emulating axes and button actions. Then JavaScript in browser can extract values from the emulated gamepad.


read more on http://deqingsun.github.io/Arduino_HID_frontendJS/

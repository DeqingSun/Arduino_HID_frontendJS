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

Make sure you followed the [install guide](https://github.com/NicoHood/HID/wiki/Installation) and put HID in hardware folder of your sketch book.

Make sure you chose "Arduino Leonardo HID-Project" in Board:
![Arduino Leonardo HID-Project](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/HID_library_board.png)


And "Serial + Gamepad HID" in USB Core:
![Serial + Gamepad HID](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/HID_library_board.png)


Then you can open "sketch_forward_input_JS_gamepad/sketch_forward_input_JS_gamepad.ino" in this repo and upload it to your Leonardo. Also you can modify the code to add your own feature.

###Upload hex file directly

If you want to skip installing the library and only want to try it. There is a sketch_forward_input_JS_gamepad.cpp.hex to use.


You can check both verbose output so you can copy avrdude command from Arduino.

![verbose output](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/upload_hex_1.png)


Compile and upload any sketch to Leonardo. Find avrdude command in output.

![Avrdude command](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/upload_hex_2.png)


Paste the command into terminal

![Paste command](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/upload_hex_3.png)


Delete original hex file path

![Remove hex](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/upload_hex_4.png)

Drag and drop new hex file into terminal

![new file](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/upload_hex_5.png)


Now you can reset Leonardo and press enter to upload hex file

![upload](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/upload_hex_6.png)


##Test Gamepad

Now you should be able to see a functional gamepad. You can use "Game Controller" in control panel if you are using Windows.

![gamepad](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/working_joystick.png)

##Wiring

I used a potentiometer to generate a analog value and buttons to generate digital ones. No pull-up resistor is needed because internal ones are enabled. Just connect buttons between IO and Ground.

![photo](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/test_circuit/Leonardo_test_circuit.jpg)

![circuit](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/test_circuit/Leonardo_test_circuit.png)


##Connect it with Browser!

Firefox is recommended in this step. You can open http://www.html5rocks.com/en/tutorials/doodles/gamepad/ to test if gamepad is recognized.

![rock](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/html5rockFirefox.png)


If you want to write your own code, you can refer to simple.html in this repo.

![simple](https://raw.githubusercontent.com/DeqingSun/Arduino_HID_frontendJS/master/tutorial/connectFirefox.png)




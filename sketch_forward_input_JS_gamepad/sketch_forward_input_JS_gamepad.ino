unsigned long previousMillis = 0;

const long interval = 50;

void setup() {
  Gamepad.begin();
  for (unsigned char i = 0; i < 16; i++) {
    pinMode(i, INPUT);           // set pin to input
    digitalWrite(i, HIGH);       // turn on pullup resistors
  }
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    Gamepad.releaseAll();
    for (unsigned char i = 0; i < 16; i++) {
      if (digitalRead(i) == LOW) {
        Gamepad.press(i + 1); //NicoHood's library starts with button 1
      }
    }

    // move x/y Axis to a new position (16bit)
    Gamepad.xAxis(analogRead(0) * 64 - 32768); //map analog value to full range of position
    Gamepad.yAxis(analogRead(1) * 64 - 32768);
    Gamepad.zAxis(analogRead(2) / 4 - 128); //NicoHood's library use 8bit for z and rz
    Gamepad.rxAxis(analogRead(3) * 64 - 32768);
    Gamepad.ryAxis(analogRead(4) * 64 - 32768);
    Gamepad.rzAxis(analogRead(5) / 4 - 128);

    // functions above only set the values
    // this writes the report to the host
    Gamepad.write();
  }
}


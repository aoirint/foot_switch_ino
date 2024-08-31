#include "HID-Project.h"

#define PIN_BUTTON 4
#define PIN_LED 13

void setup() {
  Mouse.begin();

  pinMode(PIN_BUTTON, INPUT_PULLUP);

  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);
}

void loop() {
  while (digitalRead(PIN_BUTTON) == HIGH) {
    delay(100);
  }

  Mouse.press(MOUSE_NEXT);

  digitalWrite(PIN_LED, HIGH);
  delay(100);

  while (digitalRead(PIN_BUTTON) == LOW) {
    delay(100);
  }

  Mouse.release(MOUSE_NEXT);
  digitalWrite(PIN_LED, LOW);
  delay(100);
}

#include "AS5611.h"

AS5611 display;

void setup() {
  int ports[8] = {2, 3, 4, 5, 6, 7, 8, 9};
  display.init(ports);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    display.clearAll();
    display.setNum(i);
    delay(500);
    display.turnOnDot();
    delay(500);
    display.turnOffDot();
  }
}

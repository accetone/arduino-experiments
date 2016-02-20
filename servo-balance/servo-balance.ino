#include <Servo.h>

int angle = 0;
bool direct = true;

Servo servo;

void setup() {
  servo.attach(9);
}

void loop() {
  if (direct) angle++;
  else angle--;

  if(angle == 180) direct = false;
  else if(angle == 0) direct = true;
  
  servo.write(angle);
  delay(10);
}


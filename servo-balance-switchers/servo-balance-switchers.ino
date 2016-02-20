#include <Servo.h>

#define SERVO_PIN 9
#define SPEED_PIN 1
#define RESET_PIN 2
#define ACTIVE_PIN 3

bool activeBtnUp = true;
bool resetBtnUp = true;
bool speedBtnUp = true;

int angle = 0;
bool isDirect = true;
bool isActive = false;
int delayTime = 10;

Servo servo;

void setup() {
  servo.attach(SERVO_PIN);  
  pinMode(SPEED_PIN, INPUT_PULLUP);
  pinMode(RESET_PIN, INPUT_PULLUP);
  pinMode(ACTIVE_PIN, INPUT_PULLUP);
}

void loop() {
  if (isClicked(ACTIVE_PIN, &activeBtnUp)) {
    isActive = !isActive;
  }

  if (isClicked(RESET_PIN, &resetBtnUp)) {
    resetServo();
  }

  if (isClicked(SPEED_PIN, &speedBtnUp)) {
    delayTime += 10;

    if (delayTime > 50) delayTime = 10;
  }
    
  moveServo();
}

bool isClicked(int pin, bool* wasUp) {
  bool isUp = digitalRead(pin);
  bool clicked = false;

  if (*wasUp && !isUp) {
    delay(10);

    isUp = digitalRead(pin);

    if (!isUp) clicked = true;
  }

  *wasUp = isUp;

  return clicked;
}

void moveServo() {
  if (!isActive) return;
  
  if (isDirect) angle++;
  else angle--;

  if(angle == 180) isDirect = false;
  else if(angle == 0) isDirect = true;
  
  servo.write(angle);  
  delay(delayTime);
}

void resetServo() {
  if (isDirect) angle = 0;
  else angle = 180;

  servo.write(angle);
  delay(delayTime);
}


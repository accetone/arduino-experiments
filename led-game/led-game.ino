#define FIRST_LED_PIN 0
#define LED_COUNT 7
#define L_PIN 13
#define R_PIN 8
#define BUZZ_PIN 11
#define S_PIN 9

int activeLED = FIRST_LED_PIN;
int* delayTime = new int[5] {20, 50, 100, 250, 500};
int speed = 4;
bool notified = false;
bool speedIsUp = false;

void setup() {
  for (int pin = FIRST_LED_PIN; pin < FIRST_LED_PIN + LED_COUNT; pin++) 
    pinMode(pin, OUTPUT);

  pinMode(L_PIN, INPUT_PULLUP);
  pinMode(R_PIN, INPUT_PULLUP);
  pinMode(S_PIN, INPUT_PULLUP);
  pinMode(BUZZ_PIN, OUTPUT);

  digitalWrite(activeLED, HIGH);
}

void loop() {
  bool isDownL = !digitalRead(L_PIN);
  bool isDownR = !digitalRead(R_PIN);

  if (isClicked(S_PIN, &speedIsUp)) {
    speed--;

    if (speed == -1) speed = 4;
  }

  if ((isDownL && isDownR) || (!isDownL && !isDownR)) {
    if(activeLED == FIRST_LED_PIN + 3 && !notified) {
      tone(BUZZ_PIN, 500, 100);
      notified = true;
    }
    
    return;
  }

  notified = false;

  if (isDownL) {
    activeLED--;

    if (activeLED < FIRST_LED_PIN) {
      activeLED = FIRST_LED_PIN + LED_COUNT - 1;
      digitalWrite(FIRST_LED_PIN, LOW);
    }
    else {
      digitalWrite(activeLED + 1, LOW);
    }

    digitalWrite(activeLED, HIGH);
    delay(delayTime[speed]);
  }

  if (isDownR) {
    activeLED++;

    if (activeLED >= FIRST_LED_PIN + LED_COUNT) {
      activeLED = FIRST_LED_PIN;                
      digitalWrite(FIRST_LED_PIN + LED_COUNT - 1, LOW);
    }
    else {
      digitalWrite(activeLED - 1, LOW);
    }

    digitalWrite(activeLED, HIGH);    
    delay(delayTime[speed]);
  }
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

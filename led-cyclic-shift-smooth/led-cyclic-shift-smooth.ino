#define FIRST_LED_PIN 0
#define LED_COUNT 7
#define L_PIN 13
#define R_PIN 8

int activeLED = FIRST_LED_PIN;

void setup() {
  for (int pin = FIRST_LED_PIN; pin < FIRST_LED_PIN + LED_COUNT; pin++) 
    pinMode(pin, OUTPUT);

  pinMode(L_PIN, INPUT_PULLUP);
  pinMode(R_PIN, INPUT_PULLUP);

  digitalWrite(activeLED, HIGH);
}

void loop() {
  bool isDownL = !digitalRead(L_PIN);
  bool isDownR = !digitalRead(R_PIN);

  if (isDownL && isDownR) {
    delay(100);
    return;
  }

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
  }

  delay(100);
}

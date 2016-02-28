#define FIRST_LED_PIN 0
#define LED_COUNT 7
#define L_PIN 13
#define R_PIN 8
#define BUZZ_PIN 11

int activeLED = FIRST_LED_PIN;

bool leftBtnUp = true;
bool rightBtnUp = true;

void setup() {
  for (int pin = FIRST_LED_PIN; pin < FIRST_LED_PIN + LED_COUNT; pin++) 
    pinMode(pin, OUTPUT);

  pinMode(L_PIN, INPUT_PULLUP);
  pinMode(R_PIN, INPUT_PULLUP);
  pinMode(BUZZ_PIN, OUTPUT);

  digitalWrite(activeLED, HIGH);
}

void loop() {
    if (isClicked(L_PIN, &leftBtnUp)) {
      activeLED--;

      if (activeLED < FIRST_LED_PIN) {
        activeLED = FIRST_LED_PIN + LED_COUNT - 1;
        digitalWrite(FIRST_LED_PIN, LOW);
      }
      else {
        digitalWrite(activeLED + 1, LOW);
      }

      digitalWrite(activeLED, HIGH);
      tone(BUZZ_PIN, 500, 50);
    }

    if (isClicked(R_PIN, &rightBtnUp)) {
      activeLED++;

      if (activeLED >= FIRST_LED_PIN + LED_COUNT) {
        activeLED = FIRST_LED_PIN;                
        digitalWrite(FIRST_LED_PIN + LED_COUNT - 1, LOW);
      }
      else {
        digitalWrite(activeLED - 1, LOW);
      }

      digitalWrite(activeLED, HIGH);
      tone(BUZZ_PIN, 500, 50);
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

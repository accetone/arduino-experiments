#define PIN_START 2

void setup() {
  Serial.begin(9600);

  for (int pin = 0; pin < 7; pin++) 
    pinMode(pin, OUTPUT);
}

void loop() {
  if (Serial.available() <= 0) return;
  
  String msg = Serial.readString();

  if (msg.length() >= 3) {
    int pin = (int)msg[0] - 48;
    int state = (int)msg[2] - 48;
  
    if (msg[2] == '1') {
      digitalWrite(PIN_START + pin, HIGH);
    }
    else {
      digitalWrite(PIN_START + pin, LOW);
    }
  }
    
  Serial.flush();
}

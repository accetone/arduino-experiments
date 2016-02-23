#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

bool notified = false;

int greenThreshold = 25;
int yellowThreshold = 26;
int redThreshold = 27;

void setup() {
  lcd.begin(16,2);
  lcd.print("Temperature");

  for (int i = 0; i <= 3; i++) 
  {
    pinMode(i, OUTPUT);
  }  
}

void loop() {
  float v = analogRead(A0) * 5.0 / 1023.0;
  float t = 1.0 / (log(v / 2.5) / 4300.0 + 1.0/298.0) - 273.0;  

  lcd.setCursor(0, 1);
  lcd.print(t);

  if (t >= greenThreshold) digitalWrite(0, HIGH);
  else digitalWrite(0, LOW);

  if (t >= yellowThreshold) digitalWrite(1, HIGH);
  else digitalWrite(1, LOW);

  if (t >= redThreshold) {
    if (!notified) {
      tone(3, 4000, 100);
      notified = true;
    }
    
    digitalWrite(2, HIGH);    
  }
  else {
    notified = false;
    digitalWrite(2, LOW);    
  }

  delay(1000);
}

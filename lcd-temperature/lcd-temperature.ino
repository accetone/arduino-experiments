#include <LiquidCrystal.h>
#include <math.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup() {
  lcd.begin(16,2);
  lcd.print("Temperature");
}

void loop() {
  float v = analogRead(A0) * 5.0 / 1023.0;
  float t = 1.0 / (log(v / 2.5) / 4300.0 + 1.0/298.0) - 273.0;  

  lcd.setCursor(0, 1);
  lcd.print(t);

  delay(1000);
}

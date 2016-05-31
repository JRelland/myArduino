/* José Relland - Juillet 2015
 
 Arduino Projects
 Project Bonjour LEDUS
 Dans différentes langues :)
 Le présent programme est dans le domaine public.   
 */
//
// Version du 30 juin 2015 à 22:00
//
#include <LiquidCrystal.h> // Call the library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Library set-up
//const int switchPin = 6;
//int switchState = 0;
//int prevSwitchState = 0;
//int reply = 0;
int languageChoice = 0;
void setup() {
}
void loop() {
  lcd.begin(16, 2);  // say how the LCD display is (16 characters, 2 rows)
//  pinMode(switchPin, INPUT);
  for (languageChoice = 0; languageChoice <= 3; languageChoice++) {
  switch (languageChoice) {
  case 0:  
    lcd.setCursor(0, 0);
    lcd.print("TechniStub :)");
    delay(2000);
    lcd.setCursor(4, 1);
    lcd.print("Ca va ?!");
    delay(2000);
    lcd.clear(); 
    break;
 case 1:
    lcd.setCursor(0, 0);
    lcd.print("TechniStub :)");
    delay(2000);
    lcd.setCursor(1, 1);
    lcd.print("How are you?!");
    delay(2000);
    lcd.clear(); 
    break;
 case 2:
    lcd.setCursor(0, 0);
    lcd.print("Chinese words");
    delay(2000);
    lcd.setCursor(4, 1);
    lcd.print("soon...  :)");
    delay(2000);
    lcd.clear(); 
    break;
    }
  }
}


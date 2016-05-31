/* José Relland - Juillet 2015
 
 Arduino Projects
 Project Troyes Aube FabLab, bienvenue :)
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

    lcd.setCursor(0, 0);
    lcd.print(" Troyes  Aube ");
    lcd.setCursor(4, 1);
    lcd.print("Fablab :) ");
    delay(5000);
    lcd.clear(); 
    lcd.setCursor(0, 0);
    lcd.print("Bienvenue :) ");
    lcd.setCursor(2, 1);
    lcd.print("Au Quietime Coffee :)");
    delay(5000);
    lcd.clear();  
  }


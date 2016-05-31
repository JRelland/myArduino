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
int languageChoice = 0;

char messageLine0 = 'Text Line 0'; // Text for first line
int posLine0 = 0;      // Position first line
int tempoLine0 = 1000; // Delay first line in ms
char messageLine1 = 'Text Line 1'; // Text for second line
int posLine1 = 0;      // Position second line
int tempoLine1 = 1000;     // Delay first line in ms

void setup() {
  // Paramètre le display LCD 16 caractères, 2 lignes
  lcd.begin(16, 2);  
}

void loop() {

  messageLine0 = 'TechniStub'; // Text for first line
  posLine0 = 0;      // Position first line
  tempoLine0 = 1000; // Delay first line in ms
  
  messageLine1 = 'TechniStub'; // Text for second line
  posLine1 = 0;      // Position second line
  tempoLine1 = 1000; 
  
  
  // Passer en revue les différents messages dans une boucle for
   for (languageChoice = 0; languageChoice <= 3; languageChoice++) {  
     // Envoi du m
     void displayMessage(messageLine1, posLine1, tempoLine1, messageLine2, tempoLine2, posLine2) {

}
 
 
  for (count=0;count<5;count++) {
   digitalWrite(pinArray[count], HIGH);
   delay(timer);
   digitalWrite(pinArray[count + 1], HIGH);
   delay(timer);
   digitalWrite(pinArray[count], LOW);
   delay(timer*2);
  }
 
  switch (languageChoice) {
  case 0:  
    lcd.setCursor(0, 0);
    lcd.print("TechniStub :)");
    delay(1000);
    lcd.setCursor(4, 1);
    lcd.print("Ca va ?!");
    delay(2000);
    lcd.clear(); 
    break;
 case 1:
    lcd.setCursor(1, 0);
    lcd.print("TechniStub :)");
    delay(1000);
    lcd.setCursor(2, 1);
    lcd.print("How are you?!");
    delay(2000);
    lcd.clear(); 
    break;
 case 2:
    lcd.setCursor(0, 0);
    lcd.print("Chinese chara-");
    //delay(2000);
    lcd.setCursor(4, 1);
    lcd.print("cters soon... :)");
    delay(2000);
    lcd.clear(); 
    break;
    }
  }
}


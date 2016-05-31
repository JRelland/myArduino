/* José Relland - Juillet 2015
 
 Arduino Projects Book
 Project 11, Crystal Ball
 With Liquid Crystal Display
 Le présent programme est dans le domaine public.   
 */
//
// Version du 30 juin 2015 à 22:00
//
#include <LiquidCrystal.h> // Call the library
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Library set-up
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;
void setup() {
  lcd.begin(16, 2);  // say how the LCD display is (16 characters, 2 rows)
  pinMode(switchPin, INPUT);
  lcd.print("Ask the ");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!"); 
}
void loop() {
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The Ball says: ");
      lcd.setCursor(0, 1);
      switch(reply){
      case 0:
        lcd.print("Yes");
        break;
      case 1:
        lcd.print("Most Likely");
        break;
      case 2:
        lcd.print("Certainly");
        break;
      case 3:
        lcd.print("Outlook Good");
        break;
      case 4:
        lcd.print("Unsure");
        break;
      case 5:
        lcd.print("Ask Again");
        break;
      case 6:
        lcd.print("Doubtful");
        break;
      case 7:
        lcd.print("No");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}


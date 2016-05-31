/* Programme Morse 
 *  Fichier ccpp Source code
 *  
 *  Tester les libraiires
 * 
 * José Relland Mai 2016
 * 
 * https://www.arduino.cc/en/Hacking/LibraryTutorial
 */
 #include "Arduino.h"
 #include "morse02.h"
 
void Morse::dot()
{
  digitalWrite(_ledPin, HIGH);
  delay(250);
  digitalWrite(_ledPin, LOW);
  delay(250);  
}

void Morse::dash()
{
  digitalWrite(_ledPin, HIGH);
  delay(1000);
  digitalWrite(_ledPin, LOW);
  delay(250);
}


/*
char envoiMorse(char readLetter, int ledPin) {

if (readLetter == 'o' || readLetter == 'O') 
{
    dot(ledPin) ; dot(ledPin) ; dot(ledPin) ;
//    Serial.println("J'ai émis le \'o\' :)");
}
else if (readLetter == 's' || readLetter == 'S') 
{
    dash(ledPin) ; dash(ledPin) ; dash(ledPin) ;
//    Serial.println("J'ai émis le \'S\' :)");
}
else
{
//    Serial.println("C'est une autre lettre :)");
}

}

*/

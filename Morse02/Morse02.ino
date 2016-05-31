/* Programme Morse 
 *  Un seul fichier
 *  
 *  Tester les libraiires
 * 
 * José Relland Mai 2016
 * 
 * https://www.arduino.cc/en/Hacking/LibraryTutorial
 */

#include "morse02.h"

Morse morse02(13);


void setup() {
  // put your setup code here, to run once:

Serial.begin(9600) ;

}

void loop() {
  // put your main code here, to run repeatedly:

  morse02.dot(); morse02.dot(); morse02.dot();
  morse02.dash(); morse02.dash(); morse02.dash();
  morse02.dot(); morse02.dot(); morse02.dot();
  delay(3000);

/*
  // Fonction pour lire le caractère
  if(Serial.available() > 0) {   // Attente de la lettre
  
  Serial.print("Vous avez tapé : ") ;
  readLetter = Serial.read() ;   // Lecture de la lettre
  Serial.println(readLetter) ;

  // Envoi à la fonction pour le morse
char  envoiMorse(char readLetter, int ledPin) ;

 }
delay(1000) ;

*/
}






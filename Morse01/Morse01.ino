/* Programme Morse 
 *  Un seul fichier
 *  
 *  Tester les libraiires
 * 
 * José Relland Mai 2016
 * 
 * https://www.arduino.cc/en/Hacking/LibraryTutorial
 */

const int ledPin = 13 ; 

char readLetter ; // Pour recevoir la lettre

void setup() {
  // put your setup code here, to run once:
pinMode(ledPin, OUTPUT) ; 

Serial.begin(9600) ;

}

void loop() {
  // put your main code here, to run repeatedly:


  // Fonction pour lire le caractère
  if(Serial.available() > 0) {   // Attente de la lettre
  
  Serial.print("Vous avez tapé : ") ;
  readLetter = Serial.read() ;   // Lecture de la lettre
  Serial.println(readLetter) ;

  // Envoi à la fonction pour le morse
  envoiMorse(readLetter) ;

 }
delay(1000) ;
}

/***************************************************/
char envoiMorse(char myLetter) {

if (myLetter == 'o' || myLetter == 'O') 
{
    dot() ; dot() ; dot() ;
    Serial.println("J'ai émis le \'o\' :)");
}
else if (myLetter == 's' || myLetter == 'S') 
{
    dash() ; dash() ; dash() ;
    Serial.println("J'ai émis le \'S\' :)");
}
else
{
    Serial.println("C'est une autre lettre :)");
}

}
// fonction dot
void dot() 
{
  digitalWrite(ledPin, HIGH);
  delay(250) ;
  digitalWrite(ledPin, LOW);
  delay(250) ;
}

// Fonction dash
void dash() 
{
  digitalWrite(ledPin, HIGH);
  delay(500) ;
  digitalWrite(ledPin, LOW);
  delay(250) ;
}




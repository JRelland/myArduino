/*  MOOC Fabriquer un objet connecté
    Mines-Télécom - Plateforme FUN
    TP1 - La servoserrure.
    
* Solution inspirée du programme : Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 Modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep

* et du programme : AnalogInOutSerial
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 
 Programme réalisé par José Relland le 22 mai 2016 
 dans le cadre du TP1 - Le servoserurre.
 
 Objectif :
 Mouvement >120° puis < 60° puis entre 60° et 120°
 Si réalisé, 3 clignotements de la LED 13 (500 ms allumée puis éteinte)

**************************************
    Programme testé et validé :)
**************************************
 
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

// Je passe tout en variables afin de rendre le programme facilement paramétrable.

boolean etape1 = false;   // Étape 1 fausse et curseur > à 120° pour passer à vrai
boolean etape2 = false;   // Étape 2 fausse et curseur < à 60° pour passer à vrai, étape 1 désactivée
boolean etape3 = false;   // Étape 3 fausse et curseur entre 60° et 120° pour passer à vrai, étape 2 désactivé
                          // Une fois étape 3 vrai, commande ouverture à true et étape 3 retourne à false.

boolean openStatus = false ; // Ordre d'ouvre le coffre-fort (Faire clignoter la led :).

const int ledPin = 13 ;     // LED de Validation

const int servoPin = 9 ;    // La commande du servomoteur. a priori, pas nécessaire :).

const int potentiometrePin = A0 ;  // Branchement du potentiomètre
      int potentiometreValue ;     // Valeur analogique en entrée du potar (avant mpa :)
      int servoPos ;               // variable to store the servo position

const int delayValue = 5000 ;    // Durée d'un état de la led pour clignotement

const int seuilHaut = 120 ;
const int seuilBas = 60 ;



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  
}

void loop() {

  // --------------------------------------------------------------------------------
  // Gestion de la mesure du potentiomètre et du moniteur série (Menu Outils > Moniteur série)
  
  // read the analog in value:
  potentiometreValue = analogRead(potentiometrePin);  // lecture potar
  // map it to the range of the analog out:
  servoPos = map(potentiometreValue, 0, 1023, 0, 179);  // Position servo issue de map et séparée de la valeur du potar
                                                        // Plus lisible dans le Moniteur série :).
  // change the analog out value:

  // print the results to the serial monitor:
  Serial.print("Potentiomètre = ");
  Serial.print(potentiometreValue);
  Serial.print("\t output = ");
  Serial.print(servoPos);
  Serial.println(" °,");

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);

  // Note. Voir dans le moniteur série : Example : "Potentiomètre = 435   output = 76 °,"
  // ------------------------------------------------------------------------------------

  // ------------------------------------------------------------------------------------
  // Gestion de l'ouverture du coffre
      
  if (servoPos > seuilHaut && etape1 == false ) {

    etape1 = true ;   // Validation première condition
    Serial.println("Etape 1 ok ");    // Juste pour vérification à la mise en route.
    
  }

  if (servoPos < seuilBas && etape1 == true && etape2 == false) {

    etape2 = true ;   // Validation première condition
    Serial.println("Etape 2 ok ");    // Juste pour vérification à la mise en route.
    etape1 = false ; 
    
  }

  if (servoPos > seuilBas && servoPos < seuilHaut && etape2 == true && etape1 == false) {

    etape3 = true ;   // Validation première condition
    Serial.println("Etape 3 ok ");    // Juste pour vérification à la mise en route.
    etape2 = false ;

  // Je sépare l'étape de validation d'ouverture et l'ordre d'ouverture
    openStatus = true ;

  // Remise à 0 de létape 3 et remise à 0 de la validation de la combinaison
  etape3 = false ;
    
  }


  // ------------------------------------------------------------------------------------

  /*
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  */
  // ------------------------------------------------------------------------------------
  // Gestion de l'ouverture du coffre-fort - Faire clignoter la led
  
  if (openStatus == true) {    // ordre d'ouverture

  // Cycle de 3 clignotements 
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH) ;
    delay(delayValue);

    Serial.println("LED13 On");

    digitalWrite(ledPin, LOW  ) ;
    delay(delayValue);

    Serial.println("LED13 Off");
    
  // Remise à zéro de la variable
    openStatus = false ;    
  }
  // ------------------------------------------------------------------------------------
  }
  
}


/* José Relland - Janvier 2015
   
   Exercice MOOC - La Fabrication Numérique
   De l'Institut Les Mines - Telecom
   Sur la plateforme FUN : France Université Numérique.
   
   TP de la leçon N°2
   Cahier des Charges :
   Cours sur la gestion d'un bouton poussoir (Capteur numérique, tout ou rien)
      
   Note : Pas d'amélioration de prévu

Branchements :
Broche 2, branchée sur une résistance de mise à la masse (220 Ω) et sur BP avec retour au +5V.
LED rouge entre la broche 13 et la masse.
 
Remerciements à l'équipe du MOOC "La Fabrication Numérique" de l'Intitut Mines - Telecom.

Le présent programme est dans le domaine public.

*/

// Déclaration des entrées/sorties : Bouton-poussoir et LED
const int buttonPin = 2;
const int ledPin = 13;

// Variable bouton
int buttonState = 0;


// Fonction d'initialisation
void setup() {
  // Pin de la LED en sortie
  pinMode(ledPin, OUTPUT);
  
  // Pin du BP en entrée
  pinMode(buttonPin, INPUT);
  
}

// Fonction de travail qui tourne en boucle
void loop() {
  
  // Lecture de l'état de la variable liée au bouton
  buttonState = digitalRead(buttonPin);
  
  // Gestion de l'état de ce bouton
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

// Pas de caractère au-delà de l'accolage. 
}


/* José Relland - Janvier 2015
   
   Exercice MOOC - La Fabrication Numérique
   De l'Institut Les Mines - Telecom
   Sur la plateforme FUN : France Université Numérique.
   
   TP de la leçon N°2
   Cahier des Charges :
   Feux Tricolores (Rouge (3s) ; vert (3s) ; orange (1s)
      
   Note : Améliorations :
   1. Rendre la temporisation facilement modifiable
   2. Temporisation indépendante par couleur

Branchements :
Connexion des LED entre les broches de sorties et la masse (GND)
1. Verte : Broche Arduino 2
2. Jaune : Broche Arduino 4
3. Rouge : Broche Arduino 8
4. + 5 V : Broche Arduino "5V"
5. 0 V (Masse) : Broche Arduino "GND"

*/

// Paramétrage temps d'allumage/extinction LED

// Temps en millisecondes (1 000 ms = 1 secondes)
int LEDRougeTempo = 3000;
int LEDJauneTempo = 1000;
int LEDVerteTempo = 3000;

// Paramétrage Branchement LED
// Si vous modifier les branchements de la carte Arduino
// Mettre à jor les numéros de broche ci-dessous.
int LEDVerte = 2;
int LEDJaune = 4;
int LEDRouge = 8;


// Function SETUP
void setup() {
pinMode(LEDRouge, OUTPUT);
pinMode(LEDJaune, OUTPUT);
pinMode(LEDVerte, OUTPUT);

// Au démarrage, toutes les LED à LOW
digitalWrite(LEDRouge, LOW);
digitalWrite(LEDJaune, LOW);
digitalWrite(LEDVerte, LOW);
}

// Function MAIN
void loop() {
// Démarrage sur la LED rouge
digitalWrite(LEDRouge, HIGH);
delay (LEDRougeTempo);
digitalWrite(LEDRouge, LOW);

// Cycle du feu vert
digitalWrite(LEDVerte, HIGH);
delay (LEDVerteTempo);
digitalWrite(LEDVerte, LOW);

// Cycle du feu orange
digitalWrite(LEDJaune, HIGH);
delay (LEDJauneTempo);
digitalWrite(LEDJaune, LOW);

// Retrour au cycle du feu rouge 
// par retour du programme MAIN.

}

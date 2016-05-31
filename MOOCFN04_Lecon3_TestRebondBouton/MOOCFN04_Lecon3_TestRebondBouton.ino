/* José Relland - Janvier 2015
   
   Exercice MOOC - La Fabrication Numérique
   De l'Institut Les Mines - Telecom
   Sur la plateforme FUN : France Université Numérique.
   
   TP de la leçon N°3
   Cahier des Charges :
   Test des rebond du bouton poussoir
   - Compter les rebonds
   - Faire compter ces rebonds par la LED
   
   Note : Néant

Branchements :
Bouton poussoir en 2,
LED en 8.
 
Remerciements à l'équipe du MOOC "La Fabrication Numérique" de l'Intitut Mines - Telecom.

Le présent programme est dans le domaine public.
*/

// Déclaration de variables, constantes 
const int brocheBoutonooussoir = 2;
const int ledTest = 8;
int compteur = 0;
int etatBouton = 0;
int memoireBP = 0;

// Fonction d'initialisation
void setup() {
  pinMode(brocheBoutonooussoir, INPUT);
  pinMode(ledTest, OUTPUT);
  
}

// Fonction de travail qui tourne en boucle
void loop() {
  etatBouton = digitalRead(brocheBoutonooussoir);
  compteur = 0;
  while (etatBouton == HIGH) {
    // Incrémente le compteur
    compteur = compteur+1;  
    // C'est le nombre de passage du programme pendant l'appui
    // qui fait le nombre d'impulsions (et non le rebond mécanique
  etatBouton = digitalRead(brocheBoutonooussoir);  
} loop;
  
  // delay(1000);
  
  // Comptage des impulsions enregistrées
  while (compteur/100 != 0) {
    digitalWrite(ledTest, HIGH);
    delay(50);
    digitalWrite(ledTest, LOW);
    delay(50);
    compteur = compteur-100;
  } loop;

  // Pas de caractère au-delà de l'accolage. 
}


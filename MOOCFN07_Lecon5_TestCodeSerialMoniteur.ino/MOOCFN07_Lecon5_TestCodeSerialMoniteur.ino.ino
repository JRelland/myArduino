/* José Relland - Janvier 2015
   
   Exercice MOOC - La Fabrication Numérique
   De l'Institut Les Mines - Telecom
   Sur la plateforme FUN : France Université Numérique.
   
   TP de la leçon N°5
   Cahier des Charges :
   Essai de boucle affichées dans le serial monitor
   
   Note : Les questions

Branchements :
Juste le serial monitor
 
Remerciements à l'équipe du MOOC "La Fabrication Numérique" de l'Intitut Mines - Telecom.

Le présent programme est dans le domaine public.
*/

// Déclarations
int i = 0;
int j = 0;

// Fonction d'initialisation
void setup() {
  Serial.begin(9600);
}

// Fonction de travail qui tourne en boucle
void loop() {

  for(int i = 2; i < 8; i+=2) {
  Serial.println("bip bip");
  
  for(int j = 2; j < 50; j+=10) {
    Serial.print("meuh ");
    
  }
  Serial.println("");
  }
Serial.println("-------------------");
// Pas de caractère au-delà de l'accolage. 
delay(1000);
for(int i = 1; i <= 8; i++) {
  Serial.println("meuh");
}
}


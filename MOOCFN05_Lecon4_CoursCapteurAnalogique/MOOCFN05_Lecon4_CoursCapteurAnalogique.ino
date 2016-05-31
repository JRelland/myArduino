/* José Relland - Janvier 2015
   
   Exercice MOOC - La Fabrication Numérique
   De l'Institut Les Mines - Telecom
   Sur la plateforme FUN : France Université Numérique.
   
   TP de la leçon N°4 
   Cahier des Charges :
   Manip sur les capteurs analogiques
   
   Note : #La première bibliothèque

Branchements :
LED en ~9 (Sortie analogique)
Photorésistance en A0 (Entrée analogique)
 
Remerciements à l'équipe du MOOC "La Fabrication Numérique" de l'Intitut Mines - Telecom.

Le présent programme est dans le domaine public.
*/

// Déclaration de variables, constantes 
const int BrochePhotoResistance = A0;
const int BrochePilotageLed = 9;

int lumiereMesure = 0;
int lumiereAction = 0;

// Fonction d'initialisation
void setup() {

    // Initialise la communication serie de broches analogiques
    // Bibliothèque serial.
    Serial.begin(9600);
    
   
  // Branchements des broches
  pinMode(BrochePilotageLed, OUTPUT);
  pinMode(BrochePhotoResistance, INPUT);
  
}

// Fonction de travail qui tourne en boucle
void loop() {
 // Lire la valeur de la photorésistance
 // et stockage dans variable
 lumiereMesure = analogRead(BrochePhotoResistance);
 
 // Adapte la valeur entrée à la sortie 0 à 123 => 0 à 255
  lumiereAction = map(lumiereMesure, 0, 123, 0, 255); // Linéaire ? Si log ou autres relations ?
 
 // et envoi vers la sortie analogique (LED)
 analogWrite(BrochePilotageLed, lumiereAction); 
 
 // Envoi vers l'ordinateur
 Serial.print("sensor = " );                       
 Serial.print(lumiereMesure);      
 Serial.print("\t output = ");      
 Serial.println(lumiereAction);

// Pas de caractère au-delà de l'accolage. 
}


/* José Relland - Janvier 2015
 
 Exercice MOOC - La Fabrication Numérique
 De l'Institut Les Mines - Telecom
 Sur la plateforme FUN : France Université Numérique.
 
 TP de la leçon N°4 Réaliser un Thérémine  
 Cahier des Charges :
 A l'aide d'une photorésistance et d'un buzzer, faire de la musique 
 en fonction de l'éclairage de la photorésistance.
 
 Note : Pas de schéma ni de programme de base.
 S'inspirer du programme dans le cours.
 
 Branchements : Sur starter kit Arduino.
 Buzzer en ~9 (Sortie analogique)
 Photorésistance en A0 (Entrée analogique) 
 Note : Le buszzer s'alimente en 5 V.
 
 Note :  Avec le serial moniteur, on constate le bon fonctionnement des fréquences
 A0 à 0V, fréquence à 50 Hz ; A0 à 5V, fréquence à 30 000 Hz.
 Mais le buzzer ne donne pas vraiment les variations de fréquence attendues.
  (J'ai mis un potentionmètre pour vérifier les variations de fréquences)
  
 Remerciements à l'équipe du MOOC "La Fabrication Numérique" de l'Intitut Mines - Telecom.
 
 Le présent programme est dans le domaine public.
 */

// Déclaration de variables, constantes 
const int BrochePhotoResistance = A0;
const int BrocheBuzzer = 9;

int varMesureLumiere = 0;
int varAlimBuzzer = 0;

// Fonction d'initialisation
void setup() {

  // Initialise la communication serie de broches analogiques
  // Bibliothèque serial.
  Serial.begin(9600);

  // Branchements des broches
  pinMode(BrochePhotoResistance, INPUT);
  pinMode(BrocheBuzzer, OUTPUT);

}

// Fonction de travail qui tourne en boucle
void loop() {
  // Lire la valeur de la photorésistance
  // et stockage dans variable
  varMesureLumiere = analogRead(BrochePhotoResistance);

  // Adapte la valeur entrée à la sortie 0 à 1023 => 100 Hz à 10 000 Hz
  // Cette plage m'apparaît plus audible sur toute la gamme (Le buzzer)
  varAlimBuzzer = map(varMesureLumiere, 0, 1023, 20, 10000);

  // et envoi vers la sortie analogique (LED)
  tone(BrocheBuzzer, varAlimBuzzer);

  // Déclaration pour l'outil Serial Monitor
  // On voit bien les valeurs encadrées par la function map :)
  Serial.print("sensor = " );                       
  Serial.print(varMesureLumiere);      
  Serial.print("\t output = ");      
  Serial.println(varAlimBuzzer);

  // Pas de caractère au-delà de l'accolage. 
}



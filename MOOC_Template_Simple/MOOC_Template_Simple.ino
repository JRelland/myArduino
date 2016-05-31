/* José Relland - Janvier 2015
   
   Exercice MOOC - La Fabrication Numérique
   De l'Institut Les Mines - Telecom
   Sur la plateforme FUN : France Université Numérique.
   
   TP de la leçon N°5
   Cahier des Charges :
   Gestion d'une barrière et d'un feu bicolore.
   Feu rouge quand barrière abaissée (Angle servomoteur = 0°).
   BP pour ouvrir, barriére haute (Angle servomoteur = 90°), feu vert,
   Tempo 5 s., feu rouge et redescente.
   "Bouton appuye" dans le moniteur série
   Note sécurité : à la mise sous tension de la barrière, celle-ci se met en position ferméee.

Branchements :
Servomoteur en 9
Bouton poussoir en 2
Feu bicolore en 3 et 4
Moniteur serie.

*** Réalisé sur starter kit arduino ***

Remerciements à l'équipe du MOOC "La Fabrication Numérique" de l'Intitut Mines - Telecom.
Programme inspiré de Sweep, by BARRAGAN <http://barraganstudio.com> 
 
Le présent programme est dans le domaine public.
*/

// Paramétrage des broches
const int brocheServomoteur = 9;
const int brocheBP = 2;
const int brocheFeuRouge = 3;
const int brocheFeuVert = 4;

// Déclaration de variables, constantes 
int varPosBarriere = 0;
int varDemandePassage = 0;
int varTempoMouvementBarriere = 20;
int varTempoPassage = 5000;
int varTempoNonPassage = 5000;

// Appel de bibliothèques
#include <Servo.h> 

// Instanciation du servomoteur
Servo servoBarriere;

// Fonction d'initialisation
void setup() {

  // Initialisation des bibliothèque
Serial.begin(9600);

// Déclaration des branchements
servoBarriere.attach(brocheServomoteur);
pinMode(brocheBP,INPUT);
pinMode(brocheFeuRouge, OUTPUT);
pinMode(brocheFeuVert, OUTPUT);


// Sécurité : fermeture de la barrière à la mise en route si celle-ci ouverte
  Serial.println("Fermeture Barrière à la mise sous tension.");  
  for (varPosBarriere >= 90; varPosBarriere >= 0; varPosBarriere--) {
  servoBarriere.write(varPosBarriere);
  Serial.println(varPosBarriere);
  delay(varTempoMouvementBarriere);
  }

}

// Fonction de travail qui tourne en boucle
void loop() {

  // Feu rouge en début de cycle (et à la mise en route)
  digitalWrite(brocheFeuRouge, HIGH);
  digitalWrite(brocheFeuVert, LOW);
  
  // Détection d'un appel : traitement sinon retour à la boucle
  varDemandePassage = digitalRead(brocheBP);
   // Envoi de l'info sur le BRP au serial moniteur
  
  // Traitement de la demande
  if (varDemandePassage == 1) {
    Serial.println("Bouton appuyé");
    
  // Ouverture barrière
  Serial.println("Pilotage Ouverture Barrière : ");
  for (varPosBarriere = 0; varPosBarriere <= 90; varPosBarriere++) {
  Serial.println(varPosBarriere);          // Indique la position dans le serial moniteur
  servoBarriere.write(varPosBarriere);
  delay(varTempoMouvementBarriere);
}
   // Voir pour boucle de l'ouverture
   // Serial : varTestBarriere 
   
  digitalWrite(brocheFeuRouge, LOW);
  digitalWrite(brocheFeuVert, HIGH);
  
  delay(varTempoPassage);
  Serial.println("Fin ouverture");
  
  // Fermeture de la barrière
  digitalWrite(brocheFeuRouge, HIGH);
  digitalWrite(brocheFeuVert, LOW);
  
  Serial.println("Pilotage fermeture Barrière : ");  
  for (varPosBarriere = 90; varPosBarriere >= 0; varPosBarriere--) {
  servoBarriere.write(varPosBarriere);
  Serial.println(varPosBarriere);
  delay(varTempoMouvementBarriere);
  }
  // Tempo minimale pour ne pas relancer la barrière tout de suite.
  delay(varTempoNonPassage);
  Serial.println("Fin fermeture");
   }  
   // Fin de la boucle de traitement de demande de passage
  

// Pas de caractère au-delà de l'accolage. 
}


/* José Relland - Janvier 2015

*********************************************************
*      Message pour le correcteur du MOOC               *
* 1. J'ai voulu démarrer sur un feu orange              *
* 2. D'où gestion BP par deux tests :                   *
*  - Mémorisation de l'appui BP après Feu voiture Vert  *
*  - Traitement BP après le feu voiture orange          *
* => Traitement des feux par bloc unique                *
*    pour faciliter la maintenance du programme         *
*    (on est en programmation linéaire)                 *
*********************************************************
   
   Exercice MOOC - La Fabrication Numérique
   De l'Institut Les Mines - Telecom
   Sur la plateforme FUN : France Université Numérique.
   
   TP de la leçon N°3
   Cahier des Charges :
   Feu tricolore voiture, feu bicolore piéton, bouton piéton. 
   Appui sur bouton piéton quand feu vert voiture, passage au feu vert piéton quand feu voiture rouge 
   Après une temporisation de 5 s, retour au cycle feu voiture en commençant par le vert voiture.
   
   Note : Voir commentaire sur sécurité à l'init
   Il n'y a pas d'interruption de la fonction delay(), l'appui doit être maintenu 
   jusqu'à la fin du cycle feu vert.

Branchements :
Feu tricore en 10, 11, 12
Feu piéton en 8 et 9
BP en 2.
 
Remerciements à l'équipe du MOOC "La Fabrication Numérique" de l'Intitut Mines - Telecom.

Le présent programme est dans le domaine public.
*/

// Déclaration du câblage
  const int brocheFeuVoitureRouge = 12;
  const int brocheFeuVoitureOrange = 11;
  const int brocheFeuVoitureVert = 10;
  const int brocheFeuPietonRouge = 9;
  const int brocheFeuPietonVert = 8;
  const int brocheBoutonPieton = 2;

// Déclaration variable Bouton Piéton
  int etatBoutonPieton = 0;

// Variable des tempos
  int tempoVoitureOrange = 1000;
  int tempoVoitureVertRouge = 3000;
  int tempPietonVertRouge = 3000;
  int tempoPietonVert = 5000;
  
// Enregistrement de l'appui BP demande piéton
  int demandePieton = 0;
  
  
// Fonction d'initialisation
void setup() {

// Paramétrage des broches
  pinMode(brocheFeuVoitureRouge, OUTPUT);
  pinMode(brocheFeuVoitureOrange, OUTPUT);
  pinMode(brocheFeuVoitureVert, OUTPUT);
  pinMode(brocheFeuPietonRouge, OUTPUT);
  pinMode(brocheFeuPietonVert, OUTPUT);
  pinMode(brocheBoutonPieton, INPUT);

// Mise à LOW de toutes les sorties
  digitalWrite(brocheFeuVoitureRouge, LOW);
  digitalWrite(brocheFeuVoitureOrange, LOW);
  digitalWrite(brocheFeuVoitureVert, LOW);
  digitalWrite(brocheFeuPietonRouge, LOW);
  digitalWrite(brocheFeuPietonVert, LOW);
  
// Pour raison de sécurité, traitement Feu Piéton Rouge en priorité
  digitalWrite(brocheFeuPietonRouge, HIGH);
  digitalWrite(brocheFeuPietonVert, LOW);
}


// Fonction de travail qui tourne en boucle
void loop() {

  // Feu Voiture Orange 
  digitalWrite(brocheFeuVoitureOrange, HIGH);
  delay(tempoVoitureOrange);
  digitalWrite(brocheFeuVoitureOrange, LOW);
  
  // Traitement feu voiture rouge selon statut demande piéton
  // Note : Pour le premier cycle, demande à 0 par l'init
  if (demandePieton == 0) {
    // Pas de demande piéton, feu rouge voiture normal (avec feu piéton rouge)
    digitalWrite(brocheFeuVoitureRouge, HIGH);
    delay(tempoVoitureVertRouge);              // Tempo de 3 s.
    digitalWrite(brocheFeuVoitureRouge, LOW);
  }
  else {
    // Si demande piéton, feu voiture rouge et feu piéton vert
    digitalWrite(brocheFeuVoitureRouge, HIGH);
    digitalWrite(brocheFeuPietonVert, HIGH);
    digitalWrite(brocheFeuPietonRouge, LOW);
    delay(tempoPietonVert);                    // Tempo de 5 s.
    digitalWrite(brocheFeuPietonRouge, HIGH);
    digitalWrite(brocheFeuVoitureRouge, LOW);
    digitalWrite(brocheFeuPietonVert, LOW);
    
    // Remise à 0 de la demande piéton
    demandePieton = 0;
  }
  
  // Feu Voiture Vert
  digitalWrite(brocheFeuVoitureVert, HIGH);
  delay(tempoVoitureVertRouge);                // Tempo de 3 s
  digitalWrite(brocheFeuVoitureVert, LOW);

  // Gestion bouton piéton
  etatBoutonPieton = digitalRead(brocheBoutonPieton);
  if (etatBoutonPieton == HIGH) {
     demandePieton = 1;                        // Demande piéton mémoriser pour traitement après l'orange
  }

// Pas de caractère au-delà de l'accolage. 
}


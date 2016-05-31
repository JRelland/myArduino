/* José Relland - Janvier 2015
   
   Exercice MOOC - La Fabrication Numérique
   De l'Institut Les Mines - Telecom
   Sur la plateforme FUN : France Université Numérique.
   
   TP de la leçon N°3
   Cahier des Charges :
   Feu tricolore voiture, feu bicolore piéton, bouton piéton. 
   Appui sur bouton piéton quand feu vert voiture, passage au feu vert piéton quand feu voiture rouge 
   Après une temporisation de 5 s, retour au cycle feu voiture en commençant par le vert voiture.
   
   Note : 
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
  
}

// Fonction de travail qui tourne en boucle
void loop() {

  // Feu Piéton Rouge
  digitalWrite(brocheFeuPietonRouge, HIGH);
  
  // Feu Voiture Orange 
  digitalWrite(brocheFeuVoitureOrange, HIGH);
  delay(tempoVoitureOrange);
  digitalWrite(brocheFeuVoitureOrange, LOW);
  
  // Feu Voiture Rouge et feu vert piéton
  digitalWrite(brocheFeuVoitureRouge, HIGH);
  delay(tempoVoitureVertRouge);
  digitalWrite(brocheFeuVoitureRouge, LOW);
  
  // Feu Voiture Vert
  digitalWrite(brocheFeuVoitureVert, HIGH);
  delay(tempoVoitureVertRouge);
  digitalWrite(brocheFeuVoitureVert, LOW);

  // Gestion bouton piéton
  etatBoutonPieton = digitalRead(brocheBoutonPieton);
  if (etatBoutonPieton == HIGH) {
     digitalWrite(brocheFeuPietonRouge, LOW);
     digitalWrite(brocheFeuPietonVert, HIGH);
     digitalWrite(brocheFeuVoitureRouge, HIGH);
    
    // Tempo feu piéton
     delay(tempoPietonVert);
     digitalWrite(brocheFeuVoitureRouge, LOW);
     digitalWrite(brocheFeuPietonVert, LOW);
     digitalWrite(brocheFeuPietonRouge, HIGH);
    
    // Cycle du feu vert avant retour au cycle à partir de l'orange
    digitalWrite(brocheFeuVoitureVert, HIGH);
    delay(tempoVoitureVertRouge);
    digitalWrite(brocheFeuVoitureVert, LOW);
  }

// Pas de caractère au-delà de l'accolage. 
}


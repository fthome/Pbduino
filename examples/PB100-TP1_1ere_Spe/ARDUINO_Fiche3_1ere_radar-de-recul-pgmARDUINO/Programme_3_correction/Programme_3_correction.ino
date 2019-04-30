
/*******************************************************
Nom ......... : programme_3_correction.ino
Projet ...... : Formation Compétences Numériques - Réforme Lycée 2019
                Maquettes Pierron PB100-PB200-PB300
                PB100 : Déterminer la célérité d'une onde à l'aide d'un microcontrôleur
Role ........ : Programme pour maquette PB100
                L’écran LCD de la maquette PB100 affiche la distance entre le dispositif et un obstacle.
Auteur ...... : Patrice Buffet (patrice.buffet@ac-amiens.fr)
coAuteur .... : David Jung (djung@pierron.fr)
Ressources .. : https://www.pierron.fr
Version ..... : V2 du 30/04/2019
Licence ..... : CeCILL
********************************************************/


#include <LiquidCrystal_I2C.h>                   // on importe la bibliothèque.

LiquidCrystal_I2C EcranLCD(0x20,16,2);        // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB100.

const float VITESSE_SON = 340.0 / 100;     // Vitesse du son en cm/µs
const int pin_Trigger = 8;
const int pin_Echo = 9;
const int TIMEOUT = 600 / VITESSE_SON;  // TIMEOUT en µs (pour 600cm aller/retour)

void setup()                          // La fonction setup s'execute une seule fois au démarrage du programme.
{
    EcranLCD.begin(16, 2);            // on initialise la communication entre l'Arduino et l'afficheur (16 colonnes et 2 lignes).
    pinMode(pin_Trigger, OUTPUT);               // La broche 11 de la carte Arduino est reliée à l'Emetteur "E" (déclencheur de salves d'ondes ultrasonores).
    pinMode(pin_Echo, INPUT);                // La broche 12 de la carte Arduino reliée au Récepteur "R" (reçoit et mesure le temps de vol de la salve émise par E).
    digitalWrite(pin_Trigger, LOW);
}

void loop()                           // La fonction loop s'execute en boucle.
{
   unsigned long temps1;
   unsigned long duree_ar;
   unsigned long distance;

   digitalWrite(pin_Trigger, HIGH);             // met la broche TRIGGER à l'état haut
   delayMicroseconds(10);                       // pendant 10 microsecondes, pour envoi une salve d'ondes ultrasonores.
   digitalWrite(pin_Trigger, LOW);              // met la broche  TRIGGER à l'état bas, en attendant la prochaine boucle.

   while(digitalRead(pin_Echo) == LOW)
   {
     // Attente ECHO passe à l'état haut : la salve d'ondes ultrasonore est partie
   }
   temps1 = micros();                      // horloge interne en µs
   while(digitalRead(pin_Echo) == HIGH and micros() - temps1 < TIMEOUT)
   {
     // Attente ECHO passe à l'état bas : la salve d'ondes ultrasonore est revenue
   }

   duree_ar = micros() - temps1;           // Durée Aller-Retour en microsecondes (µs)

   distance = duree_ar * VITESSE_SON / 2;  // Distance en cm

   EcranLCD.clear();                               // Efface l'écran
   EcranLCD.setCursor(0, 0);                       // Positionne le curseur Colonne 0, Ligne 0
   EcranLCD.print("distance");               // Ecrit "temps A-R onde"
   EcranLCD.setCursor(0, 1);                       // Positionne le curseur Colonne 0, Ligne 1
   EcranLCD.print(" d = ");                        // Ecrit " t = "
   EcranLCD.setCursor(5, 1);                       // Positionne le curseur Colonne 5, Ligne 1
   EcranLCD.print(distance);                 // Afiche la distance qui sépare le télémètre à l'obstacle en cm
   EcranLCD.setCursor(11, 1);                      // Positionne le curseur Colonne 11, Ligne 1
   EcranLCD.print("cm");                           // Ecrit l'unité de la mesure "cm"
   delay(1000);                                    // Petite pause de 1 seconde avant de faire une autre mesure (= une autre boucle ici).
}

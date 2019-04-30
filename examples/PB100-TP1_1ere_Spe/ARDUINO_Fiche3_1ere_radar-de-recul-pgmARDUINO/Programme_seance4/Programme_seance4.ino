
// Formation Compétences numériques - Réforme Lycée 2019 -  
// Programme et maquette réalisés par patrice.buffet@ac-amiens.fr
// Maquette PB100 : Influence de la température de l'air sur la célérité d'une onde
// Positionnez la maquette à 2,00 mètres d'un obstacle.
// Mesurer le temps de vol pour deux Températures différentes (0°C et 20°C par exemple)
// Conclure : la température de l'air a-t-elle une influence sur la célérité d'une onde ultrasonore ?

#include <LiquidCrystal_I2C.h>                // on importe la bibliothèque.
LiquidCrystal_I2C EcranLCD(0x20,16,2);        // on crée l'objet EcranLCD, c'est l'afficheur LCD de la maquette PB100.


const int pin_E = 11;
const int pin_R = 12;

void setup()                          // La fonction setup s'execute une seule fois au démarrage du programme.
{                
    EcranLCD.begin(16, 2);            // on initialise la communication entre l'Arduino et l'afficheur (16 colonnes et 2 lignes).
    pinMode(pin_E, OUTPUT);               // La broche 11 de la carte Arduino est reliée à l'Emetteur "E" (déclencheur de salves d'ondes ultrasonores).
    pinMode(pin_R, INPUT);                // La broche 12 de la carte Arduino reliée au Récepteur "R" (reçoit et mesure le temps de vol de la salve émise par E).
    digitalWrite(pin_E, LOW);
}

void loop()                           // La fonction loop s'execute en boucle.     
{
   unsigned long temps1;
   unsigned long dureear;
   
   digitalWrite(pin_E, HIGH);             // met la broche 11 TRIGGER à l'état haut pendant 10 microsecondes, puis envoi une salve d'ondes ultrasonores.
   delayMicroseconds(10);             
   digitalWrite(pin_E, LOW);              // met la broche 11 TRIGGER à l'état bas, en attendant la prochaine boucle.

   temps1 = millis();
   while(pin_R == HIGH) 
   {
    // Attente retour ECHO
   }

   dureear = millis() - temps1;
   //unsigned long dureear = pulseIn(9, HIGH);    // Le dispositif reçoit l'ECHO de la salve sur la broche 12, mesure le temps de vol Aller-Retour en microsecondes,
                                                // et enregitre la valeur dans la variable nommée ici "dureear"(=durée aller retour).

EcranLCD.clear();                               // Efface l'écran
EcranLCD.setCursor(0, 0);                       // Positionne le curseur Colonne 0, Ligne 0
EcranLCD.print("Mesurez T en ");              // Ecrit "temps A-R onde"
EcranLCD.print((char)223);
EcranLCD.print("C"); 
EcranLCD.setCursor(0, 1);                       // Positionne le curseur Colonne 0, Ligne 1
EcranLCD.print(" t = ");                        // Ecrit " t = "
EcranLCD.setCursor(5, 1);                       // Positionne le curseur Colonne 5, Ligne 1
EcranLCD.print(dureear/1000.0);                 // Afiche la mesure du temps de vol de l'onde en millisecondes.
EcranLCD.setCursor(10, 1);                      // Positionne le curseur Colonne 10, Ligne 1
EcranLCD.print("ms");                           // Ecrit l'unité de la mesure "ms"
delay(1000);                                    // Petite pause de 1 seconde avant de faire une autre mesure (= une autre boucle ici).     
}

// Formation aux Compétences numériques - Réforme Lycée 2019 -  
// Concept, programmes et maquettes pensées par patrice.buffet@ac-amiens.fr, professeur et formateur Physique-Chimie.
// Fabrication et distribution PIERRON

// défi n°2 :
// Lorsque j’appuie sur le BP JAUNE, la led JAUNE s’allume.
// Lorsque j’appuie sur le BP ROUGE, la led ROUGE s’allume.
// Lorsque j’appuie sur le BP BLEU, la led BLEUE s’allume.
// Lorsque j’appuie sur le BP VERT, la led VERTE s’allume.

const int pin_led_jaune = 10;
const int pin_bp_jaune = 3;
const int pin_led_rouge = 9;
const int pin_bp_rouge = 4;
const int pin_led_bleue = 8;
const int pin_bp_bleu = 5;
const int pin_led_verte = 11;
const int pin_bp_vert = 2;

void setup(){
    pinMode(pin_bp_jaune,INPUT);
    pinMode(pin_bp_rouge,INPUT);
    pinMode(pin_bp_bleu,INPUT);
    pinMode(pin_bp_vert,INPUT);

    pinMode(pin_led_jaune,OUTPUT);
    pinMode(pin_led_rouge,OUTPUT);
    pinMode(pin_led_bleue,OUTPUT);
    pinMode(pin_led_verte,OUTPUT);
}

void loop(){
     if(digitalRead(pin_bp_jaune)==HIGH)
     {
        digitalWrite(pin_led_jaune,HIGH);
     }
     else
     {
        digitalWrite(pin_led_jaune,LOW);
     }
       
    if(digitalRead(pin_bp_rouge)==HIGH)
    {
        digitalWrite(pin_led_rouge,HIGH);
    }
    else
    {
        digitalWrite(pin_led_rouge,LOW);
    }
   
    if(digitalRead(pin_bp_bleu)==HIGH)
    {
        digitalWrite(pin_led_bleue,HIGH);
    }
    else
    {
        digitalWrite(pin_led_bleue,LOW);
    }
          
    if(digitalRead(pin_bp_vert)==HIGH)
    {
        digitalWrite(pin_led_verte,HIGH);
    }
    else
    {
        digitalWrite(pin_led_verte,LOW);
    }
}




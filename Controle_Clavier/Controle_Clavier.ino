/* 
Fichier : Controle_Clavier.ino
Auteur  : Rajith Rajathurai
Date    : 8 semptembre 2022
Titre   : TP1 - Robot 3D
But(s) du laboratoire:  Se familiariser avec les boucles de controle utilisant
                        la fonction Servo pour servomoteur.
*/
#include <Servo.h> // Librairie nÃ©cessaire pour les instructions du servo moteur

int Key; int CurrentServo; int Delay = 20;

Servo SERV_1; int Servo1_POS = 68;  // Position Initiale SERVO_1
Servo SERV_2; int Servo2_POS = 130; // Position Initiale SERVO_2
Servo SERV_3; int Servo3_POS = 120; // Position Initiale SERVO_3
Servo SERV_4; int Servo4_POS = 90;  // Position Initiale SERVO_4

int MotorSpeed_1 =  1.5; // Vitesse SERVO_1
int MotorSpeed_2 =  2;   // Vitesse SERVO_2
int MotorSpeed_3 =  5;   // Vitesse SERVO_3
int MotorSpeed_4 = 10;   // Vitesse SERVO_4

void setup() {
  pinMode(13, OUTPUT);  // DEL rouge
  Serial.begin (9600);  // initialize serial comms at 9600 baud
}

void detach_ALL(int Number){ // Detache toutes les ServoMotors
  CurrentServo = Number-48;
  Serial.print("Servo: " ); Serial.print(CurrentServo); Serial.println(" Active");

SERV_1.detach();
SERV_2.detach();
SERV_3.detach();
SERV_4.detach();
}

void loop() {
if (Serial.available()) {
Key = Serial.read();
//---------------------------------------------------------------------[[Touche pour changer de SERVO]]
       if (Key == '1') {
detach_ALL(Key);
SERV_1.attach(2);                                               //SERVO_1 Active

} else if (Key == '2') {
detach_ALL(Key);
SERV_2.attach(4);                                               //SERVO_2 Active

} else if (Key == '3') {
detach_ALL(Key);
SERV_3.attach(7);                                               //SERVO_3 Active

} else if (Key == '4') {
detach_ALL(Key);
SERV_4.attach(8);                                               //SERVO_4 Active

}
//---------------------------------------------------------------------[[Touche pour tourner a DROITE ou EN BAS]]
else if (Key == 'd' || Key == 'D' || Key == 's' || Key == 'S') {
  digitalWrite(13, HIGH); //DEL rouge en Mode HIGH
  
         if (CurrentServo == 1){                                               //Rotation DROITE SERVO_1
  if (Servo1_POS > -22) { Servo1_POS -= MotorSpeed_1;
     SERV_1.write(Servo1_POS);
     Serial.println(Servo1_POS);
     delay(Delay);
    }

  } else if (CurrentServo == 2){                                               //Rotation EN BAS SERVO_2
  if (Servo2_POS > 74) { Servo2_POS -= MotorSpeed_2;
     SERV_2.write(Servo2_POS);
     Serial.println(Servo2_POS);
     delay(Delay);
    }
      
  } else if (CurrentServo == 3){                                               //Rotation EN BAS SERVO_3
      if (Servo3_POS < 180) { Servo3_POS += MotorSpeed_3;
     SERV_3.write(Servo3_POS);
     Serial.println(Servo3_POS);
     delay(Delay);
    }
    
  } else if (CurrentServo == 4){                                               //Rotation EN BAS SERVO_4
        if (Servo4_POS > 0) { Servo4_POS -= MotorSpeed_4;
     SERV_4.write(Servo4_POS);
     Serial.println(Servo4_POS);
     delay(Delay);
    }

  }
//---------------------------------------------------------------------[[Touche pour tourner a GAUCHE ou EN HAUT]]
  digitalWrite(13, LOW);
} else if (Key == 'a' || Key == 'A' || Key == 'w' || Key == 'W') {
  digitalWrite(13, HIGH);
  
         if (CurrentServo == 1){                                               //Rotation GAUCHE SERVO_1
  if (Servo1_POS < 158) { Servo1_POS += MotorSpeed_1;
     SERV_1.write(Servo1_POS);
     Serial.println(Servo1_POS);
     delay(Delay);
    }

  } else if (CurrentServo == 2){                                               //Rotation EN HAUT SERVO_2
      if (Servo2_POS < 150){ Servo2_POS += MotorSpeed_2;
     SERV_2.write(Servo2_POS);
     Serial.println(Servo2_POS);
     delay(Delay);
    }
      
  } else if (CurrentServo == 3){                                               //Rotation EN HAUT SERVO_3
            if (Servo3_POS > 30){ Servo3_POS -= MotorSpeed_3;
     SERV_3.write(Servo3_POS);
     Serial.println(Servo3_POS);
     delay(Delay);
     }
     
  } else if (CurrentServo == 4){                                              //Rotation EN HAUT SERVO_4
            if (Servo4_POS < 180){ Servo4_POS += MotorSpeed_4;
     SERV_4.write(Servo4_POS);
     Serial.println(Servo4_POS);
     delay(Delay);
    }
    
 }
 
  digitalWrite(13, LOW); //DEL rouge en Mode LOW
  
}
}}

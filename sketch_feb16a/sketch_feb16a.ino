int rosso = 12;
int verde = 10;
int bianco = 8;
int giallo = 6;
int rossoGiallo = 0;
int biancoVerde = 0;

void setup() {
  Serial.begin(9600);
  pinMode(rosso,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(bianco,OUTPUT);
  pinMode(giallo,OUTPUT);

 if ( rossoGiallo == 0)
    {
     Richiesta1();
    }

 if ( biancoVerde == 0)
    {
      Richiesta2();
    }
}


void loop() { 
  DurataRossoGiallo();
  DurataBiancoVerde();
}



void Richiesta1(){
       Serial.println ("inserisci la durata dei colori rosso e giallo");
       while(Serial.available() == 0) {};
       rossoGiallo = Serial.readString().toInt();
       Serial.print ("il rosso e il giallo dureranno ");
       Serial.print (rossoGiallo);
       Serial.println (" millisecondi");
}


void Richiesta2(){
       Serial.println ("inserisci la durata dei colori bianco e verde");
       while(Serial.available() == 0) {};
       biancoVerde = Serial.readString().toInt();
       Serial.print ("il bianco e il verde dureranno ");
       Serial.print (biancoVerde);
       Serial.println (" millisecondi");
}

 void DurataRossoGiallo(){
  digitalWrite(rosso,HIGH);
  digitalWrite(giallo,HIGH);
  digitalWrite(verde,LOW);
  digitalWrite(bianco,LOW);
  delay(rossoGiallo);
  }

 void DurataBiancoVerde(){
  digitalWrite(rosso,LOW);
  digitalWrite(giallo,LOW);
  digitalWrite(verde,HIGH);
  digitalWrite(bianco,HIGH);
  delay(biancoVerde);
  }

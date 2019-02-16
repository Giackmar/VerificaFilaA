int rosso = 12;
int verde = 10;
int bianco = 8;
int giallo = 6;
int rossoGiallo = 0;
int biancoVerde = 0;
int cicli = 0;
int var1 = 0;
int var2 = 0;

void setup() {
   cicli = 0;
   var1 = 0;
   var2 = 0;
  Serial.begin(9600);
  pinMode(rosso,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(bianco,OUTPUT);
  pinMode(giallo,OUTPUT);

 if ( cicli == 0)
    {
     tempo();
    }
}


void loop() { 
  randomi();
  met();
}



void tempo(){
       Serial.println ("fra quanti cicli vuoi che cambino le durate dei led?");
       while(Serial.available() == 0) {};
       cicli = Serial.readString().toInt();
       Serial.print ("le durate dei led cambieranno fra ");
       Serial.print (cicli);
       Serial.println (" cicli");
       if (cicli <= 0) {
        reset();
        tempo();
       }
}


void met(){
  int i =0;
  while (i < cicli){
    i++;
    DurataRossoGiallo();
    DurataBiancoVerde();
  }
  setup();
}

void randomi(){
  var1 = random(0,5000);
  var2 = random(0,5000);
}


 void DurataRossoGiallo(){
  digitalWrite(rosso,HIGH);
  digitalWrite(giallo,HIGH);
  digitalWrite(verde,LOW);
  digitalWrite(bianco,LOW);
  delay(var1);
  }

 void DurataBiancoVerde(){
  digitalWrite(rosso,LOW);
  digitalWrite(giallo,LOW);
  digitalWrite(verde,HIGH);
  digitalWrite(bianco,HIGH);
  delay(var2);
  }

  void reset(){
  digitalWrite(rosso,LOW);
  digitalWrite(giallo,LOW);
  digitalWrite(verde,LOW);
  digitalWrite(bianco,LOW);
  }

  

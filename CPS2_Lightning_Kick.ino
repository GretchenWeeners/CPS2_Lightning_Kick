





int dr0;
int dr1;
int dr2;
int dr3;
int switched = 0;
static unsigned long lastsecs = -1; // pre-initialize with non zero value
unsigned long secs;


void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}

ISR (PCINT0_vect) // handle pin change interrupt for D0 to D7 here
 {


     secs = millis() / 100;
     lastsecs = secs; // keep track of last seconds

     dr0 = digitalRead(10);
     dr1 = digitalRead(11);
     dr2 = digitalRead(12);
     dr3 = digitalRead(13);
     Serial.print(dr0);
     Serial.print(dr1);
     Serial.print(dr2);
     Serial.print(dr3);
     Serial.println();

     switched = 0;
      
 }  

void setup()
{

  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  
  pinMode(8, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  
  pciSetup(8);
  Serial.begin(115200);
 

}

void loop()
{
   if(switched == 0)
   {
     
     secs = millis() / 100;
     if(secs != lastsecs)
     {
      switched = 1; // keep track of last seconds
      if(dr0 == 0 && dr1 == 1 & dr2 == 0 & dr3 == 0)
      {
        Serial.println();
        Serial.print("2 player");
        digitalWrite(7, HIGH);
      } else if(dr0 == 1 && dr1 == 1 & dr2 == 0 & dr3 == 0)
      {
        Serial.println();
        Serial.print("3 player");
        digitalWrite(7, LOW);
      } else if(dr0 == 0 && dr1 == 0 & dr2 == 1 & dr3 == 0)
      {
        Serial.println();
        Serial.print("4 player");
        digitalWrite(7, LOW);
      }
      
      Serial.println();
     }
   }    
}

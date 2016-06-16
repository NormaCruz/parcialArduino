#include <Servo.h>


#define pulsador 5
#define pulsador2 4
//#define MovPin 11

#define ledV 12
#define ledR 11
//#define LedA 4

Servo pluma;
 


int contador1;
int contador2;
int abierto=0;
int movimiento = 0;


int pir = 7; //sensor pir

int estado1 = HIGH;
int estado2 = HIGH;

void setup() {
Serial.begin(9600);

pluma.attach(8);

pinMode(ledV,OUTPUT);
pinMode(ledR,OUTPUT);


pinMode(pir,INPUT);
pinMode(pulsador2,INPUT);
pinMode(pulsador,INPUT);
//delay(4000); //tiempo de espera para inicializar el sensor.

pluma.write(0);
}






void loop() {
  
  
 
   /*contador1 = digitalRead(pulsador);
   contador2 = digitalRead(pulsador2);*/
   
   if((contador1 > 10) || (contador2 > 10))
    {
      contador1 = 0;
      contador2 = 0;
    }
    
    if (abierto == 0 )
  {
    digitalWrite(ledR, HIGH);//led rojo
    digitalWrite(ledV,LOW); //led verde
  
  
  if(movimiento == 1)
      {
        int i = 0;
        for (i=0; i<3; i++)
          {
            digitalWrite(ledR, HIGH);
            delay(200);
            digitalWrite(ledV, LOW);
            delay(800);
          }
         movimiento = 0;
      }
      
  }
  
  else
  {
    digitalWrite(ledV, HIGH); //led verde
    digitalWrite(ledR, LOW);//led rojo
  }
  
    
    
  
  
    if(digitalRead(pulsador) != estado1 )
    {
      contador1++;
     
         Serial.print(contador1);
    Serial.print(" - ");
    Serial.println(contador2);
     delay(1000); 
    }

    if(digitalRead(pulsador2) != estado2)
    {
      contador2++;
     
        Serial.print(contador1);
    Serial.print(" - ");
    Serial.println(contador2);
      delay(1000);
    }
    
    estado1 = digitalRead(pulsador);
     estado2 = digitalRead(pulsador2);

  
  
  if((contador1 == 3) && (contador2 == 2))
  {
    pluma.write(180);
   digitalWrite(ledV, HIGH); //led verde
   digitalWrite(ledR, LOW);//led rojo
    
    abierto= 1;
    contador1 = 0;
    contador2 = 0;
  }
  
  /*else
  {
    digitalWrite(ledR, HIGH); //led rojo
    digitalWrite(ledV,LOW); // led verde
  } */ 
  
  if((contador1 == 4 ) && (contador2 == 3))
  {
    pluma.write(0);
    digitalWrite(ledR, HIGH);//led rojo
    digitalWrite(ledV,LOW); //led verde
    
    abierto = 0;
    contador1 = 0;
    contador2 = 0;
    
  }
  
  if((digitalRead(pir) == HIGH) && (abierto == 0))
         {
           movimiento = 1;
          
         } 
  
   
   
}

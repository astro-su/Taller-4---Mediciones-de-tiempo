#include <TimerOne.h>
int p1=24;
int p2=25;
int p3=26;
int led1=27;
int led2=28;
int led3=29;
  

void setup() {
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(p1,INPUT);
 pinMode(p2,INPUT);
 pinMode(p3,INPUT);

 
 digitalWrite(led1,0);
 digitalWrite(led2,0);

}

/* punto 1 */
void parpadea(){
 if(digitalRead(led1)==1){
  digitalWrite(led1,0);
} 
 else{
  digitalWrite(led1,1);
  }
}

void punto1(){
  Timer1.initialize(500000);
  Timer1.attachInterrupt(parpadea);
} 

/* punto 2 */

void parpadea2(){
 if(digitalRead(led2)==1){
  digitalWrite(led2,0);
} 
 else{
  digitalWrite(led2,1);
  }
}

void punto2(){
  Timer1.initialize(500000);
  Timer1.attachInterrupt(parpadea2);
} 

void apagado(){
  while ((digitalRead(led1)==1)||(digitalRead(led2)==1)){
    Timer1.stop();
    digitalWrite(led1,0);
    digitalWrite(led2,0);
  }
}


void loop() {
  if (digitalRead(p1)==1){
    punto1();
  }
  if (digitalRead(p2)==1){
    punto2();
  } 
  if (digitalRead(p3)==1){
    apagado();
  }
}


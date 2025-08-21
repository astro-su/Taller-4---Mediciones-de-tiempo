#include <TimerOne.h>

int S1 = 53;
int S2 = 52;
int inicio = 24;

unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempo3 = 0;
unsigned long tiempo4 = 0;
unsigned long tiempo5 = 0;

unsigned long mrtea = 0;

unsigned long times[5];

void conteo() {
  mrtea++;
}

void setup() {
  Serial.begin(9600);
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(inicio, INPUT);
  Serial.println("pulsa 24 para iniciar");
  Timer1.initialize(1000);
}

void medir() {
  // tiempo 1
  while (digitalRead(S1) == LOW) {}
  noInterrupts(); 
  mrtea = 0; 
  interrupts();
  Timer1.attachInterrupt(conteo);
  while (digitalRead(S2) == LOW) {}
  Timer1.detachInterrupt();
  tiempo1 = mrtea;
  Serial.println("midiendo tiempo 1...");
  //Serial.print("Tiempo 1: "); 
  //Serial.print(tiempo1);
  // Serial.println(" ms");
  times[0] = tiempo1;

  // tiempo 2
  while (digitalRead(S1) == LOW) {}
  noInterrupts(); 
  mrtea = 0; 
  interrupts();
  Timer1.attachInterrupt(conteo);
  while (digitalRead(S2) == LOW) {}
  Timer1.detachInterrupt();
  tiempo2 = mrtea;
  Serial.println("midiendo tiempo 2...");
  //Serial.print("Tiempo 2: "); 
  //Serial.print(tiempo2); 
  //Serial.println(" ms");
  times[1] = tiempo2;

  // tiempo 3
  while (digitalRead(S1) == LOW) {}
  noInterrupts(); 
  mrtea = 0; interrupts();
  Timer1.attachInterrupt(conteo);
  while (digitalRead(S2) == LOW) {}
  Timer1.detachInterrupt();
  tiempo3 = mrtea;
  Serial.println("midieno tiempo 3...");
  //Serial.print("Tiempo 3: "); 
  //Serial.print(tiempo3); 
  //Serial.println(" ms");
  times[2] = tiempo3;

  // tiempo 4
  while (digitalRead(S1) == LOW) {}
  noInterrupts(); 
  mrtea = 0; interrupts();
  Timer1.attachInterrupt(conteo);
  while (digitalRead(S2) == LOW) {}
  Timer1.detachInterrupt();
  tiempo4 = mrtea;
  Serial.println("midiendo tiempo 4...");
  //Serial.print("Tiempo 4: "); 
  //Serial.print(tiempo4); 
  //Serial.println(" ms");
  times[3] = tiempo4;

  // tiempo 5
  while (digitalRead(S1) == LOW) {}
  noInterrupts(); 
  mrtea = 0; interrupts();
  Timer1.attachInterrupt(conteo);
  while (digitalRead(S2) == LOW) {}
  Timer1.detachInterrupt();
  tiempo5 = mrtea;
  Serial.println("midiendo tiempo 5...");
  //Serial.print("Tiempo 5: "); 
  //Serial.print(tiempo5); 
  //Serial.println(" ms");
  times[4] = tiempo5;
}

void loop() {
  if (digitalRead(inicio) == HIGH) {   
    Serial.println("Iniciando..., pase el objeto por los sensores");
    medir();
    delay(500);

    // el array
    int pepsi = sizeof(times) / sizeof(times[0]); 
    for (int i = 0; i < pepsi; i++) {
      Serial.print("Tiempo ");
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(times[i]);  
      Serial.println(" ms");
    }

    // calcular promedio
    unsigned long cocaCola = 0;
    for (int i = 0; i < 5; i++) {
      cocaCola = cocaCola + times[i];
    }
    unsigned long promedio = cocaCola / 5;
    Serial.print("Promedio: ");
    Serial.print(promedio);
    Serial.print(" ms");

   
  }
}
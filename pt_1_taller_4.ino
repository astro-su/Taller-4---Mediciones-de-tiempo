#include <TimerOne.h>
int s1=53;
int s2=52;
int inicio=24;
volatile unsigned long contadorTiempo = 0;

unsigned long tiempoInicio = 0;
unsigned long tiempoFin = 0;

bool detectado1 = false;
bool detectado2 = false;

float distancia_cm = 2.51;

void contarTiempo(){
  contadorTiempo += 10;
}

void setup() {
  Serial.begin(9600);
  
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  
  Timer1.initialize(10);
  Timer1.attachInterrupt(contarTiempo);

  
  Serial.println("Sistema listo. Ingresa nuevo diametro de la moneda en cm:");
}

void loop() {
  int s1E = digitalRead(s1);
  int s2E = digitalRead(s2);

  if (!detectado1 && s1E == HIGH) {
    noInterrupts();
    tiempoInicio = contadorTiempo;
    interrupts();
    detectado1 = true;
    Serial.println("Sensor 1 activado");
  }

  if (detectado1 && !detectado2 && s2E == HIGH) {
    noInterrupts();
    tiempoFin = contadorTiempo;
    interrupts();
    detectado2 = true;
    Serial.println("Sensor 2 activado");

    unsigned long tiempoMicro = tiempoFin - tiempoInicio;
    float tiempoSegundos = tiempoMicro / 1000000.0;

    float g = 2 * (distancia_cm / 100.0) / (tiempoSegundos * tiempoSegundos);

    Serial.print("Tiempo: ");
    Serial.print(tiempoSegundos, 4);
    Serial.println(" s");
  
    Serial.print("g calculado: ");
    Serial.print(g, 4);
    Serial.println(" m/s^2");
    
    delay(200);
    detectado1 = false;
    detectado2 = false;
    contadorTiempo = 0;
  }
}

#define DISTANCIA_ENTRE_SENSORES_CM 50

unsigned long startTime;
unsigned long endTime;
unsigned long timeDiff;
float velocidade;

void setup() {
  Serial.begin(9600);
}

void loop() {
  startTime = micros();
  delay(1000);
  endTime = micros();
  timeDiff = endTime - startTime;

  velocidade = ((float)DISTANCIA_ENTRE_SENSORES_CM / ((float)timeDiff / 1000000.0)) * 3.6;

  Serial.print("Velocidade do objeto: ");
  Serial.print(velocidade);
  Serial.println(" km/h");

  delay(1000);
}

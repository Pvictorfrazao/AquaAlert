const int startSensorEchoPin = 2; 
const int endSensorEchoPin = 3;

unsigned long startTime = 0; 
unsigned long endTime = 0;
bool startDetected = false; 
bool endDetected = false; 
double velocidade; 
double distSens = 50; // Distância entre os sensores
double fatorParaSegundos = 1000.0; // Fator de conversão para segundos (milissegundos)

void setup() {
  Serial.begin(9600);
  pinMode(startSensorEchoPin, INPUT);
  pinMode(endSensorEchoPin, INPUT);
}

void loop() {
  // Lógica de detecção do sensor de início
  if (digitalRead(startSensorEchoPin) == HIGH && !startDetected) {
    startTime = millis();
    startDetected = true;
    Serial.println("Objeto detectado no sensor de início.");
  }

  // Lógica de detecção do sensor de final
  if (digitalRead(endSensorEchoPin) == HIGH && startDetected && !endDetected) {
    endTime = millis();
    endDetected = true;
    Serial.println("Objeto detectado no sensor de final.");
  }

  // Cálculo da velocidade quando ambos os pontos foram detectados
  if (startDetected && endDetected) {
    double tempo = (endTime - startTime) / fatorParaSegundos; 
    velocidade = (distSens / tempo) * 3.6; // Velocidade em km/h
    Serial.print("Tempo: ");
    Serial.print(tempo);
    Serial.println("s");
    Serial.print("Velocidade: ");
    Serial.print(velocidade);
    Serial.println("km/h");
    
    
    startDetected = false;
    endDetected = false;
  }
}

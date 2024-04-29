/* Constantes pour les broches */
const byte TRIGGER_PIN = 10; // Broche TRIGGER
const byte ECHO_PIN = 12;    // Broche ECHO
const int ledPin = 8;
const int Buzzer = 6;
int freqmin = 20000; //La fréquence plus basse à émettre
 
/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

void setup() {
   
  /* Initialise le port série */
  Serial.begin(9600);
   
  /* Initialise les broches */
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
  pinMode(ledPin, OUTPUT);
   pinMode(Buzzer, OUTPUT);
}
void loop() {
  
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  float distance_mm = measure / 2.0 * SOUND_SPEED;
   
  /* Affiche les résultats en mm, cm et m */
  Serial.print(F("Distance: "));
  Serial.print(distance_mm);
  Serial.print(F("mm ("));
  Serial.print(distance_mm / 10.0, 2);
  Serial.print(F("cm, "));
  Serial.print(distance_mm / 1000.0, 2);
  Serial.println(F("m)"));
   
  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(500);

  if(distance_mm  >= 200 ){
    if(distance_mm  <=1000){
    digitalWrite(ledPin, HIGH);
    tone(6,freqmin);
    delay(500);
    digitalWrite(ledPin, LOW);
    noTone(6);
    }
  }
  if(distance_mm  <200){
    if(distance_mm  >=150){
    digitalWrite(ledPin, HIGH);
    tone(6,freqmin);
    delay(300);
    digitalWrite(ledPin, LOW);
    noTone(6);
    }
  }
  if(distance_mm  <150){
    if(distance_mm  >=100){
    digitalWrite(ledPin, HIGH);
    tone(6,freqmin);
    delay(200);
    digitalWrite(ledPin, LOW);
    noTone(6);
    }
  }
  if(distance_mm  <100){
    if(distance_mm  >=50){
    digitalWrite(ledPin, HIGH);
    tone(6,freqmin);
    delay(100);
    digitalWrite(ledPin, LOW);
    noTone(6);
    }
  }
  if(distance_mm  <50){
    if(distance_mm  >=0){
    digitalWrite(ledPin, HIGH);
    tone(6,freqmin);
  }
  }
}
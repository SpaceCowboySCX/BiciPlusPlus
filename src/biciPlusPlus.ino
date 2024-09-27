#include <Adafruit_NeoPixel.h>
#define NUMBER_LEDS 10
#define INTERMITTENT_SPEED 100

// Pin collegato alla striscia LED
#define LED_PIN 6

// Pin dello switch a 3 stati
#define SWITCH_LEFT 2
#define SWITCH_RIGHT 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Imposta i pin dello switch come input
  pinMode(SWITCH_LEFT, INPUT);
  pinMode(SWITCH_RIGHT, INPUT);
  
  strip.begin();
  strip.show();
}

void loop() {
  bool leftSignal, rightSignal;
  
  // Se l'interruttore è su sinistra (scorrimento da destra a sinistra)
  while (leftSignal == HIGH && rightSignal == LOW) {
    slideLeftToRight();
    readSwitchSignal();
  }
  // Se l'interruttore è su destra (scorrimento da sinistra a destra)
  while (leftSignal == LOW && rightSignal == HIGH) {
    slideRightToLeft();
    readSwitchSignal();
  }
  // Se l'interruttore è nella posizione centrale, spegni i LED
  if (leftSignal == LOW && rightSignal == LOW) {
    strip.clear(); // Spegne i LED
    strip.show();
  }
}

void readSwitchSignal() {
    leftSignal = digitalRead(SWITCH_LEFT);   // Aggiorna lo stato dell'interruttore
    rightSignal = digitalRead(SWITCH_RIGHT); // Aggiorna lo stato dell'interruttore
}

// Funzione per creare lo slide, il parametro i indica i-esimo LED da accendere 
void slide(int i){
  strip.clear(); // Spegne i LED prima di ogni ciclo
  strip.setPixelColor(i, strip.Color(255, 0, 0)); // Illumina il LED corrente di rosso
  strip.show();
  delay(INTERMITTETNT_SPEED); 
}
// Funzione per creare lo slide da destra verso sinistra
void slideLeftToRight() {
  for (int i = NUM_LEDS - 1; i >= 0; i--)
    slide(i);
}
// Funzione per creare lo slide da sinistra verso destra
void slideRightToLeft() {
  for (int i = 0; i < NUM_LEDS; i++)
    slide(i);
}

#include <Adafruit_NeoPixel.h>
// Definisci il numero di LED nella striscia
#define NUM_LEDS 10
#define INTERMITTETNT_SPEED 100

// Definisci il pin collegato alla striscia LED
#define LED_PIN 6

// Definisci i pin dello switch a 3 stati
#define SWITCH_LEFT 2
#define SWITCH_RIGHT 3

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // Imposta i pin dello switch come input
  pinMode(SWITCH_LEFT, INPUT);
  pinMode(SWITCH_RIGHT, INPUT);
  
  // Inizializza la striscia LED
  strip.begin();
  strip.show(); // Spegne tutti i LED all'inizio
}

void loop() {
  // Leggi lo stato dei due pin dello switch
  bool leftSignal = digitalRead(SWITCH_LEFT);
  bool rightSignal = digitalRead(SWITCH_RIGHT);
  
  // Se l'interruttore è su sinistra (scorrimento da destra a sinistra)
  while (leftSignal == HIGH && rightSignal == LOW) {
    slideLeftToRight(); // Continua l'effetto di scorrimento
    leftSignal = digitalRead(SWITCH_LEFT);   // Aggiorna lo stato dell'interruttore
    rightSignal = digitalRead(SWITCH_RIGHT); // Aggiorna lo stato dell'interruttore
  }
  
  // Se l'interruttore è su destra (scorrimento da sinistra a destra)
  while (leftSignal == LOW && rightSignal == HIGH) {
    slideRightToLeft(); // Continua l'effetto di scorrimento
    leftSignal = digitalRead(SWITCH_LEFT);   // Aggiorna lo stato dell'interruttore
    rightSignal = digitalRead(SWITCH_RIGHT); // Aggiorna lo stato dell'interruttore
  }

  // Se l'interruttore è nella posizione centrale, spegni i LED
  if (leftSignal == LOW && rightSignal == LOW) {
    strip.clear(); // Spegne i LED
    strip.show();
  }
}

// Funzione per creare loo slide, il parametro i indica i-esimo LED da accendere 
void slide(int i){
  strip.clear(); // Spegne i LED prima di ogni ciclo
  strip.setPixelColor(i, strip.Color(255, 0, 0)); // Illumina il LED corrente di rosso
  strip.show();
  delay(INTERMITTETNT_SPEED); 
}

// Funzione per creare lo slide da destra verso sinistra
void slideLeftToRight() {
  for (int i = NUM_LEDS - 1; i >= 0; i--)
    slide(i)
}

// Funzione per creare lo slide da sinistra verso destra
void slideRightToLeft() {
  for (int i = 0; i < NUM_LEDS; i++)
    slide(i)
}

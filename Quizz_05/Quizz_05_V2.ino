//QUIZZ 05 "A QUOI SERVENT CES PLUMES ?"
#include <Adafruit_NeoPixel.h>

const int numPixels = 24;
const int pixelPin = 10;
Adafruit_NeoPixel ring = Adafruit_NeoPixel(numPixels, pixelPin);
uint32_t VERT = ring.Color(0x00, 0xFF, 0x00); // r, g, b - vert
uint32_t ROUGE = ring.Color(0xFF, 0x00, 0x00); // rouge
uint32_t ETEINT = ring.Color(0x00, 0x00, 0x00); // eteint

const int questions[] = {14, 15, 16, 17, 18, 19}; // Boutons des questions {A0, A1, A2, A3, A4, A5}
const int reponses[] = {2, 3, 4, 5, 6, 7}; // Boutons des réponses
const int  attendre = (5);

const int correspondances[][6] = {
    {-1, 3, -1, -1, -1, -1}, // Solutions question 1 
    {2, -1, -1,  -1, -1, -1}, // Solutions question 2 
    {-1, -1, -1, -1, -1, 7}, // Solutions question 3 
    {-1, -1, 4, -1, -1, -1}, // Solutions question 4 
    {-1, -1, -1, -1, 6, -1}, // Solutions question 5 
    {-1, -1, -1, 5, -1, -1} // Solutions question 6 
 };
const int nbQuestions = sizeof(questions) / sizeof(questions[0]);
const int nbReponses = sizeof(reponses) / sizeof(reponses[0]);
const int maxReponses = sizeof(correspondances[0]) / sizeof(correspondances[0][0]);

void setup() {
    Serial.begin(9600);
    pinMode(pixelPin, OUTPUT);
    
    for (int i = 0; i < nbQuestions; i++) {
        pinMode(questions[i], INPUT_PULLUP);
    }
    for (int i = 0; i < nbReponses; i++) {
        pinMode(reponses[i], INPUT_PULLUP);
    }
}

void loop() {
    int questionAppuyee = -1;
    int reponseAppuyee = -1;
    int nbBoutonsAppuyes = 0;

    for (int i = 0; i < nbQuestions; i++) {
        if (digitalRead(questions[i]) == LOW) {
            questionAppuyee = i;
            nbBoutonsAppuyes++;
        }
    }
    
    for (int j = 0; j < nbReponses; j++) {
        if (digitalRead(reponses[j]) == LOW) {
            reponseAppuyee = reponses[j];
            nbBoutonsAppuyes++;
        }
    }
    
    if (nbBoutonsAppuyes == 2 && questionAppuyee != -1 && reponseAppuyee != -1) {
        bool bonneReponse = false;
        for (int k = 0; k < maxReponses; k++) {
            if (correspondances[questionAppuyee][k] == reponseAppuyee) {
                bonneReponse = true;
                break;
            }
        }
        if (bonneReponse) {
            for (int i = 0; i < numPixels; i++) {
            ring.setPixelColor(i, VERT); // set pixel i to foreground
            ring.show();                       // actually display it
            delay(attendre);                         // milliseconds 
            Serial.println("correcte");
            } 
        } else {
            for (int i = 0; i < numPixels; i++) {
            ring.setPixelColor(i, ROUGE); // set pixel i to foreground
            ring.show();                       // actually display it
            delay(attendre);                         // milliseconds 
            Serial.println("faux");
        }
      } 
    } else {
        for (int i = 0; i < numPixels; i++) {
        ring.setPixelColor(i, ETEINT); // set pixel i to foreground
        ring.show();                       // actually display it
        delay(attendre);                         // milliseconds 
        Serial.println("eteint");
        } 
    }
}

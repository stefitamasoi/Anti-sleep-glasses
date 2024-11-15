#include "pitches.h"
int Sinput = A1;
int BUZZER_PIN = 3;
int LED = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(Sinput, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

int melody[] = {
  NOTE_E5, NOTE_D5, NOTE_FS4, NOTE_GS4,
  NOTE_CS5, NOTE_B4, NOTE_D4, NOTE_E4,
  NOTE_B4, NOTE_A4, NOTE_CS4, NOTE_E4,
  NOTE_A4
};

int durations[] = {
  8, 8, 4, 4,
  8, 8, 4, 4,
  8, 8, 4, 4,
  2
};




void loop() {

  if (digitalRead(Sinput) == LOW) {
    delay(2000);  // we are waiting for two second after the input pulse from the sensor. if the pulse is for more than  2 second then buzzer get triggered
    if (digitalRead(Sinput) == LOW) {
      //digitalWrite(BUZZER_PIN, HIGH);
      int size = sizeof(durations) / sizeof(int);

      for (int note = 0; note < size; note++) {
        //to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int duration = 1000 / durations[note];
        tone(BUZZER_PIN, melody[note], duration);

        //to distinguish the notes, set a minimum time between them.
        //the note's duration + 30% seems to work well:
        int pauseBetweenNotes = duration * 1.30;
        delay(pauseBetweenNotes);

        //stop the tone playing:
        noTone(BUZZER_PIN);
      }
    }
  } else {

    if (digitalRead(Sinput) == HIGH) {

      digitalWrite(BUZZER_PIN, LOW);
    }
  }
}
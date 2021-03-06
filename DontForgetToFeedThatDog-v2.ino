

// -----------------------------------------------------------------------------------------
// INCLUDES
// -----------------------------------------------------------------------------------------


#include <mthread.h> // for multi-thread capabilities 

#include
<TimedAction.h>
  #include "pitches.h" // THIS IS FOR THE TONES



// -----------------------------------------------------------------------------------------
// GLOBAL VARIABLES
// -----------------------------------------------------------------------------------------




// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

const int morningLight = 6; // red led
const int eveningLight = 5; // yellow led
const int resetButton = 12; // farthest from buzzer
const int doorButton = 13; // closest to buzzer
const int buzzer = 9; // closest to buzzer

int doorButtonSwitchState = 0;
int resetButtonSwitchState = 0;

int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated
long interval = 1000;



void setup() {

  pinMode(morningLight, OUTPUT);
  pinMode(eveningLight, OUTPUT);
  pinMode(resetButton, INPUT);
  pinMode(doorButton, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  }

}

void loop() {
  // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >
    interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // set the LED with the ledState of the variable:
    digitalWrite(morningLight, ledState);
  }







  

  doorButtonSwitchState = digitalRead(doorButton);
  Serial.println("doorButtonSwitchState: " + doorButtonSwitchState);
  //  Serial.print("resetButton: "+resetButton);

  //  if (doorButtonSwitchState == HIGH) {
  //    digitalWrite(eveningLight, LOW);
  //  } else {
  //    digitalWrite(eveningLight, HIGH);
  //  }

  //   doorButtonSwitchState = digitalRead(doorButton);   // read the input pin
  //  digitalWrite(eveningLight, doorButtonSwitchState);
  resetButtonSwitchState = digitalRead(resetButton);
  Serial.println("resetButtonSwitchState: " + resetButtonSwitchState);
  //  Serial.print("resetButton: "+resetButton);

  //  if (resetButtonSwitchState == HIGH) {
  //    digitalWrite(morningLight, HIGH);
  //  } else {
  //    digitalWrite(morningLight, LOW);
  //  }

}


void playMelody(){

    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzer, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzer);

}



// -----------------------------------------------------------------------------------------
// NOT SURE IF WE'LL NEED THIS YET
// -----------------------------------------------------------------------------------------

//Serial.println("hour: "+hour);
  // Serial.println("day: "+day);
  // Serial.println("second: "+second);


  // doorButtonSwitchState = digitalRead(doorButton);
  // Serial.println("doorButtonSwitchState: " + doorButtonSwitchState);
  //  Serial.print("resetButton: "+resetButton);

  //  if (doorButtonSwitchState == HIGH) {
  //    digitalWrite(eveningLight, LOW);
  //  } else {
  //    digitalWrite(eveningLight, HIGH);
  //  }

  //   doorButtonSwitchState = digitalRead(doorButton);   // read the input pin
  //  digitalWrite(eveningLight, doorButtonSwitchState);
  // resetButtonSwitchState = digitalRead(resetButton);
  // Serial.println("resetButtonSwitchState: " + resetButtonSwitchState);
  //  Serial.print("resetButton: "+resetButton);

  //  if (resetButtonSwitchState == HIGH) {
  //    digitalWrite(morningLight, HIGH);
  //  } else {
  //    digitalWrite(morningLight, LOW);
  //  }


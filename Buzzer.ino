const int buzzerPin = 9; // Buzzer connected to pin 9

void setup() {
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    singleBeep();
    delay(1000);
    doubleBeep();
    delay(1000);
    longBeep();
    delay(2000);
}

void singleBeep() {
    tone(buzzerPin, 1000); // 1kHz frequency
    delay(200); // Beep duration
    noTone(buzzerPin);
}

void doubleBeep() {
    for (int i = 0; i < 2; i++) {
        tone(buzzerPin, 1000);
        delay(150);
        noTone(buzzerPin);
        delay(150);
    }
}

void longBeep() {
    tone(buzzerPin, 1000);
    delay(800); // Longer duration
    noTone(buzzerPin);
}

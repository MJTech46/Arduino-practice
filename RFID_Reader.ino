#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10  // Slave Select pin
#define RST_PIN 9  // Reset pin

MFRC522 rfid(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
    Serial.begin(9600); // Initialize serial communication
    SPI.begin();        // Start SPI bus
    rfid.PCD_Init();    // Initialize RFID module

    Serial.println("Place your RFID card near the reader...");
}

void loop() {
    // Check if a new RFID card is available
    if (!rfid.PICC_IsNewCardPresent()) {
        return;
    }

    // Check if the card can be read
    if (!rfid.PICC_ReadCardSerial()) {
        return;
    }

    Serial.print("RFID Tag UID: ");
    
    // Print UID (Unique Identifier)
    for (byte i = 0; i < rfid.uid.size; i++) {
        Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(rfid.uid.uidByte[i], HEX);
    }
    Serial.println();

    rfid.PICC_HaltA();      // Stop communication with the card
    rfid.PCD_StopCrypto1(); // Stop encryption
}

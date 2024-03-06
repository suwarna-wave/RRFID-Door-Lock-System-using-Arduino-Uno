#include <Wire.h> 
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define RELAY_PIN 8 // Relay pin

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Keep the relay off initially
  Serial.println("Smart Door Lock");
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    String uid = "";
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      uid += (mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      uid += String(mfrc522.uid.uidByte[i], HEX);
    }
    uid.toUpperCase();

    // Compare UID with authorized cards
    if (uid == "0243581C") {
      Serial.println("Access Granted!");
      grantAccess(); // Turn on the relay to grant access
      delay(5000); // Keep the door unlocked for 5 seconds
      revokeAccess(); // Turn off the relay after granting access
    } else {
      Serial.println("Access Denied!");
    }
    mfrc522.PICC_HaltA();
    mfrc522.PCD_StopCrypto1();
  }
}

void grantAccess() {
  digitalWrite(RELAY_PIN, HIGH); // Turn on the relay to grant access
}

void revokeAccess() {
  digitalWrite(RELAY_PIN, LOW); // Turn off the relay to revoke access
}

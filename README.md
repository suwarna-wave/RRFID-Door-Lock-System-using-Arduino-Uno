# RRFID-Door-Lock-System-using-Arduino-Uno
Pins: 
- **Arduino Uno Connections:**
    
    - Connect the Arduino Uno to your computer using a USB cable for programming and power.
- **MFRC522 RFID Module Connections:**
    
    - **SDA (SS) pin (Serial Data Pin):** Connect to digital pin 10 (SS) on the Arduino Uno.
    - **SCK pin (Serial Clock Pin):** Connect to digital pin 13 (SCK) on the Arduino Uno.
    - **MOSI pin (Master Out Slave In):** Connect to digital pin 11 (MOSI) on the Arduino Uno.
    - **MISO pin (Master In Slave Out):** Connect to digital pin 12 (MISO) on the Arduino Uno.
    - **IRQ pin (Interrupt Request Pin):** Not used in this project, you can leave it unconnected.
    - **GND (Ground):** Connect to any ground (GND) pin on the Arduino Uno.
    - **RST pin (Reset Pin):** Connect to digital pin 9 on the Arduino Uno (you can change this pin in the code if needed).
    - **3.3V and VCC:** Connect to the 3.3V pin on the Arduino Uno for power.

- **Relay Module:**
    
    - VCC -> 5V (from Arduino)
    - GND -> GND (common with Arduino)
    - IN -> Digital Pin 8
- **Solenoid Lock and 12V Power Supply:**
    
    - Connect one end of the solenoid to the Common (COM) pin of the relay.
    - Connect the Normally Open (NO) pin of the relay to the positive terminal of the 12V power supply.
    - Connect the other end of the solenoid to the negative terminal of the 12V power supply.
    - Connect the negative terminal of the 12V power supply to Arduino GND (common ground).


```
### Notes:

1. **Ground Connection:**
    
    - It's crucial to connect the ground (GND) of the Arduino, 12V power supply, and relay together. This ensures a common ground reference for all components.
```


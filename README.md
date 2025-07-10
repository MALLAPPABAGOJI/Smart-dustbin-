# Smart-dustbin-

 Smart Dustbin using ESP32 and Blynk

  PROJECT OVERVIEW:
  
 This project implements a Smart Dustbin using an ESP32 microcontroller, an ultrasonic sensor to detect waste levels, a servo motor to control the dustbin lid, and a buzzer/LED to indicate when the bin is full. It uses the Blynk IoT platform to send real-time updates and notifications to the user's smartphone.

FEATURES :
1. Measures waste level using Ultrasonic Sensor (HC-SR04)
2. Automatically opens/closes the lid with Servo Motor
3. Alerts with buzzer or LED when the dustbin is full
4. Sends real-time updates and notifications using Blynk app

HARDWARE USED :
1. ESP32 Dev Board
   <img width="669" height="342" alt="wifi_esp32_ap" src="https://github.com/user-attachments/assets/f7f0923e-4364-4513-b64e-f3f558fb03eb" />

3. Ultrasonic Sensor (HC-SR04)
   <img width="981" height="540" alt="image" src="https://github.com/user-attachments/assets/0156c11a-afa4-4dee-aed1-b7a302eea759" />

4. Servo Motor (SG90)
   <img width="974" height="614" alt="image" src="https://github.com/user-attachments/assets/fc6836ea-91dc-4281-8611-d8b852ab3893" />

6. Buzzer or LED
7. Jumper Wires
8. Breadboard or Mounting Setup
   
 Circuit Diagram
 <img width="992" height="662" alt="image" src="https://github.com/user-attachments/assets/f9178864-b81b-456a-b1a2-81f8694a4977" />

 CONNECTIONS :
 
Component	      ESP32 Pin
HC-SR04 Trig	  GPIO 5
HC-SR04 Echo	  GPIO 18
Servo Motor	    GPIO 19
Buzzer / LED	  GPIO 2

Arduino code :
The complete Arduino code is in the `SmartDustbin.ino` file in this repository.

Blynk Setup:
- Create a new template on [Blynk IoT](https://blynk.io/)
- Add widgets:
- Value Display on V0 (Waste Level)
- LED on V1 (Full Bin Alert)
- Add an Event named `bin_full` to send push notifications
- Use the generated Blynk Auth Token in your Arduino code

  output :
- When dustbin is empty, Blynk shows low level, LED is OFF.
- When full, LED is ON, buzzer beeps, and mobile receives notification.


Indsurty Relevance :
This project simulates real-world smart waste systems used by companies like Bigbelly and Enevo to reduce collection costs and support smart city infrastructure.







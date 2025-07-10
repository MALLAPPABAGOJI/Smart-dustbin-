#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "Smart Dustbin"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Servo.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

#define TRIG_PIN 5
#define ECHO_PIN 18
#define SERVO_PIN 19
#define BUZZER_PIN 21

Servo lidServo;

long duration;
float distance;
int dustbinHeight = 30; // cm
int threshold = 5;      // cm (full if less than this)
bool notified = false;  // To avoid repeated notifications

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lidServo.attach(SERVO_PIN);
  lidServo.write(0); // Lid closed

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
  measureWasteLevel();
}

void measureWasteLevel() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  int wasteLevel = dustbinHeight - distance;
  Blynk.virtualWrite(V0, wasteLevel); // Send level to Blynk

  Serial.print("Waste Level: ");
  Serial.print(wasteLevel);
  Serial.println(" cm");

  if (distance < threshold) {
    digitalWrite(BUZZER_PIN, HIGH);
    Blynk.virtualWrite(V1, 255); // LED ON

    if (!notified) {
      Blynk.logEvent("bin_full", "Dustbin is full. Please empty it!");
      notified = true;
    }
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    Blynk.virtualWrite(V1, 0); // LED OFF
    notified = false;          // Reset flag if no longer full
  }

  openLid();
  delay(5000); // Delay before next reading
}

void openLid() {
  lidServo.write(90); // Open
  delay(1500);
  lidServo.write(0);  // Close
}

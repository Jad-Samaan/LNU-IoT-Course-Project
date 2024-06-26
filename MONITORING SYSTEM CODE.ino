#include "PubSubClient.h"
#include <WiFi.h>
#include "dht11.h"

// WiFi credentials
const char* ssid = "XXXXXXXXXXXX";
const char* password = "XXXXXXXXXXXX";

 //MQTT broker credentials
const char* mqttServer = "XXXXXXXXXXXX";
const int mqttPort = 1883;
const char* mqttUser = "XXXXXXXXXXXX";
const char* mqttPassword = "XXXXXXXXXXXXXXXXXXXXXXXX";

WiFiClient LORAClient;
PubSubClient client(LORAClient);

// Define the pins that the sensors are connected to
#define VIBRATION_SENSOR_PIN 45
#define HALL_SENSOR_PIN 47
#define TEMP_SENSOR_PIN 48
#define LED_PIN 35

char buffer[10];  // Buffer to hold the resulting string.
double rpm=0;
double lastrpmreading;
double previousreading;
bool vibration;
float temperature;

// Variables to hold the current count and the last time we counted
volatile unsigned long count = 0;
unsigned long lastMillis = 0;


// This function is called every time the Hall effect sensor goes from LOW to HIGH
void countRotation() {
  count++;
}


// Open a serial connection to output the results of the program.
// Connect to WiFi network to reach the MQTT broker and publish messages to topics.
 
void setup() {
 
 // Begin serial communication at 9600 baud to see the program output 
  Serial.begin(9600);   
  WiFi.begin(ssid, password);
  client.setServer(mqttServer, mqttPort);

  // Subscribe to LED feed on Adafruit broker
  client.subscribe("jadsamaan/f/led");

// Set up the vibration sensor as an input
  pinMode(VIBRATION_SENSOR_PIN, INPUT);

  // Set up the Hall effect sensor as an input
  pinMode(HALL_SENSOR_PIN, INPUT);

   // Set up the temperature sensor as an input
  pinMode(TEMP_SENSOR_PIN, INPUT);

  // Set up LED as an output
  pinMode(LED_PIN, OUTPUT);


  // Attach an interrupt to the Hall effect sensor
  attachInterrupt(digitalPinToInterrupt(HALL_SENSOR_PIN), countRotation, RISING);
 
}
 
void loop() {

  lastrpmreading = rpm;

  // Every second, calculate the RPM
  if (millis() - lastMillis >= 1000) {

    // Calculate RPM: (Number of rotations per second) * 60 seconds
      rpm = (count / (millis() - lastMillis)) * 60;
  
    // Reset the count and lastMillis
    count = 0;
    lastMillis = millis();

  }
  
    previousreading = 0.9 * lastrpmreading;
    // Read vibration sensor value
    dht11 DHT11;
    DHT11.read(TEMP_SENSOR_PIN);
    temperature = DHT11.temperature;

    
 if ( vibration == HIGH && rpm < previousreading && temperature > 50 ) {
    // Bearing issue detected
    digitalWrite(LED_PIN, HIGH); // Turn on LED
    Serial.println("Bearing issue detected!");
  } else {
    // No bearing issue detected
    digitalWrite(LED_PIN, LOW); // Turn off LED
    Serial.println("No bearing issue detected");
  }

  
  if (client.connect("LoRa32Client", mqttUser, mqttPassword )) 

   // Convert the number to a string in base 10
  // Publish rpm value to RPM feed on Adafruit broker
  {
  Serial.println("Connected to MQTT broker");

  client.publish("jadsamaan/f/rpm-01", ultoa(rpm, buffer, 10));
   Serial.print("RPM: ");
   Serial.print(rpm);
  

  // Publish Temperatue value to temp-01 feed on Adafruit broker
  client.publish("jadsamaan/f/temp-01", ultoa(temperature +50, buffer, 10));
  Serial.print("Temperature: ");
  Serial.print(temperature+50);

  
  // Publish vibration value to vib-01 feed on Adafruit broker
  client.publish("jadsamaan/f/vib-01", ultoa(vibration, buffer, 10));
  Serial.println(vibration);

   
   }
 
delay(60000);

}

```

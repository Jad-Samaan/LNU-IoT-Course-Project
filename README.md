# Machine Health Monitoring System
## Detects bearing issues by reading an comparing machine rotor parameters

## Objectives
Most of our applications in pulp & paper machinery we use rotors and bearing houses that are operating continuously. This project is aiming to design a machine monitoring system consists of  Tachometer and Thermometer, which collect data from concerned machine and publish it on MQTT broker to allow remote monitoring. 
The RPM readings (from tachometer)  used to detect rotor speed deviation which may indicates bearings deterioration. The temperature readings (from thermometer)  used to detect overheating in bearing house which indicates bearing issues such as lubrication, overload and heat dissipation.
This system can be used for early fault identification.

## Material

| Product       | Where to buy  | Description   | Price |
| ------------- | ------------- | ------------- | ------------- |
| Heltec LoRa32 (V3) microcontroller |Amazone.se|MCU, ESP32, LoRa & WiFi support|350 SEK|
| KY-024 module |Hobby King |Hall effect digital sensor|  SEK|
| DHT11 module |          |Humidity & temerature digital sensor |  SEK|
| KY-002 module |          |Vibration switch sensor |15  SEK|
|Power supply module |          |Powers the bread board with 9v battery |  SEK|

## Environment setup
1. Install needed drivers for MCU board from Heltec Automation.
2. Install Arduino IDE to program in C++ / Arduino environment
3. Install following libraries
  - "PubSubClient.h" to talk with MQTT server
  - <WiFi.h> to connect WiFi network
  - "dht11.h" to use DHT11 sensor

## Putting everything together
1. Connect the antenna to MCU
2. Connect MCU and sensors acc. pin mapping
3. Connect the MCU to the computer via USB cable

## The Code

## The physical network layer
Set up the communication with Adafruit MQTT server usnig WiFi

## Visualisation and user interface
Data visualzation can performrd using Adafruit dashboards 

## Finalizing the design
In this course I made a POC prototype for the concerned project. When it comes to the industrial real application, some enhancements should be implemented:
- Communicate with TTN to reduce power consumption using Webhooks between TTN and MQTT server.
- Improve the accuracy of parameter reading by installing more sensitive and idustrial sensors.













![Schematic diagram](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/f6e26a2e-687c-4d11-8c76-6cc45bdcce7a)


![20240415_141715](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/3132adbf-2a09-4e60-a677-89ec5974d787)


# Roadmap
- IDE: Arduino C++
- MCU: Heltec LoRa32 (V3), installed drivers, checked the pinmap.

  ![image](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/2ff06d71-5ec2-4bda-ac15-b1c0d1682b32)

- Sensors:
    Digital temperature & humidity sensor DH11 (This is just for prototyping, It should be replaced later with DS18b20)
    Hall effect sensor KY-028, used as revolution counter by facing a magnet mounted on rotating shaft, it counts one revolution every time changes from LOW to HIGH.

 ![image](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/5328e4bc-d4de-45e9-a305-41a79c144c62)


  

  
- Network protocol: I have tested the connection with WiFi
- Data visualization on Adafruit, created account,published from Heltec board to specific feeds.

![Data Visualization](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/33615433-03e2-4222-a217-3f1c0668dff3)



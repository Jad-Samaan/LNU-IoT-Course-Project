# Machine Health Monitoring System
## Detects bearing issues by reading an comparing machine rotor parameters
1. [Objectives](#Objectives)
2. [Material](#Material)
3. [Environment setup](#Environment-setup)
4. [Putting everything together](#Putting-everything-together)
5. [Platforms and infrastructure](#Platforms-and-infrastructure)
6. [The code](#The-code)
7. [The physical network layer](#The-physical-network-layer)
8. [Visualisation and user interface](#Visualisation-and-user-interface)
9. [Finalizing the design](#Finalizing-the-design)
9. [References](#References)

## Objectives
Most of our applications in pulp & paper machinery we use rotors and bearing houses that are operating continuously. This project is aiming to design a machine monitoring system consists of  Tachometer and Thermometer, which collect data from concerned machine and publish it on MQTT broker to allow remote monitoring. 
The RPM readings (from tachometer)  used to detect rotor speed deviation which may indicates bearings deterioration. The temperature readings (from thermometer)  used to detect overheating in bearing house which indicates bearing issues such as lubrication, overload and heat dissipation.
This system can be used for early fault identification.

## Material

| Product       | Where to buy  | Description   | Price |
| ------------- | ------------- | ------------- | ------------- |
| Heltec LoRa32 (V3) microcontroller | [Amazon](https://www.amazon.se/dp/B08243JHMW?ref_=pe_24982401_518009621_302_E_DDE_dt_1)|MCU, ESP32, LoRa & WiFi support|350 SEK|
| KY-024 module |[Conrad]([https://www.elecbee.com/en-25755-KY-024-4pin-Linear-Magnetic-Switches-Speed-Counting-Hall-Sensor-Module?srsltid=AfmBOorAhfsdkkDF4iAIMdi11oZEC1BLC0Bt0tlnnuFqLrIr4vYlWTo4tVQ](https://www.conrad.se/sv/p/hall-effektsensor-1485303-arduino-1485303.html?utm_source=google&utm_medium=surfaces&utm_campaign=shopping-feed&utm_content=free-google-shopping-clicks&utm_term=1485303&gad_source=1&gclid=EAIaIQobChMIkKD8u8D0hQMV6QCiAx1Qkg1_EAQYBSABEgJHY_D_BwE)) |Hall effect digital sensor|  SEK|
| DHT11 module |          |Humidity & temerature digital sensor |  SEK|
| KY-002 module |          |Vibration switch sensor |15  SEK|
|Power supply module |          |Powers the bread board with 9v battery |  SEK|

| Product | Where to buy | Description | Price |
| --------- | ---------------- | ---------------- | ----------------: |
| NodeMCU ESP32 Heltec | [link](https://www.amazon.se/dp/B08243JHMW?ref_=pe_24982401_518009621_302_E_DDE_dt_1) | Microcontroller supporting WiFi and Lora. Built in OLED display. | 350SEK |
| Vibration sensor high sensitivity | [link](https://www.electrokit.com/produkt/vibrationssensor-hog-kanslighet/) | Measures vibration through digital output | 42SEK |
| Jumper wires male-male | [link](https://www.electrokit.com/produkt/labbsladd-40-pin-30cm-hane-hane/) | Wires to connect the circuits | 49SEK |
| Jumper wires female-male | [link](https://www.electrokit.com/produkt/labbsladd-40-pin-30cm-hona-hane/) | Wires to connect the circuits | 49SEK |
| USB to Micro USB cable | [link](https://www.kjell.com/se/produkter/kablar-kontakter/usb-kablar/linocell-micro-usb-kabel-svart-05-m-p93424?gclid=Cj0KCQiAsdKbBhDHARIsANJ6-jdFMu6K6bP9FJbrX_VwUeSgRLyFK9sPdiU4-TL19HrHKeCEr88ER2IaAqSyEALw_wcB&gclsrc=aw.ds) | Cable to program the device | 110SEK |
| Battery | [link](https://www.kjell.com/se/produkter/el-verktyg/laddare/mobilladdare/powerbank/linocell-powerbank-10000-mah-p89256) | Power supply | 199SEK |
| Breadboard | [link](https://sizable.se/P.TVY7M/Kopplingsdack-med-830-punkter) | Breadboard to connect device and sensor during development | 59SEK |


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



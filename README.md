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
| KY-024 module |[Conrad](https://www.conrad.se/sv/p/hall-effektsensor-1485303-arduino-1485303.html?utm_source=google&utm_medium=surfaces&utm_campaign=shopping-feed&utm_content=free-google-shopping-clicks&utm_term=1485303&gad_source=1&gclid=EAIaIQobChMIkKD8u8D0hQMV6QCiAx1Qkg1_EAQYBSABEgJHY_D_BwE)|Hall effect digital sensor|42 SEK|
| DHT11 module |[M.NU](https://www.m.nu/sensorer-matinstrument/dht11-basic-temperature-humidity-sensor-extras-1?srsltid=AfmBOorLXW_rPV_zYkX4GU9dweg2mRc9Y7y5fdeVRWpZpyMFvfTcuSQaqlA)|Humidity & temerature digital sensor |55 SEK|
| KY-002 module |[Electrokit](https://www.electrokit.com/vibrationssensor?gad_source=1&gclid=EAIaIQobChMIvprl78T0hQMVnwuiAx3COw_3EAQYAyABEgICSvD_BwE)|Vibration switch sensor |29 SEK|
|MB102 module|[M.NU](https://www.m.nu/breadboarding/breadboard-power-supply-assembled-3-3v-5v-output?srsltid=AfmBOor5E_Hh1M0d4MLVzGWZ6Szp_-FCtS_we5MxzKzrBhdCsADn4298CgQ)|Breadboard power supply - assembled 3,3V/5V output|59 SEK|
| Breadboard | [Sizable](https://sizable.se/P.TVY7M/Kopplingsdack-med-830-punkter) |Main board to connect all components | 59SEK |

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
4. Mount a neodymium magnet on a rotating shaft (electrical screwdriver for example).

![shared image (1)](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/b6ba46d6-3e27-4445-95a3-58035814651a)

![shared image](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/270d9cb4-ae47-4db5-84ad-ef374f7d2e46)


   
## The Code

## The physical network layer
Set up the communication with Adafruit MQTT server usnig WiFi
![Presentation1](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/3c7e54a8-d61b-47fd-a38b-acb382662ae5)


## Visualisation and user interface
Data visualzation can performrd using Adafruit dashboards 

![TEMP Dashboard](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/6754c9d6-55d3-4ab3-b0c5-1c2050b7cd2c)

![VIB Dashboard 01](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/90026331-79c5-44d9-8b85-554bf67424a1)

![RPM Dashboard](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/7c575882-e8f0-429e-b418-c7cca0d36bc8)


## Finalizing the design
In this course I made a POC prototype for the concerned project. When it comes to the industrial real application, some enhancements should be implemented:
- Communicate with TTN to reduce power consumption using Webhooks between TTN and MQTT server.
- Improve the accuracy of parameter reading by installing more sensitive and idustrial sensors.

# References
https://www.youtube.com/watch?v=az6m_upGleU&list=PL70wNv4dBdJxh0lJjnLlQjqh9rshaht6X&index=21

https://docs.heltec.org/en/node/esp32/quick_start.html



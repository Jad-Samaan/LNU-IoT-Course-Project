# Machine Health Monitoring System
IoT course project at LNU
# Project objectives
Most of our applications in pulp & paper machinery we use rotors and bearing houses that are operating continuously. This project is aiming to design a machine monitoring system consists of  Tachometer and Thermometer, which collect data from concerned machine and publish it on MQTT broker to allow remote monitoring. 
The RPM readings (from tachometer)  used to detect rotor speed deviation which may indicates bearings deterioration. The temperature readings (from thermometer)  used to detect overheating in bearing house which indicates bearing issues such as lubrication, overload and heat dissipation.
This system can be used for early fault identification.

![20240415_141715](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/3132adbf-2a09-4e60-a677-89ec5974d787)


# Roadmap
- IDE: Arduino C++
- MCU: Heltec LoRa32 (V3), installed drivers, checked the pinmap.

  ![image](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/2ff06d71-5ec2-4bda-ac15-b1c0d1682b32)

- Sensors:
    Digital temperature & humidity sensor DH11 (This is just for prototyping, It should be replaced later with DS18b20)
    Hall effect sensor KY-028

 ![image](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/5328e4bc-d4de-45e9-a305-41a79c144c62)


  

  
- Network protocol: I have tested the connection with WiFi
- Data visualization on Adafruit, created account,published from Heltec board to specific feeds.

![Data Visualization](https://github.com/Jad-Samaan/LNU-IoT-Course-Project/assets/163136017/33615433-03e2-4222-a217-3f1c0668dff3)



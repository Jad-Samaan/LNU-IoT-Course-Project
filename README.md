# Machine Health Monitoring System
IoT course project at LNU
# Project objectives
Most of our applications in pulp & paper machinery we use rotors and bearing houses that are operating continuously. This project is aiming to design a machine monitoring system consists of  Tachometer and Thermometer, which collect data from concerned machine and publish it on MQTT broker to allow remote monitoring. 
The RPM readings (from tachometer)  used to detect rotor speed deviation which may indicates bearings deterioration. The temperature readings (from thermometer)  used to detect overheating in bearing house which indicates bearing issues such as lubrication, overload and heat dissipation.
This system can be used for early fault identification.


This system can be used either as prediction tool for any trouble or as "Black Box" in case of machine trip.
# Roadmap
- IDE: Arduino C++
- MCU: Heltec LoRa32, installed drivers, checked the pinmap, have some issues with libraries.
- Sensors: did not test yet.
- Network protocol: I have tested the connection with WiFi
- Data visualization on Adafruit, created account,published from Heltec board to specific feeds.

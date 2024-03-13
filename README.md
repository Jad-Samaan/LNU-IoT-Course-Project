# Overheating Protection Unit
IoT course project at LNU
# Project objective
Most of our applications in pulp & paper industry we use seals and bearings that are working under high temperature circumstance. Both of these types of components has cooling media: oil for bearings and water for seals. My project intend to design a system reads media temperature continuously, send read values as MQTT messages  and accordingly should the system decide whether the machine will continue to rotate or stop to protect the bearing or seal from damage. This system can be used either as protection unit for a rotating machine  or as a part of test station.
# Roadmap
- IDE: Arduino C++
- MCU: Heltec LoRa32, installed drivers, checked the pinmap, have some issues with libraries.
- Sensors: did not test yet.
- Network protocol: I have tested the connection with WiFi
- Data visualization on Adafruit, created account,published from LoRa32 board to a specific feed.

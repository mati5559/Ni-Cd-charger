# Ni-Cd charger
Charger for 24V (10 s) NiCd battery


# Description
This charger was designed to charge 24V NiCd battery with current about 1,2A. It uses continous current method and delta V detection. 

Schematic contains DC-DC step up converter, microcontroller, current source.
Step up converter generates higher voltage than input voltage and limits current. It is very efficient (about 85%).
Current source limits short circuit current and charging current when battery voltage is lower than input voltage. It generates a lot of heat, so it have big radiator and temperature sensor to prevent overheat. In case of overheat charging will be interrupted  and error LED will blink. After cooling down charging will be resumed automatically. Current source works only for a while at the beginning of charging and when circuit is shorted. Most of the time it is turned off and do not generate heat. 
Microcontroller controls charging process, turns on and off step up converter and current source, measures voltages, tepmerature etc. 

You can regulate charging current with R13 potentiometer, short circuit current with R6 potentiometer (it must be greather than charging current) and maximum output voltage with R16 potentiometer. 

Other parameters can be modified in config.hpp file before programming Attiny13. 


# How to use it
1. Connect power supply to X1 screw clamp (20V 4A).
2. Connect battery to X2 screw clamp and temperature sensor to pin 3 and 4 of JP1. (short pin 3 and 4 of JP1 if your battery do not have temperature sensor)
3. LED1 should light up.
4. Charging is ended when LED1 stop lighting and LED2 is not lighting or blinking.

If LED2 is blinking it seems that over temperature protection was activated. You should wait a while to cool down. Charger will automatically turn on.
If LED2 lights constantly it seems that something went wrong (for example battery was disconnected, is dead or charger is broken). You should turn off power supply for a while, make sure that all is connected properly and turn on power supply. 




GNU GPL license
Source code and hardware is open and free of charge for everyone.

Author is not responsible for any damages made by this device.
You make and use it at your own risk.


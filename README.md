# Ni-Cd charger
Charger for 24V (10 s) NiCd battery


# Assembly and run
1. Order or DIY PCB, that you can find in hardware folder. You can open it with AutoDesk Eagle software.
2. Solder all elements except Attiny13.
3. Coil L1 should be high current coil for SMPS (I used DTMSS-27/0.068/10-V coil).
4. Q1, Q2, D1, D4, IC2, IC3 should have radiators, because they will warm up.
5. All capacitors at least 25V unless the schematic says otherwise.
6. Stick NTC 10k thermistor to Q2 radiator and connect to 1 and 2 terminals of JP1.
7. Set all potentiometers to half of it's values.
8. Connect 18-25V, at least 3A power supply to input (X1 screw clamp).
9. Connect 5 and 8 pin of Attiny13 socket on board, CHG diode should light up.
10. Connect voltage meter to output (X2 screw clamp).
11. Adjust output voltage using R16 to about 40V.
12. Disconnect 5 and 8 pin of Attiny13 and wait about 1 minute for capacitors discharge.
13. Connect ammeter with range at least 5A to output.
14. Connect 5 and 8 pin of Attiny13 socket on board, CHG diode should light up.
15. Adjust current to about 1,4A with R6. 
You should do it fast, because Q2 will warm up and it could burn. Big radiator is suggested at least for calibration.
16. Disconnect ammeter and connect 25-30 ohm resistor in series with ammeter to output (X2 screw clamp). 
This resistor should be at least 5W. It will warm up, so you must do next step quickly.
17. Adjust current to about 1-1,2A with R13.
18. Disconnect ammeter and resistor.
19. Disconnect 5 and 8 pin of Attiny13.
20. Disconnect power supply.
21. Import project from software folder to Eclipse (for C/C++). 
Eclipse should have AVRplugin installed (https://sourceforge.net/projects/avr-eclipse/), configured programmer and you should have AVRDude and AVR compiler on your computer. 
Project was made on Debian 10 (Linux) with avr-libc gcc-avr binutils-avr and avrdude packets (sudo apt-get install avr-libc gcc-avr binutils-avr avrdude). 
On windows you probably should change settings in Properties->C/C++ Build->Settings.
22. Open config.hpp file, read it, change vlues if you need and save it.
23. Connect Attiny13 to programmer (I use USBasp).
24. Build project and upload to Attiny13.
25. Solder Attiny13 to PCB.
26. Connect power supply to X1, battery to X2 (+ to pin 2, - to pin 1) and battery temperature sensor to 3 and 4 pin of JP1.
27. Short 3 and 4 pin of JP1 if your battery do not have temperature sensor. 
Battery temperature sensor is also battery connection sensor. Pin 3 and 4 of JP1 should be connected only if battery is connected to X2. 

Enjoy!


# How to use it
1. Connect power supply to X1 screw clamp.
2. Connect battery to X2 screw clamp and temperature sensor to pin 3 and 4 of JP1.
3. LED1 should light up.
4. Charging is ended when LED1 stop lights and LED2 is not lighting or blinking.

If LED2 is blinking it seems that over temperature protection was activated. You should wait a while to cool down. Charger will automatically turn on.
If LED2 lights constantly it seems that something went wrong (for example battery was disconnected, is dead or charger is broken). You should turn off power supply for a while, make sure that all is connected properly and turn on power supply. 




GNU GPL license
Source code and hardware is open and free of charge for everyone.

Author is not responsible for any damages made by this device.
You make and use it at your own risk.


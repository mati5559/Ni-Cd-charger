/*
 * config.hpp
 *
 *  Created on: 8 mar 2020
 *
 *  Author: Mateusz Dąbrowski (mati5559)
 *  Github: https://github.com/mati5559
 *
 *  GNU GPL license
 *  Source code and hardware is open and free of charge for everyone.
 *
 *  Author is not responsible for any damages made by this device.
 *  You use it at your own risk.
 */

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

// Amount of measurements per one voltage read
//
// To provide high accuracy and cancel noise
// this program do a few measurements and compute average of them
// (see src/adc.cpp).
//
// Each measurement takes 5 ms.
//
// 10-15 is optimal value
#define VOL_ACCURACY 12




// Delta V
//
// Ni-Cd's voltage during charging changes only a little.
// When battery is full, the voltage falls down.
// This value determines how much voltage must decrease to detect
// that the battery is full and turn off charger.
// DELTA_V value could be calculated from this formula:
//
// DELTA_V = U * 25
// U - voltage change on output [V]
//
// This formula is not precise because of resistors tolerance, noise, ADC error etc.
// It should be adjusted experimentally.
// 20 is optimal value for 24V (10 s) battery pack.
// Default: 20
#define DELTA_V 20






// Over voltage protection
// Charger will turn off and error diode will light up if voltage increase above this value
//
// OVP_VOL value could be calculated from this formula:
//
// OVP_VOL = U * 25
// U - max output voltage [V]
//
// This formula is not precise because of resistors tolerance, noise, ADC error etc.
// This value is not critical, so do not change it if charger works properly.
// Default: 950 (about 38V)
#define OVP_VOL 950




// Temperature protection
//
// This charger uses 2 temperature sensors.
// Charger will turn off if temperature on battery increases above MAX_BATTERY_TMP
// or transistor temperature increases above MAX_TRANSISTOR_TMP.
// Error diode will blink.
//
// Charger will turn on automatically if battery temperature decreases
// below (MAX_BATTERY_TMP - BATTERY_TMP_HYSTERESIS) and  transistor temperature decreases
// below (MAX_TRANSISTOR_TMP - TRANSISTOR_TMP_HYSTERESIS).
//
// Sensors should be 10k NTC with B = 4150K.
// If your sensors are different (use only NTC, resistance should be between 3k and 20k) you can calculate
// these values from this formula:
//
// MAX_xxx_TMP = 2250600 / (Rt + 2200)
// xxx_TMP_HYSTERESIS = (2250600 / (Rt + 2200)) - (2250600 / (Rm + 2200))
// Rt - resistance of sensor in max temperature [ohm]
// Rm - resistance of sensor in temperature, that charger should turn on
//
// Set MAX_BATTERY_TMP to 1025 if your battery do not have temperature sensor
//
// Default values:
// MAX_BATTERY_TMP - 360 (about 50 Celsius degrees)
// BATTERY_TMP_HYSTERESIS - 85
// MAX_TRANSISTOR_TMP - 640 (about 70 Celsius degrees)
// TRANSISTOR_TMP_HYSTERESIS - 150
#define MAX_BATTERY_TMP 360
#define BATTERY_TMP_HYSTERESIS 85
#define MAX_TRANSISTOR_TMP 640
#define TRANSISTOR_TMP_HYSTERESIS 150

#endif /* CONFIG_HPP_ */

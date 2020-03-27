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

#ifndef ADC_HPP_
#define ADC_HPP_

#include <avr/io.h>
#include <util/delay.h>

#include "config.hpp"


namespace adc
{
	extern int read_voltage();
	extern int read_battery_temp();
	extern int read_transistor_temp();
	extern void init();
}



#endif /* ADC_HPP_ */

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


#define READ_TRANSISTOR_TEMP adc::read_adc(2)
#define READ_BATTERY_TEMP adc::read_adc(3)
#define READ_BATTERY_VOLTAGE adc::read_adc(1)

namespace adc
{
	void init();
	int read_adc(uint8_t channel);
}



#endif /* ADC_HPP_ */

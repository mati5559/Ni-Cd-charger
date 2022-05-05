/*
 *  adc.cpp
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

#include "adc.hpp"

namespace adc
{
	void init()
	{
		// init ADC in free running mode
		ADCSRA = 0b11100101;
		ADCSRB = 0b00000000;
	}

	int read_adc(uint8_t channel)
	{
		// Choose channel and reference voltage (AVcc with external capacitor)
		ADMUX = 0b01000000 | channel;

		// Start conversion
		ADCSRA |= 0b01000000;

		// Wait until conversion is done
		while ((ADCSRA & 0b00010000) == 0) {};

		return ADC;
	}
}


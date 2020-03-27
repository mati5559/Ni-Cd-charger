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


	int read_voltage()
	{
		// check if ADC input is set to 1
		if(ADMUX != 0b00000001)
		{
			ADMUX = 0b00000001;
			_delay_ms(5);
		}
		unsigned long int result = 0;

		// do a few measurements
		for(int a = 0; a<VOL_ACCURACY; a++)
		{
			result += ADC;
			_delay_ms(5);
		}

		// compute and return average of all measurements
		result /= VOL_ACCURACY;
		return (int) result;
	}

	int read_battery_temp()
	{
		// check if ADC input is set to 3
		if(ADMUX != 0b00000011)
		{
			ADMUX = 0b00000011;
			_delay_ms(5);
		}
		unsigned long int result = 0;

		// do a few measurements
		for(int a = 0; a<5; a++)
		{
			result += ADC;
			_delay_ms(5);
		}

		// compute and return average of all measurements
		result /= 5;
		return (int) result;
	}


	int read_transistor_temp()
	{
		// check if ADC input is set to 2
		if(ADMUX != 0b00000010)
		{
			ADMUX = 0b00000010;
			_delay_ms(5);
		}

		unsigned long int result = 0;

		// do a few measurements
		for(int a = 0; a<5; a++)
		{
			result += ADC;
			_delay_ms(5);
		}

		// compute and return average of all measurements
		result /= 5;
		return (int) result;
	}
}


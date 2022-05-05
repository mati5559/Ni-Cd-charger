/*
 *  main.cpp
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





// Include requied libraries
#include <avr/wdt.h>
#include <avr/io.h>
#include <util/delay.h>

#include "adc.hpp"
#include "config.hpp"


// Define some values to make code more transparent
#define CHG_OFF PORTB &= 0b11111110
#define CHG_ON PORTB |= 0b00000001
#define ERR_DIODE_ON PORTB |= 0b00000010
#define ERR_DIODE_OFF PORTB &= 0b11111101

int vol_ath = 0;

int main()
{
	// reset watchdog
	bool error = false;
	if(MCUSR & 0b00001000) error = true;
	MCUSR = 0x00;
	wdt_disable();



	// wait for voltage stabilization and init everything
	_delay_ms(1000);
	adc::init();

	// watchdog enable (1s)
	wdt_enable(WDTO_1S);

	// set pin mode
	DDRB = 0b00000011;
	CHG_OFF;

	// Wait for battery connection
	while(READ_BATTERY_TEMP < 20)
	{
		wdt_reset();
	}


	// Wait 10s if uC reset from watchdog
	// it prevents burning the device
	if(error)
	{
		error = false;
		for(int a = 0; a<20; a++)
		{
			wdt_reset();
			_delay_ms(500);
		}
	}

	// start charging
	wdt_reset();
	_delay_ms(500);
	CHG_ON;

	int thread_1 = 0;

	while(1)
	{
		// reset watchdog
		wdt_reset();


		// count loop iterations
		thread_1++;


		// measure actual battery voltage
		int vol_actual = READ_BATTERY_VOLTAGE;


		// over voltage protection - turn off charger and light up error diode when voltage is too high
		if(vol_actual > OVP_VOL)
		{
			CHG_OFF;
			ERR_DIODE_ON;
			wdt_disable();
			return 0;
		}


		// check if measured voltage is higher than voltage measured a while ago
		if(vol_actual > vol_ath)
		{
			vol_ath = vol_actual;
		}


		// detect if battery voltage decreased
		if((vol_ath - vol_actual) > DELTA_V)
		{
			// turn off charger
			CHG_OFF;
			wdt_disable();
			return 0;
		}

		// instructions that are not critical and can be done every 20 loop iterations
		if(thread_1 > 20)
		{
			thread_1 = 0;

			// checking if battery temperature is too high
			if(READ_BATTERY_TEMP > MAX_BATTERY_TMP)
			{
				// turn off charger
				CHG_OFF;

				// blink error diode
				while(READ_BATTERY_TEMP > (MAX_BATTERY_TMP - BATTERY_TMP_HYSTERESIS))
				{
					ERR_DIODE_ON;

					wdt_reset();
					_delay_ms(500);
					wdt_reset();
					_delay_ms(500);


					ERR_DIODE_OFF;


					wdt_reset();
					_delay_ms(500);
					wdt_reset();
					_delay_ms(500);
				}
				vol_ath = 0;
				CHG_ON;
			}


			// checking if transistor temperature is too high
			if(READ_TRANSISTOR_TEMP > MAX_TRANSISTOR_TMP)
			{
				// turn off charger
				CHG_OFF;

				// blink error diode
				while(READ_TRANSISTOR_TEMP > (MAX_TRANSISTOR_TMP - TRANSISTOR_TMP_HYSTERESIS))
				{
					ERR_DIODE_ON;

					wdt_reset();
					_delay_ms(500);
					wdt_reset();
					_delay_ms(500);


					ERR_DIODE_OFF;


					wdt_reset();
					_delay_ms(500);
					wdt_reset();
					_delay_ms(500);
				}
				vol_ath = 0;
				CHG_ON;
			}
		}
	}
}





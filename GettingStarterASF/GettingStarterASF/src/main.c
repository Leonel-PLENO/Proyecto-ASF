/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="http://www.atmel.com/design-support/">Atmel Support</a>
 */
#include <asf.h>

#include <string.h>
#include "compiler.h"
#include "conf_clock.h"

//#include <util/setbaud.h>
#include <avr/interrupt.h>
//#include "ring_buffer.h"

/************************************************************************/
/* Los #define para definir terminales                                  */
/************************************************************************/
#define LED_GREEN    IOPORT_CREATE_PIN(PORTA, 5)
#define LED_RED		IOPORT_CREATE_PIN(PORTA, 6)

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	board_init();
	sysclk_init();
	delay_init(sysclk_get_cpu_hz());
	
	//gpio_configure_pin(PORTA5,1);
	
	ioport_init();
		
	ioport_set_pin_dir(LED_GREEN,IOPORT_DIR_OUTPUT);
	ioport_set_pin_dir(LED_RED,IOPORT_DIR_OUTPUT);
	
	/* Insert application code here, after the board has been initialized. */
	
	ioport_set_pin_high(LED_RED);
	ioport_set_pin_low(LED_GREEN);
	
	//gpio_set_pin_high(PORTA5);
	
	while(true){
		ioport_toggle_pin(LED_GREEN);
		ioport_toggle_pin(LED_RED);
		delay_ms(500);
	}
	
}

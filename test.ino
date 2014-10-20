#include "ui.h"

//#include <avr/io.h>
//#include <avr/interrupt.h>


void setup(void)
{
	Serial.begin(9600);
}

void loop(void)
{
	user_mode();
}

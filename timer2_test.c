
/*--------------------------------------------------------------------------------------------------------------

 &[FILE NAME]    : timer2_test

 &[AUTHOR(S)]    : Muhammed Eldabea Hashem

 &[DATE CREATED] : 20 April 2020

 &[DESCRIPTION]  : test timer 2
------------------------------------------------------------------------------------------------------------------*/



#include "timer_8_bit.h"


volatile uint8 flag = 0 ;

/*toggle led every tow second */
void increme(void)
{

flag++ ;


}


int main ()
{
	DDRA |=(1<<3) ;

	Timer2_Configuration config = {Normal_mode,Normal_Port_OC2_Diconnected_NON_PWM,FrqBY_256_Prescaler,synch_clockSource} ;
	Timer2_init(&config) ;
	Timer2_callBack(increme) ;

	while(1)
	{
if (flag == 16)
{
	PORTA ^=(1<<3) ;
	flag = 0 ;
}
	}

}






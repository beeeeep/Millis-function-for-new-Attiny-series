/*
 * Timers_utility.c
 *
 * Created: 6/4/2020 4:10:38 μμ
 *  Author: Anestman
 */ 
#include "millis.h"

volatile static millis_t milliseconds;

void millis_init(void)
{
cli();

 /* enable overflow interrupt */
 TIMER.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
 
 /* set Normal mode */
 TIMER.SINGLE.CTRLB = TCA_SINGLE_WGMODE_NORMAL_gc;

  /* disable event counting */
  TIMER.SINGLE.EVCTRL &= ~(TCA_SINGLE_CNTEI_bm);

  /* set the period */
  TIMER.SINGLE.PER = PERIOD_VALUE;
  
  TIMER.SINGLE.CTRLA |= TCA_SINGLE_CLKSEL_DIV64_gc         /* set clock source (sys_clk/256) */
					 | TCA_SINGLE_ENABLE_bm;                /* start timer */

sei();
}



millis_t millis(void)
{
	return milliseconds;
}

ISR(TIMER_VECT)
{
	++milliseconds;
		
			
			/* The interrupt flag has to be cleared manually */
			TIMER.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;
}
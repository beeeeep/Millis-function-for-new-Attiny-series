/*
 * Timers_utility.h
 *
 * Created: 6/4/2020 4:10:50 μμ
 *  Author: Anestman
 */ 

#ifndef MILLIS_H_
#define MILLIS_H_

#include <avr/interrupt.h>
#ifndef F_CPU
 # warning "F_CPU not defined for <millis.h>"
#endif

#define  TIMER TCA0
#define  TIMER_VECT TCA0_OVF_vect

#define  PERIOD_VALUE 41
typedef unsigned long millis_t;

void millis_init(void);

millis_t millis(void);



#endif /* MILLIS_H_ */
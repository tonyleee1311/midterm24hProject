/*
 * fsm_advance.c
 *
 *  Created on: Nov 5, 2022
 *      Author: nguye
 */
#include"fsm_advance.h"
void fsm_advance_buttons_run(){
	switch(status){
	case LONGPRESSINC:
		if(timer3_flag==1){
			counterLed++;
			if(counterLed>MAXIMU_VALUE) counterLed=0;
			updateLedBuffer(counterLed);
			update7SEG(FIRSTSEVENSEGMENTLED);
			timer3_flag=0;
		}
		if(isButtonPressedMoreThan3s(SECOND_BUTTON)){
			status=LONGPRESSINC;
			setTimer3(100);
		}
		break;
	case LONGPRESSDEC:
		break;
	default:
		break;
	}
}


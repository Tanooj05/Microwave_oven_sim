#include<xc.h>
#include"timers.h"


void init_timer2(void)
{//timer2 cntrl register
     
    //selecting postscalar as 1:1
    TOUTPS3=0;
    TOUTPS2=0;
    TOUTPS1=0;
    TOUTPS0=0;
    //turn on timer2 when required
    TMR2ON=0;
    //prescalar as 1:1
    T2CKPS1=0;
    T2CKPS0=0;
    //enable tmr2 interrupt
    TMR2IE=1;
    //clear timer 2 int
    TMR2IF=0;
    //no of ticks in pr2
    PR2 = 250;
    
 
}
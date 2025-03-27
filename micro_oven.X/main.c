/*
 * File:   main.c
 * Author: K
 *
 * Created on 26 February, 2025, 9:32 PM
 */


#include <xc.h>
#include"clcd.h"
#include"main.h"
#include"micro.h"
#include"matrix_keypad.h"
#include"timers.h"
#pragma config WDTE=OFF
extern unsigned char sec, min;

unsigned char operational_flag = POWER_ON_SCREEN;
unsigned char reset_flag =RESET_NOTHING;

void init_config(void)
{
//config clcd
    init_clcd();
     init_matrix_keypad();
     //config fan
     FAN_DDR=0;
     FAN=0;
     //config timer
     init_timer2();
     PEIE=1;
     GIE=1;
     //config buzzer
     BUZZER_DDR=0;
     BUZZER=0;


}
void main(void) {
    unsigned char key;
    unsigned char start_mode=0;
    init_config();
    
    while(1)
    {        key=read_matrix_keypad(STATE);//0 1 2 3 4 5 6 7 8 9 * # ALL_RELEASED
        //select the mode based on operational flag in menu screen
        if(operational_flag==MENU_SCREEN)
        {
       
        
            if(key==1)
                {   clear_screen();
                start_mode=0;
                operational_flag= MICRO_MODE;
                clcd_print("Power = 900W",LINE2(0));
                __delay_ms(2000);
                clear_screen();
                reset_flag=RESET_MODE;
                }
            else if(key==2)
            {     clear_screen();
                  start_mode=0;
                  operational_flag=  GRILL_MODE;  
                  reset_flag=RESET_MODE;
            }
          else if(key==3)
            {     clear_screen();
                  start_mode=0;
                  operational_flag=  CONVECTION_MODE; 
                  reset_flag=RESET_MODE;
            }
         else if(key==4)
            {     clear_screen();
                  operational_flag=  START_MODE ;  
                  start_mode=1;
                   reset_flag=RESET_MODE;
         }
        
        }
            
    if(operational_flag==DISPLAY_TIME)//display time
            {  if(key==4)
                {   //operational_flag=START;
                if(start_mode)//inc cooking time by 30 sec
                {sec=sec+30;
                if(sec>59)
                {   min++;
                sec=sec-60;
                }
                
                
                }
                }
            else if(key==5)
            {operational_flag=PAUSE;
                     
            }
          else if(key==6)
            {
                     operational_flag= STOP;
            }
                
                
        
        
        
            }
    else if(operational_flag==PAUSE)
    {
                //resume the oven
        if(key==4)
        {   FAN=1;
            TMR2ON=1;
            operational_flag=DISPLAY_TIME;
        
        }
    
    }
        switch (operational_flag)
        {   case POWER_ON_SCREEN :
            //display poweer on screen
                                    power_on_screen();
                                    operational_flag=MENU_SCREEN;//switching to menu screen
                                    clear_screen();//to clear clcd
                                    break;
        
            case MENU_SCREEN    :
                
                                    display_menu_screen();
                                    break;
                
                
            case MICRO_MODE     :
                                    //read the key and display time
                                set_time(key,reset_flag);
                
                
                
                                     //turn on micro wave and display time
                
                                break;
            case DISPLAY_TIME   :
                time_display();
                break;
                
            case PAUSE:
                //stop fan and timer
                FAN=0;
                TMR2ON=0;
                break;
                
            case STOP :
                            FAN=0;
                            TMR2ON=0;
                             clear_screen();
                            operational_flag=MENU_SCREEN;
                            break;
                
                
                                
                
            case GRILL_MODE    : 
                   set_time(key,reset_flag);
                   break;
                
            case CONVECTION_MODE :
                //set_temperature, set time,display time
                set_temp(key,reset_flag);
                break;
                
            case START_MODE     :  
                    //display time with 30 sec as cooking time
                heat_food();
                break;
                
                
                
                
            
        }
    
    reset_flag=RESET_NOTHING;
    
    }
}


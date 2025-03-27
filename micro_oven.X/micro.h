/* 
 * File:   micro.h
 * Author: K
 *
 * Created on 26 February, 2025, 9:47 PM
 */

#ifndef MICRO_H
#define	MICRO_H

void power_on_screen(void);
void clear_screen(void);
void display_menu_screen(void);
void set_time(unsigned char key,unsigned char reset_flag);
void set_temp(unsigned char key,unsigned char reset_flag);
void time_display(void);
void heat_food(void);
#endif	/* MICRO_H */


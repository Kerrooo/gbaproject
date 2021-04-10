// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "gba.h"
#include "mygbalib.h"

int count = 0; // small counts to count seconds and refresh rate of y 
int sec = 0;  // how many seconds passed
int replay0,replay1,replay2 = 0;  // timer for draw car to compare with interval, every sprite needs their own replay
int y0,y1,y2 = 0;    // y axis for car
int number0 = 3,number1 =100, number2 = 100; 
void bigcount (void) {  //to increase sec and replay every second: so count will not overflow
	if (count == 52 ) {
		sec++;
		replay0++;
		replay1++;
		replay2++;
		count =0;
	}
} 

void drawvehicle(int veh, int id, int speed, int x, int *y, int interval, int starttime, int *nooftimes, int *replay) {  //draws the car travelling down every "interval"
	if ((*replay > interval) && (*nooftimes > 0) && (starttime <= sec)) { 
		drawSprite(veh, id, x, *y); // y = 0 for first count 
 		if (speed==1){ 
	    (*y)++; //increase y for the next count
		 }
		else if (speed == 2) {
		(*y) = (*y +2);
		}     
		if (*y == 160) {   //once reach the bottom of screen, hide car and refresh y and replay
		drawSprite( veh, id, 240, 160);	
		*y = 0;
		*replay = 0;
		(*nooftimes)--;
		}
	}
}

void Handler(void)
{
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one
    
	 if ((REG_IF & INT_TIMER0) == INT_TIMER0) // TODO: replace XXX with the specific interrupt you are handling
    {	
        // TODO: Handle timer interrupt here
	 count++;  
	 bigcount();   //to increase sec and replay every "second"   
	 drawvehicle(CAR,0,1,112,&y0,3,3,&number0, &replay0); //car, id, speed(1 or 2), x, dont change y, interval, start time, number of times, dont care
	 drawvehicle(CAR2,1,2,126,&y1,4,4,&number1, &replay1);// middle dotted line should be at 124 and 100
	 drawvehicle(CAR3,2,2,98,&y2,2,2,&number2, &replay2); // change number from global int. set x, interval, start time here. 
    } 
    
    REG_IF = REG_IF; // Update interrupt table, to confirm we have handled this interrupt
    
    REG_IME = 0x01;  // Re-enable interrupt handling
}


// -----------------------------------------------------------------------------
// Project Entry Point    
// -----------------------------------------------------------------------------
int main(void)
{
   
    // Set Mode 2
    *(unsigned short *) 0x4000000 = 0x40 | 0x2 | 0x1000;

    // Fill SpritePal
	 fillPalette();

    // Fill SpriteData
    fillSprites();

    // Set Handler Function for interrupts and enable selected interrupts
	 REG_IME = 0x0;
	 REG_INT = (int)&Handler;
    REG_IE |= INT_TIMER0;				// TODO: complete this line to choose which timer interrupts to enable
	 
    // Set Timer Mode (fill that section and replace TMX with selected timer number)
    REG_TM0D = 60535;			// TODO: interrupt after 0.019 sec (refresh rate)
	 //REG_TM1D =         
    //REG_TM2D = 0;
    REG_TM0CNT |= TIMER_FREQUENCY_64 | TIMER_ENABLE | TIMER_INTERRUPTS;		// TODO: complete this line to set timer frequency and enable timer   
 	 //REG_TM1CNT |= TIMER_FREQUENCY | TIMER_ENABLE;
	 //REG_TM2CNT |= TIMER_FREQUENCY | TIMER_ENABLE;

	 REG_IME = 0x1;		// Enable interrupt handling
    while(1);

	return 0;
}








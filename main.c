// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "gba.h"
#include "mygbalib.h"

int count = 0; // small counts to count seconds and refresh rate of y 
int sec = 0;  // how many seconds passed
int replay0,replay1,replay2 = 0;  // timer for draw car to compare with interval, every sprite needs their own replay
int y0,y1,y2 = 0;    // y axis for car
int number0 = 3;
void bigcount (void) {  //to increase sec and replay every second: so count will not overflow
	if (count == 52 ) {
		sec++;
		replay0++;
		replay1++;
		replay2++;
		count =0;
	}
} 

void drawcar(int x, int *y, int interval, int starttime, int *nooftimes, int *replay) {  //draws the car travelling down every "interval"
	if ((*replay > interval) && (*nooftimes > 0) && (starttime <= sec)) { 
		drawSprite(CAR, 0, x, *y); // y = 0 for first count 
 		(*y)++;     //increase y for the next count
		if (*y == 160) {   //once reach the bottom of screen, hide car and refresh y and replay
		drawSprite( CAR, 0, 240, 160);	
		*y = 0;
		*replay = 0;
		(*nooftimes)--;
		}
	}
}

void drawcar1(void) {  //draws the car travelling down every "interval"
	int interval = 4;
	if (replay1 > interval ) { 
		drawSprite( CAR, 1, 130, y1); // y = 0 for first count 
 		y1++;     //increase y for the next count, increase speed here
		if (y1 == 160) {   //once reach the bottom of screen, hide car and refresh y and replay
		drawSprite( CAR, 1, 240, 160);	
		y1 = 0;
		replay1 = 0;
		}
	}
}
/*void drawcar2(void) {  //draws the car travelling down every "interval"
	int interval = 3;
	if (replay2 > interval && sec > 7 ) { 
		drawSprite( CAR, 2, 110, y2); // y = 0 for first count 
 		y2++;     //increase y for the next count
		if (y2 == 160) {   //once reach the bottom of screen, hide car and refresh y and replay
		drawSprite( CAR, 2, 240, 160);	
		y2 = 0;
		replay2 = 0;
		}
	}
}*/

void Handler(void)
{
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one
    
	 if ((REG_IF & INT_TIMER0) == INT_TIMER0) // TODO: replace XXX with the specific interrupt you are handling
    {	
        // TODO: Handle timer interrupt here
	 count++;  
	 bigcount();   //to increase sec and replay every "second"   
	 drawcar(120,&y0,3,3,&number0, &replay0); // change number from global int. set x, interval, start time here.
	 drawcar1(); 
	 //drawcar(110,&y1,2,2,2,&replay1);
	 //drawcar(130,&y2,5,4,5,&replay2);    // draw the car every count if conditions are met
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



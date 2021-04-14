// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "gba.h"
#include "mygbalib.h"

int state = 0;// game state: 0 for menu, 1 for stage 1, 2 for stage 2.
int count = 0; // small counts to count seconds and refresh rate of y 
int sec = 0;  // how many seconds passed
int replay0,replay1,replay2,replay3,replay4,replay5,replay6 = 0;  // timer for draw car to compare with interval, every sprite needs their own replay
int y0,y1,y2,y3,y4,y5,y6 = 0;    // y axis for car
int number0 = 3,number1 =3, number2 = 3, number3 = 3,number4 = 4,number5 = 4,number6 = 3; 
int xuser = 120;	// x-axis for user's car
int middle = 112, left = 96, right = 128;	// x-axis for drawvehicle

void bigcount (void) {  //to increase sec and replay every second: so count will not overflow
	if (count == 53 ) {
		sec++;
		replay0++;
		replay1++;
		replay2++;
		replay3++;
		replay4++;
		replay5++;
		replay6++;
		count =0;
	}
	if (count > 53) {
		count =0;
	}
} 

void drawvehicle(int veh, int id, int speed, int x, int *y, int interval, int starttime, int *nooftimes, int *replay) {  //draws the car travelling down every "interval"
	if ((*replay >= interval) && (*nooftimes > 0) && (starttime <= sec)) { 	
 		if (speed==1){ //3.01 sec to clear screen
	   	(*y)++; //increase y for the next count
		 }
		else if (speed == 2) { // 1.509 sec to clear screen
		(*y) = (*y +2);
		}
		drawSprite(veh, id, x, *y); // y = 0 for first count      
		if (*y == 160) {   //once reach the bottom of screen, hide car and refresh y and replay
		drawSprite( veh, id, 240, 160);	
		*y = 0;	
		(*nooftimes)--;
		*replay = 0;
		}
	}
}

void game(void) {
	if (state == 0) { 
		drawSprite(CAR0,0,240,160);
		drawSprite(CAR1,1,240,160);
		drawSprite(CAR2,2,240,160);
		drawSprite(CAR2,3,240,160);
		drawSprite(CAR0,4,240,160);
		drawSprite(CAR0,5,240,160);
		drawSprite(CAR1,6,240,160);
		drawSprite(user,9,240,160);
			if (count == 52) {
				drawSprite( P, 100, 32, 72);
				drawSprite( R, 101, 48, 72);
				drawSprite( E, 102, 64, 72);
				drawSprite( S, 103, 80, 72);
				drawSprite( S, 104, 96, 72);
				drawSprite( S, 105, 128, 72);
				drawSprite( T, 106, 144, 72);
				drawSprite( A, 107, 160, 72);
				drawSprite( R, 108, 176, 72);
				drawSprite( T, 109, 192, 72);
			}
			if (count == 104) {
				drawSprite( S, 100, 240, 160);
				drawSprite( T, 101, 240, 160);
				drawSprite( A, 102, 240, 160);
				drawSprite( R, 103, 240, 160);
				drawSprite( T, 104, 240, 160);
				drawSprite( P, 105, 240, 160);
				drawSprite( R, 106, 240, 160);
				drawSprite( E, 107, 240, 160);
				drawSprite( S, 108, 240, 160);
				drawSprite( S, 109, 240, 160);
				count =0;
			}
	}
	else if(state == 1) { 
		bigcount();
		drawSprite( S, 100, 240, 160);
		drawSprite( T, 101, 240, 160);
		drawSprite( A, 102, 240, 160);
		drawSprite( R, 103, 240, 160);
		drawSprite( T, 104, 240, 160);
		drawSprite( P, 105, 240, 160);
		drawSprite( R, 106, 240, 160);
		drawSprite( E, 107, 240, 160);
		drawSprite( S, 108, 240, 160);									//interval must be 2 or more
		drawSprite( S, 109, 240, 160);									// start time must be more than interval
		drawvehicle(CAR0,0,1,middle,&y0,3,3,&number0, &replay0); //car, id, speed(1 or 2), x, dont change y, interval, start time, number of times, dont care
	   drawvehicle(CAR1,1,1,right,&y1,4,4,&number1, &replay1); // middle dotted line should be at 124 and 100
	   drawvehicle(CAR2,2,1,left,&y2,3,5,&number2, &replay2); // change number from global int. set x, interval, start time here.
		drawvehicle(CAR2,3,1,middle,&y3,3,7,&number3, &replay3);
		drawvehicle(CAR0,4,1,right,&y4,5,11,&number4, &replay4);
		drawvehicle(CAR0,5,1,left,&y5,4,10,&number5, &replay5);
		drawvehicle(CAR1,6,1,middle,&y6,3,17,&number6, &replay6);
		drawSprite(user, 9, xuser, 140);
		if((y0==140&&((xuser-8<=middle)&&(middle<=xuser+8)))||(y1==140&&((xuser-8<=right)&&(right<=xuser+8)))||(y2==140&&((xuser-8<=left)&&(left<=xuser+8)))||(y3==140&&((xuser-8<=middle)&&(middle<=xuser+8)))||(y4==140&&((xuser-8<=right)&&(right<=xuser+8)))||(y5==140&&((xuser-8<=left)&&(left<=xuser+8)))||(y6==140&&((xuser-8<=middle)&&(middle<=xuser+8)))) {	// At y=140, check if any point at the front of the car intersects other cars.
			state = 0;
			}			
	}
	else if(state == 2) {
   }
} 

void Handler(void)
{
    REG_IME = 0x00; // Stop all other interrupt handling, while we handle this current one
    
	 if ((REG_IF & INT_TIMER0) == INT_TIMER0) // TODO: replace XXX with the specific interrupt you are handling
    {	
        // TODO: Handle timer interrupt here
	 checkbutton();
	 count++;
	 game();  
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
    REG_TM0D = 60618;			// TODO: interrupt after 0.0188 sec (refresh rate) -4917 
	 //REG_TM1D =         
    //REG_TM2D = 0;
    REG_TM0CNT |= TIMER_FREQUENCY_64 | TIMER_ENABLE | TIMER_INTERRUPTS;		// TODO: complete this line to set timer frequency and enable timer   
 	 //REG_TM1CNT |= TIMER_FREQUENCY | TIMER_ENABLE;
	 //REG_TM2CNT |= TIMER_FREQUENCY | TIMER_ENABLE;
	 //REG_P1CNT |= 0x7FFF;
	 REG_IME = 0x1;		// Enable interrupt handling
    while(1);

	return 0;
}



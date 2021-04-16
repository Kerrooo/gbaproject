// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "gba.h"
#include "mygbalib.h"

int state = 0;// game state: 0 for menu, 1 for stage 1, 2 for stage 2, 3 for lose, 4 for win.
int count = 0; // small counts to count seconds and refresh rate of y 
int sec = 0;  // how many seconds passed
int sec2 = 0;
int sec3 = 0;
int sec4 = 0;
int replay0,replay1,replay2,replay3,replay4,replay5,replay6 = 0;  // timer for draw car to compare with interval, every sprite needs their own replay
int replay10,replay11,replay12,replay13,replay14,replay15,replay16 = 0;
int y0,y1,y2,y3,y4,y5,y6 = 0;    // y axis for car
int y10,y11,y12,y13,y14,y15,y16 = 0;
int number0 = 3,number1 =3, number2 = 3, number3 = 3,number4 = 4,number5 = 4,number6 = 3;
int number10 = 3,number11 =3, number12 = 3, number13 = 3,number14 = 4,number15 = 4,number16 = 3;  
int xuser = 120;	// x-axis for user's car
int middle = 112, left = 96, right = 128;	// x-axis for drawvehicle

void resettimer(void) {    // put in bigcount, checks in every sate // also sets initial state of cars need to change both here and top
	if (state != 1) {
		sec = 0;
		replay0 = 0;
		replay1 = 0;
		replay2 = 0;
		replay3 = 0;
		replay4 = 0;
		replay5 = 0;
		replay6 = 0;
		y0 = 0;
		y1 = 0;
		y2 = 0;
		y3 = 0;
		y4 = 0;
		y5 = 0;
		y6 = 0;
		number0 = 3,number1 =3, number2 = 3, number3 = 3,number4 = 4,number5 = 4,number6 = 3; 
	}
	if (state != 2) {
		sec2 = 0;
		replay10 = 0;
		replay11 = 0;
		replay12 = 0;
		replay13 = 0;
		replay14 = 0;
		replay15 = 0;
		replay16 = 0;
		y10,y11,y12,y13,y14,y15,y16 = 0;
		number10 = 3,number11 =3, number12 = 3, number13 = 3,number14 = 4,number15 = 4,number16 = 3; 
	}
	if (state != 3) {
		sec3 = 0;
	}
	if (state != 4) {
		sec4 = 0;
	}
}			

void bigcount (void) {  //to increase sec and replay every second: so count will not overflow
	resettimer();
	if (count > 53 && state != 0) {
		count =0;
	}
	if (state == 1) {		
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
	}
	if (state == 2) {
		if (count == 53 ) {
			sec2++;
			replay10++;
			replay11++;
			replay12++;
			replay13++;
			replay14++;
			replay15++;
			replay16++;
			count =0;
		}
	}
	if (state == 3) {
		if (count == 53 ) {
			sec3++;
			count =0;
		}
	}
	if (state == 4) {
		if (count == 53 ) {
			sec4++;
			count =0;
		}
	}
} 

void drawvehicle(int veh, int id, int speed, int x, int *y, int interval, int starttime, int *nooftimes, int *replay) {  //draws the car travelling down every "interval"
	if ((*replay >= interval) && (*nooftimes > 0) && (starttime <= sec)) { 	
 		drawSprite(veh, id, x, *y); // y = 0 for first count 
		 if (speed==1){ //3.01 sec to clear screen
	   	(*y)++; //increase y for the next count
		 }
		else if (speed == 2) { // 1.509 sec to clear screen
		(*y) = (*y + 2);
		}
		else if (speed == 3) {
		(*y) = (*y + 3);
		}     
		if (*y >= 160) {   //once reach the bottom of screen, hide car and refresh y and replay
		drawSprite( veh, id, 240, 160);	
		*y = 0;	
		(*nooftimes)--;
		*replay = 0;
		}
	}
}

void game(void) {
	bigcount();
	if (state == 0) { 
		drawSprite(CAR0,0,240,160);
		drawSprite(CAR1,1,240,160);
		drawSprite(CAR2,2,240,160);
		drawSprite(CAR2,3,240,160);
		drawSprite(CAR0,4,240,160);
		drawSprite(CAR0,5,240,160);
		drawSprite(CAR1,6,240,160);
		//drawSprite(user,9,240,160);
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
		drawSprite( S, 100, 240, 160);
		drawSprite( T, 101, 240, 160);
		drawSprite( A, 102, 240, 160);
		drawSprite( R, 103, 240, 160);
		drawSprite( T, 104, 240, 160);
		drawSprite( P, 105, 240, 160);
		drawSprite( R, 106, 240, 160);
		drawSprite( E, 107, 240, 160);
		drawSprite( S, 108, 240, 160);									//interval must be 2 or more
		drawSprite( S, 109, 240, 160);
		if (sec ==0) {
			drawSprite( S, 100, 80, 72);
			drawSprite( T, 101, 96, 72);
			drawSprite( A, 102, 112, 72);
			drawSprite( G, 103, 128, 72);
			drawSprite( E, 104, 144, 72);
			drawSprite( O, 105, 176, 72);
			drawSprite( N, 106, 192, 72);
			drawSprite( E, 107, 208, 72);
		}	
		if(sec == 2) {
		drawSprite( S, 100, 240, 160);
		drawSprite( T, 101, 240, 160);
		drawSprite( A, 102, 240, 160);
		drawSprite( G, 103, 240, 160);
		drawSprite( E, 104, 240, 160);
		drawSprite( O, 105, 240, 160);
		drawSprite( N, 106, 240, 160);
		drawSprite( E, 107, 240, 160);
		}									        // start time must be more than interval
		drawvehicle(CAR0,0,1,middle,&y0,3,3,&number0, &replay0); //car, id, speed(1 or 2), x, dont change y, interval, start time, number of times, dont care
	  	drawvehicle(CAR1,1,1,right,&y1,4,4,&number1, &replay1); // middle dotted line should be at 124 and 100
	    drawvehicle(CAR2,2,1,left,&y2,3,5,&number2, &replay2); // change number from global int. set x, interval, start time here.
		drawvehicle(CAR2,3,1,middle,&y3,3,7,&number3, &replay3);
		drawvehicle(CAR0,4,1,right,&y4,5,11,&number4, &replay4);
		drawvehicle(CAR0,5,1,left,&y5,4,10,&number5, &replay5);
		drawvehicle(CAR1,6,1,middle,&y6,3,17,&number6, &replay6);
		drawSprite(user, 9, xuser, 140);

		if((y0==140&&((xuser-8<=middle)&&(middle<=xuser+8)))||(y1==140&&((xuser-8<=right)&&(right<=xuser+8)))||(y2==140&&((xuser-8<=left)&&(left<=xuser+8)))||(y3==140&&((xuser-8<=middle)&&(middle<=xuser+8)))||(y4==140&&((xuser-8<=right)&&(right<=xuser+8)))||(y5==140&&((xuser-8<=left)&&(left<=xuser+8)))||(y6==140&&((xuser-8<=middle)&&(middle<=xuser+8)))) {	// At y=140, check if any point at the front of the car intersects other cars.
			count = 0;
			state = 3;
			}
		if (sec == 35) {
		drawSprite( Y1, 101, 60, 72);
		drawSprite( Y2, 102, 76, 72);
		drawSprite( O, 103, 80, 72);
		drawSprite( U, 104, 96, 72);
		drawSprite( W1, 105, 144, 72);
		drawSprite( W2, 106, 160, 72);
		drawSprite( I, 107, 168, 72);
		drawSprite( N, 108, 178, 72);
		}
		if (sec == 37) {   //win condition
			int i2;
			for(i2 = 0; i2 < 128; i2++) {    //clear everything prepare for state 2
        		drawSprite(0, i2, 240,160);  
    		} 
			count = 0;
			state = 2;
		}		
	}
	else if(state == 2) {
		if (sec2 == 0  ) {
			drawSprite( S, 100, 64, 72);
			drawSprite( T, 101, 80, 72);
			drawSprite( A, 102, 96, 72);
			drawSprite( G, 103, 112, 72);
			drawSprite( E, 104, 128, 72);
			drawSprite( T, 105, 176, 72);
			drawSprite( W1, 106, 192, 72);
			drawSprite( W2, 107, 208, 72);
			drawSprite( O, 108, 216, 72);
		}
		if (sec2 == 2) {
			drawSprite( S, 100, 240, 160);
			drawSprite( T, 101, 240, 160);
			drawSprite( A, 102, 240, 160);
			drawSprite( G, 103, 240, 160);
			drawSprite( E, 104, 240, 160);
			drawSprite( T, 105, 240, 160);
			drawSprite( W1, 106, 240, 160);
			drawSprite( W2, 107, 240, 160);
			drawSprite( O, 108, 240, 160);
   	}

		if (sec2 == 5) {   //win condition
			state = 4;
		}		
	}
	else if (state == 3 ) {
		int i3;
		drawSprite(XPLODE, 9, xuser, 140);
		if (sec3 == 2) {
			drawSprite( Y1, 100, 40, 72);
			drawSprite( Y2, 101, 56, 72);
			drawSprite( O, 102, 64, 72);
			drawSprite( U, 103, 80, 72);
			drawSprite( L, 104, 128, 72);
			drawSprite( O, 105, 144, 72);
			drawSprite( S, 106, 160, 72);
			drawSprite( E, 107, 176, 72);
		}
		if (sec3 == 5) {
			sec3 = 0;
			for(i3 = 0; i3 < 128; i3++) {
        		drawSprite(0, i3, 240,160);
    		}
			state = 0;
		}
	}
	else if (state ==4) {
		int i4;
		bigcount();
		drawSprite( Y1, 101, 60, 72);
		drawSprite( Y2, 102, 76, 72);
		drawSprite( O, 103, 80, 72);
		drawSprite( U, 104, 96, 72);
		drawSprite( W1, 105, 144, 72);
		drawSprite( W2, 106, 160, 72);
		drawSprite( I, 107, 168, 72);
		drawSprite( N, 108, 178, 72);
		if (sec4 == 2) {
			sec4 = 0;
			for(i4 = 0; i4 < 128; i4++) {
        		drawSprite(0, i4, 240,160);
    		}
			state =0;
		}
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



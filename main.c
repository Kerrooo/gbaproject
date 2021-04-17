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
int road_y,beach_y,ocean_y,palm_y1,palm_y2,finish_y = 0; //pointer to store the moving y-coordinates of the background for state 1
int road_y2,bridgeleft_y,bridgeright_y,lavaleft_y,lavaright_y,finish_y2 = 0;

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
	}	else if (state != 2) {
		sec2 = 0;
		replay10 = 0;
		replay11 = 0;
		replay12 = 0;
		replay13 = 0;
		replay14 = 0;
		replay15 = 0;
		replay16 = 0;
		y10 = 0;
		y11 = 0;
		y12 = 0;
		y13 = 0;
		y14 = 0;
		y15 = 0;
		y16 = 0;
		number10 = 3,number11 =3, number12 = 3, number13 = 3,number14 = 4,number15 = 4,number16 = 3; 
	} else if (state != 3) {
		sec3 = 0;
	} else if (state != 4) {
		sec4 = 0;
	}
}			

void bigcount (void) {  //to increase sec and replay every second: so count will not overflow
	resettimer();
	if (count > 53 && state != 0) {
		count =0;
	} else if (state == 1) {		
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
	} else if (state == 2) {
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
	} else if (state == 3) {
		if (count == 53 ) {
			sec3++;
			count =0;
		}
	} else if (state == 4) {
		if (count == 53 ) {
			sec4++;
			count =0;
		}
	}
} 

void drawvehicle(int veh, int id, int speed, int x, int *y, int interval, int starttime, int *nooftimes, int *replay) {  //draws the car travelling down every "interval"
	if (((*replay >= interval) && (*nooftimes > 0)) && ((starttime <= sec) || (starttime <= sec2))) { 	
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

void drawRoad(int road1, int road2, int *road_y, int x_start, int width, int road_id) {
	int i, j;
	int x33, y33;
	
	if (*road_y >16) {
		*road_y = 0;
	}

	for (j=0; j<10; j++) {
		y33 = *road_y + j*16;
		for (i=0; i<width; i++) {
			x33 = x_start + i*16;
			if (i == width - 1) {
			drawSprite(road2, road_id, x33, y33);
			} else {
			drawSprite(road1, road_id, x33, y33);
			}
			road_id++;
		}
	}
	*road_y = *road_y + 2;
}	

void drawStationary(int sprite, int x, int id) {
		int i,y = 0;
		
		for (i=0; i<10; i++) {
			drawSprite(sprite, id, x, y);
			y = y +16;
			id++;
		}			
}

int drawYMoving(int sprite, int y, int x, int id) {
	int i,temp_y = 0;
		
	if (y >16) {
		y = 0;
	}	

	for (i=0; i<11; i++) {
		drawSprite(sprite, id, x, temp_y);
		temp_y = y + i*16;		
		id++;
	}	
	y = y + 1;
	return y;
}

int drawXLineMoving(int sprite, int y, int x, int id) {
	int i,temp_x = 0;

	if (y ==162) {
		for (i=0; i<5; i++) {
		drawSprite(sprite, id, 240, 160);
		id++;
		}
	return 162;		
	}

	for (i=0; i<5; i++) {
		temp_x = x + i*16;		
		drawSprite(sprite, id, temp_x, y);		
		id++;
	}
	y = y + 2;
	return y;
}

void clearSprite(void) {
	int i;
	for(i = 0; i < 128; i++) {    //clear everything prepare for state 2
       drawSprite(0, i, 240,160);
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
		if (sec < 2) {
			drawSprite( S, 12, 80, 72);
			drawSprite( T, 13, 96, 72);
			drawSprite( A, 14, 112, 72);
			drawSprite( G, 15, 128, 72);
			drawSprite( E, 16, 144, 72);
			drawSprite( O, 17, 96, 90);
			drawSprite( N, 18, 112, 90);
			drawSprite( E, 19, 128, 90);
		}	
		if(sec == 2) {
		drawSprite( S, 12, 240, 160);
		drawSprite( T, 13, 240, 160);
		drawSprite( A, 14, 240, 160);
		drawSprite( G, 15, 240, 160);
		drawSprite( E, 16, 240, 160);
		drawSprite( O, 17, 240, 160);
		drawSprite( N, 18, 240, 160);
		drawSprite( E, 19, 240, 160);
		}	
		// start time must be more than interval
		drawSprite(user, 0, xuser, 140); //User's car
		drawvehicle(CAR0,1,1,middle,&y0,3,3,&number0, &replay0); //car, id, speed(1 or 2), x, dont change y, interval, start time, number of times, dont care
	  	drawvehicle(CAR1,2,1,right,&y1,4,4,&number1, &replay1); // middle dotted line should be at 124 and 100
	   drawvehicle(CAR2,3,1,left,&y2,3,5,&number2, &replay2); // change number from global int. set x, interval, start time here.
		drawvehicle(CAR2,4,1,middle,&y3,3,7,&number3, &replay3);
		drawvehicle(CAR0,5,1,right,&y4,5,11,&number4, &replay4);
		drawvehicle(CAR0,6,1,left,&y5,4,10,&number5, &replay5);
		drawvehicle(CAR1,7,1,middle,&y6,3,17,&number6, &replay6);
		beach_y = drawYMoving(BEACH, beach_y, 64, 80); //Moving background
		ocean_y = drawYMoving(OCEAN, ocean_y, 48, 91); //Moving background
		palm_y1 = drawYMoving(PALM1, palm_y1, 160, 102); //Moving background
		palm_y2 = drawYMoving(PALM2, palm_y2, 176, 113); //Moving background
	
		drawRoad (ROAD1, ROAD2, &road_y, 80, 5, 30); //road background that moves downwards


		if((y0==140&&((xuser-8<=middle)&&(middle<=xuser+8)))||(y1==140&&((xuser-8<=right)&&(right<=xuser+8)))||(y2==140&&((xuser-8<=left)&&(left<=xuser+8)))||(y3==140&&((xuser-8<=middle)&&(middle<=xuser+8)))||(y4==140&&((xuser-8<=right)&&(right<=xuser+8)))||(y5==140&&((xuser-8<=left)&&(left<=xuser+8)))||(y6==140&&((xuser-8<=middle)&&(middle<=xuser+8)))) {	// At y=140, check if any point at the front of the car intersects other cars.
			count = 0;
			state = 3;
			}
		if (sec > 8) {
			finish_y = drawXLineMoving(FINISH, finish_y, 80, 25); //draws the finish line
		}
		
		
		if (sec == 11) {
		drawSprite( S, 12, 80, 72);
		drawSprite( T, 13, 96, 72);
		drawSprite( A, 14, 112, 72);
		drawSprite( G, 15, 128, 72);
		drawSprite( E, 16, 144, 72);
		drawSprite( O, 17, 96, 90);
		drawSprite( N, 18, 112, 90);
		drawSprite( E, 19, 128, 90);
		drawSprite( C, 20, 80, 108);
		drawSprite( L, 21, 96, 108);
		drawSprite( E, 22, 112, 108);
		drawSprite( A, 23, 128, 108);
		drawSprite( R, 24, 144, 108);
		
		}
		if (sec == 13) {   //win condition
			clearSprite();	  
			count = 0;
			state = 2;
		}		
	}
	else if(state == 2) {
		if (sec2 == 0  ) {
			drawSprite( S, 12, 80, 72);
			drawSprite( T, 13, 96, 72);
			drawSprite( A, 14, 112, 72);
			drawSprite( G, 15, 128, 72);
			drawSprite( E, 16, 144, 72);
			drawSprite( T, 17, 96, 90);
			drawSprite( W, 18, 112, 90);
			drawSprite( O, 19, 128, 90);
		}
		if (sec2 == 2) {
			drawSprite( S, 12, 240, 160);
			drawSprite( T, 13, 240, 160);
			drawSprite( A, 14, 240, 160);
			drawSprite( G, 15, 240, 160);
			drawSprite( E, 16, 240, 160);
			drawSprite( T, 17, 240, 160);
			drawSprite( W, 18, 240, 160);
			drawSprite( O, 19, 240, 160);
   	}
		
		drawSprite(user, 0, xuser, 140); //User's car
		drawvehicle(CAR0,1,1,middle,&y10,3,3,&number10, &replay10); //car, id, speed(1 or 2), x, dont change y, interval, start time, number of times, dont care
	  	drawvehicle(CAR1,2,1,right,&y11,4,4,&number11, &replay11); // middle dotted line should be at 124 and 100
	   drawvehicle(CAR2,3,1,left,&y12,3,5,&number12, &replay12); // change number from global int. set x, interval, start time here.
		drawvehicle(CAR2,4,1,middle,&y13,3,7,&number13, &replay13);
		drawvehicle(CAR0,5,1,right,&y14,5,11,&number14, &replay14);
		drawvehicle(CAR0,6,1,left,&y15,4,10,&number15, &replay15);
		drawvehicle(CAR1,7,1,middle,&y16,3,17,&number16, &replay16);
		
		drawRoad(ROAD1, ROAD2, &road_y2, 80, 5, 30);
		bridgeleft_y = drawYMoving(BRIDGELEFT, bridgeleft_y, 64, 80);
		bridgeright_y = drawYMoving(BRIDGERIGHT, bridgeright_y, 160, 91);			
		lavaleft_y = drawYMoving(LAVALEFT, lavaleft_y, 48, 102);
		lavaright_y =drawYMoving(LAVARIGHT, lavaright_y, 176, 113);

		if (sec2 > 8) {
			finish_y2 = drawXLineMoving(FINISH, finish_y, 80, 25); //draws the finish line
		}		

		if (sec2 == 11) {
			drawSprite( S, 12, 80, 72);
			drawSprite( T, 13, 96, 72);
			drawSprite( A, 14, 112, 72);
			drawSprite( G, 15, 128, 72);
			drawSprite( E, 16, 144, 72);
			drawSprite( T, 17, 96, 90);
			drawSprite( W, 18, 112, 90);
			drawSprite( O, 19, 128, 90);
			drawSprite( C, 20, 80, 108);
			drawSprite( L, 21, 96, 108);
			drawSprite( E, 22, 112, 108);
			drawSprite( A, 23, 128, 108);
			drawSprite( R, 24, 144, 108);
		}
		if (sec2 == 13) {   //win condition
			clearSprite();
			state = 4;
		}		
	}
	else if (state == 3 ) {
		drawSprite(XPLODE,124, xuser, 140);
		if (sec3 == 2) {
			drawSprite( Y, 100, 80, 72);			
			drawSprite( O, 102, 112, 72);
			drawSprite( U, 103, 128, 72);
			drawSprite( L, 104, 80, 72);
			drawSprite( O, 105, 96, 72);
			drawSprite( S, 106, 112, 72);
			drawSprite( E, 107, 128, 72);
		}
		if (sec3 == 5) {
			sec3 = 0;
			clearSprite();
			state = 0;
		}
	}
	else if (state == 4) {
		bigcount();
		drawSprite( Y, 101, 60, 72);
		drawSprite( O, 103, 80, 72);
		drawSprite( U, 104, 96, 72);
		drawSprite( W, 105, 128, 72);	
		drawSprite( I, 106, 144, 72);
		drawSprite( N, 107, 160, 72);

		if (sec4 == 4) {
			sec4 = 0;
			clearSprite();
			state = 0;
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




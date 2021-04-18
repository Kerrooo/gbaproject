// -----------------------------------------------------------------------------
// C-Skeleton to be used with HAM Library from www.ngine.de
// -----------------------------------------------------------------------------
#include "gba.h"
#include "mygbalib.h"

int state = 0;// game state: 0 for menu, 1 for stage 1, 2 for stage 2, 3 for lose, 4 for win, 5 for credits.
int count = 0; // small counts to count seconds and refresh rate of y 
int sec = 0;  // how many seconds passed
int sec2 = 0;
int sec3 = 0;
int sec4 = 0;
int replay0,replay1,replay2,replay3,replay4,replay5,replay6,replay7,replay8,replay9,replay10 = 0;  // timer for draw car to compare with interval, every sprite needs their own replay
int replay20,replay21,replay22,replay23,replay24,replay25,replay26,replay27,replay28,replay29,replay30 = 0;
int y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10 = 0;    // y axis for car
int y20,y21,y22,y23,y24,y25,y26,y27,y28,y29,y30 = 0;
int number0 = 3,number1 =6, number2 = 3, number3 = 4,number4 = 5,number5 = 5,number6 = 4,number7 = 4,number8 = 5,number9 = 4,number10 = 4;
int number20 = 5,number21 = 6, number22 = 4, number23 = 8,number24 = 6,number25 = 8,number26 = 5,number27 = 6,number28 = 6,number29 = 3,number30 = 6; 
int xuser = 120;	// x-axis for user's car
int middle = 112, left = 96, right = 128;	// x-axis for drawvehicle
int road_y,beach_y,ocean_y,palm_y1,palm_y2,finish_y = 0; //pointer to store the moving y-coordinates of the background for state 1
int road_y2,bridgeleft_y,bridgeright_y,lavaleft_y,lavaright_y,finish_y2 = 0;
int select = 0, blinker = 0; // menu selection and visual cue

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
		replay7 = 0;
		replay8 = 0;
		replay9 = 0;
		replay10 = 0;
		y0 = 0;
		y1 = 0;
		y2 = 0;
		y3 = 0;
		y4 = 0;
		y5 = 0;
		y6 = 0;
		y7 = 0;
		y8 = 0;
		y9 = 0;
		y10 = 0;
		number0 = 3;
		number1 =6;
		number2 = 3;
		number3 = 4;
		number4 = 5;
		number5 = 5;
		number6 = 4;
		number7 = 4;
		number8 = 5;
		number9 = 4;
		number10 = 4;
		finish_y = 0; 
	}
	if (state != 2) {
		sec2 = 0;
		replay20 = 0;
		replay21 = 0;
		replay22 = 0;
		replay23 = 0;
		replay24 = 0;
		replay25 = 0;
		replay26 = 0;
		replay27 = 0;
		replay28 = 0;
		replay29 = 0;
		replay30 = 0;
		y20 = 0;
		y21 = 0;
		y22 = 0;
		y23 = 0;
		y24 = 0;
		y25 = 0;
		y26 = 0;
		y27 = 0;
		y28 = 0;
		y29 = 0;
		y30 = 0;
		number20 = 5;
		number21 = 6;
		number22 = 4; 
		number23 = 8;
		number24 = 6;
		number25 = 8;
		number26 = 5;
		number27 = 6;
		number28 = 6;
		number29 = 3;
		number30 = 6;
		finish_y2 = 0; 
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
	else if (state == 0 || state == 5) {
		if (count == 25 )	{
			blinker ++;
			count = 0;
		}
	}	
	else if (state == 1) {
		replay0++;
		replay1++;
		replay2++;
		replay3++;
		replay4++;
		replay5++;
		replay6++;
		replay7++;
		replay8++;
		replay9++;
		replay10++;	
		if (count == 53 ) {
			sec++;
			count =0;		
		}
	}	
	else if (state == 2) {
		replay20++;
		replay21++;
		replay22++;
		replay23++;
		replay24++;
		replay25++;
		replay26++;
		replay27++;
		replay28++;
		replay29++;
		replay30++;
		if (count == 53 ) {
			sec2++;
			count =0;
		}
	} 
	else if (state == 3) {
		if (count == 53 ) {
			sec3++;
			count =0;
		}
	} 
	else if (state == 4) {
		if (count == 53 ) {
			sec4++;
			count =0;
		}
	}
} 

void drawvehicle(int veh, int id, int speed, int x, int *y, int interval, int starttime, int *nooftimes, int *replay) {  //draws the car travelling down every "interval"
	if (((*replay >= interval*53) && (*nooftimes > 0)) && ((starttime <= sec) || (starttime <= sec2))) { 	
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

void drawMenu(void)	{
	drawSprite( XPLODE, 113, 70, 30);
	drawSprite( V, 114, 86, 36);
	drawSprite( R, 115, 104, 36);
	drawSprite( O, 116, 120, 36);
	drawSprite( O, 117, 136, 36);
	drawSprite( M, 118, 152, 36);
		
	drawSprite( S, 100, 88, 96);
	drawSprite( T, 101, 104, 96);
	drawSprite( A, 102, 120, 96);
	drawSprite( R, 103, 136, 96);
	drawSprite( T, 104, 152, 96);

	drawSprite( C, 105, 72, 130);
	drawSprite( R, 106, 88, 130);
	drawSprite( E, 107, 104, 130);
	drawSprite( D, 108, 120, 130);
	drawSprite( I, 109, 136, 130);
	drawSprite( T, 110, 144, 130);
	drawSprite( S, 111, 162, 130);

	if(select == 0)	{
		drawSprite( ARROW, 112, 50, 96);
	}

	else if(select == 1)	{
		drawSprite( ARROW, 112, 50, 130);
	}

	if(blinker%2)	{
		if(select == 0)	{
			drawSprite( S, 100, 240, 160);
			drawSprite( T, 101, 240, 160);
			drawSprite( A, 102, 240, 160);
			drawSprite( R, 103, 240, 160);
			drawSprite( T, 104, 240, 160);
		}
		else if(select == 1)	{
			drawSprite( C, 105, 240, 160);
			drawSprite( R, 106, 240, 160);
			drawSprite( E, 107, 240, 160);
			drawSprite( D, 108, 240, 160);
			drawSprite( I, 109, 240, 160);
			drawSprite( T, 110, 240, 160);
			drawSprite( S, 111, 240, 160);
		}
	}
}

void drawCredits(void)	{
	drawSprite( C, 105, 72, 24);
	drawSprite( R, 106, 88, 24);
	drawSprite( E, 107, 104, 24);
	drawSprite( D, 108, 120, 24);
	drawSprite( I, 109, 136, 24);
	drawSprite( T, 110, 144, 24);
	drawSprite( S, 111, 162, 24);

	drawSprite( K, 120, 80, 72);
	drawSprite( E, 121, 96, 72);	
	drawSprite( R, 122, 112, 72);	
	drawSprite( V, 123, 126, 72);	
	drawSprite( I, 124, 144, 72);	
	drawSprite( N, 125, 152, 72);

	drawSprite( K, 126, 88, 96);
	drawSprite( E, 127, 104, 96);	
	drawSprite( N, 128, 120, 96);	
	drawSprite( J, 113, 136, 96);	
	drawSprite( I, 114, 152, 96);	

	drawSprite( R, 115, 104, 120);	
	drawSprite( O, 116, 120, 120);	
	drawSprite( N, 117, 136, 120);	

	drawSprite( ARROW, 112, 220, 140);

	if(blinker%2)	{
		drawSprite( ARROW, 112, 240, 160);
	}
}

void game(void) {
	bigcount();
	if (state == 0) { 
		drawMenu();
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
		drawvehicle(CAR0,1,1,middle,&y0,0,3,&number0, &replay0); //car, id, speed(1 or 2), x, dont change y, interval, start time, number of times, dont care
	  	drawvehicle(CAR1,2,1,right,&y1,1,4,&number1, &replay1); // middle dotted line should be at 124 and 100
	    drawvehicle(CAR2,3,1,left,&y2,0,5,&number2, &replay2); // change number from global int. set x, interval, start time here.
		drawvehicle(CAR2,4,1,middle,&y3,0,7,&number3, &replay3);
		drawvehicle(CAR0,5,1,right,&y4,1,10,&number4, &replay4);
		drawvehicle(CAR0,6,1,left,&y5,1,10,&number5, &replay5);
		drawvehicle(CAR1,7,1,middle,&y6,0,17,&number6, &replay6);
		drawvehicle(CAR2,8,2,80,&y7,0,6,&number7, &replay7); 
		drawvehicle(CAR0,9,1,144,&y8,2,5,&number8, &replay8);
		drawvehicle(CAR1,10,1,80,&y9,1,16,&number9, &replay9);
		drawvehicle(CAR2,11,1,144,&y10,0,8,&number10, &replay10);
		
		beach_y = drawYMoving(BEACH, beach_y, 64, 80); //Moving background
		ocean_y = drawYMoving(OCEAN, ocean_y, 48, 91); //Moving background
		palm_y1 = drawYMoving(PALM1, palm_y1, 160, 102); //Moving background
		palm_y2 = drawYMoving(PALM2, palm_y2, 176, 113); //Moving background
	
		drawRoad (ROAD1, ROAD2, &road_y, 80, 5, 30); //road background that moves downwards


if(((y0>=134&&y0<=140)&&((xuser-8<=middle)&&(middle<=xuser+8)))||((y1>=134&&y1<=141)&&((xuser-8<=right)&&(right<=xuser+8)))||((y2>=134&&y2<=140)&&((xuser-8<=left)&&(left<=xuser+8)))||((y3>=134&&y3<=140)&&((xuser-8<=middle)&&(middle<=xuser+8)))||((y4>=134&&y4<=140)&&((xuser-8<=right)&&(right<=xuser+8)))||((y5>=134&&y5<=140)&&((xuser-8<=left)&&(left<=xuser+8)))||((y6>=134&&y6<=140)&&((xuser-8<=middle)&&(middle<=xuser+8)))||((y7>=134&&y7<=140)&&((xuser-8<=80)&&(80<=xuser+8)))||((y8>=134&&y8<=140)&&((xuser-8<=144)&&(144<=xuser+8)))||((y9>=134&&y9<=140)&&((xuser-8<=80)&&(80<=xuser+8)))||((y10>=134&&y10<=140)&&((xuser-8<=144)&&(144<=xuser+8)))) { // At y=140, check if any point at the front of the car intersects other cars.			count = 0;
			count = 0;
			state = 3;
			}
		if (sec > 29) {
			finish_y = drawXLineMoving(FINISH, finish_y, 80, 1); //draws the finish line
		}
		
		
		if (sec == 32) {
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
		if (sec == 35) {   //win condition
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
		drawvehicle(CAR0,1,2,middle,&y20,2,4,&number20, &replay20); //car, id, speed(1 or 2), x, dont change y, interval, start time, number of times, dont care
	  	drawvehicle(CAR1,2,3,right,&y21,0,3,&number21, &replay21); // middle dotted line should be at 124 and 100
	    drawvehicle(CAR2,3,2,left,&y22,2,3,&number22, &replay22); // change number from global int. set x, interval, start time here.
		drawvehicle(CAR2,4,3,middle,&y23,0,19,&number23, &replay23);
		drawvehicle(CAR0,5,2,right,&y24,1,15,&number24, &replay24);
		drawvehicle(CAR0,6,3,left,&y25,1,15,&number25, &replay25);
		drawvehicle(CAR1,7,2,144,&y26,1,3,&number26, &replay26);
		drawvehicle(CAR0,8,3,80,&y27,1,6,&number27, &replay27);
		drawvehicle(CAR1,9,2,144,&y28,1,11,&number28, &replay28);
		drawvehicle(CAR2,10,2,80,&y29,2,17,&number29, &replay29);
		drawvehicle(CAR2,11,3,144,&y30,0,22,&number30, &replay30);
		
		drawRoad(ROAD1, ROAD2, &road_y2, 80, 5, 30);
		bridgeleft_y = drawYMoving(BRIDGELEFT, bridgeleft_y, 64, 80);
		bridgeright_y = drawYMoving(BRIDGERIGHT, bridgeright_y, 160, 91);			
		lavaleft_y = drawYMoving(LAVALEFT, lavaleft_y, 48, 102);
		lavaright_y =drawYMoving(LAVARIGHT, lavaright_y, 176, 113);

		if(((y20>=134&&y20<=140)&&((xuser-8<=middle)&&(middle<=xuser+8)))||((y21>=134&&y21<=141)&&((xuser-8<=right)&&(right<=xuser+8)))||((y22>=134&&y22<=140)&&((xuser-8<=left)&&(left<=xuser+8)))||((y23>=134&&y23<=140)&&((xuser-8<=middle)&&(middle<=xuser+8)))||((y24>=134&&y24<=140)&&((xuser-8<=right)&&(right<=xuser+8)))||((y25>=134&&y25<=140)&&((xuser-8<=left)&&(left<=xuser+8)))||((y26>=134&&y26<=140)&&((xuser-8<=144)&&(144<=xuser+8)))||((y27>=134&&y27<=140)&&((xuser-8<=80)&&(80<=xuser+8)))||((y28>=134&&y28<=140)&&((xuser-8<=144)&&(144<=xuser+8)))||((y29>=134&&y29<=140)&&((xuser-8<=80)&&(80<=xuser+8)))||((y30>=134&&y30<=140)&&((xuser-8<=144)&&(144<=xuser+8)))) {	// At y=140, check if any point at the front of the car intersects other cars.
			sec3 = 0;
			state = 3;
			}

		if (sec2 > 29) {
			finish_y2 = drawXLineMoving(FINISH, finish_y2, 80, 1); //draws the finish line
		}		

		if (sec2 == 32) {
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
		if (sec2 == 35) {   //win condition
			clearSprite();
			state = 4;
		}		
	}
	else if (state == 3 ) {
		drawSprite(XPLODE,0, xuser, 140);
		if (sec3 == 2) {
			drawSprite( Y, 2, 96, 72);			
			drawSprite( O, 3, 112, 72);
			drawSprite( U, 4, 128, 72);
			drawSprite( L, 5, 88, 88);
			drawSprite( O, 6, 104, 88);
			drawSprite( S, 7, 120, 88);
			drawSprite( E, 8, 136, 88);
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
		drawSprite( I, 106, 148, 72);
		drawSprite( N, 107, 156, 72);

		if (sec4 == 4) {
			sec4 = 0;
			clearSprite();
			state = 0;
		}
	}
	else if (state == 5)	{
		drawCredits();
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




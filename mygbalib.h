#include "sprites.h"
#include "gba.h"
#define INPUT                      (KEY_MASK & (~REG_KEYS))
extern int state;
extern int xuser;
// Updated upstream
extern int select;
extern int blinker; //delay for buttons in main menu and credits
extern int select2;
extern int blinker2;
extern int count1;
extern int cheatcode;

// Stashed changes
void checkbutton(void)
{
	// Gift function to show you how a function that can be called upon button interrupt to detect which button was pressed and run a specific function for each button could look like. You would have to define each buttonA/buttonB/... function yourself.
    u16 buttons = INPUT;
    
	if (cheatcode >= 6) {
		cheatcode =5;
	}

    if ((buttons & KEY_A) == KEY_A)
    {
     	if (state == 0 && count1 > 15) {
             if (select == 0)   {
                 clearSprite1();
                 state = 1;
             }
             else if (select == 1)   {
                 clearSprite1();
                 state = 5;
             }
         }
        else if (state == 5) {
            clearSprite1();
            state = 0;
        }
        else if (state == 6) {
            if (select2 == 0) {
                clearSprite1();
                state = 2;
            }
            else if (select2 == 1) {
                clearSprite1();
                state = 0;
            }
        }
    }
    if ((buttons & KEY_B) == KEY_B)
    {
		if (state == 0) {
			if (cheatcode == 4) {
				cheatcode = 5;
			}
		} 
    }
    if ((buttons & KEY_SELECT) == KEY_SELECT)
    {
      
    }
    if ((buttons & KEY_START) == KEY_START)
    {
     	if (state == 0 && count1 > 15) {
             if (select == 0)   {
                 clearSprite1();
                 state = 1;
             }
             else if (select == 1 && blinker > 1)   {
                 clearSprite1();
                 state = 5;
                 blinker = 0;
             }
         }
        else if (state == 5 && blinker > 1) {
            clearSprite1();
            state = 0;
            blinker = 0;
        }
     	if (state == 6) {
             if (select2 == 0)   {
                 clearSprite1();
                 state = 2;
             }
             else if (select2 == 1 && blinker2 > 1)   {
                 clearSprite1();
                 state = 0;
                 blinker2 = 0;
             }
        }       
    }
    if ((buttons & KEY_RIGHT) == KEY_RIGHT)
    {
		if (state == 0) {
			if (cheatcode == 1) {
				cheatcode = 2;
			} 
			if (cheatcode == 3) {
				cheatcode = 4;
			}
		}
      if (xuser < 144) {
			xuser++;
		}
    }
    if ((buttons & KEY_LEFT) == KEY_LEFT)
    {
		if (state == 0) {
			if (cheatcode == 0) {
				cheatcode = 1;
			} 
			if (cheatcode == 2) {
				cheatcode = 3;
			}
		}
      if (xuser > 80) {
			xuser--;
		}
    }
    if ((buttons & KEY_UP) == KEY_UP)
    {
       if(state == 0 && count1 > 15)   {
           if(select == 1)  {
               select = 0;
           }
       }
       if(state == 6)   {
           if(select2 == 1)  {
               select2 = 0;
           }
       }
    }
    if ((buttons & KEY_DOWN) == KEY_DOWN)
    {
       if(state == 0 && count1 > 15)   {
           if(select == 0)  {
               select = 1;
           }
       }
       if(state == 6)   {
           if(select2 == 0)  {
               select2 = 1;
           }
       }
    }
}

void fillPalette(void)
{
    int i;

	// Fill the palette in GBA memory
    for (i = 0; i < NCOLS; i++)
        spritePal[i] = palette[i];
}


void fillSprites(void)
{
    int i;

	// Load all sprites in GBA memory
    for (i = 0; i < 128*16*16; i++) {
        spriteData[i] = (sprites[i*2+1] << 8) + sprites[i*2];
 	 }

	// draw all sprites on screen, but all of them outside of the screen (starting at position (240,160) the bottom right corner of the GBA screen)
    for(i = 0; i < 128; i++) {
        drawSprite(0, i, 240, 160);
    }
}


void drawSprite(int numb, int No, int x, int y)
{
	// Same as CA2, make specific sprite (based on its name/numb) appear on screen, as slide number N (each sprite needs a different, arbitrary, N >= 0)
    *(unsigned short *)(0x7000000 + 8*No) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8*No) = x | 0x4000;
    *(unsigned short *)(0x7000004 + 8*No) = numb*8;
}

void clearSprite1(void) {
	int i;
	for(i = 0; i < 128; i++) {    //clear everything prepare for state 2
       drawSprite(0, i, 240, 160);
	}
}



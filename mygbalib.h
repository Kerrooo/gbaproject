#include "sprites.h"
#include "gba.h"
#define INPUT                      (KEY_MASK & (~REG_KEYS))
extern int state;
extern int xuser;
extern int left;
extern int right;
void checkbutton(void)
{
	// Gift function to show you how a function that can be called upon button interrupt to detect which button was pressed and run a specific function for each button could look like. You would have to define each buttonA/buttonB/... function yourself.
    u16 buttons = INPUT;
    
    if ((buttons & KEY_A) == KEY_A)
    {
       
    }
    if ((buttons & KEY_B) == KEY_B)
    {
     
    }
    if ((buttons & KEY_SELECT) == KEY_SELECT)
    {
      
    }
    if ((buttons & KEY_START) == KEY_START)
    {
     	if (state == 0) {
			state = 1;
      }
    }
    if ((buttons & KEY_RIGHT) == KEY_RIGHT)
    {
      		if (xuser < right) {
			xuser++;
		}
    }
    if ((buttons & KEY_LEFT) == KEY_LEFT)
    {
       if (xuser > left) {
			xuser--;
		}
    }
    if ((buttons & KEY_UP) == KEY_UP)
    {
       
    }
    if ((buttons & KEY_DOWN) == KEY_DOWN)
    {
        
    }
}


void fillPalette(void)
{
    int     i;

	// Fill the palette in GBA memory
    for (i = 0; i < NCOLS; i++)
        spritePal[i] = palette[i];
}


void fillSprites(void)
{
    int     i;

	// Load all sprites in GBA memory
    for (i = 0; i < 128*16*16; i++) {
        spriteData[i] = (sprites[i*2+1] << 8) + sprites[i*2];
 	 }

	// draw all sprites on screen, but all of them outside of the screen (starting at position (240,160) the bottom right corner of the GBA screen)
    for(i = 0; i < 128; i++) {
        drawSprite(0, i, 240,160);
    }
}


void drawSprite(int numb, int No, int x, int y)
{
	// Same as CA2, make specific sprite (based on its name/numb) appear on screen, as slide number N (each sprite needs a different, arbitrary, N >= 0)
    *(unsigned short *)(0x7000000 + 8*No) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8*No) = x | 0x4000;
    *(unsigned short *)(0x7000004 + 8*No) = numb*8;
}



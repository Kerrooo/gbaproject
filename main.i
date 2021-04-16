# 1 "main.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "main.c"



# 1 "gba.h" 1







typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef unsigned char byte;
typedef unsigned short hword;
typedef unsigned int word;
# 211 "gba.h"
enum
{
    VBLANK_HANDLER,
    HBLANK_HANDLER,
    VCOUNT_HANDLER,
    TIMER0_HANDLER,
    TIMER1_HANDLER,
    TIMER2_HANDLER,
    TIMER3_HANDLER,
    SERIAL_COM_HANDLER,
    DMA0_HANDLER,
    DMA1_HANDLER,
    DMA2_HANDLER,
    DMA3_HANDLER,
    KEYS_HANDLER,
    CART_HANDLER,
    MAX_INTERRUPT_HANDLERS,
};
# 267 "gba.h"
typedef void (*fp)(void);
# 5 "main.c" 2
# 1 "mygbalib.h" 1
# 1 "sprites.h" 1





int palette[] = {
((0) + (0<<5) + (0<<10)),
((31) + (31<<5) + (31<<10)),
((0) + (31<<5) + (31<<10)),
((26) + (26<<5) + (26<<10)),
((9) + (9<<5) + (9<<10)),
((31) + (31<<5) + (0<<10)),
((31) + (0<<5) + (0<<10)),
((0) + (0<<5) + (31<<10)),
((11) + (8<<5) + (3<<10)),
((27) + (27<<5) + (27<<10)),
((16) + (16<<5) + (16<<10)),
((31) + (17<<5) + (17<<10)),
((31) + (24<<5) + (24<<10)),
((27) + (0<<5) + (0<<10)),
((0) + (16<<5) + (0<<10)),
((0) + (31<<5) + (0<<10)),
((16) + (31<<5) + (16<<10)),
((23) + (31<<5) + (23<<10))
};




u16 sprites[] = {


0,0,0,0,1,5,1,6,
0,0,0,0,1,1,1,6,
0,0,0,4,1,1,1,6,
0,0,0,4,1,1,1,6,
0,0,0,4,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,1,1,6,

6,1,5,1,0,0,0,0,
6,1,1,1,0,0,0,0,
6,1,1,1,4,0,0,0,
6,1,1,1,4,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,0,0,0,0,
10,10,10,1,0,0,0,0,
6,1,1,1,0,0,0,0,

0,0,0,0,1,1,1,6,
0,0,0,0,1,1,1,6,
0,0,0,4,1,10,10,10,
0,0,0,4,1,10,10,10,
0,0,0,4,1,1,1,6,
0,0,0,0,1,1,1,6,
0,0,0,0,1,1,4,4,
0,0,0,0,0,0,0,0,

6,1,1,1,0,0,0,0,
6,1,1,1,0,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,4,0,0,0,
6,1,1,1,4,0,0,0,
6,1,1,1,0,0,0,0,
4,4,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,


0,0,0,0,7,5,7,1,
0,0,0,0,7,7,7,1,
0,0,0,4,7,7,7,1,
0,0,0,4,7,7,7,1,
0,0,0,4,7,10,10,10,
0,0,0,0,7,10,10,10,
0,0,0,0,7,10,10,10,
0,0,0,0,7,7,7,1,

1,7,5,7,0,0,0,0,
1,7,7,7,0,0,0,0,
1,7,7,7,4,0,0,0,
1,7,7,7,4,0,0,0,
10,10,10,7,4,0,0,0,
10,10,10,7,0,0,0,0,
10,10,10,7,0,0,0,0,
1,7,7,7,0,0,0,0,

0,0,0,0,7,7,7,1,
0,0,0,0,7,7,7,1,
0,0,0,4,7,10,10,10,
0,0,0,4,7,10,10,10,
0,0,0,4,7,7,7,1,
0,0,0,0,7,7,7,1,
0,0,0,0,7,7,4,4,
0,0,0,0,0,0,0,0,

1,7,7,7,0,0,0,0,
1,7,7,7,0,0,0,0,
10,10,10,7,4,0,0,0,
10,10,10,7,4,0,0,0,
1,7,7,7,4,0,0,0,
1,7,7,7,0,0,0,0,
4,4,7,7,0,0,0,0,
0,0,0,0,0,0,0,0,


0,0,0,0,1,5,1,15,
0,0,0,0,1,1,1,15,
0,0,0,4,1,1,1,15,
0,0,0,4,1,1,1,15,
0,0,0,4,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,1,1,15,

15,1,5,1,0,0,0,0,
15,1,1,1,0,0,0,0,
15,1,1,1,4,0,0,0,
15,1,1,1,4,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,0,0,0,0,
10,10,10,1,0,0,0,0,
15,1,1,1,0,0,0,0,

0,0,0,0,1,1,1,15,
0,0,0,0,1,1,1,15,
0,0,0,4,1,10,10,10,
0,0,0,4,1,10,10,10,
0,0,0,4,1,1,1,15,
0,0,0,0,1,1,1,15,
0,0,0,0,1,1,4,4,
0,0,0,0,0,0,0,0,

15,1,1,1,0,0,0,0,
15,1,1,1,0,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,4,0,0,0,
15,1,1,1,4,0,0,0,
15,1,1,1,0,0,0,0,
4,4,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,


0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,0,0,0,0,0,1,
1,1,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,

1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,0,0,0,0,0,1,1,
1,0,0,0,0,0,1,1,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,1,

1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,1,1,0,0,0,0,0,
1,1,1,0,0,0,0,0,

1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

0,0,1,1,0,0,1,1,
0,0,1,1,0,0,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,

0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,

0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,

1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,0,0,1,1,
0,0,1,1,0,0,1,1,

0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,

0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,

1,1,0,0,1,1,0,0,
1,1,0,0,1,1,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,

0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,1,1,0,0,
1,1,0,0,1,1,0,0,
1,1,0,0,1,1,0,0,
1,1,0,0,1,1,0,0,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,

1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,

0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,

0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,

0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,

0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

0,0,0,0,1,5,1,2,
0,0,0,0,1,1,1,2,
0,0,0,4,1,1,1,2,
0,0,0,4,1,1,1,2,
0,0,0,4,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,1,1,2,

2,1,5,1,0,0,0,0,
2,1,1,1,0,0,0,0,
2,1,1,1,4,0,0,0,
2,1,1,1,4,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,0,0,0,0,
10,10,10,1,0,0,0,0,
2,1,1,1,0,0,0,0,

0,0,0,0,1,1,1,2,
0,0,0,0,1,1,1,2,
0,0,0,4,1,10,10,10,
0,0,0,4,1,10,10,10,
0,0,0,4,1,1,1,2,
0,0,0,0,1,1,1,2,
0,0,0,0,1,1,4,4,
0,0,0,0,0,0,0,0,

2,1,1,1,0,0,0,0,
2,1,1,1,0,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,4,0,0,0,
2,1,1,1,4,0,0,0,
2,1,1,1,0,0,0,0,
4,4,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,


0,0,0,0,0,0,0,0,
0,14,14,0,0,0,0,14,
0,14,15,15,0,0,0,14,
0,0,0,16,16,0,0,0,
0,0,0,16,0,0,9,0,
0,0,0,0,0,10,3,9,
0,14,15,16,0,10,3,3,
0,14,15,16,16,1,1,1,

14,14,0,0,0,0,0,0,
15,15,14,0,0,0,0,0,
17,17,14,0,0,0,0,0,
17,17,0,0,0,16,15,15,
1,0,0,17,16,16,15,14,
1,10,3,9,17,0,14,14,
1,10,3,3,0,0,0,0,
1,0,10,10,0,0,3,0,

0,0,15,0,1,1,9,1,
0,0,17,17,17,10,1,1,
0,0,17,0,10,0,1,0,
0,17,17,0,17,0,1,3,
14,15,17,17,17,0,0,0,
15,15,16,0,0,0,0,3,
14,15,14,0,0,0,10,0,
0,14,0,0,0,0,0,0,

1,1,1,0,0,10,10,0,
3,3,1,10,0,0,0,0,
3,0,1,1,0,0,0,0,
3,3,17,17,0,0,0,0,
0,17,0,17,17,0,0,0,
0,0,0,0,16,16,14,0,
0,0,0,0,16,15,14,0,
0,0,0,0,0,14,14,0

};
# 2 "mygbalib.h" 2


extern int state;
extern int xuser;
extern int left;
extern int right;
void checkbutton(void)
{

    u16 buttons = (0x3FF & (~*(volatile u16*)0x4000130));

    if ((buttons & 0x001) == 0x001)
    {

    }
    if ((buttons & 0x002) == 0x002)
    {

    }
    if ((buttons & 0x004) == 0x004)
    {

    }
    if ((buttons & 0x008) == 0x008)
    {
        if (state == 0) {
                        state = 1;
      }
    }
    if ((buttons & 0x010) == 0x010)
    {
                if (xuser < right) {
                        xuser++;
                }
    }
    if ((buttons & 0x020) == 0x020)
    {
       if (xuser > left) {
                        xuser--;
                }
    }
    if ((buttons & 0x040) == 0x040)
    {

    }
    if ((buttons & 0x080) == 0x080)
    {

    }
}


void fillPalette(void)
{
    int i;


    for (i = 0; i < 20; i++)
        ((unsigned short *) 0x5000200)[i] = palette[i];
}


void fillSprites(void)
{
    int i;


    for (i = 0; i < 128*16*16; i++) {
        ((unsigned short *) 0x6010000)[i] = (sprites[i*2+1] << 8) + sprites[i*2];
         }


    for(i = 0; i < 128; i++) {
        drawSprite(0, i, 240,160);
    }
}


void drawSprite(int numb, int No, int x, int y)
{

    *(unsigned short *)(0x7000000 + 8*No) = y | 0x2000;
    *(unsigned short *)(0x7000002 + 8*No) = x | 0x4000;
    *(unsigned short *)(0x7000004 + 8*No) = numb*8;
}
# 6 "main.c" 2

int state = 0;
int count = 0;
int sec = 0;
int sec2 = 0;
int sec3 = 0;
int sec4 = 0;
int replay0,replay1,replay2,replay3,replay4,replay5,replay6 = 0;
int replay10,replay11,replay12,replay13,replay14,replay15,replay16 = 0;
int y0,y1,y2,y3,y4,y5,y6 = 0;
int y10,y11,y12,y13,y14,y15,y16 = 0;
int number0 = 3,number1 =3, number2 = 3, number3 = 3,number4 = 4,number5 = 4,number6 = 3;
int number10 = 3,number11 =3, number12 = 3, number13 = 3,number14 = 4,number15 = 4,number16 = 3;
int xuser = 120;
int middle = 112, left = 96, right = 128;

void resettimer(void) {
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

void bigcount (void) {
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

void drawvehicle(int veh, int id, int speed, int x, int *y, int interval, int starttime, int *nooftimes, int *replay) {
        if ((*replay >= interval) && (*nooftimes > 0) && (starttime <= sec)) {
                drawSprite(veh, id, x, *y);
                 if (speed==1){
                (*y)++;
                 }
                else if (speed == 2) {
                (*y) = (*y + 2);
                }
                else if (speed == 3) {
                (*y) = (*y + 3);
                }
                if (*y >= 160) {
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
                drawSprite(0,0,240,160);
                drawSprite(1,1,240,160);
                drawSprite(2,2,240,160);
                drawSprite(2,3,240,160);
                drawSprite(0,4,240,160);
                drawSprite(0,5,240,160);
                drawSprite(1,6,240,160);

                if (count == 52) {
                        drawSprite( 7, 100, 32, 72);
                        drawSprite( 5, 101, 48, 72);
                        drawSprite( 8, 102, 64, 72);
                        drawSprite( 3, 103, 80, 72);
                        drawSprite( 3, 104, 96, 72);
                        drawSprite( 3, 105, 128, 72);
                        drawSprite( 4, 106, 144, 72);
                        drawSprite( 6, 107, 160, 72);
                        drawSprite( 5, 108, 176, 72);
                        drawSprite( 4, 109, 192, 72);
                }
                if (count == 104) {
                        drawSprite( 3, 100, 240, 160);
                        drawSprite( 4, 101, 240, 160);
                        drawSprite( 6, 102, 240, 160);
                        drawSprite( 5, 103, 240, 160);
                        drawSprite( 4, 104, 240, 160);
                        drawSprite( 7, 105, 240, 160);
                        drawSprite( 5, 106, 240, 160);
                        drawSprite( 8, 107, 240, 160);
                        drawSprite( 3, 108, 240, 160);
                        drawSprite( 3, 109, 240, 160);
                        count =0;
                }
        }
        else if(state == 1) {
                drawSprite( 3, 100, 240, 160);
                drawSprite( 4, 101, 240, 160);
                drawSprite( 6, 102, 240, 160);
                drawSprite( 5, 103, 240, 160);
                drawSprite( 4, 104, 240, 160);
                drawSprite( 7, 105, 240, 160);
                drawSprite( 5, 106, 240, 160);
                drawSprite( 8, 107, 240, 160);
                drawSprite( 3, 108, 240, 160);
                drawSprite( 3, 109, 240, 160);
                if (sec ==0) {
                        drawSprite( 3, 100, 80, 72);
                        drawSprite( 4, 101, 96, 72);
                        drawSprite( 6, 102, 112, 72);
                        drawSprite( 9, 103, 128, 72);
                        drawSprite( 8, 104, 144, 72);
                        drawSprite( 10, 105, 176, 72);
                        drawSprite( 11, 106, 192, 72);
                        drawSprite( 8, 107, 208, 72);
                }
                if(sec == 2) {
                drawSprite( 3, 100, 240, 160);
                drawSprite( 4, 101, 240, 160);
                drawSprite( 6, 102, 240, 160);
                drawSprite( 9, 103, 240, 160);
                drawSprite( 8, 104, 240, 160);
                drawSprite( 10, 105, 240, 160);
                drawSprite( 11, 106, 240, 160);
                drawSprite( 8, 107, 240, 160);
                }
                drawvehicle(0,0,1,middle,&y0,3,3,&number0, &replay0);
                drawvehicle(1,1,1,right,&y1,4,4,&number1, &replay1);
            drawvehicle(2,2,1,left,&y2,3,5,&number2, &replay2);
                drawvehicle(2,3,1,middle,&y3,3,7,&number3, &replay3);
                drawvehicle(0,4,1,right,&y4,5,11,&number4, &replay4);
                drawvehicle(0,5,1,left,&y5,4,10,&number5, &replay5);
                drawvehicle(1,6,1,middle,&y6,3,17,&number6, &replay6);
                drawSprite(19, 9, xuser, 140);

                if((y0==140&&((xuser-8<=middle)&&(middle<=xuser+8)))||(y1==140&&((xuser-8<=right)&&(right<=xuser+8)))||(y2==140&&((xuser-8<=left)&&(left<=xuser+8)))||(y3==140&&((xuser-8<=middle)&&(middle<=xuser+8)))||(y4==140&&((xuser-8<=right)&&(right<=xuser+8)))||(y5==140&&((xuser-8<=left)&&(left<=xuser+8)))||(y6==140&&((xuser-8<=middle)&&(middle<=xuser+8)))) {
                        count = 0;
                        state = 3;
                        }
                if (sec == 5) {
                drawSprite( 14, 101, 60, 72);
                drawSprite( 15, 102, 76, 72);
                drawSprite( 10, 103, 80, 72);
                drawSprite( 16, 104, 96, 72);
                drawSprite( 12, 105, 144, 72);
                drawSprite( 13, 106, 160, 72);
                drawSprite( 18, 107, 168, 72);
                drawSprite( 11, 108, 178, 72);
                }
                if (sec == 7) {
                        int i2;
                        for(i2 = 0; i2 < 128; i2++) {
                        drawSprite(0, i2, 240,160);
                }
                        count = 0;
                        state = 2;
                }
        }
        else if(state == 2) {
                if (sec2 == 0 ) {
                        drawSprite( 3, 100, 64, 72);
                        drawSprite( 4, 101, 80, 72);
                        drawSprite( 6, 102, 96, 72);
                        drawSprite( 9, 103, 112, 72);
                        drawSprite( 8, 104, 128, 72);
                        drawSprite( 4, 105, 176, 72);
                        drawSprite( 12, 106, 192, 72);
                        drawSprite( 13, 107, 208, 72);
                        drawSprite( 10, 108, 216, 72);
                }
                if (sec2 == 2) {
                        drawSprite( 3, 100, 240, 160);
                        drawSprite( 4, 101, 240, 160);
                        drawSprite( 6, 102, 240, 160);
                        drawSprite( 9, 103, 240, 160);
                        drawSprite( 8, 104, 240, 160);
                        drawSprite( 4, 105, 240, 160);
                        drawSprite( 12, 106, 240, 160);
                        drawSprite( 13, 107, 240, 160);
                        drawSprite( 10, 108, 240, 160);
        }

                if (sec2 == 5) {
                        state = 4;
                }
        }
        else if (state == 3 ) {
                int i3;
                drawSprite(20, 9, xuser, 140);
                if (sec3 == 2) {
                        drawSprite( 14, 100, 40, 72);
                        drawSprite( 15, 101, 56, 72);
                        drawSprite( 10, 102, 64, 72);
                        drawSprite( 16, 103, 80, 72);
                        drawSprite( 17, 104, 128, 72);
                        drawSprite( 10, 105, 144, 72);
                        drawSprite( 3, 106, 160, 72);
                        drawSprite( 8, 107, 176, 72);
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
                drawSprite( 14, 101, 60, 72);
                drawSprite( 15, 101, 76, 72);
                drawSprite( 10, 102, 80, 72);
                drawSprite( 16, 103, 96, 72);
                drawSprite( 12, 104, 144, 72);
                drawSprite( 13, 104, 160, 72);
                drawSprite( 18, 105, 168, 72);
                drawSprite( 11, 106, 178, 72);
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
    *(u16*)0x4000208 = 0x00;

         if ((*(u16*)0x4000202 & 0x8) == 0x8)
    {

         checkbutton();
         count++;
         game();
    }

    *(u16*)0x4000202 = *(u16*)0x4000202;

    *(u16*)0x4000208 = 0x01;
}





int main(void)
{


    *(unsigned short *) 0x4000000 = 0x40 | 0x2 | 0x1000;


         fillPalette();


    fillSprites();


         *(u16*)0x4000208 = 0x0;
         (*(unsigned int*)0x3007FFC) = (int)&Handler;
    *(u16*)0x4000200 |= 0x8;


    *(u16*)0x4000100 = 60618;


    *(u16*)0x4000102 |= 0x0001 | 0x0080 | 0x0040;



         *(u16*)0x4000208 = 0x1;
    while(1);

        return 0;
}
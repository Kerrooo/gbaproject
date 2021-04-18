#include "gba.h"
#define NCOLS 20


// RGB palette used for sprites. The sprites defined below use the index of the color in the palette (so black = 0, white = 1, ...)
int palette[] = {
RGB(0,0,0), // pure black 0
RGB(31,31,31), // pure white 1
RGB(0,31,31), // light blue 2
RGB(26,26,26), // light grey 3
RGB(9,9,9), // darkest grey 4
RGB(31,31,0), // pure yellow 5
RGB(31,0,0), // pure red 6
RGB(0,0,31), // pure blue 7
RGB(11,8,3), // dark brown 8
RGB(27,27,27), // lightest grey 9
RGB(16,16,16), // dark grey 10
RGB(31,17,17), // light red 11
RGB(31,24,24), // lighter red 12
RGB(27,0,0), // dark red 13
RGB(0,16,0), // darkest green 14
RGB(0,31,0), // pure green 15
RGB(16,31,16), // light green 16
RGB(23,31,23) // lightest green 17
};


// Sprite array, defining each big 16x16 sprite as 4 8x8 tiles, using the palette above

u16 sprites[] = {
#define CAR0 0 // Astro looking Right with NO FIRE
// Tile 00
0,0,0,0,1,5,1,6,
0,0,0,0,1,1,1,6,
0,0,0,4,1,1,1,6,
0,0,0,4,1,1,1,6,
0,0,0,4,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,1,1,6,
//Tile 1
6,1,5,1,0,0,0,0,
6,1,1,1,0,0,0,0,
6,1,1,1,4,0,0,0,
6,1,1,1,4,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,0,0,0,0,
10,10,10,1,0,0,0,0,
6,1,1,1,0,0,0,0,
//Tile 2
0,0,0,0,1,1,1,6,
0,0,0,0,1,1,1,6,
0,0,0,4,1,10,10,10,
0,0,0,4,1,10,10,10,
0,0,0,4,1,1,1,6,
0,0,0,0,1,1,1,6,
0,0,0,0,1,1,4,4,
0,0,0,0,0,0,0,0,
//Tile 3
6,1,1,1,0,0,0,0,
6,1,1,1,0,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,4,0,0,0,
6,1,1,1,4,0,0,0,
6,1,1,1,0,0,0,0,
4,4,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,

#define CAR1 1
// Tile 00
0,0,0,0,7,5,7,1,
0,0,0,0,7,7,7,1,
0,0,0,4,7,7,7,1,
0,0,0,4,7,7,7,1,
0,0,0,4,7,10,10,10,
0,0,0,0,7,10,10,10,
0,0,0,0,7,10,10,10,
0,0,0,0,7,7,7,1,
//Tile 1
1,7,5,7,0,0,0,0,
1,7,7,7,0,0,0,0,
1,7,7,7,4,0,0,0,
1,7,7,7,4,0,0,0,
10,10,10,7,4,0,0,0,
10,10,10,7,0,0,0,0,
10,10,10,7,0,0,0,0,
1,7,7,7,0,0,0,0,
//Tile 2
0,0,0,0,7,7,7,1,
0,0,0,0,7,7,7,1,
0,0,0,4,7,10,10,10,
0,0,0,4,7,10,10,10,
0,0,0,4,7,7,7,1,
0,0,0,0,7,7,7,1,
0,0,0,0,7,7,4,4,
0,0,0,0,0,0,0,0,
//Tile 3
1,7,7,7,0,0,0,0,
1,7,7,7,0,0,0,0,
10,10,10,7,4,0,0,0,
10,10,10,7,4,0,0,0,
1,7,7,7,4,0,0,0,
1,7,7,7,0,0,0,0,
4,4,7,7,0,0,0,0,
0,0,0,0,0,0,0,0,

#define CAR2 2
// Tile 00
0,0,0,0,1,5,1,15,
0,0,0,0,1,1,1,15,
0,0,0,4,1,1,1,15,
0,0,0,4,1,1,1,15,
0,0,0,4,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,1,1,15,
//Tile 1
15,1,5,1,0,0,0,0,
15,1,1,1,0,0,0,0,
15,1,1,1,4,0,0,0,
15,1,1,1,4,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,0,0,0,0,
10,10,10,1,0,0,0,0,
15,1,1,1,0,0,0,0,
//Tile 2
0,0,0,0,1,1,1,15,
0,0,0,0,1,1,1,15,
0,0,0,4,1,10,10,10,
0,0,0,4,1,10,10,10,
0,0,0,4,1,1,1,15,
0,0,0,0,1,1,1,15,
0,0,0,0,1,1,4,4,
0,0,0,0,0,0,0,0,
//Tile 3
15,1,1,1,0,0,0,0,
15,1,1,1,0,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,4,0,0,0,
15,1,1,1,4,0,0,0,
15,1,1,1,0,0,0,0,
4,4,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,

#define S 3
// Tile 00
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,
// Tile 01
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 02
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
//// Tile 03
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

#define T 4
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,0,0,0,0,0,1,
1,1,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
// Tile 01
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,0,0,0,0,0,1,1,
1,0,0,0,0,0,1,1,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
//// Tile 02
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,1,
//// Tile 03
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,1,1,0,0,0,0,0,
1,1,1,0,0,0,0,0,

#define R 5
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
// Tile 01
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
//// Tile 02
0,0,1,1,0,0,1,1,
0,0,1,1,0,0,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
//// Tile 03
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,

#define A 6
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
// Tile 01
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
//// Tile 02
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
//// Tile 03
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

#define P 7
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
// Tile 01
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
//// Tile 02
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
//// Tile 03
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

#define E 8
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
// Tile 01
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
//// Tile 02
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
//// Tile 03
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

#define G 9
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
// Tile 01
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 02
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
//// Tile 03
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

#define O 10
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
// Tile 01
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
//// Tile 02
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
//// Tile 03
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,

#define N 11
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,0,0,1,1,
0,0,1,1,0,0,1,1,
// Tile 01
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
//// Tile 02
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
//// Tile 03
1,1,0,0,1,1,0,0,
1,1,0,0,1,1,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,

#define W 12
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
// Tile 01
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
//// Tile 02
0,0,1,1,0,0,0,1,
0,0,1,1,0,0,0,1,
0,0,1,1,0,1,1,0,
0,0,1,1,0,1,1,0,
0,0,1,1,0,1,1,0,
0,0,1,1,0,1,1,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
//// Tile 03
1,0,0,0,1,1,0,0,
1,0,0,0,1,1,0,0,
0,1,1,0,1,1,0,0,
0,1,1,0,1,1,0,0,
0,1,1,0,1,1,0,0,
0,1,1,0,1,1,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,

#define Y 13
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
// Tile 01
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
//// Tile 02
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,1,1,
//// Tile 03
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

#define U 14
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
// Tile 01
0,0,1,1,1,1,1,1,
0,0,1,1,1,1,1,1,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
//// Tile 02
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
//// Tile 03
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

#define L 15
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
// Tile 01
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 02
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
//// Tile 03
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

#define I 16
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
// Tile 01
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 02
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,0,0,
1,1,1,1,1,1,0,0,
//// Tile 03
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

#define user 17  // User Car
0,0,0,0,1,5,1,2,
0,0,0,0,1,1,1,2,
0,0,0,4,1,1,1,2,
0,0,0,4,1,1,1,2,
0,0,0,4,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,10,10,10,
0,0,0,0,1,1,1,2,
// Tile 1
2,1,5,1,0,0,0,0,
2,1,1,1,0,0,0,0,
2,1,1,1,4,0,0,0,
2,1,1,1,4,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,0,0,0,0,
10,10,10,1,0,0,0,0,
2,1,1,1,0,0,0,0,
// Tile 2
0,0,0,0,1,1,1,2,
0,0,0,0,1,1,1,2,
0,0,0,4,1,10,10,10,
0,0,0,4,1,10,10,10,
0,0,0,4,1,1,1,2,
0,0,0,0,1,1,1,2,
0,0,0,0,1,1,4,4,
0,0,0,0,0,0,0,0,
// Tile 3
2,1,1,1,0,0,0,0,
2,1,1,1,0,0,0,0,
10,10,10,1,4,0,0,0,
10,10,10,1,4,0,0,0,
2,1,1,1,4,0,0,0,
2,1,1,1,0,0,0,0,
4,4,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,

#define XPLODE 18
// Tile 00
0,0,0,0,0,0,0,0,
0,13,13,0,0,0,0,13,
0,13,6,6,0,0,0,13,
0,0,0,11,11,0,0,0,
0,0,0,11,0,0,9,0,
0,0,0,0,0,10,3,9,
0,13,6,11,0,10,3,3,
0,13,6,11,11,1,1,1,
// Tile 01
13,13,0,0,0,0,0,0,
6,6,13,0,0,0,0,0,
12,12,13,0,0,0,0,0,
12,12,0,0,0,11,6,6,
1,0,0,12,11,11,6,13,
1,10,3,9,12,0,13,13,
1,10,3,3,0,0,0,0,
1,0,10,10,0,0,3,0,
// Tile 02
0,0,6,0,1,1,9,1,
0,0,12,12,12,10,1,1,
0,0,12,0,10,0,1,0,
0,12,12,0,12,0,1,3,
13,6,12,12,12,0,0,0,
6,6,11,0,0,0,0,3,
13,6,13,0,0,0,10,0,
0,13,0,0,0,0,0,0,
// Tile 03
1,1,1,0,0,10,10,0,
3,3,1,10,0,0,0,0,
3,0,1,1,0,0,0,0,
3,3,12,12,0,0,0,0,
0,12,0,12,12,0,0,0,
0,0,0,0,11,11,13,0,
0,0,0,0,11,6,13,0,
0,0,0,0,0,13,13,0,

#define ROAD1 19
//// Tile 00 
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 01
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 02
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 03
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

#define ROAD2 20
//// Tile 00 
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 01
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 02
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 03
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

#define BEACH 21
//// Tile 00 
1,5,5,5,5,5,10,10,
2,5,5,5,5,5,10,10,
5,5,5,5,5,5,10,10,
2,5,5,5,5,5,10,10,
1,2,5,5,5,5,10,10,
2,1,5,5,5,5,10,10,
2,5,8,5,5,5,10,10,
2,2,5,5,5,5,10,10,
//// Tile 01
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
//// Tile 02
1,5,5,5,5,5,10,10,
2,5,5,5,5,5,10,10,
5,5,5,8,5,5,10,10,
5,5,5,5,5,5,10,10,
2,5,5,5,5,5,10,10,
5,5,5,5,5,5,10,10,
2,2,5,5,5,5,10,10,
2,5,5,5,5,5,10,10,
//// Tile 03
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,
10,0,0,0,1,1,0,0,

#define OCEAN 22
//// Tile 00 
7,7,1,7,7,7,1,7,
7,1,7,7,7,1,1,7,
7,7,7,1,7,7,7,7,
7,7,7,7,7,7,7,7,
7,1,7,1,7,7,7,1,
7,7,7,7,7,7,1,7,
7,7,7,1,7,7,7,7,
7,1,7,7,1,7,7,7,
//// Tile 01
7,7,7,7,2,1,1,2,
7,7,7,2,2,1,2,2,
1,2,7,2,1,1,2,2,
7,1,7,2,1,2,2,7,
7,7,7,7,1,1,2,2,
7,2,1,7,1,1,2,2,
1,7,7,2,7,1,2,2,
7,7,7,1,7,2,1,2,
//// Tile 02
7,1,7,1,7,7,7,7,
7,1,7,7,7,7,7,7,
1,7,7,7,1,7,7,7,
7,7,7,7,7,1,7,7,
7,7,1,7,7,7,7,7,
7,7,7,7,1,7,1,7,
7,7,1,1,7,7,7,7,
7,7,7,1,7,7,1,7,
//// Tile 03
7,7,1,7,7,2,1,2,
7,1,7,2,7,1,2,2,
7,7,7,7,1,1,2,2,
1,7,7,2,7,1,1,2,
7,7,7,7,2,2,1,2,
7,1,2,7,1,1,2,2,
7,7,7,7,2,1,2,2,
7,7,1,2,2,1,2,2,

#define PALM1 23
//// Tile 00 
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
//// Tile 01
10,10,5,5,5,5,5,5,
10,10,5,5,5,5,5,5,
10,10,5,8,5,5,5,5,
10,10,5,5,5,5,5,5,
10,10,5,5,5,5,5,5,
10,10,5,5,5,5,5,5,
10,10,5,5,5,5,8,5,
10,10,5,5,5,5,5,5,
//// Tile 02
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
0,0,1,1,0,0,0,10,
//// Tile 03
10,10,5,5,16,5,5,5,
10,10,5,16,16,16,5,5,
10,10,5,16,16,16,16,5,
10,10,5,5,16,5,5,5,
10,10,5,5,16,5,5,5,
10,10,5,5,5,5,5,5,
10,10,8,5,5,5,5,5,
10,10,5,5,5,5,8,5,

#define PALM2 24
//// Tile 00 
5,5,5,5,5,5,5,5,
5,5,5,8,5,5,5,5,
5,8,5,5,5,8,5,5,
5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,
8,5,5,5,5,5,5,5,
5,5,5,5,5,5,8,5,
5,8,5,5,5,5,5,5,
//// Tile 01
5,5,5,5,8,5,5,8,
5,5,5,5,5,5,5,5,
5,5,8,5,5,5,5,5,
5,5,5,5,5,8,5,5,
5,5,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,
5,5,5,5,5,8,5,5,
5,5,5,5,5,5,5,5,
//// Tile 02
5,5,5,5,5,8,5,8,
5,8,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,
5,5,5,5,5,8,5,5,
5,5,5,5,5,5,5,5,
5,5,5,8,5,5,5,5,
5,8,5,5,5,5,5,5,
5,5,5,5,5,5,5,5,
//// Tile 03
5,8,5,5,5,5,5,5,
5,5,5,8,5,5,5,5,
5,5,5,5,8,5,5,5,
5,5,5,5,5,5,5,5,
5,5,5,5,8,5,5,5,
5,8,5,5,5,5,8,5,
5,5,8,5,5,5,5,5,
5,5,5,5,5,5,5,8,

#define FINISH 25
//// Tile 00 
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
//// Tile 01
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
//// Tile 02
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
//// Tile 03
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,
0,0,1,1,0,0,1,1,
1,1,0,0,1,1,0,0,

#define BRIDGELEFT 26
//// Tile 00 
13,13,13,13,11,12,13,13,
13,13,13,11,11,12,13,13,
13,13,11,11,12,13,13,13,
13,13,12,13,11,13,13,13,
13,13,12,13,11,13,13,13,
13,13,11,11,13,11,11,13,
13,13,13,11,13,11,11,12,
13,13,13,13,13,12,11,11,
//// Tile 01
13,13,13,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,0,0,0,0,0,
11,11,11,0,0,0,0,0,
//// Tile 02
13,13,13,13,11,11,11,13,
12,12,12,13,13,11,12,13,
12,12,12,12,13,11,11,12,
11,12,12,12,13,11,12,13,
11,12,12,12,13,13,13,13,
13,13,13,12,13,13,13,13,
13,13,11,11,13,13,13,13,
13,13,13,12,13,11,13,13,
//// Tile 03
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,3,3,3,0,0,
11,11,11,0,0,0,0,0,
11,11,11,0,0,0,0,0,

#define BRIDGERIGHT 27
//// Tile 00 
0,0,3,3,3,13,13,13,
0,0,3,3,3,13,13,13,
0,0,3,3,3,13,13,13,
0,0,3,3,3,13,13,13,
0,0,3,3,3,13,13,13,
0,0,3,3,3,13,13,13,
0,0,0,0,0,13,13,11,
0,0,0,0,0,13,13,12,
//// Tile 01
12,11,13,13,13,13,13,13,
11,11,12,11,13,13,13,13,
11,11,11,11,13,13,13,13,
13,13,11,11,12,11,11,13,
13,13,12,13,13,11,11,11,
13,13,13,13,13,13,11,12,
13,13,13,11,11,13,11,11,
13,13,13,12,13,13,13,13,
//// Tile 02
0,0,3,3,3,13,13,13,
0,0,3,3,3,13,13,13,
0,0,3,3,3,13,11,11,
0,0,3,3,3,13,11,12,
0,0,3,3,3,13,13,12,
0,0,3,3,3,13,13,13,
0,0,0,0,0,13,13,13,
0,0,0,0,0,13,13,13,
//// Tile 03
13,13,13,13,13,13,13,13,
13,13,13,13,13,13,13,13,
13,13,13,13,13,12,11,13,
13,11,11,11,13,12,11,11,
13,11,11,12,13,13,11,13,
13,13,13,12,13,13,11,13,
13,13,13,13,13,13,11,13,
13,13,13,13,12,11,13,13,

#define LAVALEFT 28
//// Tile 00 
11,11,13,13,13,13,13,13,
13,13,13,11,13,13,13,13,
11,11,13,11,13,13,13,13,
13,13,11,13,12,13,11,13,
13,11,12,13,12,11,13,11,
13,13,13,13,13,13,13,13,
11,11,13,13,13,13,13,13,
11,13,13,12,13,13,13,13,
//// Tile 01
13,12,12,13,13,13,13,13,
13,11,11,13,13,13,13,13,
13,13,12,12,13,13,13,13,
13,13,13,13,11,12,13,13,
13,13,13,13,11,11,13,13,
13,11,11,13,13,11,13,13,
13,12,12,13,13,13,13,13,
13,13,12,13,13,13,13,13,
//// Tile 02
13,13,13,13,13,13,13,13,
13,13,13,13,13,13,13,13,
13,13,13,13,11,12,12,11,
13,13,13,11,11,12,12,11,
13,13,13,13,13,13,13,11,
13,13,13,11,13,13,12,11,
13,13,11,12,13,13,13,13,
13,13,13,11,12,12,13,13,
//// Tile 03
13,13,13,13,13,13,13,13,
13,13,13,13,13,11,12,13,
13,13,13,13,11,12,11,13,
13,13,11,13,11,13,13,13,
13,13,11,13,13,13,13,13,
11,13,13,13,13,13,13,13,
12,12,13,13,13,13,13,13,
11,12,13,13,13,13,13,13,

#define LAVARIGHT 29
//// Tile 00 
12,13,13,13,13,13,13,13,
13,13,13,13,11,13,13,13,
12,13,13,13,11,11,13,13,
12,13,13,13,11,12,13,13,
11,11,13,13,13,12,13,13,
13,11,13,13,13,13,13,13,
13,13,13,13,11,11,13,13,
13,13,13,13,13,12,12,13,
//// Tile 01
13,13,13,11,13,13,13,13,
13,13,13,11,13,13,13,13,
11,13,11,13,13,13,13,13,
13,13,11,11,12,13,13,13,
13,13,11,11,12,13,13,13,
13,13,13,13,13,13,13,13,
13,13,13,13,13,13,13,13,
13,13,13,11,11,13,13,13,
//// Tile 02
13,13,13,13,13,13,13,13,
13,11,13,13,13,12,13,13,
11,11,11,13,13,12,12,11,
11,11,13,13,13,13,11,11,
13,11,13,13,13,13,11,13,
11,11,13,13,13,13,13,13,
12,12,13,13,13,12,12,13,
13,13,13,13,13,12,12,13,
//// Tile 03
13,13,13,13,13,12,11,13,
13,13,13,13,12,12,11,13,
11,11,13,13,13,13,13,13,
13,11,13,13,13,13,13,13,
13,13,12,13,13,13,13,13,
13,12,11,11,13,12,13,13,
11,12,11,11,13,12,13,13,
13,13,11,11,13,13,13,13,

#define C 30
//// Tile 00 
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
//// Tile 01
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 02
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
//// Tile 03
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,

#define D 31
//// Tile 00 
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
//// Tile 01
1,0,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
//// Tile 02
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,1,0,0,0,0,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
//// Tile 03
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,1,1,0,0,0,0,
0,1,1,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,

#define J 32
//// Tile 00 
0,0,0,0,0,1,1,1,
0,0,0,0,0,1,1,1,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 01
1,1,1,1,1,0,0,0,
1,1,1,1,1,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
//// Tile 02
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,0,1,1,1,
0,0,0,0,0,0,1,1,
//// Tile 03
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,

#define K 33
//// Tile 00 
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,1,
0,0,0,1,1,0,1,1,
0,0,0,1,1,1,1,0,
0,0,0,1,1,1,0,0,
//// Tile 01
0,0,1,1,1,0,0,0,
0,0,1,1,1,0,0,0,
0,1,1,0,0,0,0,0,
1,1,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 02
0,0,0,1,1,1,0,0,
0,0,0,1,1,1,1,0,
0,0,0,1,1,0,1,1,
0,0,0,1,1,0,0,1,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
0,0,1,1,1,1,0,0,
0,0,1,1,1,1,0,0,
//// Tile 03
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
1,0,0,0,0,0,0,0,
1,1,0,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,0,1,1,1,0,0,0,
0,0,1,1,1,0,0,0,

#define M 34
//// Tile 00 
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,1,1,0,0,0,
0,1,1,1,1,0,0,0,
0,1,1,0,0,1,1,0,
0,1,1,0,0,1,1,0,
// Tile 01
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,1,1,1,1,0,
0,0,0,1,1,1,1,0,
0,1,1,0,0,1,1,0,
0,1,1,0,0,1,1,0,
//// Tile 02
0,1,1,0,0,0,0,1,
0,1,1,0,0,0,0,1,
0,1,1,0,0,0,0,1,
0,1,1,0,0,0,0,1,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
//// Tile 03
1,0,0,0,0,1,1,0,
1,0,0,0,0,1,1,0,
1,0,0,0,0,1,1,0,
1,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,

#define V 35
//// Tile 00 
1,1,1,1,0,0,0,0,
1,1,1,1,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,0,1,1,0,0,0,
0,0,1,1,0,0,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
//// Tile 01
0,0,0,0,1,1,1,1,
0,0,0,0,1,1,1,1,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,1,1,0,0,0,
0,0,0,1,1,0,0,0,
//// Tile 02
0,0,0,0,1,1,0,0,
0,0,0,0,1,1,0,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,1,1,0,
0,0,0,0,0,0,1,0,
0,0,0,0,0,0,1,1,
0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,
//// Tile 03
0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,
0,0,1,1,0,0,0,0,
0,0,1,0,0,0,0,0,
0,0,1,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

#define ARROW 36
//// Tile 00 
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 01
0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,1,1,0,0,0,0,
0,1,1,1,1,0,0,0,
0,1,1,1,1,1,0,0,
0,1,1,1,1,1,1,0,
0,1,1,1,1,1,1,1,
//// Tile 02
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
//// Tile 03
0,1,1,1,1,1,1,1,
0,1,1,1,1,1,1,0,
0,1,1,1,1,1,0,0,
0,1,1,1,1,0,0,0,
0,1,1,1,0,0,0,0,
0,1,1,0,0,0,0,0,
0,1,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,

};


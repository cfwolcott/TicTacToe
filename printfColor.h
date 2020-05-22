#ifndef PRINTFCOLOR_H_INCLUDED
#define PRINTFCOLOR_H_INCLUDED

typedef enum
{
	E_COLOR_BLACK		= 30,
	E_COLOR_RED,
	E_COLOR_GREEN,
	E_COLOR_YELLOW,
	E_COLOR_BLUE,
	E_COLOR_MAGENTA,
	E_COLOR_CYAN,
	E_COLOR_WHITE,

	E_COLOR_MAX
} eCOLOR;

typedef enum
{
	E_STYLE_NORMAL,
	E_STYLE_BOLD,
	E_STYLE_UNDERLINE	= 4,
	E_STYLE_INVERSE		= 7,

	E_STYLE_MAX
} eSTYLE;

void printfColor( char *pString, eCOLOR eColor, eSTYLE eStyle);

#endif // PRINTFCOLOR_H_INCLUDED

/*
You need to output ANSI colour codes. Note that not all terminals support this; if colour sequences are not supported, garbage will show up.

Example:

 cout << "\033[1;31mbold red text\033[0m\n";

Here, \033 is the ESC character, ASCII 27. It is followed by [, then zero or more numbers separated by ;, and finally the letter m. The numbers describe the colour and format to switch to from that point onwards.

The codes for foreground and background colours are:

         foreground background
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47

Additionally, you can use these:

reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
inverse off      27

See the table on Wikipedia for other, less widely supported codes.
*/

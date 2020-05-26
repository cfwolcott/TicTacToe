#include <string.h>
#include <stdio.h>

#include "printfColor.h"

//-----------------------------------------------------------------------------
void printfColor( char *pString, eCOLOR eColor, eSTYLE eStyle)
{
	char newString[80];

	sprintf(newString, "\033[%i;%im", eStyle, eColor);
	strcat(newString, pString);
	strcat(newString, "\033[0m");

	printf("%s", newString);

	return;
}

//-----------------------------------------------------------------------------
void printfColorStart(eCOLOR eColor, eSTYLE eStyle)
{
	printf("\033[%i;%im", eStyle, eColor);
}

//-----------------------------------------------------------------------------
void printfColorEnd( void )
{
	printf("\033[0m");
}

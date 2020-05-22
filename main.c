#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <errno.h>

typedef enum
{
	E_GAME_CHECK__NO_RESULT,
	E_GAME_CHECK__WIN,
	E_GAME_CHECK__DRAW,

	GAME_CHECK__MAX
} tGAME_CHECK;

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool markSquare( int choice, char mark );
tGAME_CHECK checkWin();
void drawBoard();

//-----------------------------------------------------------------------------
int getInput()
{
	char input[2];

	fflush(stdin);
	//memset(input, 0, sizeof(input));
	do
	{
		fgets(input, sizeof(input), stdin);
	} while( input[0] == '\n');

	return atoi(input);
}

//-----------------------------------------------------------------------------
int main()
{
	int player = 1, choice;
	tGAME_CHECK tGameCheck;

	char mark;

	do
	{
		drawBoard();

		printf("Player %s, enter a number:  ", (player == 1) ? "X" : "O");

		choice = getInput();

		mark = (player == 1) ? 'X' : 'O';

		if( markSquare( choice, mark ) )
		{
			tGameCheck = checkWin();

			if( tGameCheck == E_GAME_CHECK__NO_RESULT )
			{
				// next player
				player++;

				if( player > 2 )
				{
					player = 1;
				}
			}
		}
		else
		{
			printf("Invalid move ");

			for(int i=0; i<2; i++)
			{
				sleep(1);
			}
		}

	} while( tGameCheck == E_GAME_CHECK__NO_RESULT);

	drawBoard();

	if( tGameCheck == E_GAME_CHECK__WIN )
	{
		printf("==> Player %s wins!!\n", (player == 1) ? "X" : "O");
	}
	else
	{
		printf("==> Game draw!\n");
	}

	getchar();

	return 0;
}

//-----------------------------------------------------------------------------
bool markSquare( int choice, char mark )
{
	bool bValidMove = true;

	if( choice <= 9 && square[choice] != 'X' && square[choice] != 'O' )
	{
		square[choice] = mark;
	}
	else
	{
		bValidMove = false;
	}

	return bValidMove;
}

//-----------------------------------------------------------------------------
/*********************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/
tGAME_CHECK checkWin()
{
	tGAME_CHECK eResult = E_GAME_CHECK__WIN;

	// Check row 1
	if (square[1] == square[2] && square[2] == square[3])
		return eResult;
	// Check row 2
	else if (square[4] == square[5] && square[5] == square[6])
		return eResult;
	// Check row 3
	else if (square[7] == square[8] && square[8] == square[9])
		return eResult;
	// Check column 1
	else if (square[1] == square[4] && square[4] == square[7])
		return eResult;
	// Check column 2
	else if (square[2] == square[5] && square[5] == square[8])
		return eResult;
	// Check column 3
	else if (square[3] == square[6] && square[6] == square[9])
		return eResult;
	// Check diag top-left to bottom-right
	else if (square[1] == square[5] && square[5] == square[9])
		return eResult;
	// Check diag top-right to bottom-left
	else if (square[3] == square[5] && square[5] == square[7])
		return eResult;
	// Check for draw
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
		square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
		!= '7' && square[8] != '8' && square[9] != '9')
	{
		eResult = E_GAME_CHECK__DRAW;
	}
	else
	{
		eResult = E_GAME_CHECK__NO_RESULT;
	}

	return eResult;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/
void drawBoard()
{
	system("clear");
	printf("\n\n\tTic Tac Toe\n\n");

	printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

	printf("_____|_____|_____\n");
	printf("     |     |     \n");

	printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

	printf("     |     |     \n\n");
}


#pragma once
#include "SubGrid\SubGrid.h"
#include "../logger.h"
#include <time.h>
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include <algorithm>

enum Difficulty
{
	EASY,
	INTERMEDIATE,
	HARD,
	HARDEST
};

enum ScanType
{
	COL,
	ROW,
	BOTH
};

class Board
{
	bool isChallengeBoard;
	Difficulty level;
	SubGrid* grids[3][3];
	unsigned char evalArr[9];

	unsigned char& arrayFill(SubGrid grid);
	unsigned char& arrayFill(ScanType toScan, unsigned int rowColCheck);
	const bool checkArray(unsigned char* arr);
	const bool checkArray(SubGrid grid);
	const bool checkArray(ScanType toScan, unsigned int rowColCheck);

public:

	Board(Difficulty p_diff, bool p_isChallengeBoard = false) : level(p_diff), isChallengeBoard(p_isChallengeBoard)
	{
		for (unsigned int iter = 0; iter < 3; iter++)
		{
			for (unsigned int iter2 = 0; iter2 < 3; iter2++)
			{
				grids[iter][iter2] = new SubGrid;
			}
		}

		srand(static_cast<unsigned int>(time(NULL)));

		FillAndCheck();

		/*grids[0][0]->changeValues(0, 0, '1');
		grids[0][0]->changeValues(1, 0, '2');
		grids[0][0]->changeValues(2, 0, '3');
		grids[0][0]->changeValues(0, 1, '4');
		grids[0][0]->changeValues(1, 1, '5');
		grids[0][0]->changeValues(2, 1, '6');
		grids[0][0]->changeValues(0, 2, '7');
		grids[0][0]->changeValues(1, 2, '8');
		grids[0][0]->changeValues(2, 2, '9');*/

	}

	void FillAndCheck();

	void EmptyDrawBoard();
	void DrawBoard();
};
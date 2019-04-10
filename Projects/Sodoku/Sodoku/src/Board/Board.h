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
	ROW
};

class Board
{
	bool isChallengeBoard;
	Difficulty level;
	SubGrid* grids[3][3];
	unsigned char evalArr[9];

	unsigned char& ArrayFill(SubGrid grid);
	unsigned char& ArrayFill(ScanType toScan, unsigned int rowColCheck);
	const bool CheckArray(unsigned char* arr);
	const bool CheckArray(SubGrid grid);
	const bool CheckArray(ScanType toScan, unsigned int rowColCheck);
	void FillAndCheck();
	void RemoveValues();

public:

	Board(Difficulty p_diff) : level(p_diff), isChallengeBoard(false)
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
	}

	Board(Board* inputBoard)
	{
		if (!inputBoard->isChallengeBoard)
		{
			isChallengeBoard = true;

			for (unsigned int iter = 0; iter < 3; iter++)
			{
				for (unsigned int iter2 = 0; iter2 < 3; iter2++)
				{
					grids[iter][iter2] = new SubGrid;
				}
			}

			for (unsigned int iter = 0; iter < 3; iter++)
			{
				for (unsigned int iter2 = 0; iter2 < 3; iter2++)
				{
					for (unsigned int iter3 = 0; iter3 < 3; iter3++)
					{
						for (unsigned int iter4 = 0; iter4 < 3; iter4++)
						{
							grids[iter][iter2]->ChangeValues(iter3, iter4, inputBoard->grids[iter][iter2]->GetValues(iter3, iter4));;
						}
					}
				}
			}
			level = inputBoard->level;

			RemoveValues();
		}
		else //if input board is challenge, just copy
		{
			for (unsigned int iter = 0; iter < 3; iter++)
			{
				for (unsigned int iter2 = 0; iter2 < 3; iter2++)
				{
					grids[iter][iter2] = new SubGrid;
				}
			}

			for (unsigned int iter = 0; iter < 3; iter++)
			{
				for (unsigned int iter2 = 0; iter2 < 3; iter2++)
				{
					for (unsigned int iter3 = 0; iter3 < 3; iter3++)
					{
						for (unsigned int iter4 = 0; iter4 < 3; iter4++)
						{
							grids[iter][iter2]->ChangeValues(iter3, iter4, inputBoard->grids[iter][iter2]->GetValues(iter3, iter4));;
						}
					}
				}
			}
			level = inputBoard->level;
		}
	}

	unsigned char GetBoardValue(unsigned int col, unsigned int row);
	void ModifyBoardValue(unsigned int col, unsigned int row, unsigned char changeChar);

	Board GetBoard() const;

	void EmptyDrawBoard();
	void DrawBoard();
};
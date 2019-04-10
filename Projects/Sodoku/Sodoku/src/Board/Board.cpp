#include "Board.h"
#include <chrono>


unsigned char& Board::ArrayFill(SubGrid grid)
{
	for (unsigned int iter = 0; iter < 3; iter++)
	{
		for (unsigned int iter2 = 0; iter2 < 3; iter2++)
		{
			evalArr[iter * 3 + iter2] = grid.GetValues(iter2, iter);
		}
	}
	return *evalArr;
}

unsigned char& Board::ArrayFill(ScanType toScan, unsigned int rowColCheck)  //DO NOT FORGET THAT THERE IS NO ROW 9!!
{
	if (toScan == COL)
	{
		for (unsigned int iter = 0; iter < 9; iter++)
		{
			evalArr[iter] = grids[rowColCheck / 3][iter / 3]->GetValues(rowColCheck % 3, iter % 3);
		}
	}

	else if (toScan == ROW)
	{
		for (unsigned int iter = 0; iter < 9; iter++)
		{
			evalArr[iter] = grids[iter / 3][rowColCheck / 3]->GetValues(iter % 3, rowColCheck % 3);
		}
	}

	return *evalArr;
}

const bool Board::CheckArray(unsigned char* arr) 
{
	std::sort(arr, arr + 9);
	for (unsigned int iter = 0; iter < 8; iter++)
	{
		if (arr[iter] == arr[iter + 1] && arr[iter] != '0') return false;
	}

	return true;
}

const bool Board::CheckArray(SubGrid grid)
{
	return CheckArray(&ArrayFill(grid));
}

const bool Board::CheckArray(ScanType toScan, unsigned int rowColCheck)
{
	return(CheckArray(&ArrayFill(toScan, rowColCheck)));
}

///<summary>
///Fills in values randomly, then checks if they are valid, if not, tries again.
///</summary>
void Board::FillAndCheck()
{
	auto timeStart = std::chrono::steady_clock::now();
	unsigned int attempts = 0;
	unsigned int boardAttempts = 0;
	for (unsigned int mainIter = 0; mainIter < 9; mainIter++) //Each loop places next number
	{
		for (unsigned int rowIter = 0; rowIter < 3; rowIter++)  //Pass through each SubGrid
		{
			for (int colIter = 0; colIter < 3; colIter++) //int in case colIter-- results in binary "rollunder?"
			{
				if (attempts > 100)
				{
					boardAttempts++;
					LowLog("Reset board to attempt another combination!");
					mainIter = rowIter = colIter = 0;
					for (unsigned int iter = 0; iter < 3; iter++)
					{
						for (unsigned int iter2 = 0; iter2 < 3; iter2++)
						{
							for (unsigned int iter3 = 0; iter3 < 3; iter3++)
							{
								for (unsigned int iter4 = 0; iter4 < 3; iter4++)
								{
									grids[iter][iter2]->ChangeValues(iter3, iter4, '0');
								}
							}
						}
					}
				}
				unsigned int pos = rand() % 9;
				if (grids[colIter][rowIter]->GetValues(pos % 3, pos / 3) == '0') //check no number already assigned
				{
					grids[colIter][rowIter]->ChangeValues(pos % 3, pos / 3, '1' + mainIter);
					if (!CheckArray(*grids[colIter][rowIter]) || !CheckArray(ROW, rowIter * 3 + pos / 3) || !CheckArray(COL, colIter * 3 + pos % 3))
					{
						grids[colIter][rowIter]->ChangeValues(pos % 3, pos / 3, '0');
						colIter--;
						attempts++;
					}
					else attempts = 0;
				}
				else
				{
					colIter--;
					attempts++;
				}
			}
		}
	}
	auto timeEnd = std::chrono::steady_clock::now();
	std::cout << "Generated a solution Board in " << std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd-timeStart).count() << "ms, after " << boardAttempts << " attempts." << std::endl;
}

///<summary>
///Draws Board with all values currently stored in it.
///</summary>
void Board::DrawBoard()
{
	std::cout << std::endl;

	for (unsigned int iter = 0; iter < 36; iter++)
	{
		if ((iter - 1) % 2 == 0 && (iter - 1) % 4 != 0) std::cout << (iter - 1) / 4 + 1; //iter - 1 due to offset from row numbers
		else std::cout << ' ';
	}
	std::cout << std::endl;

	//Num Rows Elem: Num Rows * 2 + 1 -> 19 //same for columns
	for (unsigned int iter = 0; iter < 19; iter++) //rows
	{
		for (int iter2 = -1; iter2 < 19; iter2++) //columns -1 was a very cheap way to add the row numbers afterwards..
		{
			if (iter2 == -1 && iter % 2 != 0) std::cout << iter / 2 + 1;
			else if (iter2 == -1 && iter % 2 == 0) std::cout << ' ';
			else
			{
				char nextSym = (iter2 + iter) % 2 == 0 ? iter % 2 == 0 ? '*' :
					grids[(iter2 - 1) / 2 / 3][(iter - 1) / 2 / 3]->GetValues((iter2 - 1) / 2 % 3, (iter - 1) / 2 % 3) :
					iter % 2 == 0 ? '-' : '|'; //choose char
				if (nextSym == '-' && iter % 6 == 0 && iter % 18 != 0) nextSym = '=';
				else if (nextSym == '|' && iter2 % 6 == 0 && iter2 % 18 != 0) nextSym = ':';
				std::cout << nextSym << ' ';
			}
		}

		std::cout << std::endl;
	}
}

///<summary>
///Draws Board with ' ' instead of values. Kind of redundant now...
///</summary>
void Board::EmptyDrawBoard()
{
	//Num Rows Elem: Num Rows * 2 + 1 -> 19 //same for columns
	for (unsigned int iter = 0; iter < 19; iter++) //rows
	{
		for (unsigned int iter2 = 0; iter2 < 19; iter2++) //columns
		{
			char nextSym = (iter2 + iter) % 2 == 0 ? iter % 2 == 0 ? '*' :
				' ' :
				iter % 2 == 0 ? '-' : '|'; //choose char
			if (nextSym == '-' && iter % 6 == 0 && iter % 18 != 0) nextSym = '=';
			else if (nextSym == '|' && iter2 % 6 == 0 && iter2 % 18 != 0) nextSym = ':';
			std::cout << nextSym << ' ';
		}

		std::cout << std::endl;
	}
}

void Board::RemoveValues()
{
	auto timeStart = std::chrono::steady_clock::now();
	unsigned int validPos = 0;
	for (int iter = 0; iter < 35 + level * 20; iter++)
	{
		unsigned int pos = rand() % 81;
		unsigned char prevChar = grids[(pos / 3) % 3][pos / 27]->GetValues(pos % 3, pos / 9 % 3);
		grids[(pos / 3) % 3][pos / 27]->ChangeValues(pos % 3, pos / 9 % 3, '0');
		for (unsigned int iter2 = 0; iter2 < 9; iter2++) //check that prevChar can only go into its square
		{
			if (grids[(pos / 3) % 3][pos / 27]->GetValues(iter2 % 3, iter2 / 3) == '0') //if square is empty, check if prevChar is valid in that position
			{
				grids[(pos / 3) % 3][pos / 27]->ChangeValues(iter2 % 3, iter2 / 3, prevChar);
				if (CheckArray(ROW, (pos / 3) % 3) && CheckArray(COL, pos / 27)) //no need to check SubGrid -> Value to test already removed
				{
					grids[(pos / 3) % 3][pos / 27]->ChangeValues(iter2 % 3, iter2 / 3, '0');
					validPos++;
					break;
				}
				else grids[(pos / 3) % 3][pos / 27]->ChangeValues(iter2 % 3, iter2 / 3, '0');

			}
		}
	}
	for (unsigned int iter = 0; iter < 81; iter++)
	{
		if (grids[(iter / 3) % 3][iter / 27]->GetValues(iter % 3, iter / 9 % 3) == '0')
			grids[(iter / 3) % 3][iter / 27]->ChangeValues(iter % 3, iter / 9 % 3, ' ');
	}
	auto timeEnd = std::chrono::steady_clock::now();
	std::cout << "Generated Challenge Board in " << std::chrono::duration_cast<std::chrono::microseconds>(timeEnd - timeStart).count() * .001 << "ms" << std::endl;
}

Board Board::GetBoard() const
{
	return *this;
}

unsigned char Board::GetBoardValue(unsigned int col, unsigned int row)
{
	return grids[col / 3][row / 3]->GetValues(col % 3, row % 3);
}

void Board::ModifyBoardValue(unsigned int col, unsigned int row, unsigned char ent)
{
	grids[col / 3][row / 3]->ChangeValues(col % 3, row % 3, ent);;
}
#include "Board.h"
#include <chrono>


unsigned char& Board::arrayFill(SubGrid grid)
{
	for (unsigned int iter = 0; iter < 3; iter++)
	{
		for (unsigned int iter2 = 0; iter2 < 3; iter2++)
		{
			evalArr[iter * 3 + iter2] = grid.getValues(iter2, iter);
		}
	}
	return *evalArr;
}

unsigned char& Board::arrayFill(ScanType toScan, unsigned int rowColCheck)  //DO NOT FORGET THAT THERE IS NO ROW 9!!
{
	if (toScan == COL)
	{
		for (unsigned int iter = 0; iter < 9; iter++)
		{
			evalArr[iter] = grids[rowColCheck / 3][iter / 3]->getValues(rowColCheck % 3, iter % 3);
		}
	}

	else if (toScan == ROW)
	{
		for (unsigned int iter = 0; iter < 9; iter++)
		{
			evalArr[iter] = grids[iter / 3][rowColCheck / 3]->getValues(iter % 3, rowColCheck % 3);
		}
	}

	return *evalArr;
}

const bool Board::checkArray(unsigned char* arr) 
{
	std::sort(arr, arr + 9);
	for (unsigned int iter = 0; iter < 8; iter++)
	{
		if (arr[iter] == arr[iter + 1] && arr[iter] != '0') return false;
	}

	return true;
}

const bool Board::checkArray(SubGrid grid)
{
	return checkArray(&arrayFill(grid));
}

const bool Board::checkArray(ScanType toScan, unsigned int rowColCheck)
{
	return(checkArray(&arrayFill(toScan, rowColCheck)));
}

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
									grids[iter][iter2]->changeValues(iter3, iter4, '0');
								}
							}
						}
					}
				}
				unsigned int pos = rand() % 9;
				if (grids[colIter][rowIter]->getValues(pos % 3, pos / 3) == '0') //check no number already assigned
				{
					grids[colIter][rowIter]->changeValues(pos % 3, pos / 3, '1' + mainIter);
					if (!checkArray(*grids[colIter][rowIter]) || !checkArray(ROW, rowIter * 3 + pos / 3) || !checkArray(COL, colIter * 3 + pos % 3))
					{
						grids[colIter][rowIter]->changeValues(pos % 3, pos / 3, '0');
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
	std::cout << "Found a complete solution in " << std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd-timeStart).count() << "ms, after " << boardAttempts << " attempts." << std::endl;
}

void Board::DrawBoard()
{
	//Num Rows Elem: Num Rows * 2 + 1 -> 19 //same for columns
	for (unsigned int iter = 0; iter < 19; iter++) //rows
	{
		for (unsigned int iter2 = 0; iter2 < 19; iter2++) //columns
		{
			char nextSym = (iter2 + iter) % 2 == 0 ? iter % 2 == 0 ? '*' :
				grids[(iter2 - 1) / 2 / 3][(iter - 1) / 2 / 3]->getValues((iter2 - 1) / 2 % 3, (iter - 1) / 2 % 3) :
				iter % 2 == 0 ? '-' : '|'; //choose char
			if (nextSym == '-' && iter % 6 == 0 && iter % 18 != 0) nextSym = '=';
			else if (nextSym == '|' && iter2 % 6 == 0 && iter2 % 18 != 0) nextSym = ':';
			std::cout << nextSym << ' ';
		}

		std::cout << std::endl;
	}
}

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
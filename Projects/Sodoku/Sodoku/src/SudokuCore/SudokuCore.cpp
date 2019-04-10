#include "SudokuCore.h"

void SudokuGame::Launch()
{
	unsigned int row, col;
	unsigned char entChar;

	challenge->DrawBoard();
	std::cout << "Enter coordinates of value to modify and with what to fill it." << std::endl;
	std::cin >> row >> col >> entChar;

	while (row != 0 && col != 0)
	{
		if (!Input(row - 1, col - 1, entChar)) std::cout << "Square strictly set to current value" << std::endl;
		else
		{
			challenge->DrawBoard();
		}
		std::cout << "Enter coordinates of value to modify and with what to fill it." << std::endl;
		std::cin >> row >> col >> entChar;
	}

	std::cout << std::endl << std::endl;

	solution->DrawBoard();
}

bool SudokuGame::Input(unsigned int col, unsigned int row, unsigned char ent)
{
	if (originalChallenge->GetBoardValue(col, row) != ' ') return false; //checks original challenge so user can change his values.
	challenge->ModifyBoardValue(col, row, ent);
	return true;
}
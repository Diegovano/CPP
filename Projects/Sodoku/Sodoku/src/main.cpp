#include "SudokuCore\SudokuCore.h"

const bool checkArray(unsigned char* arr)
{
	std::sort(arr, arr + 9);
	for (unsigned int iter = 0; iter < 8; iter++)
	{
		if (arr[iter] != arr[iter + 1] && arr[iter] != '0') return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	Board game(EASY);
	game.DrawBoard();
//	unsigned char arr[9] = { '1','0','1','1','1','1','1','1','1' };
//	if (checkArray(arr)) std::cout << "true\n";
//	else std::cout << "false\n";
	system("pause");
	return 0;
}
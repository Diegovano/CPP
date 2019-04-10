#include "SudokuCore\SudokuCore.h"

int main(int argc, char* argv[])
{
	SudokuGame game(EASY);
	game.Launch();
	system("pause");
	return 0;
}
#include "SudokuCore\SudokuCore.h"

int main(int argc, char* argv[])
{
	unsigned int dif;

	std::cout << "Difficulty: ";
	std::cin >> dif;
	SudokuGame game((Difficulty)(dif % 4));
	game.Launch();
	system("pause");
	return 0;
}
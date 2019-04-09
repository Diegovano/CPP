#pragma once
#include "../Board/Board.h"

class SudokuGame
{
	Difficulty diff;
	Board* solution, *challenge;

public:

	SudokuGame(Difficulty p_diff) : diff(p_diff), solution(new Board(diff))
	{
		challenge = new Board(solution);
	}

	~SudokuGame()
	{
		delete challenge;
		delete solution;
	}

	bool Input(unsigned int col, unsigned int row, unsigned char ent);

	void Launch();
};

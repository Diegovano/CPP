#pragma once
#include "../Board/Board.h"

class SudokuGame
{
	Difficulty diff;
	Board* solution, *challenge, *originalChallenge;

public:

	SudokuGame(Difficulty p_diff) : diff(p_diff), solution(new Board(diff))
	{
		challenge = new Board(solution);
		originalChallenge = new Board(challenge);
	}

	~SudokuGame()
	{
		delete solution;
		delete challenge;
		delete originalChallenge;
	}

	bool Input(unsigned int col, unsigned int row, unsigned char ent);

	void Launch();
};

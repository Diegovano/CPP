#pragma once

class SubGrid
{
	char values[3][3];

public:

	SubGrid()
	{
		for (unsigned int iter = 0; iter < 3; iter++)
		{
			for (unsigned int iter2 = 0; iter2 < 3; iter2++)
			{
				values[iter2][iter] = '0';
			}
		}
	}

	const char getValues(unsigned int row, unsigned int col);
	void changeValues(unsigned int row, unsigned int col, char change);
};

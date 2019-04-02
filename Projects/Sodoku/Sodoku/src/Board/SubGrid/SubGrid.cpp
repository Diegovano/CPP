#include "SubGrid.h"
#include "../../logger.h"

const char SubGrid::getValues(unsigned int col, unsigned int row)
{
	if (row > 2 || col > 2) Error("getValues(): Subscript out of range!");
	return values[col][row];
}

void SubGrid::changeValues(unsigned int col, unsigned int row, char change)
{
	if (row > 2 || col > 2) Error("changeValues(): Subscript out of range!");
	values[col][row] = change;
}
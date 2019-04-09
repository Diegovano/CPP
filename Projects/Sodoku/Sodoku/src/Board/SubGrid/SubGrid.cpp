#include "SubGrid.h"
#include "../../logger.h"

const char SubGrid::GetValues(unsigned int col, unsigned int row) //col then row
{
	if (row > 2 || col > 2) Error("getValues(): Subscript out of range!");
	return values[col][row];
}

void SubGrid::ChangeValues(unsigned int col, unsigned int row, char change) //col then row
{
	if (row > 2 || col > 2) Error("changeValues(): Subscript out of range!");
	values[col][row] = change;
}
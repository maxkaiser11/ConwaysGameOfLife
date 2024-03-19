#include "Grid.hpp"
#include <raylib.h>

void Grid::Draw()
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			Color color = cells[row][column] ? Color{ 0, 255, 0, 255 } : Color{ 55, 55, 55, 255 };
		}
	}
}
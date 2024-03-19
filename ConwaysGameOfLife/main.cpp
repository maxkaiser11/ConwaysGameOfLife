#include <iostream>
#include <raylib.h>
#include "Simulation.hpp"

int main()
{
	Color GREY = { 29, 29, 29, 255 };
	const int WINDOW_WIDTH = 1200;
	const int WINDOW_HEIGHT = 800;
	const int CELL_SIZE = 4;
	int FPS = 12;

	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Game of Life");
	SetTargetFPS(FPS);
	Simulation simulation{ WINDOW_WIDTH, WINDOW_HEIGHT, CELL_SIZE };

	// Simulation Loop
	while (!WindowShouldClose())
	{
		// 1. Event Handling
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
		{
			Vector2 mousePosition = GetMousePosition();
			int row = mousePosition.y / CELL_SIZE;
			int column = mousePosition.x / CELL_SIZE;
			simulation.ToggleCell(row, column);
		}
		if (IsKeyPressed(KEY_ENTER))
		{
			simulation.Start();
			SetWindowTitle("Game of Life is running...");
		}
		else if (IsKeyPressed(KEY_SPACE))
		{
			simulation.Stop();
			SetWindowTitle("Game of Life has stopped!");
		}
		else if (IsKeyPressed(KEY_F))
		{
			FPS += 2;
			SetTargetFPS(FPS);
		}
		else if (IsKeyPressed(KEY_S))
		{
			if (FPS > 5)
			{
				FPS -= 2;
				SetTargetFPS(FPS);
			}
		}
		else if (IsKeyPressed(KEY_R))
		{
			simulation.CreateRandomState();
		}
		else if (IsKeyPressed(KEY_C))
		{
			simulation.ClearGrid();
		}

		// 2. Updating state
		simulation.Update();

		// 3.Drawing
		BeginDrawing();
		ClearBackground(GREY);
		simulation.Draw();
		EndDrawing();
	}

	CloseWindow();
}
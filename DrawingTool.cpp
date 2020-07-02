#include "DrawingTool.h"
#include <fstream>
#include <time.h>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

DrawingTool::DrawingTool()
{
	setImmediateDrawMode(false);
	int PlayerX = 50;
	int PlayerY = 100;
	visitedV.push_back(shuffleTiles[0][0]);

}


DrawingTool::~DrawingTool()
{
}
void DrawingTool::drawPath()
{
	//for (int i = 0; i <= 6; i++)
	//{
	//	for (int j = 0; j <= 6; j++)
	//	{
	//		if (destination.c_str() == tilePositions[i][j])
	//		{
	//			string destinationTile = shuffleTiles[i][j];
	//			ofstream out("destination.txt");
	//			out << destinationTile;
	//			out.close();
	//		}
	//		else {
	//			ofstream out("destination.txt");
	//			out << destination;
	//			out << i;
	//			out << j;
	//			out.close();
	//		}

	//	}
	//}

	//for (int i = 0; i < 6; i++)
	//{
	//	for (int j = 0; j < 6; j++)
	//	{
	//		// we need to iterate through the tiles to assign them to a path. Needs to be done randomly but within the limits, starting at AA and ending at destination.
	//		path[i] = shuffleTiles[i][j];
	//	}
	//}
	int tileX = rand() % 6 + 1;
	int tileY = rand() % 6 + 1;



}




void DrawingTool::onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	onKeyDownAction(nChar);

}

void DrawingTool::drawPlayer()
{
	drawBitmap(L"assets\\Player.bmp", PlayerX, PlayerY, 50, 50);
}
void DrawingTool::onKeyDownAction(UINT nChar)
{
	if (nChar >= 'A' && nChar <= 'Z')
	{
		if (name.size() <= 15) {
			name += nChar;
		}
	}
	else if (nChar == VK_BACK)
	{
		if (name.size() > 0) {
			name.erase(name.size() - 1, 1);
		}
	}
	onDraw();

	switch (nChar) {
	case VK_LEFT:
		setTimer(REDRAW_TIMER_ID, 1);
		direction = -1;
		break;
	case VK_RIGHT:
		setTimer(REDRAW_TIMER_ID, 1);
		direction = 1;
		break;
	case VK_DOWN:
		setTimer(REDRAW_TIMER_ID, 1);
		direction = 2;
		break;
	case VK_UP:
		setTimer(REDRAW_TIMER_ID, 1);
		direction = 3;
		/*PlayerY = PlayerY - 50;*/
		break;
	case 'C':
		// insert 'cheat' line here
		// use onMouseMove or something, call here to draw the line
		// then call onDraw()
		// for all locations in the path: draw the path bitmap
		drawBitmap(L"assets//Path.bmp", 50, 50, 50, 50);
		break;
	}
	



}


void DrawingTool::onTimer(UINT nIDEvent)
{		
	if (nIDEvent == REDRAW_TIMER_ID && direction == 1 && PlayerX < 250)
	{
		PlayerX += 50;
		// Rightward path tracking
		// AB to AF
		if ((PlayerX == 50) && (PlayerY == 0)) {
			visitedV.push_back(shuffleTiles[1][0]);
		}
		else if ((PlayerX == 100) && (PlayerY == 0)) {
			visitedV.push_back(shuffleTiles[2][0]);
		}
		else if ((PlayerX == 150) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[3][0]);
		}
		else if ((PlayerX == 200) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[4][0]);
		}
		else if ((PlayerX == 250) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[5][0]);
		}
		//BB to BF
		else if ((PlayerX == 50) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[1][1]);
		}
		else if ((PlayerX == 100) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[2][1]);
		}
		else if ((PlayerX == 150) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[3][1]);
		}
		else if ((PlayerX == 200) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[4][1]);
		}
		else if ((PlayerX == 250) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[5][1]);
		}
		// CB to CF
		else if ((PlayerX == 50) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[1][2]);
		}
		else if ((PlayerX == 100) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[2][2]);
		}
		else if ((PlayerX == 150) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[3][2]);
		}
		else if ((PlayerX == 200) && (PlayerY == 100)) {
			visitedV.push_back(shuffleTiles[4][2]);
		}
		else if ((PlayerX == 250) && (PlayerY == 100)) {
			visitedV.push_back(shuffleTiles[5][2]);
		}
		// DB to DF
		else if ((PlayerX == 50) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[1][3]);
		}
		else if ((PlayerX == 100) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[2][3]);
		}
		else if ((PlayerX == 150) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[3][3]);
		}
		else if ((PlayerX == 200) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[4][3]);
		}
		else if ((PlayerX == 250) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[5][3]);
		}
		// EB to EF
		else if ((PlayerX == 50) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[1][4]);
		}
		else if ((PlayerX == 100) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[2][4]);
		}
		else if ((PlayerX == 150) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[3][4]);
		}
		else if ((PlayerX == 200) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[4][4]);
		}
		else if ((PlayerX == 250) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[5][4]);
		}
		// FB to FF
		else if ((PlayerX == 50 && (PlayerY == 250)))
		{
			visitedV.push_back(shuffleTiles[1][5]);
		}
		else if ((PlayerX == 100) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[2][5]);
		}
		else if ((PlayerX == 150) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[3][5]);
		}
		else if ((PlayerX == 200) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[4][5]);
		}
		else if ((PlayerX == 250) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[5][5]);
		}
		onDraw();
		}
	else if (nIDEvent == REDRAW_TIMER_ID && direction == -1 && PlayerX>0)
		{
			PlayerX -= 50;
			// AF to AA
			if ((PlayerX == 250) && (PlayerY == 0))
			{
				visitedV.push_back(shuffleTiles[5][0]);
			}
			else if ((PlayerX == 200) && (PlayerY == 0))
			{
				visitedV.push_back(shuffleTiles[4][0]);
			}
			else if ((PlayerX == 150) && (PlayerY == 0))
			{
				visitedV.push_back(shuffleTiles[3][0]);
			}
			else if ((PlayerX == 100) && (PlayerY == 0))
			{
				visitedV.push_back(shuffleTiles[2][0]);
			}
			else if ((PlayerX == 50) && (PlayerY == 0))
			{
				visitedV.push_back(shuffleTiles[1][0]);
			}
			else if ((PlayerX == 0) && (PlayerY == 0))
			{
				visitedV.push_back(shuffleTiles[0][0]);
			}
			//BF to BA
			else if ((PlayerX == 250) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[5][1]);
			}
			else if ((PlayerX == 200) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[4][1]);
			}
			else if ((PlayerX == 150) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[3][1]);
			}
			else if ((PlayerX == 100) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[2][1]);
			}
			else if ((PlayerX == 50) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[1][1]);
			}
			else if ((PlayerX == 0) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[0][1]);
			}
			// CF to CA
			else if ((PlayerX == 250) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[5][2]);
			}
			else if ((PlayerX == 200) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[4][2]);
			}
			else if ((PlayerX == 150) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[3][2]);
			}
			else if ((PlayerX == 100) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[2][2]);
			}
			else if ((PlayerX == 50) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[1][2]);
			}
			else if ((PlayerX == 0) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[0][2]);
			}
			// DF to DA
			else if ((PlayerX == 250) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[5][3]);
			}
			else if ((PlayerX == 200) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[4][3]);
			}
			else if ((PlayerX == 150) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[3][3]);
			}
			else if ((PlayerX == 100) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[2][3]);
			}
			else if ((PlayerX == 50) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[1][3]);
			}
			else if ((PlayerX == 0) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[0][3]);
			}
			//EF to EA
			else if ((PlayerX == 250) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[5][4]);
			}
			else if ((PlayerX == 200) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[4][4]);
			}
			else if ((PlayerX == 150) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[3][4]);
			}
			else if ((PlayerX == 100) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[2][4]);
			}
			else if ((PlayerX == 50) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[1][4]);
			}
			else if ((PlayerX == 0) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[0][4]);
			}
			//FF to FA
			else if ((PlayerX == 250) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[5][5]);
			}
			else if ((PlayerX == 200) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[4][5]);
			}
			else if ((PlayerX == 150) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[3][5]);
			}
			else if ((PlayerX == 100) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[2][5]);
			}
			else if ((PlayerX == 50) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[1][5]);
			}
			else if ((PlayerX == 0) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[0][5]);
			}
			onDraw();
		}
		else if (nIDEvent == REDRAW_TIMER_ID && direction == 2 && PlayerY<250)
		{
			PlayerY += 50;
			// convention exists because of precedence rules
			// BA to EA
			if ((PlayerX == 0) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[0][1]);
			}
			else if ((PlayerX == 0) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[0][2]);
			}
			else if ((PlayerX == 0) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[0][3]);
			}
			else if ((PlayerX == 0) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[0][4]);
			}
			else if ((PlayerX == 0) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[0][5]);
			}
			// BB to FB
			else if ((PlayerX == 50) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[1][1]);
			}
			else if ((PlayerX == 50) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[1][2]);
			}
			else if ((PlayerX == 50) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[1][3]);
			}
			else if ((PlayerX == 50) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[1][4]);
			}
			else if ((PlayerX == 50) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[1][5]);
			}
			// BC to FC
			else if ((PlayerX == 100) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[2][1]);
			}
			else if ((PlayerX == 100) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[2][2]);
			}
			else if ((PlayerX == 100) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[2][3]);
			}
			else if ((PlayerX == 100) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[2][4]);
			}
			else if ((PlayerX == 100) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[2][5]);
			}
			// BD to FD
			else if ((PlayerX == 150) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[3][1]);
			}
			else if ((PlayerX == 150) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[3][2]);
			}
			else if ((PlayerX == 150) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[3][3]);
			}
			else if ((PlayerX == 150) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[3][4]);
			}
			else if ((PlayerX == 150) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[3][5]);
			}
			//BE to FE
			else if ((PlayerX == 200) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[4][1]);
			}
			else if ((PlayerX == 200) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[4][2]);
			}
			else if ((PlayerX == 200) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[4][3]);
			}
			else if ((PlayerX == 200) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[4][4]);
			}
			else if ((PlayerX == 200) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[4][5]);
			}
			//BF to FF
			else if ((PlayerX == 250) && (PlayerY == 50))
			{
				visitedV.push_back(shuffleTiles[5][1]);
			}
			else if ((PlayerX == 250) && (PlayerY == 100))
			{
				visitedV.push_back(shuffleTiles[5][2]);
			}
			else if ((PlayerX == 250) && (PlayerY == 150))
			{
				visitedV.push_back(shuffleTiles[5][3]);
			}
			else if ((PlayerX == 250) && (PlayerY == 200))
			{
				visitedV.push_back(shuffleTiles[5][4]);
			}
			else if ((PlayerX == 250) && (PlayerY == 250))
			{
				visitedV.push_back(shuffleTiles[5][5]);
			}
			onDraw();
		}
		else if (nIDEvent == REDRAW_TIMER_ID && direction == 3 && PlayerY > 0)
	{
		PlayerY -= 50;
		// AA to AF (AF to AA)
		if ((PlayerX == 0) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[0][0]);
		}
		else if ((PlayerX == 0) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[0][1]);
		}
		else if ((PlayerX == 0) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[0][2]);
		}
		else if ((PlayerX == 0) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[0][3]);
		}
		else if ((PlayerX == 0) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[0][4]);
		}
		else if ((PlayerX == 0) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[0][5]);
		}
		// BF to BA
		else if ((PlayerX == 50) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[1][5]);
		}
		else if ((PlayerX == 50) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[1][4]);
		}
		else if ((PlayerX == 50) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[1][3]);
		}
		else if ((PlayerX == 50) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[1][2]);
		}
		else if ((PlayerX == 50) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[1][1]);
		}
		else if ((PlayerX == 50) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[1][0]);
		}
		//CF to CA
		else if ((PlayerX == 100) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[2][5]);
		}
		else if ((PlayerX == 100) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[2][4]);
		}
		else if ((PlayerX == 100) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[2][3]);
		}
		else if ((PlayerX == 100) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[2][2]);
		}
		else if ((PlayerX == 100) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[2][1]);
		}
		else if ((PlayerX == 100) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[2][0]);
		}
		// DF to DA
		else if ((PlayerX == 150) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[3][5]);
		}
		else if ((PlayerX == 150) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[3][4]);
		}
		else if ((PlayerX == 150) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[3][3]);
		}
		else if ((PlayerX == 150) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[3][2]);
		}
		else if ((PlayerX == 150) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[3][1]);
		}
		else if ((PlayerX == 150) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[3][0]);
		}
		// EF to EA
		else if ((PlayerX == 200) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[4][5]);
		}
		else if ((PlayerX == 200) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[4][4]);
		}
		else if ((PlayerX == 200) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[4][3]);
		}
		else if ((PlayerX == 200) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[4][2]);
		}
		else if ((PlayerX == 200) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[4][1]);
		}
		else if ((PlayerX == 200) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[4][0]);
		}
		// FF to FA
		else if ((PlayerX == 250) && (PlayerY == 250))
		{
			visitedV.push_back(shuffleTiles[5][5]);
		}
		else if ((PlayerX == 250) && (PlayerY == 200))
		{
			visitedV.push_back(shuffleTiles[5][4]);
		}
		else if ((PlayerX == 250) && (PlayerY == 150))
		{
			visitedV.push_back(shuffleTiles[5][3]);
		}
		else if ((PlayerX == 250) && (PlayerY == 100))
		{
			visitedV.push_back(shuffleTiles[5][2]);
		}
		else if ((PlayerX == 250) && (PlayerY == 50))
		{
			visitedV.push_back(shuffleTiles[5][1]);
		}
		else if ((PlayerX == 250) && (PlayerY == 0))
		{
			visitedV.push_back(shuffleTiles[5][0]);
		}
			onDraw();
		}
		ofstream f("path.txt");
		for (vector<string>::const_iterator i = visitedV.begin(); i != visitedV.end(); ++i)
		{
			f << *i << '\n';

		}
		f.close();

}
void DrawingTool::writeName()
{
	setBackColour(YELLOW);
	setPenColour(BLACK, 3);
	drawRectangle(500, 0, 300, 80, true);
	setTextColour(BLUE);
	setFont(16, L"Tahoma");
	drawText("Write your name here", 520, 10);
	setTextColour(RED);
	setFont(20, L"Tahoma");
	drawText(name.c_str(), 520, 30);
	drawText("High Scores", 500, 100);
	drawText(name.c_str(), 500, 130);
	string Score = "";
	Score += to_string(score);
	drawText(Score.c_str(), 500, 150);
}
void DrawingTool::onDraw()
{
	colour = WHITE;
	clearScreen(colour);
	setTextColour(WHITE);
	setPenColour(BLACK, 15);
	setFont(20, L"Segoe UI");
	drawText("Follow Me", 0, 0);
	string Level = "Level: ";
	Level += to_string(level);
	drawText(Level.c_str(), 600, 0);
	int PicValue = 0;
	// drawLine for random path?
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			string tile = "assets\\" + shuffleTiles[i][j] + ".bmp";

			/*		int x = 215 + (50 * i);
					int y = 105 + (50 * j);*/
			int x = 50 * i;
			int y = 50 * j;

			wstring wTile(tile.begin(), tile.end());
			drawBitmap(wTile.c_str(), x, y, 50, 50);


		}
	}
	drawBitmap(L"assets\\rokk.bmp", destX, destY, 50, 50);
	drawPlayer();
	drawPath();
	writeName();
	EasyGraphics::onDraw();
}




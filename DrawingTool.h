#pragma once
#include "EasyGraphics.h"
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class DrawingTool :
	public EasyGraphics

{
public:
	DrawingTool();
	~DrawingTool();
	int level = 0;
	int PlayerX = 0;
	int PlayerY = 0;
	// player starts in top-left corner
	int multiplier = rand() % 5 + 1;
	int lineMultiplier = rand() % 5 + 1;
	int destX = 50 * multiplier;
	int destY = 50 * lineMultiplier;
	int lx = 50 * lineMultiplier;
	int ly = 50 * lineMultiplier;
 	// ensuring that destination is a square and not between two squares
	string shuffleTiles[6][7] = { {"AA", "BA", "CA", "DA", "EA", "FA" },
	{"AB", "BB", "CB", "DB", "EB", "FB"},
	{"AC", "BC", "CC", "DC", "EC", "FC"},
	{"AD", "BD", "CD", "DD", "ED", "FD"},
	{"AE", "BE", "CE", "DE", "EE", "FE"},
	{"AF", "BF", "CF", "DF", "FE", "FF", "XX"} };
	string tilePositions[6][7] = { {"0, 0", "0, 50", "0, 100", "0, 150", "0, 200", "0, 250"}, 
	{"50, 0", "50, 50", "50, 100", "50, 150", "50, 200", "50, 250" }, 
	{"100, 0", "100, 50", "100, 100", "100150", "100, 200", "100, 250" }, 
	{"150, 0", "150, 50", "150, 100", "150, 150", "150, 200", "150, 250"}, 
	{"200, 0", "200, 50", "200, 100", "200, 150", "200, 200", "200, 250"}, 
	{"250, 0", "250, 50", "250, 100", "250, 150", "250, 200", "250, 250", "XX, XX"} };
	
	string destinationX = to_string(destX);
	string destinationY = to_string(destY);
	string destination =  {""+destinationX+", "+destinationY+""};
	string destinationTile;
	string path[6];
	string visited[7];
	vector <string> pathV;
	vector <string> visitedV;
	// path, visited items. We append values from tiles to visited as we go. Path gets them all instantaneously - path is generated at the start and doesn't look back. Needs to get a random set leading to destination. start is always AA.

	char press;
	int colour;
	int REDRAW_TIMER_ID = 1;
	int direction;
	int score;
	int recx, recy;
	string name;
	virtual void onDraw();
	virtual void onKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void drawPath();
	virtual void onTimer(UINT nIDEvent);
	virtual void onKeyDownAction(UINT nChar);
	virtual void drawPlayer();
	virtual void writeName();
};

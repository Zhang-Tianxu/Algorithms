#include <iostream>
#include <limits.h>
#include "Maze.h"

// MazePos class relative
MazePos::MazePos() {
	x = -1;
	y = -1;
}

MazePos::MazePos(int px, int py) {
	x = px;
	y = py;
}

MazePos MazePos::up(int d) {
	return MazePos(x - d,y);
}

MazePos MazePos::down(int d) {
	return MazePos(x + d,y);
}

MazePos MazePos::left(int d) {
	return MazePos(x,y - d);
}

MazePos MazePos::right(int d) {
	return MazePos(x,y + d);
}

bool MazePos::operator==(const MazePos& b) {
	return (x == b.x) && (y == b.y);
}
void MazePos::print() {
	std::cout << "(" << x << ", " << y << ")";
}

// Maze class relative

Maze::Maze() {
	MazeBoard = std::vector<std::vector<int>> (0,std::vector<int>(0));
	in = MazePos(0,0);
	out = MazePos(0,0);
}

Maze::Maze(std::vector<std::vector<int>> board, MazePos in_pos, MazePos out_pos) {
	MazeBoard = board;
	in = in_pos;
	out = out_pos;
}

int Maze::getPosValue(MazePos p) {
	if(!posInMaze(p)) {
		return INT_MIN;
	}
	return MazeBoard[p.x][p.y];
}

void Maze::setPosValue(MazePos p, int v) {
	if(!posInMaze(p)) {
		return;
	}
	MazeBoard[p.x][p.y] = v;
}

bool Maze::posInMaze(MazePos p) {
	if(MazeBoard.size() <= 0) {
		return false;
	}
	return p.x >= 0 && p.y >= 0 && p.x < MazeBoard.size() && p.y < MazeBoard[0].size();
}

void Maze::print() {
	int row = MazeBoard.size();
	if (row <= 0) {
		return;
	}
	int col = MazeBoard[0].size();
	for(int i = 0;i < row;i++) {
		for(int j = 0;j < col;j++) {
			std::cout << MazeBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// help methods
Maze makeMaze() {
	return Maze({{1, 1, 1, 1, 1},
                     {1, 0, 1, 0, 1},
                     {1, 0, 1, 0, 1},
                     {1, 0, 1, 0, 0},
                     {1, 1, 1, 1, 1}}, MazePos(0,0), MazePos(4,4));
}

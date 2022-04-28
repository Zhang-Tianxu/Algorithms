#ifndef _MAZE_H_
#define _MAZE_H_

#include <vector>

class MazePos {
public:
	int x;
	int y;
	MazePos();
	MazePos(int px, int py);
	MazePos up(int d);
	MazePos down(int d);
	MazePos left(int d);
	MazePos right(int d);
	bool operator==(const MazePos& b);
	void print();
};

class Maze {
public:
	std::vector<std::vector<int>> MazeBoard;
	MazePos in;
	MazePos out;
	Maze();
	Maze(std::vector<std::vector<int>> board, MazePos in_pos, MazePos out_pos);
	int getPosValue(MazePos p);
	void setPosValue(MazePos p, int v);
	bool posInMaze(MazePos p);
	void print();
};


Maze makeMaze();

#endif

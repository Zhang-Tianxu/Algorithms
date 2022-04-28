#include <iostream>
#include <vector>
#include <queue>
#include "Maze.h"


using namespace std;

void DFSBackTrace(Maze& maze, MazePos current, vector<vector<MazePos>>& paths, vector<MazePos>& path);
vector<vector<MazePos>> BFSBackTrace(Maze maze);

int main() {
	vector<vector<MazePos>> paths;
	vector<MazePos> path;
	Maze maze = makeMaze();
	Maze maze2 = makeMaze();
	cout << "迷宫结构：" << endl;
	maze.print();
	cout << "入口：";
	maze.in.print();
	cout <<endl;
	cout << "出口：";
	maze.out.print();
	cout <<endl;
	DFSBackTrace(maze, maze.in, paths, path);
	cout << "迷宫有" << paths.size() << "条路径，分别是：" << endl;
	for(int i = 0;i < paths.size();i++) {
		for(int j = 0;j < paths[i].size();j++) {
			paths[i][j].print();
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	vector<vector<MazePos>> paths2 = BFSBackTrace(maze2);
	cout << "迷宫有" << paths.size() << "条路径，分别是：" << endl;
	for(int i = 0;i < paths2.size();i++) {
		for(int j = 0;j < paths2[i].size();j++) {
			paths2[i][j].print();
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void DFSBackTrace(Maze& maze, MazePos current, vector<vector<MazePos>>& paths, vector<MazePos>& path) {
	if(current == maze.out) {
		path.push_back(current);
		paths.push_back(path);
		return;
	}

	if(maze.getPosValue(current.up(1)) == 1) {
		path.push_back(current);
		maze.setPosValue(current, 0);
		DFSBackTrace(maze, current.up(1), paths, path);
		maze.setPosValue(current, 1);
		path.pop_back();
	}

	if(maze.getPosValue(current.down(1)) == 1) {
		path.push_back(current);
		maze.setPosValue(current, 0);
		DFSBackTrace(maze, current.down(1), paths, path);
		maze.setPosValue(current, 1);
		path.pop_back();
	}

	if(maze.getPosValue(current.left(1)) == 1) {
		path.push_back(current);
		maze.setPosValue(current, 0);
		DFSBackTrace(maze, current.left(1), paths, path);
		maze.setPosValue(current, 1);
		path.pop_back();
	}

	if(maze.getPosValue(current.right(1)) == 1) {
		path.push_back(current);
		maze.setPosValue(current, 0);
		DFSBackTrace(maze, current.right(1), paths, path);
		maze.setPosValue(current, 1);
		path.pop_back();
	}
}

vector<vector<MazePos>> BFSBackTrace(Maze maze) {
	vector<vector<MazePos>> res;
	vector<MazePos> path;
	queue<MazePos> q;
	q.push(maze.in);
	MazePos current= maze.in;
	while(!q.empty()) {
		current = q.front();
		q.pop();
		path.push_back(current);
		maze.setPosValue(current,0);
		if(current == maze.out) {
			res.push_back(path);
			continue;
		}
		if(maze.getPosValue(current.up(1)) == 1) {
			q.push(current.up(1));
		}
		if(maze.getPosValue(current.down(1)) == 1) {
			q.push(current.down(1));
		}
		if(maze.getPosValue(current.left(1)) == 1) {
			q.push(current.left(1));
		}
		if(maze.getPosValue(current.right(1)) == 1) {
			q.push(current.right(1));
		}
	}
	return res;
}

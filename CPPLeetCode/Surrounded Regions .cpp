#include <iostream>
#include <vector>
#include <stack>
#include "Solutions.h"

using namespace std;

void solve(vector<vector<char>>& board) {
	if (board.size() == 0)
		return;
	int col = 0, row = 0, maxCol = board.size(),maxRow=board[0].size();
	bool** visited = new bool*[board.size()];
	stack<vector<int>> path;
	for (auto i = 0; i != board.size(); i++)
	{
		visited[i] = new bool[board[0].size()];
		for (int j = 0; j != board[0].size(); j++)
			visited[i][j] = false;
	}
	for (int i = 0; i != board[0].size(); i++)
	{
		if (board[0][i] == 'O'&&visited[0][i] == false)
		{
			visited[0][i] = true;
			vector<int> tmp;
			tmp.push_back(0);
			tmp.push_back(i);
			path.push(tmp);
		}
		if (board[board.size() - 1][i] == 'O'&&visited[board.size() - 1][i] == false)
		{
			visited[board.size()-1][i] = true;
			vector<int> tmp;
			tmp.push_back(board.size()-1);
			tmp.push_back(i);
			path.push(tmp);
		}
	}
	for (int i = 0; i != board.size(); i++)
	{
		if (board[i][0] == 'O'&&visited[i][0] == false)
		{
			visited[i][0] = true;
			vector<int> tmp;
			tmp.push_back(i);
			tmp.push_back(0);
			path.push(tmp);
		}
		if (board[i][board[0].size() - 1] == 'O'&&visited[i][board[0].size() - 1] == false)
		{
			visited[i][board[0].size()-1]= true;
			vector<int> tmp;
			tmp.push_back(i);
			tmp.push_back(board[0].size() - 1);
			path.push(tmp);
		}
	}
	while (!path.empty())
	{
		bool haNext = false;
		col = path.top()[0];
		row = path.top()[1];
		if ((col + 1 < maxCol) && (board[col + 1][row] == 'O') && (visited[col + 1][row] == false))
		{
			visited[col + 1][row] = true;
			vector<int> tmp = {col+1,row};
			path.push(tmp);
			haNext = true;
		}
		if ((col - 1 > 0) && (board[col - 1][row] == 'O')&&(visited[col-1][row]==false))
		{
			visited[col - 1][row] = true;
			vector<int> tmp = { col - 1, row };
			path.push(tmp);
			haNext = true;
		}
		if ((row + 1 < maxRow)&&(board[col][row + 1] == 'O')&&(visited[col][row+1]==false))
		{
			visited[col][row + 1] = true;
			vector<int> tmp = { col , row+1 };
			path.push(tmp);
			haNext = true;
		}
		if ((row - 1 > 0 )&&( board[col][row - 1] == 'O')&&(visited[col][row-1])==false)
		{
			visited[col][row - 1] = true;
			vector<int> tmp = { col, row-1 };
			path.push(tmp);
			haNext = true;
		}
		if (!haNext)
			path.pop();
	}
	for (int i = 0; i != board.size(); i++)
		for (int j = 0; j != board[0].size(); j++)
		{
			if (visited[i][j])
				board[i][j] = 'O';
			else
				board[i][j] = 'X';
		}

}
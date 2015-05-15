#include <iostream>
#include <vector>
#include <stack>
#include "Solutions.h"
using namespace std;

bool exist(vector<vector<char> > &board, string word) {
	if(board.size()==0)
		return false;
	const int row=board.size(),col=board[0].size();
	vector<vector<bool>> isContains;
	for(int i=0;i!=row;i++)
	{
		vector<bool> tmp;
		for(int j=0;j!=col;j++)
			tmp.push_back(false);
		isContains.push_back(tmp);
	}
	bool isAdd=false;
	bool result=false;

	for(int i=0;i!=row;i++)
		for(int j=0;j!=col;j++)
		{
			if(isContains[i][j])
				continue;
			if(board[i][j]==word[0])
			{
				isContains[i][j]=true;
				result=isExist(board,word,i,j,0,isContains);
				if(result)
					return true;
				else
					isContains[i][j]=false;
			}
		}
		return false;
}
bool isExist(vector<vector<char>> &board,string word,int i,int j,int pos,vector<vector<bool>> isContains)
{
	bool result=false;
	if(pos==word.length()-1)
		return true;
	int row=board.size(),col=board[0].size();
	bool tBool=false;
	if(board[i][j]==word[pos])
	{
		if(i>0&&isContains[i-1][j]!=true&&board[i-1][j]==word[pos+1])//up
		{
			isContains[i-1][j]=true;
			tBool=isExist(board,word,i-1,j,pos+1,isContains);
			if(tBool)
			{
				return true;
			}
			else
			{
				isContains[i-1][j]=false;
			}
		}
		if(j>0&&isContains[i][j-1]!=true&&board[i][j-1]==word[pos+1])//left
		{
			isContains[i][j-1]=true;
			tBool=isExist(board,word,i,j-1,pos+1,isContains);
			if(tBool)
			{
				return true;
			}
			else
			{
				isContains[i][j-1]=false;
			}
		}
		if(i+1<row&&isContains[i+1][j]!=true&&board[i+1][j]==word[pos+1])//down
		{
			isContains[i+1][j]=true;
			tBool=isExist(board,word,i+1,j,pos+1,isContains);
			if(tBool)
			{
				return true;
			}
			else
			{
				isContains[i+1][j]=false;
			}
		}
		if(j+1<col&&isContains[i][j+1]!=true&&board[i][j+1]==word[pos+1])//right
		{
			isContains[i][j+1]=true;
			tBool=isExist(board,word,i,j+1,pos+1,isContains);
			if(tBool)
			{
				return true;
			}
			else
			{
				isContains[i][j+1]=false;
			}
		}
	}
	else
		return false;
	return false;
		
}
#include <iostream>
#include <vector>
#include <stack>
#include <Windows.h>

using namespace std;

int largestRectangleArea(vector<int>& height) {
	/*if(height.size()==0)
		return 0;
	if(height.size()==1)
		return height[0];
	int left=0,right=0,min=0,max=0,curResult=0;
	bool mi = true;
	for(int i=0;i!=height.size();i++)
	{
		if ((i != height.size() - 1)&&height[i] <= height[i + 1])
			continue;
		if (height[i] == 0)
			continue;
		left=i-1;
		right=i;
		min=height[i];
		curResult=(right-left)*min;
		if (max < curResult)
			max = curResult;
		while (left >= 0)
		{
			if (height[left] == 0)
				break;
			if (min > height[left])
				min = height[left];
			curResult = (right - left + 1)*min;
			if (max < curResult)
				max = curResult;
			left--;
		}
		
	}
	return max;*/
	if (height.size() == 0) return 0;

	int res = 0;
	vector<int> tmp = height;
	tmp.push_back(0);  // Important

	stack<int> s;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) s.push(i);
		else{
			while (!s.empty() && tmp[s.top()] > tmp[i])
			{
				int idx = s.top(); s.pop();
				int width = s.empty() ? i : (i - s.top() - 1);
				res = max(res, tmp[idx] * width);
			}
			s.push(i);  // Important
		}
	}
	return res;
}
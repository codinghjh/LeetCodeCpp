#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int>> result;
	if (S.size()==0)
	{
		vector<int> tmp;
		result.push_back(tmp);
		return result;
	}
	sort(S.begin(),S.end());
	
	for(int i=0;i!=S.size();i++)
	{
		if(result.size()==0)
		{
			vector<int> tmp;
			tmp.push_back(S[i]);
			result.push_back(tmp);
		}
		else
		{
			int end=result.size();
			for(int j=0;j!=end;j++)
			{
				vector<int> tmp1;
				tmp1.insert(tmp1.end(),result[j].begin(),result[j].end());
				tmp1.push_back(S[i]);
				result.push_back(tmp1);
			}
			vector<int> tmp;
			tmp.push_back(S[i]);
			result.push_back(tmp);
		}
	}
	vector<int> tmp;
	result.push_back(tmp);
	return result;
}


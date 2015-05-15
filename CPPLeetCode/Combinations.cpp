#include <iostream>
#include <vector>
#include "Solutions.h"

using namespace std;
vector<vector<int> > combine(int n, int k) {
	vector<vector<int>> result;
	if(k>n)
		return result;
	int *p=new int[n];
	for(int i=0;i!=n;i++)
		*(p+i)=i+1;
	return subCombine(p,k,0,n-1);
}
vector<vector<int>> subCombine(int *p,int k,int start,int end)
{
	vector<vector<int>> result;
	if(end-start+1<k)
		return result;
	if(k==1)
	{
		for(int i=start;i!=end+1;i++)
		{
			vector<int> v;
			v.push_back(*(p+i));
			result.push_back(v);
		}
		return result;
	}
	for(int i=start;i!=end;i++)
	{
		vector<vector<int>> temp=subCombine(p,k-1,i+1,end);
		if(!temp.empty()&&temp.size()>0)
			for(int j=0;j!=temp.size();j++)
			{
				vector<int> t=temp[j];
				t.insert(t.begin(),*(p+i));
				result.push_back(t);
			}
	}
	return result;
}

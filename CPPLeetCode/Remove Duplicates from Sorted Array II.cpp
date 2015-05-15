#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n) {
	int pos=0,pre=0,count=1;
	if(n==0||n==1)
		return n;
	pre=A[0];

	pos=1;
	for(int i=1;i!=n;i++)
	{
		if(A[i]==pre)
		{
			if(count<2)
			{
				count++;
				A[pos]=A[i];
				pos++;
			}
		}
		else
		{
			pre=A[i];
			count=1;
			A[pos]=A[i];
			pos++;
		}
	}
	return pos;
}
#include <iostream>

using namespace std;

bool search(int A[], int n, int target) {
	int start=0,end=n-1;
	while(start<end)
	{
		int mid=(start+end)/2;
		if(A[mid]==target)
			return true;
		else
		{
			if(A[start]==A[mid])
			{
				for(int i=start;i!=mid;i++)
					if(A[i]==target)
						return true;
			start=mid+1;
			}
			else if(A[start]<A[mid])
			{
				if(A[start]<=target&&target<A[mid])
					end=mid-1;
				else
					start=mid+1;
			}
			else
			{
				if(A[mid]<target&&target<=A[end])
					start=mid+1;
				else
					end=mid-1;
			}

		}
	}
	if(start==end&&A[start]==target)
		return true;
	return false;
}
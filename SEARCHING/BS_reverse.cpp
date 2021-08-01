#include<bits/stdc++.h>
using namespace std;

int bs(int arr[],int s,int e,int key)
{
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(arr[mid] == key)
			return mid;
		if(arr[mid]>key)
			s = mid+1;
		else
			e = mid-1;
	}
	return -1;
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int key;
	cin>>key;
	cout<<bs(a,0,n-1,key)<<endl;
	return 0;
}
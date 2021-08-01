#include <bits/stdc++.h> 
#define ll long long
using namespace std;

int maxSubArrayBrute3(vector<int> &A) {
	int res = 0;
	int n = A.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int sum = 0;
			for(int k=i;k<=j;k++)
			{
				sum+=A[k];
			}
			res = max(res,sum);
		}
	}
	return res;
}

int maxSubArrayBrute2(vector<int> &A) {
	int n = A.size();
	int res = 0;
	for(int i=0;i<n;i++)
	{
		int sum = 0;
		for(int j=i;j<n;j++)
		{
			sum+=A[j];
			res = max(res,sum);
		}
	}
	return res;
}

int maxSubArray(vector<int> &A) {
    int curr=A[0],res = A[0];
    for(int i=1;i<A.size();i++)
    {
        curr = max(A[i],curr+A[i]);
        res = max(res,curr);
    }
    return res;
}

pair<int,int> maxSubArrayIndex(vector<int> &A) {
    int curr = 0,res = 0,st = -1,s = -1,e = -1;
    for(int i=0;i<A.size();i++)
    {
    	curr+=A[i];
        if(res<curr)
        {
        	res = curr;
        	st = s;
        	e = i;
        }
        if(curr<0)
        {
        	curr = 0;
        	s = i+1;
        }
    }
    return {s,e};
}

int main() 
{ 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
     int n;
     cin>>n;
     vector<int> A(n);
     for(int i=0;i<n;i++)
     	cin>>A[i];
     pair<int,int> p = maxSubArrayIndex(A);
     cout<<p.first<<" "<<p.second;
  }
 return 0; 
}
// When a smaller number comes after a larger number in the set, which violates the ascending order.

#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009,c=0;

void merge(ll a[],ll l,ll mid,ll r)
{
	ll i = l , j = mid+1 , k = 0;
	ll temp[r-l+1];

	while((i<=mid) && (j<=r))
	{
		if(a[i]<=a[j])
			temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			c+=(mid+1-i);
		}
	} 

	while(i<=mid)
		temp[k++] = a[i++];

	while(j<=r)
		temp[k++] = a[j++];

	for(ll p=0;p<k;p++)
		a[l++] = temp[p];
}

void mergeSort(ll a[],ll l,ll r)
{
	if(l>=r)
		return;
	ll mid = (l+r)/2;
	mergeSort(a,l,mid);
	mergeSort(a,mid+1,r);
	merge(a,l,mid,r);
}

int main() 
{ 
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--)
  {
     ll n;
     cin>>n;
     ll a[n];
     for(ll i=0;i<n;i++)
     	cin>>a[i];
     mergeSort(a,0,n-1);
     cout<<c<<endl;
  }
 return 0; 
}
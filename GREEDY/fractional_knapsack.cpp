#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009;
struct item
{
	ll v,w;
};

bool cmp(item a,item b)
{
	return (a.v/a.w)>(b.v/b.w);
}

int main() 
{ 
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--)
  {
     ll n,W;
     cin>>n>>W;
     item arr[n];
     for(ll i=0;i<n;i++)
     {
     	cin>>arr[i].v;
     	cin>>arr[i].w;
     }
     sort(arr,arr+n,cmp);

     ll curw=0;
     double ans=0.0;

     for(ll i=0;i<n;i++)
     {
     	if(curw+arr[i].w<=W)
     	{
     		curw+=arr[i].w;
     		ans+=arr[i].v;
     	}
     	else
     	{
     		ll remain=W-curw;
     		ans+=(arr[i].v*((double)remain/arr[i].w));
     		break;
     	}
     }

     cout<<fixed<<setprecision(2)<<ans<<endl;

  }
 return 0; 
}
#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009,c=0;

void min_swaps(ll a[],ll n)
{
	pair<ll,ll> m[n];

	for(ll i=0;i<n;i++)
    {
    	m[i].first = a[i];
    	m[i].second = i;
    }

    sort(m,m+n);

	vector<bool> vis(n,false);

	for(ll i=0;i<n;i++)
	{
		if(vis[i] && m[i].second == i)
			continue;

		ll cycle = 0;
		ll j = i;
		while(!vis[j])
		{
			vis[j] = true; 
			j = m[j].second;
      cycle++;
		}

		if(cycle>0)
			c+=(cycle-1);

	}
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
     {
     	cin>>a[i];
     }
     min_swaps(a,n);
     cout<<c<<endl;
  }
 return 0; 
}
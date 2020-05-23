#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009;
struct act
{
	ll s,f,id;
};

bool cmp(act a,act b)
{
	return a.f<b.f;
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
     act arr[n];
     for(ll i=0;i<n;i++)
     	  cin>>arr[i].s;
     for(ll i=0;i<n;i++)
     {
     	  cin>>arr[i].f;
        arr[i].id=i+1;
     }
     sort(arr,arr+n,cmp);
     ll i=0;
     cout<<arr[0].id<<" ";
     for(ll j=1;j<n;j++)
     {
        if(arr[j].s>=arr[i].f)
        {
            cout<<arr[j].id<<" ";
            i=j;
        }
     }
     cout<<endl;
  }
 return 0; 
}
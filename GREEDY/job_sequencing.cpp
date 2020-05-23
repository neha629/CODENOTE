#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009;
struct job
{
	ll profit,time,id;
};

bool cmp(job a,job b)
{
	return a.profit>b.profit;
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
     job arr[n];
     for(ll i=0;i<n;i++)
     {
        cin>>arr[i].id;
     	  cin>>arr[i].time;
     	  cin>>arr[i].profit;
     }
     bool slot[n] = {false};
     ll res=0,c=0;
     sort(arr,arr+n,cmp);
     for(ll i=0;i<n;i++)
     {
        for(ll j=min(n,arr[i].time)-1;j>=0;j--)
        {
            if(!slot[j])
            {
                res+=arr[i].profit;
                c++;
                slot[j]=true;
                break;
            }
        }
     }
     cout<<c<<" "<<res<<endl;
  }
 return 0; 
}
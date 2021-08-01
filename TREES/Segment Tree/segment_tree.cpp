#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009;

void getUpdate(ll st[],ll s,ll e,ll i,ll diff,ll si)
{
	if(i<s || i>e)
		return;

	st[si]+=diff;

	if(s!=e)
	{
		ll mid = (s+e)/2;
        getUpdate(st,s,mid,i,diff,2*si+1);
        getUpdate(st,mid+1,e,i,diff,2*si+2);
	}

}

ll getSum(ll s,ll e,ll l,ll r,ll i,ll st[])
{
	if(l>e || r<s)
		return 0;
	
	if(s>=l && e<=r)
		return st[i];

	ll mid = (s+e)/2;
	return getSum(s,mid,l,r,2*i+1,st) + getSum(mid+1,e,l,r,2*i+2,st);

}

ll construct(ll a[],ll s,ll e,ll i,ll st[])
{
	if(s==e)
	{
		st[i] = a[s];
		return st[i];
	}
	ll mid = (s+e)/2;
	st[i] = construct(a,s,mid,2*i+1,st) + construct(a,mid+1,e,2*i+2,st);
	return st[i];
}

int main()
{ 
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--)
  {
     ll n,q,ch,l,r,i,val;
     cin>>n>>q;
     ll a[n];
     for(ll i=0;i<n;i++)
     	cin>>a[i];
     ll size = ceil(log2(n))+1;
     size = pow(2,size)-1;
     ll st[size]={0};
     construct(a,0,n-1,0,st);
     while(q--)
     {
     	cin>>ch;
     	if(ch == 1)
     	{
     		cin>>l>>r;
     		if(l<0 || r>=n || l>r)
     		{
     			cout<<"-1"<<endl;
				continue;
     		}
        	cout<<getSum(0,n-1,l,r,0,st)<<endl;
     	}
     	if(ch == 2)
     	{
     		cin>>i>>val;
     		if(i<0 || i>=n)
     			continue;
            getUpdate(st,0,n-1,i,val-a[i],0);
            a[i]=val;
     	}

     	// for(ll i=0;i<size;i++)
     	// 	cout<<st[i]<<" ";
     	// cout<<endl;
     	
     }
  }
 return 0; 
}
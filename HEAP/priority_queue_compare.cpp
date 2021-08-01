//CODEFORCES https://codeforces.com/contest/1353/problem/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct cmp
{
    bool operator() (pair<ll,ll> &a,pair<ll,ll> &b)
    {
        ll lena = a.second-a.first+1;
        ll lenb = b.second-b.first+1;
        if(lena==lenb)
            return a.first>b.first;
        return lena<lenb;
    }
};

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    vector<ll> a(n);
	    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp> q;
	    q.push({0,n-1});
	    for(ll i=1;i<=n;i++)
	    {
	        pair<ll,ll> p = q.top();
	        q.pop();
	        ll id = (p.first+p.second)/2;
	        a[id]=i;
	        if(id>p.first)
	            q.push({p.first,id-1});
	        if(id<p.second)
	            q.push({id+1,p.second});
	    }
	    for(auto it:a)
	        cout<<it<<" ";
	    cout<<endl;
	}
	return 0;
}
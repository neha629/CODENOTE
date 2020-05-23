#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> euler,height,first,segtree;

void reset(ll n)
{
    adj.resize(n);
    euler.reserve(2*n);
    vis.assign(n,false);
    height.resize(n);
    first.resize(n);
}

void dfs(ll node,ll h=0)
{
	vis[node]=true;
    height[node] = h;
    first[node] = euler.size();
    euler.push_back(node);
	for(auto it:adj[node])
    {
    	if(!vis[it])
        {
    		dfs(it,h+1);
            euler.push_back(node);
        }
    }
}

void build(ll node,ll s,ll e)
{
    if(s==e)
        segtree[node] = euler[s];
    else
    {
        ll mid = (s+e)/2;
        build(2*node+1,s,mid);
        build(2*node+2,mid+1,e);

        ll l = segtree[2*node+1];
        ll r = segtree[2*node+2];

        segtree[node] = (height[l]<height[r]?l:r);
    }
}

ll query(ll node,ll s,ll e,ll l,ll r)
{
    if(l>e || r<s)
        return -1;

    if(s>=l && e<=r)
        return segtree[node];

    ll mid = (s+e)/2;
    ll left = query(node,s,mid,l,r);
    ll right = query(node,mid+1,e,l,r);

    if(left == -1)
        return r;
    if(right == -1)
        return l;

    return height[left]<height[right]?left:right;
}

ll lca_rmq(ll u,ll v)
{
    ll left = first[u];
    ll right = first[v];
    if(left>right)
        swap(left,right);
    ll m = euler.size();
    return query(0,0,m-1,left,right);
}

int main()
{
	ll n,e,u,v;
	cin>>n>>e;
	reset(n);
	for(ll i=0;i<e;i++)
    {
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(0);
    ll m = euler.size();
    ll size = ceil(log2(m))+1;
    size = pow(2,size)-1;
    segtree.assign(size,-1);
    build(0,0,m-1);
    cout<<lca_rmq(1,2)<<endl;

	return 0;
}
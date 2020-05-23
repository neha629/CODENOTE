#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj,up;
vector<bool> vis;
vector<ll> tin,tout;
ll timer,l;

void reset(ll n)
{
    adj.resize(n);
    up.assign(n,vector<ll>(l+1));
    vis.assign(n,false);
    tin.resize(n);
    tout.resize(n);
    timer = 0;
}

void dfs(ll v,ll p)
{
    tin[v] = timer++;
    up[v][0] = p;
    for(ll i=1;i<=l;i++)
        up[v][i] = up[up[v][i-1]][i-1];

	for(auto it:adj[v])
    {
        if(it!=p)
            dfs(it,v);
    }
    tout[v] = timer++;
}

bool is_ancestor(ll u,ll v)
{
    return tin[u]<=tin[v] && tout[u]>=tout[v];
}

ll lca(ll u,ll v)
{
    if(is_ancestor(u,v))
        return u;

    if(is_ancestor(v,u))
        return v;

    for(ll i=l;i>=0;i--)
    {
        if(!is_ancestor(up[u][i],v))
            u = up[u][i];
    }
    return up[u][0];
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
    l = ceil(log2(n));
    dfs(0,0);
    cout<<lca(1,3)<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> tin,low,cutpt;
vector<pair<ll,ll>> bridges;
ll timer,c=0;

void dfs(ll v,ll p=-1)
{
	vis[v]=true;
	tin[v]=low[v]=timer++;
    ll child = 0;
	for(auto it:adj[v])
    {
    	if(it==p)
    		continue;
    	if(vis[it])
    		low[v]=min(low[v],tin[it]);
    	else
    	{
    		dfs(it,v);
    		low[v]=min(low[v],low[it]);
    		if(low[it]>low[v])
    			bridges.push_back({v,it});
            if(low[it]>low[v] && p!=-1)
                cutpt.push_back(v);
            child++;
    	}
    }
    if(p==-1 && child>1)
        cutpt.push_back(v);
}

void findf(ll n)
{
	timer=0;
    tin.assign(n+1,-1);
    low.assign(n+1,-1);
    vis.assign(n+1,false);
    for(ll i=1;i<=n;i++)
    {
    	if(!vis[i])
    		dfs(i,-1);
    }
}

int main()
{
	ll n,e,u,v;
	cin>>n>>e;
	adj.resize(n+1);
	for(ll i=0;i<e;i++)
    {
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    findf(n);
    // for(auto i:bridges)
    //     cout<<i.first<<" "<<i.second<<endl;
    for(auto i:cutpt)
        cout<<i<<endl;
	return 0;
}
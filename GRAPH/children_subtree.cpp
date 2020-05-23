#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> child;
ll c=0;

void dfs(ll v)
{
    vis[v]=true;
    child[v]=1;
    for(auto it:adj[v])
    {   
        if(!vis[it])
        {
            dfs(it);
            child[v]+=child[it];
        }
    }
}
int main()
{
    ll n,q,u,v,ans=0;
    cin>>n>>q;
    adj.resize(n+1);
    pair<ll,ll> edge[n+1];
    for(ll i=0;i<n-1;i++)
    {
        cin>>u>>v;
        edge[i+1] = {u,v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.assign(n+1,false);
    child.assign(n+1,0);
    for(ll i=1;i<=n;i++)
       if(!vis[i])
        dfs(i);
    while(q--)
    {
        ll e,i,j;
        cin>>e;
        pair<ll,ll> p = edge[e];
        i=p.first;
        j=p.second;
        ans = min(child[i],child[j]);
        cout<<ans * (n-ans)<<endl;
    }
    return 0;
}
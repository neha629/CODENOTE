#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;

void dfs(ll v)
{
    vis[v]=true;
    cout<<v<<" ";
    for(auto it:adj[v])
    {
        if(!vis[it])
            dfs(it);
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
    vis.assign(n,false);
    for(ll i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i);
        cout<<endl;
    }
    return 0;
}
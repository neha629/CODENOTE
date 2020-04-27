#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<vector<ll>> trans;
vector<bool> vis;
vector<ll> component;
stack<ll> topo;

void dfs2(ll u)
{
    vis[u]=true;
    component.push_back(u);
    for(auto v:trans[u])
    {
        if(!vis[v])
            dfs2(v);
    }
}

void dfs1(ll u)
{
    vis[u]=true;
    for(auto v:adj[u])
    {
        if(!vis[v])
            dfs1(v);
    }
    topo.push(u);
}

int main()
{
    ll n,e,u,v;
    cin>>n>>e;
    adj.resize(n+1);
    trans.resize(n+1);
    for(ll i=0;i<e;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        trans[v].push_back(u);
    }
    vis.assign(n+1,false);
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    vis.assign(n+1,false);
    while(!topo.empty())
    {
        ll i = topo.top();
        topo.pop();
        if(!vis[i])
        {
            dfs2(i);
            for(auto it:component)
                cout<<it<<" ";
            cout<<endl;
            component.clear();
        }
    }

    return 0;
}
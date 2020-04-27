#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;
stack<ll> topo;

void topological_sort(ll u)
{
    vis[u]=true;
    for(auto v:adj[u])
    {
        if(!vis[v])
            topological_sort(v);
    }
    topo.push(u);
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
    }
    vis.assign(n+1,false);
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
            topological_sort(i);
    }
    while(!topo.empty())
    {
        cout<<topo.top()<<" ";
        topo.pop();
    }
    cout<<endl;
    return 0;
}
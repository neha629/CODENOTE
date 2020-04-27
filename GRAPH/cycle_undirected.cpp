#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;

bool cycle_undirected(ll u,ll p=-1)
{
    vis[u]=true;
    for(auto v:adj[u])
    {
        if(!vis[v])
        {
            if(cycle_undirected(v,u))
               return true;   
        }
        else if(v!=p)
            return true;
    }
    return false;
}
bool isCyclic(ll n)
{
    for(ll i=1;i<=n;i++)
    {
      if(!vis[i])
         if(cycle_undirected(i))
            return true; 
    }
    return false;
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
    vis.assign(n+1,false);
    cout<<isCyclic(n)<<endl;
    return 0;
}
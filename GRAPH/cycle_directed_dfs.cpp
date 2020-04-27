#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;
vector<bool> recst;

bool cycle_directed(ll u)
{
    if(!vis[u])
    {
         vis[u]=true;
         recst[u]=true;
         for(auto v:adj[u])
         {
            if(!vis[v])
            {
                if(cycle_directed(v))
                   return true;   
            }
            else if(recst[v])
                return true;
         }
    }
    recst[u]=false;
    return false;
}
bool isCyclic(ll n)
{
    for(ll i=1;i<=n;i++)
    {
      if(!vis[i])
         if(cycle_directed(i))
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
    }
    vis.assign(n+1,false);
    recst.assign(n+1,false);
    cout<<isCyclic(n)<<endl;
    return 0;
}
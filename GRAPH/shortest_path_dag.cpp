#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<pair<ll,ll>>> adj;
vector<ll> dis;
ll INF = LLONG_MAX;
vector<bool> vis;
stack<ll> topo;

void topological_sort(ll u)
{
    vis[u]=true;
    for(auto it:adj[u])
    {
        ll v = it.second;
        if(!vis[v])
        {
            topological_sort(v);
        }
    }
    topo.push(u);
}

void shortest_path_dag()
{
    while(!topo.empty())
    {
        ll u =  topo.top();
        topo.pop();
        // cout<<u<<" ";
        if(dis[u]!=INF)
        {
            for(auto it:adj[u])
            {
                ll v = it.second;
                ll cost = it.first;
                if(dis[v]>dis[u]+cost)
                    dis[v]=dis[u]+cost;
            }
        }
    }
    
    
}

int main()
{
    ll n,e,l,u,v;
    cin>>n>>e;
    adj.resize(n+1);
    for(ll i=0;i<e;i++)
    {
        cin>>u>>v>>l;
        adj[u].push_back({l,v});
    }
    dis.assign(n+1,INF);
    vis.assign(n+1,false);
    for(ll i=1;i<=n;i++)
      if(!vis[i])
        topological_sort(i);
    ll s=2;
    dis[s]=0;
    shortest_path_dag();
    for(ll i=1;i<=n;i++)
        cout<<dis[i]<<endl;
    return 0;
}
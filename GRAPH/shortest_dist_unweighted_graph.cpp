#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<ll> dis,p;
vector<bool> vis;
ll INF = LLONG_MAX;

// Works for both directed and undirected graph
void shortest_Dist_Unweighted(ll i)
{
    vis[i]=true;
    dis[i]=0;
    queue<ll> q;
    q.push(i);
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        for(auto it:adj[v])
        {
            if(!vis[it])
            {
                vis[it]=true;
                dis[it]=dis[v]+1;
                p[it]=v;
                q.push(it);
            }
        }
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
    p.assign(n+1,-1);
    vis.assign(n+1,false);
    dis.assign(n+1,INF);
    ll s=1;
    shortest_Dist_Unweighted(s);
    for(ll i=1;i<=n;i++)
        cout<<dis[i]<<endl;
    return 0;
}
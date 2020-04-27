#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<pair<ll,ll>>> adj;
vector<bool> vis;
vector<ll> dis,p;
ll INF = LLONG_MAX;

void mst()
{
    dis[1]=0;
    vis[1]=true;
    using pt = pair<ll,ll>;
    priority_queue<pt,vector<pt>,greater<pt>> q;
    q.push({0,1});
    while(!q.empty())
    {
        ll v=q.top().second;
        vis[v]=true;
        q.pop();
        for(auto it:adj[v])
        {
            ll to=it.second;
            ll len=it.first;
            if(!vis[to] && dis[to]>len)
            {
                 dis[to]=len;
                 q.push({dis[to],to});
                 p[to]=v;
            }
        }
    }
}
int main()
{
    ll n,e,l,u,v,res=0;
    cin>>n>>e;
    adj.resize(n+1);
    for(ll i=0;i<e;i++)
    {
        cin>>u>>v>>l;
        adj[u].push_back({l,v});
        adj[v].push_back({l,u});
    }
    vis.assign(n+1,false);
    p.assign(n+1,-1);
    dis.assign(n+1,INF);
    mst();
    for(ll i=1;i<=n;i++)
        res+=dis[i];
    cout<<res<<endl;
    return 0;
}
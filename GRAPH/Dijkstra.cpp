#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<pair<ll,ll>>> adj;
vector<ll> dis,p;
ll INF = LLONG_MAX;
vector<ll> ans;

void dijkstra(ll s,ll d)
{
    dis[s]=0;
    using pt = pair<ll,ll>;
    priority_queue<pt,vector<pt>,greater<pt>> q;
    q.push({0,s});
    while(!q.empty())
    {
        ll v=q.top().second;
        q.pop();
        for(auto it:adj[v])
        {
            ll to=it.second;
            ll len=it.first;
            if(dis[to]>dis[v]+len)
            {
                 dis[to]=dis[v]+len;
                 q.push({dis[to],to});
                 p[to]=v;
            }
        }
    }
}
void printpath(ll s,ll d)
{
    for(ll i=d;i!=s;i=p[i])
        ans.push_back(i);
    ans.push_back(s);
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
        cout<<it<<" ";
}
int main()
{
    ll n,e,l,u,v,s,d;
    cin>>n>>e;
    adj.resize(n+1);
    for(ll i=0;i<e;i++)
    {
        cin>>u>>v>>l;
        adj[u].push_back({l,v});
        // adj[v].push_back({l,u});
    }
    p.assign(n+1,-1);
    dis.assign(n+1,INF);
    s=1;
    d=n;
    dijkstra(s,d);
    if(dis[d]==INF)
        cout<<"-1";
    else
        printpath(s,d);
    return 0;
}
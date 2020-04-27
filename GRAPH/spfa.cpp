//Shortest Path Faster Algorithm (SPFA)
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll INF = LLONG_MAX;
vector<vector<pair<ll,ll>>> adj;
vector<bool> inqueue;
vector<ll> dis;
bool spfa(ll s,ll n)
{
    dis[s]=0;
    vector<ll> cnt(n+1,0);
    queue<ll> q;
    q.push(s);
    inqueue[s] = true;
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        inqueue[u] = false;
        for(auto edge:adj[u])
        {
            ll v = edge.first;
            ll len = edge.second;
            if(dis[u]!=INF && dis[v]>dis[u]+len)
            {
                dis[v]=max(-INF,dis[u]+len);
                if(!inqueue[v])
                {
                    q.push(v);
                    inqueue[v] = true;
                    cnt[v]++;
                    if(cnt[v]>n)
                        return 1; //negative cycle
                }
            }
        }
    }
    return 0;
}

int main()
{
    ll n,e,u,v,l;
    cin>>n>>e;
    adj.resize(n+1);
    for(ll i=0;i<e;i++)
    {
        cin>>u>>v>>l;
        adj[u].push_back({v,l});
    }
    inqueue.assign(n+1,false);
    dis.assign(n+1,INF);
    ll s=1;
    cout<<spfa(s,n)<<endl;
    for(ll i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}
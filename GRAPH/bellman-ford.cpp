#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll INF = LLONG_MAX;
vector<bool> vis;
vector<ll> dis,p;
struct edge
{
    int a,b,c;
};

vector<edge> ed;
bool bellman_ford(ll s,ll n, ll e)
{
    dis[s]=0;
    ll x;
    for(ll i=0;i<n;i++)
    {
        x=-1;
        for(ll j=0;j<e;j++)
        {
            if(dis[ed[j].a]!=INF && dis[ed[j].b] > dis[ed[j].a] + ed[j].c)
            {
                dis[ed[j].b] = max(-INF, dis[ed[j].a] + ed[j].c);
                p[ed[j].b] = ed[j].a;
                x = ed[j].b;
            }
        }
        if(x==-1)
        return 0;
    }
    return 1;  //negative cycle
}

int main()
{
    ll n,e,u,v,l;
    cin>>n>>e;
    ed.resize(e);
    for(ll i=0;i<e;i++)
    {
        cin>>ed[i].a>>ed[i].b>>ed[i].c;
    }
    vis.assign(n+1,false);
    p.assign(n+1,-1);
    dis.assign(n+1,INF);
    ll s=1;
    cout<<bellman_ford(s,n,e)<<endl;
    for(ll i=1;i<=n;i++)
        cout<<dis[i]<<" ";
    cout<<endl;
    return 0;
}
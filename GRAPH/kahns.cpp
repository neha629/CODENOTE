//Kahns(Lexicographically Smallest Topological Ordering) and cycle directed kahns
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;
vector<ll> indegree,topo;

bool kahns(ll n)
{
    ll cnt=0;
    multiset<ll> s;
    for(ll i=1;i<=n;i++)
        if(indegree[i]==0)
            s.insert(i);

    while(!s.empty())
    {
        ll u = *s.begin();
        s.erase(s.begin());
        topo.push_back(u);
        
        for(auto v:adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0)
                s.insert(v);
        }
        cnt++;

    }
    if(cnt!=n)
     return true;
    else
     return false;
}
int main()
{
    ll n,e,u,v;
    cin>>n>>e;
    adj.resize(n+1);
    indegree.assign(n+1,0);
    for(ll i=0;i<e;i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vis.assign(n+1,false);
    cout<<kahns(n)<<endl;
    for(auto it:topo)
        cout<<it<<" ";
    cout<<endl;
    return 0;
}
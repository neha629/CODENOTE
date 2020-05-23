#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;
ll x;

void dfs(ll u,ll count,ll &maxcount)
{
    vis[u] = true;
    count++;
    for(auto it:adj[u])
    {
       if(!vis[it])
       {
           if(count>maxcount)
           {
              maxcount = count;
              x = it;
           }
           dfs(it,count,maxcount);
       }
    }
}

int main()
{
    ll n,u,v;
    cin>>n;
    adj.resize(n+1);
    for(ll i=0;i<n-1;i++)
    {
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    vis.assign(n+1,false);
    ll maxcount = LLONG_MIN;
    dfs(1,0,maxcount);
    vis.assign(n+1,false);
    dfs(x,0,maxcount);
    cout<<maxcount<<endl;
    return 0;
}
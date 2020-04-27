#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>> adj;
vector<bool> vis;

void bfs()
{
    queue<ll> q;
    q.push(0);
	vis[0]=true;
    while(!q.empty())
    {
        ll v=q.front();
        q.pop();
        cout<<v<<" ";
        for(auto it:adj[v])
        {
           if(!vis[it])
           {
               q.push(it);
               vis[it]=true;
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
    vis.assign(n,false);
    bfs();
	return 0;
}
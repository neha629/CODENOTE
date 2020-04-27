#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool checkbipartite(int n,vector<vector<ll>> adj)
{
    ll c[n+1];
    memset(c,-1,sizeof(c));
    bool isbipartite=true;
    queue<ll> q;
    for(ll i=1;i<=n;i++)
    {
        if(c[i]==-1)
        {
            q.push(i);
            c[i]=0;
            while(!q.empty())
            {

                ll p=q.front();
                q.pop();
                for(auto it:adj[p])
                {
                    if(c[it]==-1)
                    {
                        c[it]=c[p]^1;
                        q.push(it);
                    }
                    else
                        isbipartite=isbipartite&(c[it]!=c[p]);
                }
            }
        }
    }
    return isbipartite;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    ll n,e,u,v;
	    cin>>n>>e;
	    vector<vector<ll>> adj(n+1);
	    for(ll i=0;i<e;i++)
	    {
	        cin>>u>>v;
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }
        cout<<checkbipartite(n,adj)<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll INF = LLONG_MAX;
vector<vector<ll>> dis;

void floyd_warshall(ll n)
{
    for(ll k=0;k<n;k++)
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                if(dis[i][k]!=INF && dis[k][j]!=INF)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
    }
}

int main()
{
    ll t;
    cin>>t;
    for(ll k=1;k<=t;k++)
    {
        ll n,q,ans=0,u,v;
        cin>>n;
        dis.resize(n);
        for(ll i=0;i<n;i++)
           dis[i].assign(n,INF);
    
       for(ll i=0;i<n;i++)
       {
            for(ll j=0;j<n;j++)
            {
                cin>>dis[i][j];
            }
       }
       floyd_warshall(n);
       cin>>q;
       while(q--)
       {
          cin>>u>>v;
          ans+=dis[u-1][v-1];
       }
       cout<<"Case #"<<k<<": "<<ans<<endl;
    }
    return 0;
}
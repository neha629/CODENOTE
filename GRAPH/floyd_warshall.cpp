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
    ll n;
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
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            cout<<dis[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n;

ll minPart(ll a[],ll i,ll curr,ll sum)
{
    if(i==n)
        return abs(curr-(sum-curr));
    
    return min(minPart(a,i+1,curr+a[i],sum),minPart(a,i+1,curr,sum));
}

int main() 
{
    ll sum=0;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    
    cout<<minPart(a,0,0,sum);
    return 0;
}
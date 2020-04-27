#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009;
ll binpow_recur(ll a,ll b)
{
	if(b==0)
		return 1;
	ll res=binpow_recur(a,b/2);
	if(b&1)
		return res*res*a;
	else
		return res*res;
}
ll binpow_mod(ll a,ll b,ll m) {
    a%=m;
    ll res=1;
    while(b>0) {
        if(b&1)
            res=(res*a)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return res;
}
ll binpow(ll a,ll b)
{
	a=a%mod;
	ll res=1;
	while(b>0)
	{
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b=b>>1;
	}
	return res;
}
int main() 
{ 
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
     cout<<binpow(2,63)<<endl;
 return 0; 
}
#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
vector<ll> fib;
ll mod=1000000007;
void fibo(ll m)
{
	fib.resize(m+1);
	fib[0]=fib[1]=1;
	for(ll i=2;i<=m;i++)
		fib[i]=(fib[i-1]+fib[i-2])%mod;
}

// Closed-form expression
long double fibo_formula(ll n)
{
	long double phi = (1+sqrt(n))/2;
	long double res = round(pow(phi,n)/sqrt(5));
	return res;
}

//Matrix form

void multiply(ll F[2][2], ll M[2][2]) 
{ 
  ll x =  ((F[0][0]*M[0][0])%mod + (F[0][1]*M[1][0])%mod)%mod; 
  ll y =  ((F[0][0]*M[0][1])%mod + (F[0][1]*M[1][1])%mod)%mod;
  ll z =  ((F[1][0]*M[0][0])%mod + (F[1][1]*M[1][0])%mod)%mod; 
  ll w =  ((F[1][0]*M[0][1])%mod + (F[1][1]*M[1][1])%mod)%mod; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 

void binpow(ll F[2][2], ll n) 
{ 
  if( n == 0 || n == 1) 
      return; 
  ll M[2][2] = {{1,1},{1,0}}; 
  
  binpow(F, n/2); 
  multiply(F, F); 
  
  if(n&1) 
     multiply(F, M); 
} 

pair<ll, ll> fibo_matrix(ll n)
{
	ll F[2][2] = {{1,1},{1,0}}; 
    if (n == 0) 
      return {0,1}; 
    binpow(F, n); 
   cout<<F[0][0]<<" "<<F[0][1]<<endl; 
   cout<<F[1][0]<<" "<<F[1][1]<<endl; 
    return {F[0][1],F[0][0]};
}



//Fast Doubling Method
pair<ll, ll> fibo_pair(ll n) 
{
    if (n == 0)
        return {0, 1};

    auto p = fibo_pair(n >> 1);
    ll c = p.first * (2 * p.second - p.first);
    ll d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}


int main() 
{ 
   cout<<fibo_formula(4)<<endl;
}
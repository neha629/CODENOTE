#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
ll m = 1000001;
vector<bool> prime;
void sieve()
{
    prime.assign(m+1,true);
    prime[0]=prime[1]=false;
    for(ll i=2;i*i<=m;i++)
    {
        if(prime[i])
          for(ll j=i*i;j<=m;j=j+i)
            prime[j]=false;
    }
}
int main() 
{ 
  sieve();
 return 0; 
}
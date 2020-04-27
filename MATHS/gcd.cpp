#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
//Euclidean algorithm for computing the greatest common divisor
//Recursive solution
ll gcd_recursive(ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd_recursive(b, a % b);
}

//Using the ternary operator in C++

ll gcd_ternary_op(ll a, ll b) {
    return b ? gcd_ternary_op(b, a % b) : a;
}

//Non-recursive implementation:
ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm (ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll extended_euclidean_algo(ll a,ll b,ll &x, ll &y)
{
  //ax+by=gcd(a,b)
   if(b==0)
   {
      x=1;
      y=0;
      return a;
   }
   ll x1,y1;
   ll d = extended_euclidean_algo(b,a%b,x1,y1);
   x=y1-(b/a)*x1;
   y=x1;
   return d;
}

int main() 
{ 
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll x=0,y=0;
  ll gcd=extended_euclidean_algo(2,7,x,y);
  cout<<x<<" "<<y<<" "<<gcd;
 return 0; 
}
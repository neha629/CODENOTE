#include <bits/stdc++.h> 
#define ll long long
using namespace std;
ll mod=1000000007;
string s;
ll n,ans=0;
bool isSafe(ll i, ll j)
{
   if(i>=0 && i<7 && j>=0 && j<7)
    return true;
  return false;
}
void func(ll i,ll j,char ch,ll c)
{
   if(c==n)
   {
     ans++;
     return;
   }
   if(!isSafe(i,j)
     return;
   if(s[c]=='?' || s[c]==ch)
   {
      func(i,j-1,'L',c+1);
      func(i-1,j,'U',c+1);
      func(i,j+1,'R',c+1);
      func(i+1,j,'D',c+1);
   }
   else
    return;
}
int main() 
{ 
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>s;
  n = s.length();
  ll c=0,ans;
  ll i=0,j=0;
  func(i,j-1,'L',0);
  func(i-1,j,'U',0);
  func(i,j+1,'R',0);
  func(i+1,j,'D',0);
  return 0; 
}
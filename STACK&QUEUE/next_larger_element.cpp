#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios_base::sync_with_stdio(false)
int main()
{
  fastio;
   int t;
   cin>>t;
   while(t--)
   {
       int n,x;
       cin>>n;
       long long arr[n],ans[n];
       memset(ans,-1,sizeof(ans));
       for(int i=0;i<n;i++)
          cin>>arr[i];
       stack<int> s;
       s.push(0);
       for(int i=1;i<n;i++)
       {
           while(!s.empty() && arr[s.top()]<=arr[i])
           {
               int in = s.top();
               s.pop();
               ans[in] = arr[i];
           }
           s.push(i);
       }
       for(int i=0;i<n;i++)
           cout<<ans[i]<<" ";
       cout<<endl;
   }
   return 0;
}
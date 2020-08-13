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
       int freq[26] = {0};
       queue<char> q;
       int n;
       char ch;
       cin>>n;
       for(int i=0;i<n;i++)
       {
           cin>>ch;
           q.push(ch);
           freq[ch-'a']++;
           while(!q.empty())
           {
               if(freq[q.front()-'a']>1)
                q.pop();
               else
               {
                   cout<<q.front()<<" ";
                   break;
               }
           }
           if(q.empty())
            cout<<-1<<" ";
       }
       cout<<endl;
   }
   return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define fastio std::ios_base::sync_with_stdio(false)

bool balanced(string str)
{
    int n = str.length();
    stack<char> s;
    char ch;
    for(int i=0;i<n;i++)
    {
        ch = str[i];
        if(ch=='(' || ch=='{' || ch=='[')
            s.push(ch);
        else
        {
            if(s.empty())
                return 0;
                
            char t = s.top();
            s.pop();
            switch(ch)
            {
                case ')':
                    if(t=='{' || t=='[')
                        return 0;
                    break;
                
                case '}':
                    if(t=='(' || t=='[')
                        return 0;
                    break;
                
                case ']':
                    if(t=='{' || t=='(')
                        return 0;
                    break;
            }
        }
    }
    return s.empty();
}

int main()
{
  fastio;
   int t;
   cin>>t;  
   while(t--)
   {
       string str;
       cin>>str;
       if(balanced(str))
            cout<<"balanced"<<endl;
       else
            cout<<"not balanced"<<endl;
   }
   return 0;
}
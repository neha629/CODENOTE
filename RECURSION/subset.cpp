#include <bits/stdc++.h> 
using namespace std;
void func(string s,int n,int i,string curr)
{
    if(n==i)
     return ;
     cout<<curr<<endl;
     for(int j=i+1;j<n;j++)
     {
         curr += s[j];
         func(s,n,j,curr);
         curr=curr.erase(curr.size()-1);
     }
    
}
int main() {
    string s="abcd";
    int n=s.length();
      func(s,n,-1,"");
	return 0;
}
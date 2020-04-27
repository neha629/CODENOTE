#include <bits/stdc++.h> 
using namespace std;
bool func(string &s,int i=0)
{
    int n=s.length();
    if(i==n/2)
     return 1;
    if(s[i]!=s[n-1-i])
    return 0;
    func(s,i+1);
}
int main() {
    string s="abdbad";
	cout<<func(s)<<endl;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int m = 1e9+9;
vector<ll> pi;

void kmp(string pat,string txt)
{
    int m = pat.length();
    int n = txt.length();
    int i=0,j=0;

    while(i<n)
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }

        if(j==m)
        {
            cout<<i-j<<" ";
            j = pi[j-1];
        }
        else if(i<n && pat[j]!=txt[i])
        {
            if(j!=0)
                j = pi[j-1];
            else
                i++;
        }
    }

}

void prefix_function(string s)
{
    int n = s.size();
    pi.assign(n,0);
    for(ll i=1;i<n;i++)
    {
        ll j = pi[i-1];

        while(j>0 && s[i]!=s[j])
            j = pi[j-1];

        if(s[i]==s[j])
            j++;

        pi[i] = j;
    }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string pat,txt;
		cin>>txt>>pat;
        prefix_function(pat);
        kmp(pat,txt);
        cout<<endl;
        pi.clear();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int m = 1e9+9;
vector<ll> res;

void rabin_karp(string s,string t)
{
	const int p = 31;
    int S = s.size(),T = t.size();

    int max_size = max(S,T);
    vector<ll> p_pow(max_size);
    p_pow[0]=1;
    for(int i=1;i<max_size;i++)
    	p_pow[i]=(p*p_pow[i-1])%m;

    vector<ll> h(T+1,0);
    for(int i=0;i<T;i++)
    	h[i+1] = (h[i] + (t[i]-'a'+1)*p_pow[i]) % m;

    ll h_p = 0;
    for(int i=0;i<S;i++)
    	h_p = (h_p + (s[i]-'a'+1)*p_pow[i]) % m;

    for(int i=0;i<=T-S;i++)
    {
    	ll cur_h = (h[i+S]+m-h[i]) % m;
    	if(cur_h == h_p*p_pow[i]%m)
    		res.push_back(i);
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
        rabin_karp(pat,txt);
        for(auto it:res)
        	cout<<it<<" ";
        cout<<endl;
        res.clear();
	}
	return 0;
}
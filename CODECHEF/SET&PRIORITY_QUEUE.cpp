#include <bits/stdc++.h> 
#define ll long long
using namespace std;
ll mod=1000000007;

// priority_queue<int> :- greatest element at top
// priority_queue<int,vector<int>,greater<int>> :- smallest element at top

int main() 
{ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,x,res=0;
        cin>>n>>k;
        priority_queue<ll> q;
        for(ll i=0;i<n;i++)
        {
            cin>>x;
            q.push(x);
        }
        while(k>0)
        {
            ll temp = q.top();
            if(temp<=0)
            {
                res=-1;
                break;
            }
            k -= temp;
            q.pop();
            q.push(temp/2);
            res++;
        }
        if(res==-1)
            cout<<"Evacuate"<<endl;
        else
            cout<<res<<endl;
    }

    return 0; 
}

#include <bits/stdc++.h> 
#define ll long long
using namespace std;
ll mod=1000000007;

int main() 
{ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,x,res=0;
        cin>>n>>k;
        set<pair<ll,ll>> s;
        for(ll i=0;i<n;i++)
        {
            cin>>x;
            s.insert({x,i});
        }
        set<pair<ll,ll>>::iterator it;
        while(k>0)
        {
            it = s.end();
            it--;
            ll temp = it->first;
            if(temp<=0)
            {
                res=-1;
                break;
            }
            k -= temp;
            s.erase(it);
            s.insert({temp/2,it->second});
            res++;
        }
        if(res==-1)
            cout<<"Evacuate"<<endl;
        else
            cout<<res<<endl;
    }

    return 0; 
}
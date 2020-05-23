#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009;
vector<ll> harr;
ll size = 0;

void insert(ll x)
{
	harr.push_back(x);
	size++;
	ll i = size-1;
	ll p = (i-1)/2;
	while(i!=0 && harr[p]>harr[i])
	{
		p = (i-1)/2;
		swap(harr[p],harr[i]);
		i = p;
	}
}

void heapify(ll i)
{
	ll lc = 2*i+1;
    ll rc = 2*i+2;
    ll smallest = i;
    if(lc<size && harr[lc]<harr[i])
    	smallest = lc;
    if(rc<size && harr[rc]<harr[smallest])
    	smallest = rc;
    if(smallest!=i)
    {
    	swap(harr[i],harr[smallest]);
    	heapify(smallest);
    }
}

ll extract_min()
{
	if(size==0)
		return -1;
	if(size==1)
		return harr[0];
	ll root = harr[0];
	harr[0] = harr[size-1];
	heapify(0);
	return root;
}

void decrease_Key(ll i,ll val)
{
	harr[i] = INT_MIN;
	ll p = (i-1)/2;
	while(i!=0 && harr[p]>harr[i])
	{
		p = (i-1)/2;
		swap(harr[p],harr[i]);
		i = p;
	}
}

void delete_key(ll i)
{
	decrease_Key(i,INT_MIN);
	extract_min();
}

void build(ll n)
{
	size += n;
	for(ll i=(n-1)/2;i>=0;i--)
		heapify(i);
}

int main() 
{ 
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--)
  {
     ll n,x;
     cin>>n;
     for(ll i=0;i<n;i++)
     {
     	cin>>x;
     	harr.push_back(x);
     }
     build(0);
     for(ll i=0;i<size;i++)
     	cout<<harr[i]<<" ";
     cout<<endl;
     // cout<<extract_min()<<endl;
     // delete_key(7);
     // for(ll i=0;i<size;i++)
     // 	cout<<harr[i]<<" ";
     // cout<<endl;

  }
 return 0; 
}
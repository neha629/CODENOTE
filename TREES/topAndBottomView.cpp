#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> inor;
vector<ll> postor;
vector<ll> preor;

struct node
{
	ll key;
	struct node *left,*right;
	node(ll key)
	{
	   this->key=key;
	   this->left=NULL;
	   this->right=NULL;
	}
};

void topview(node *root)
{
	map<ll,ll> m;
	ll hd=0;
	queue<pair<node*,ll>> q;
	q.push({root,hd});
	while(!q.empty())
	{
		auto it = q.front();
		q.pop();
		node *temp = it.first;
		hd = it.second;
        if(!m[hd])
        	m[hd] = temp->key;
		if(temp->left)
			q.push({temp->left,hd-1});
		if(temp->right)
			q.push({temp->right,hd+1});
	}
	for(auto it:m)
		cout<<it.second<<" ";
	cout<<endl;
}

void bottomview(node *root)
{
	map<ll,ll> m;
	ll hd=0;
	queue<pair<node*,ll>> q;
	q.push({root,hd});
	while(!q.empty())
	{
		auto it = q.front();
		q.pop();
		node *temp = it.first;
		hd = it.second;
        m[hd] = temp->key;
		if(temp->left)
			q.push({temp->left,hd-1});
		if(temp->right)
			q.push({temp->right,hd+1});
	}
	for(auto it:m)
		cout<<it.second<<" ";
	cout<<endl;
}

struct node *insertLevelOrder(ll a[],node *root,ll i,ll n)
{
	if(i<n)
	{
		if(a[i]==-1)
			return NULL;
		root= new node(a[i]);
        root->left=insertLevelOrder(a,root->left,2*i+1,n);
        root->right=insertLevelOrder(a,root->right,2*i+2,n);
	}
	return root;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
    	cin>>n;
   		ll a[n];
    	for(ll i=0;i<n;i++)
    		cin>>a[i];
    	node *root=insertLevelOrder(a,root,0,n);
    	bottomview(root);
	}
	return 0;
}
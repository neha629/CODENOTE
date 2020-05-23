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

void levelOrderTraversal(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node* temp = q.front();
		q.pop();
		cout<<temp->key<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

void verticalOrderTraversal(node *root)
{
	map<ll,vector<ll>> m;
	ll hd=0;
	queue<pair<node*,ll>> q;
	q.push({root,hd});
	while(!q.empty())
	{
		auto it = q.front();
		q.pop();
		node *temp = it.first;
		hd = it.second;
        m[hd].push_back(temp->key);
		if(temp->left)
			q.push({temp->left,hd-1});
		if(temp->right)
			q.push({temp->right,hd+1});
	}
	for(auto it:m)
	{
		for(auto i:m[it.first])
			cout<<i<<" ";
		cout<<endl;
	}
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

void traversal(node *root) 
{ 
	if(root!=NULL) 
	{ 
	    preor.push_back(root->key);
		traversal(root->left); 
		inor.push_back(root->key);
		cout<<root->key<<" ";
		traversal(root->right); 
		postor.push_back(root->key);
	} 
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
    	verticalOrderTraversal(root);
	}
	return 0;
}
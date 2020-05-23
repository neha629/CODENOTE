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
	    // preor.push_back(root->key);
		traversal(root->left); 
		// inor.push_back(root->key);
		// cout<<root->key<<" ";
		traversal(root->right); 
		postor.push_back(root->key);
		// cout<<root->key<<" ";
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
    	traversal(root);
    	cout<<endl;
	}
	return 0;
}
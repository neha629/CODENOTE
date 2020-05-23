#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// vector<ll> inor;
// vector<ll> postor;
// vector<ll> preor;

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

void createTree(node* created[],ll a[],ll i,node **root)
{
	if(created[i])
		return;
	created[i] = new node(i);
	if(a[i]==-1)
	{
		*root = created[i];
		return;
	}
    if(!created[a[i]])
    	created[a[i]] = new node(a[i]);
    if(!created[a[i]]->left)
    	created[a[i]]->left = created[i];
    else
    	created[a[i]]->right = created[i];
}

void traversal(node *root) 
{ 
	if(root!=NULL) 
	{ 
	    // preor.push_back(root->key);
		traversal(root->left); 
		// inor.push_back(root->key);
		cout<<root->key<<" ";
		traversal(root->right); 
		// postor.push_back(root->key);
	} 
}

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    	cin>>a[i];
    node *created[n] = { NULL };
    node *root=NULL;
    for(ll i=0;i<n;i++)
    	createTree(created,a,i,&root);
    traversal(root);
	return 0;
}
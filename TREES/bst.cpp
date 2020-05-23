#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll res = LLONG_MIN;

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

struct node *insert(node *root,ll x)
{
	if(root == NULL)
     return new node(x);

    if(root->key<x)
     root->left = insert(root->left,x);
    else
     root->right = insert(root->right,x);
    
    return root;
}

node* lca(node *root,ll n1,ll n2)
{
	if(root==NULL)
		return NULL;

    if(root->key<n1 && root->key<n2)
        return lca(root->left,n1,n2);
    
    if(root->key>n1 && root->key>n2)
        return lca(root->right,n1,n2);
        
    return root;
}

node* search(node *root,ll x)
{
    res = max(res,root->key);

    if(root->key==x)
        return root;

    if(root->key<x)
        return search(root->left,x);
    else 
        return search(root->right,x);
}

int main()
{
		ll n,x,n1,n2;
    	cin>>n;
        node *root=NULL;
    	for(ll i=0;i<n;i++)
    	{
            cin>>x;
            root = insert(root,x);
        }
        cin>>n1>>n2;
    	node *temp = lca(root,n1,n2);
        search(temp,max(n1,n2));
        cout<<res<<endl;
	return 0;
}
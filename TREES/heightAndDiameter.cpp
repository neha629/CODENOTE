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
		traversal(root->left); 
		cout<<root->key<<" ";
		traversal(root->right); 
	} 
}

ll height(node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}

ll diameter(node *root)
{
	if(root==NULL)
		return 0;
	ll lh = diameter(root->left);
	ll rh = diameter(root->right);
	res = max(res,lh+rh+1);
	return max(lh,rh)+1;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		res = LLONG_MIN;
		ll n;
    	cin>>n;
   		ll a[n];
    	for(ll i=0;i<n;i++)
    		cin>>a[i];
    	node *root=insertLevelOrder(a,root,0,n);
    	// cout<<height(root)<<endl;
    	diameter(root);
    	cout<<res<<endl;
	}
    
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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

node *lca_recursive(node *root,ll n1,ll n2)
{
	if(root==NULL)
		return NULL;

	if(root->key == n1 || root->key == n2)
		return root;

    node *l = lca_recursive(root->left,n1,n2);
    node *r = lca_recursive(root->right,n1,n2);

    if(l && r)
    	return root;

    return (l!=NULL)?l:r;

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
		ll n,n1,n2;
    	cin>>n;
   		ll a[n];
    	for(ll i=0;i<n;i++)
    		cin>>a[i];
    	node *root=insertLevelOrder(a,root,0,n);
    	cin>>n1>>n2;
    	node *ans = lca_recursive(root,n1,n2);
    	cout<<ans->key<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll maxlvl = -1; 

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

void rightview_levelorder(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		ll size = q.size();
		for(ll i=0;i<size;i++)
		{
			node *temp = q.front();
			if(i==size-1)
				cout<<temp->key<<" ";
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
    }
}

void leftview(node *root,ll lvl)
{
	if(root == NULL)
		return;

	if(lvl>maxlvl)
	{
		cout<<root->key<<" ";
		maxlvl = lvl;
	}

	leftview(root->left,lvl+1);
	leftview(root->right,lvl+1);
}

void rightview(node *root,ll lvl)
{
	if(root == NULL)
		return;

	if(lvl>maxlvl)
	{
		cout<<root->key<<" ";
		maxlvl = lvl;
	}

	rightview(root->right,lvl+1);
	rightview(root->left,lvl+1);
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
    	maxlvl = -1;
    	// rightview(root,0);
    	rightview_levelorder(root);
    	cout<<endl;
	}
	return 0;
}
#include <bits/stdc++.h> 
#define ll long long int
using namespace std;
ll mod=1000000009;
const int alpha_size = 26;

struct node
{
	struct node *children[alpha_size];
	bool isEnd;
	node()
	{
		this->isEnd = false;
		for(int i=0;i<alpha_size;i++)
			this->children[i]=NULL;
	}
};

void insert(node *root,string s)
{
	node *temp = root;
	ll n = s.length();
	for(ll i=0;i<n;i++)
	{
		ll index = s[i]-'a';
		if(!temp->children[index])
			temp->children[index] = new node();

		temp = temp->children[index];
	}
	temp->isEnd = true;
}

bool search(node *root,string s)
{
	node *temp = root;
	ll n = s.length();
	for(ll i=0;i<n;i++)
	{
		ll index = s[i]-'a';
		if(!temp->children[index])
			return false;

		temp = temp->children[index];
	}
	return (temp!=NULL && temp->isEnd);
}

bool isEmpty(node *root)
{
	for(int i=0;i<alpha_size;i++)
		if(root->children[i])
			return false;

	return true;
}

node* remove(node *root,string s,ll depth)
{
	if(!root)
		return NULL;

	if(depth == s.length())
	{
		if(root->isEnd)
			root->isEnd = false;
		if(isEmpty(root))
		{
			delete(root);
		    root = NULL;
		}
		return root;
	}

	int index = s[depth] - 'a';
	root->children[index] = remove(root->children[index],s,depth+1);

	if(isEmpty(root) && root->isEnd == false)
	{
		delete(root);
		root = NULL;
	}
    
    return root;
}

int main() 
{ 
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t;
  cin>>t;
  while(t--)
  {
     ll n,q;
     cin>>n;
     string s;
     node *root = new node();
     for(ll i=0;i<n;i++)
     {
     	cin>>s;
     	insert(root,s);
     }
     remove(root,"aaaaa",0);
     cin>>q;
     for(ll i=0;i<q;i++)
     {
     	cin>>s;
        cout<<search(root,s)<<endl;
     }
  }
 return 0; 
}
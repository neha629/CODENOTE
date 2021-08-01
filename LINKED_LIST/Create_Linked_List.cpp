#include<iostream>
using namespace std;

struct node
{
	int val;
	struct node *next;
	node(int x)
	{
		this->val = x;
		this->next = NULL;
	}
};

int main()
{
	int n,x;
	cin>>n;
	node *head=NULL,*temp;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(head==NULL)
		{
			head = new node(x);
			temp = head;
		}
		else
		{
			temp->next = new node(x);
			temp = temp->next;
		}
	}
	temp = head;
	for(int i=0;i<n;i++)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	return 0;
}
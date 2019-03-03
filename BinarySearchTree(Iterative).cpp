#include <iostream>
#include <stack>
#define MAX 100
using namespace std;
struct node
{
	int info;
	node *right;
	node *left;
	node *thread;
};
stack<node*> s;
node *root=new node;

node* newnode(int x)
{
	node *p=new node;
	p->info=x;
	p->right=NULL;
	p->left=NULL;
	p->thread=NULL;
	return p;
}
void add(int x,node *t2)
{
	bool isInserted=false;
	while(!isInserted)
	{
		if(root==NULL)
		{
			
			root=newnode(x);
			return;
		}
		if(x<t2->info)
		{
			while(t2->left!=NULL && x<t2->info)
				t2=t2->left;
			if(t2->left==NULL && x<t2->info)
			{
				t2->left=newnode(x);
				isInserted=true;
			}
			else if(t2->right==NULL && x>t2->info)
			{
				t2->left=newnode(x);
				isInserted=true;
			}
		}
		else 
		{
			while(t2->right!=NULL && x>t2->info)
				t2=t2->right;
			if(t2->left==NULL && x<t2->info)
			{
				t2->right=newnode(x);
				isInserted=true;
			}
			else if(t2->right==NULL && x>t2->info)
			{
				t2->right=newnode(x);
				isInserted=true;
			}
		}
		
	}
}
void add2(int x,node *t2)
{
	if(root==NULL)
	{
		root=newnode(x);
		return;
	}
	else
	{
		if(t2->info>x && t2->left!=NULL)
			add2(x,t2->left);
		
		else if(t2->info<x && t2->right!=NULL)
			add2(x,t2->right);

		else
			t2->right=newnode(x);
	}
}
node* current;
void preorder(node *temp3)
{
	current=root;
	s.push(current);
	while(s.empty()==false)
	{
		
		current=s.top();
		cout<<current->info<<"\t";
		s.pop();
		if(current->right!=NULL)
			s.push(current->right);
		if(current->left!=NULL)
			s.push(current->left);
	}
}

void inorder(node * temp3)
{
	current=root;
	while(current!=NULL || s.empty()==false)
	{
		while(current!=NULL)
		{
			s.push(current);
			current=current->left;
		}
		current=s.top();
		s.pop();
		cout<<current->info<<"\t";
		current=current->right;
	}
}
void postorder()
{
	current=root;
	stack<node*> s2;
	s.push(current);
	while(s.empty()==false)
	{
		current=s.top();
		s.pop();
		s2.push(current);
		if(current->left)
			s.push(current->left);
		if(current->right)
			s.push(current->right);
	}
	while(s2.empty()==false)
	{
		current=s2.top();
		s2.pop();
		cout<<current->info<<"\t";
	}
}
int main()
{
	int n;
	cout<<"Enter no. of Elements:";

	cin>>n;
	int a[MAX];
	cout<<"\nEnter Elements:\n";
	root=NULL;

	for (int i = 0; i <n ; i++)
	{
		cin>>a[i];
		add(a[i],root);
		// add2(a[i],root);
	}
	
	//inorder(root);
	//preorder(root);
	//postorder(root);
	postorder2();
	return 0;
}



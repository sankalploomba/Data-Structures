#include<iostream>
using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
    node* thread;
};

node* insert(node * t, int data)
{
    if(t->left==NULL && t->right==NULL)
        return t;

    else
    {
        if(data <= t->val)
        {
            if(t->left==NULL)
                return t;
			else
				insert(t->left,data);
        }
        else
        {
            if(t->right==NULL)
                return t;
            else
				insert(t->right,data);
        }
    }
}

void preorder(node* r)
{
    if(r!=NULL)
    {
        cout<<r->val<<" ";
            preorder(r->left);
            preorder(r->right);
    }
}

void inorder(node* r)
{
    if(r!=NULL)
    {
            inorder(r->left);
        cout<<r->val<<" ";
            inorder(r->right);
    }
}

void postorder(node* r)
{
    if(r!=NULL)
    {
            postorder(r->left);
            postorder(r->right);
        cout<<r->val<<" ";
    }
}

node* th_trav;
void inorder_thread(node* r)
{
	if(r!=NULL)
	{
			inorder_thread(r->left);
			if(th_trav==NULL)
			{
				r->thread=r;
				th_trav=r;
			}
			else
			{
				r->thread=th_trav;
				cout<<"current: "<<r->val<<"\t predecessor: "<<r->thread->val<<endl;
				th_trav=r;
			}
			inorder_thread(r->right);
	}
}
int main()
{
    int size,i;
    cout<<"Enter number of nodes: ";
    cin>>size;

    int* ar= new int[size];

    cout<<"Enter values into the array: ";
    for(i=0;i<size;i++)
    {
        cin>>ar[i];
	}
        node* t= new node;
        t->val= ar[0];
        t->left= NULL;
        t->right= NULL;

        node* head;
        head=t;

    i=1;
    while(i<size)
    {
        node* p=new node;
        p->val=ar[i];
        p->left= NULL;
        p->right= NULL;


        t=insert(head,p->val);

        if(p->val <= t->val)
            t->left=p;

        else
            t->right=p;

        i++;
    }

    cout<<endl<<endl<<"Sorted list is: ";
    inorder(head);

    cout<<endl<<endl<<"Pre-ordered list is: ";
    preorder(head);

    cout<<endl<<endl<<"Post-ordered list is: ";
    postorder(head);

	cout<<endl;
	
	inorder_thread(head);
	
	while(th_trav->thread!=th_trav)
	{
		cout<<th_trav->val<<"\t";
		th_trav=th_trav->thread;
	}
	cout<<th_trav->val;
}

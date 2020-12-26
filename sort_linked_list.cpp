//SORTING IN A SINGLY LINKED LIST
#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class node
{
	public:	T val;
			node<T> *next;
};
    node<int> *head=new node<int>;
    node<int> *t=new node<int>;
	node<int> *t2=new node<int>;

int size;

void display()
{
    cout<<endl<<"Final list: ";
    t=head;
    while(t->next!=NULL)
    {
        cout<<(t->val)<<"\t";
        t=t->next;
    }
    cout<<endl<<endl<<"Size of the list = "<<size;
}
void bsort()
{
	for(int i=0;i<size;i++)
	{
		t=head;
		for(int j=0;j<size-i-1;j++)
		{
			if(t->val > t->next->val)
			{
				int temp;
				temp=t->next->val;
				t->next->val=t->val;
				t->val=temp;
			}
			t=t->next;
		}
		
	}
}
void ssort()
{
	t=head;
	for(int i=0;i<size-1;i++)
	{
		t2=t->next;
		for(int j=i+1;j<size;j++)
		{
			if(t->val > t2->val)
			{
				int temp;
				temp=t2->val;
				t2->val=t->val;
				t->val=temp;
			}
			t2=t2->next;
		}
		t=t->next;
	}
}
void isort()
{
	t=head->next;
	for(int i=1;i<n;i++)
	{
		int j=i-1;
		t2=head;
		while(j>=0 && t2->val > t->val)
		{
			t2->next->val=t2->val;
			j=j-1;
			t2=t2->next;
		}
		t2->next->val=t->val; 
	t=t->next;
	}
}
int main()
{
    cout<<"Enter size: ";
    cin>>size;

    int ar[size], i;

    cout<<endl<<"Enter array: ";
    for(i=0;i<size;i++)
        cin>>ar[i];


    head->val=ar[0];
    head->next= NULL;
    t=head;

    i=1;
    //This loop is making a linked list which is getting VALUES from an ARRAY ar[] and is OUTPUTING them.

    cout<<endl<<"Original list: ";
    while(i<(size+1))
    {
        cout<<(t->val)<<"\t";

        node<int> * p=new node<int>;
        p->val=ar[i];
        p->next= NULL;

        t->next=p;
        t=p;
        i++;

    }
    
    bsort();
	//ssort();
	display();
}

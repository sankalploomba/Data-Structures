//SEACRHING IN A SINGLY LINKED LIST
#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class node
{
	public:
    T val;
    node<T> *next;
};
    node<int> *head=new node<int>;
    node<int> *t=new node<int>;

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
void bsearch(int key)
{
	int min,mid,max;
	min=0,max=size;


	while(min<=max)
	{
		mid=(min+max)/2;
		t=head;
		
		for(int i=0;i<mid;i++)
			t=t->next;
			
		if(key==t->val)
		{
			cout<<"Key found!"<<endl;
			break;
		}
		else if(key<t->val)
			max=mid-1;
		else
			min=mid+1;
	}
	cout<<"Key not found.";
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
    int key;
    cout<<"Enter key: ";
    cin>>key;
    bsearch(key);
}

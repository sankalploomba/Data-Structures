//Implementation of a priority queue with priority values from 1-5 where 5 is the highest priority.

#include<iostream>
using namespace std;

struct node
{
    int value;
    int priority;
    node* next;
};

class Priority_Queue
{
	public:	node* front;
			node* rear;
			bool first=true;

			void display()
			{
				node* t=new node;
				t=(front);

				if(t==NULL)
				{
					cout<<"Empty Queue. "<<endl;
					return;
				}

				cout<<endl<<"Final list: ";

				while(t!=NULL)
				{
					cout<<(t->value)<<"\t";
					t=t->next;
				}
			}

			void add()
			{
				if(first)
				{
					front=new node;
					rear=new node;
					
					cout<<"Enter value and it's priority (between the range 0-5) in queue: ";
					cin>>(rear->value);
					cin>>(rear->priority);

					if((rear->priority < 1) || (rear->priority > 5))
					{
						cout<<endl<<"Invalid priority."<<endl;
						return;
					}

					front=rear;
					first=false;
				}

				else
				{
					node* p= new node;
					if(p==NULL)
					{
						cout<<"Queue full. "<<endl;
						return;
					}
					else
					{
						cout<<"Enter value and it's priority (between the range 0-5) in queue: ";
						cin>>(p->value);
						cin>>(p->priority);

						if((p->priority < 1) || (p->priority > 5))
						{
							cout<<"Invalid priority."<<endl;
							return;
						}

						if((p->priority) > (front->priority))
						{
								p->next=front;
								front=p;
						}
						else if((p->priority) < (rear->priority))
						{
							rear->next=p;
							rear=p;
						}
						else
						{
							node* t= new node;
							t=front;
							
							while(t!=NULL)
							{
								if((p->priority) > (t->next->priority))
								{
									p->next=t->next;
									t->next=p;
									break;
								}
								else
									 t=t->next;
							}
			
						}

					}
				}
				display();
			}
			
			int del()
			{
				if(first || front==NULL)
				{
					first=true;
					return -1;
				}
				else
				{
					node* temp;
					int x=front->value;
					temp=front->next;
					delete front;
					front=temp;
					return x;
				}
			}
};

int main()
{
    Priority_Queue p;
	
	unsigned int choice;
	char ch;
	
    do
    {
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Add "<<endl<<"2. Delete "<<endl<<"3. Display "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
            p.add();

        else if(choice==2)
        {
            int x;
            x=p.del();

            if(x==-1)
                cout<<"Queue is empty. "<<endl;

            else
                cout<<"Deleted element is "<<x;
        }

        else if(choice==3)
            p.display();

        else
            cout<<"Invalid choice."<<endl;


        cout<<endl<<endl<<"Do you want to continue? ";
        cin>>ch;
        
    }	while(ch=='y' || ch=='Y');
    
}
//By Sankalp Loomba

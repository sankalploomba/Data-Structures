//LINKED LIST USING TEMPLATES
#include<iostream>
#include<stack>
using namespace std;

template<class T>
class node
{
	public:	T val;
			node<T> *next;
};

template<class T>
class List
{
	public:	node<int> *head=new node<int>;
			node<int> *t=new node<int>;	
			bool first_flag=true;
			int size=0;
			
			void display()
			{
				t=head;
				while(t->next!=NULL && !first_flag)
				{
					cout<<t->val<<"\t";
					t=t->next;
				}
				cout<<t->val<<endl;
				cout<<endl<<"Size: "<<size<<endl;
			}
			void l_search(T key)
			{
				t=head;
				while(t!=NULL)
				{
					if(key==t->val)
					{
						cout<<"Key found."<<endl;
						//display();
						return;
					}
					t=t->next;
				}
				cout<<"Key not found."<<endl;
			}
			void b_search(T key)
			{
				int mid,min=0,max=size;
				
				t=head;
				while(min<=max && t->next!=NULL)
				{
					t=head;
					mid=(min+max)/2;
					
					for(int i=0;i<mid-1;i++)
						t=t->next;
					
					if(key==t->val)
					{
						cout<<"Key found!"<<endl;
						//display();
						return;
					}
					else if(key<t->val)
						max=mid;
					else
						min=mid;
				}
				cout<<"Key not found."<<endl;
			}
			void ins()
			{
				if(first_flag==true)
				{
					cout<<"Enter the val: ";
					cin>>head->val;
					
					head->next=NULL;
					t=head;
					
					first_flag=false;
				}
				else
				{
					node<int> *p=new node<int>;
					cout<<"Enter the val: ";
					cin>>p->val;
				
					p->next=NULL;
					t->next=p;
					t=p;
				}
	
				size++;
				//display();
			}
			void del(T key)
			{
				t=head;
				if(key==head->val)
				{
					head=head->next;
					delete t;
					size--;
					display();
					return;
				}
				else
				{
					while(t!=NULL)
					{
						if(key==t->next->val)
						{
							if(t->next->next!=NULL)
								t->next=t->next->next;
							else
								t->next=NULL;
						
							size--;
							display();
							return;
						}
						else
							t=t->next;
					}
				}
			}
			void rev()
			{
				stack<int> s;
				t=head;
				while(t!=NULL)
				{
					s.push(t->val);
					t=t->next;
				}
				
				t=head;
				while(t!=NULL)
				{
					t->val=s.top();
					s.pop();
					t=t->next;
				}
				
				display();
			}
			void operator+ (List<int> l)
			{
				t=head;
				while(t->next!=NULL)
					t=t->next;
				
				t->next=l.head;
				
				display();
			}	
};
int main()
{
	List<int> l1,l2;
	
	char ch;
	do
	{
		int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Deletion "<<endl<<"2. Insertion "<<endl<<"3. Linear Search "<<endl<<"4. Binary Search "<<endl<<"5. Display "<<endl<<"6. Reverse "<<endl<<"7. Contatenate "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
			int key;
			cout<<"Enter the key: ";
			cin>>key;
			
            l1.del(key);
		}
        else if(choice==2)
        {
            l1.ins();
            l2.ins();
		}
        else if(choice==3)
        {
			int key;
			cout<<"Enter the key: ";
			cin>>key;
			
            l1.l_search(key);
		}
        else if(choice==4)
        {
			int key;
			cout<<"Enter the key: ";
			cin>>key;
			
            l1.b_search(key);
		}
        else if(choice==5)
            l1.display();
		
		else if(choice==6)
            l1.rev();
		
		else if(choice==7)
            l1+l2;

        else
            cout<<"Invalid choice."<<endl;


      cout<<endl<<endl<<"Do you want to continue? ";
      cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}

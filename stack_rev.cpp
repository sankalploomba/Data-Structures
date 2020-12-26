#include<iostream>
using namespace std;
template<class T>
class node
{
	public:	int val;
			node<T> *next;
};

template<class T>
class Stack
{
	public:	node<int> *top=new node<int>;
			node<int> *t;
			bool first=true;
			
			void display()
			{
				t=top;
				while(t!=NULL)
				{
					cout<<t->val<<"\t";
					t=t->next;
				}
			}
			void push(T element)
			{
				if(first)
				{
					top->val=element;
					top->next=NULL;
					first=false;
				}
				else
				{
					node<int> *p=new node<int>;
					p->val=element;
					
					p->next=top;
					top=p;
				}
				//display();
			}
			T pop()
			{
				if(top==NULL || first)
					return -1;
					
				T x=top->val;
				
				node<int> *temp=top->next;
				delete top;
				top=temp;
				
				return x;
			}
			void reverse(Stack<T> &s)
			{
				node<int> *t=top;
				while(t!=NULL)
				{
					int x=t->val;
					//cout<<"Element being pushed is: "<<x<<endl;
					s.push(x);
					t=t->next;
				}
				
				cout<<endl<<endl;
				s.display();
			}
};
int main()
{
	Stack<int> s1,s2;
	char ch;

    do
    {
        int choice;
        cout<<endl<<endl<<"-----------------------------------------------------------------------------"<<endl;
        cout<<"1. Push "<<endl<<"2. Pop "<<endl<<"3. Display "<<endl<<"4. Reverse "<<endl;
        cout<<endl<<"Enter choice: ";
        cin>>choice;

        if(choice==1)
        {
			int element;
			cout<<"Enter element to be pushed: ";
			cin>>element;
			
            s1.push(element);
		}
        else if(choice==2)
        {
            int x;
            x=s1.pop();

            if(x==-1)
                cout<<"Stack is empty. "<<endl;

            else
                cout<<"Popped out element is "<<x;
        }

        else if(choice==3)
            s1.display();
        
		
		else if(choice==4)
			s1.reverse(s2);
			
        else
            cout<<"Invalid choice."<<endl;


        cout<<endl<<endl<<"Do you want to continue? ";
        cin>>ch;
    }
    while(ch=='y'||ch=='Y');
}

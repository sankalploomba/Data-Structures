#include<iostream>
using namespace std;
int main()
{
	int* a,size;
	cout<<"Enter size: ";
	cin>>size;
	
	a=new int[size];
	cout<<"Enter array: ";
	for(int i=0;i<size;i++)
		cin>>a[i];
		
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(i==j)
				cout<<a[i]<<"\t";
			else
				cout<<0<<"\t";
		}
		cout<<endl;
	}
}

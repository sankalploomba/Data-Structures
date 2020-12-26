#include<iostream>
using namespace std;
int main()
{
	int* a,size;
	cout<<"Enter size of the matrix: ";
	cin>>size;
	
	int s=0;
	for(int i=size;i>0;i--)
		s+=i;
	
	a=new int[s];
	cout<<"Enter array: ";
	for(int i=0;i<s;i++)
		cin>>a[i];
		
	for(int i=0,k=0; i<size && k<s; i++)
	{
		for(int j=size;j>0;j--)
		{
			if((size-j)>=i)						//for upper right {for upper left, just keep j>i in if}
			{
				cout<<a[k]<<"\t";
				k++;
			}
			else
				cout<<0<<"\t";
		}
		cout<<endl;
	}
}

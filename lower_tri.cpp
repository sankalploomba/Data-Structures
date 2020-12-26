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
		for(int j=0;j<size;j++)
		{
			if((size-j)<=i+1)				//for lower right {for lower left, just keep j<=i in if}
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

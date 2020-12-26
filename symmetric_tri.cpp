#include<iostream>
using namespace std;
int main()
{
	int* a,size;
	cout<<"Enter size of the matrix: ";
	cin>>size;
	
	int s=0;
	for(int i=0;i<size;i++)
		s+=i;
		
	a=new int[s];
	cout<<"Enter array: ";
	for(int i=0;i<s;i++)
		cin>>a[i];
		
	for(int i=0,k=0,m=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			if(i==j)
				cout<<0<<"\t";
			
			else if(j<i)
			{
				cout<<a[k]<<"\t";
				k++;
			}
		}
		
		for(int l=size; l>0; l--)
		{
			if((size-l)>i)
			{
				cout<<a[m]<<"\t";
				m++;
			}
		}
		cout<<endl;
	}
}

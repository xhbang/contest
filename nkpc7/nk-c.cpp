/*
‘Crazy for Programming’
Nankai University Programming Contest VII
Problem C

author:hxz@acmteam
4/2/2011
compiled under g++/debian 6.0
*/
#include<iostream>
using namespace std;
int main()
{
	int N,K,i,j;
	int temp;
	cin>>N>>K;
	int *a;
	a=new int[K];
    for(i=0;i<K;i++)
		a[i]=0;
	for(i=0;i<K;i++)
		cin>>a[i];
    for(i=1;i<K;i++)
	{
	   if(a[i]>a[i-1])
	   {
		   temp=a[i];
		   for(j=i-1;j>=0&&temp>a[j];j--)
		   {
			   a[j+1]=a[j];
		   }
		   a[j+1]=temp;
	   }
	}
	for(i=K;i<N;i++)
	{
		cin>>temp;
		if(temp<=a[K-1])
			continue;
		else 
		{
		    for(j=K-2;j>=0&&a[j]<=temp;j--)
                 a[j+1]=a[j];
			a[j+1]=temp;
			
		}
	}
	cout<<a[K-1]<<endl;
	delete []a;
	return 0;
}

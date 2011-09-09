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
#define max(a,b) (((a)>(b))?(a):(b))
int main()
{
	int i,j,N,sum=0;
	cin>>N;
	int **a;
	int **b;
	a=new int*[N];
	b=new int*[N];
	for(i=0;i<N;i++)
	{
		a[i]=new int[2];
		b[i]=new int[N];
	}
	for(i=0;i<N;i++)
		for(j=0;j<2;j++)
			cin>>a[i][j];
    for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		{
			b[i][j]=max((a[j][0]-a[i][0]),(a[j][1]-a[i][1]));
           sum+=b[i][j];
		}
		cout<<sum<<endl;
	for(i=0;i<N;i++)
	{
		delete []a[i];
		delete []b[i];
	}
	delete []b;
	delete []a;
	return 0;
}

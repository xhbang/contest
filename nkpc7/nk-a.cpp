/*
‘Crazy for Programming’
Nankai University Programming Contest VII
Problem A:All Star Game

author:hxz@acmteam
4/2/2011
compiled under g++/debian 6.0
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
  freopen("in.txt","r",stdin);
	char ***names;
	int *num;
	int i,j,N,k,b;
	int sum=0,max=0;
	cin>>N;
	
	num=new int[N];
	for(i=0;i<N;i++)
		num[i]=0;
	names=new char**[N];
    for(i=0;i<N;i++)
       names[i]=new char*[3];
	for(i=0;i<N;i++)
      for(j=0;j<3;j++)
		 names[i][j]=new char[30];
	for(i=0;i<N;i++)
		for(j=0;j<3;j++)
			cin>>names[i][j];


	num[0]=1;
	bool change=true;
	for(i=1 ;i < N; i++)
	{
		for(j=0; j < i && change; j++)
		{
			for(k=0; k < 3 && change; k++)
			{
				for(b=0; b < 3 && change; b++)
				if( !strcmp(names[i][k],names[j][b]) )
			//	if(names[i][k]-names[j][b]==0)
					{
						num[i] = num[i-1];
						change = false;
					}
			}
			if(b==3 && k==3 && num[i] < num[j] + 1)	
				num[i] = num[j] + 1;
		}
		change = true;
	}
	 cout<<num[N-1]<<endl;
  for(i=0;i<N;i++)
		for(j=0;j<3;j++)
		{
			delete []names[i][j];
		}
  for(i=0;i<N;i++)
			delete []names[i];
  delete []names;
	delete []num;
	return 0;
}

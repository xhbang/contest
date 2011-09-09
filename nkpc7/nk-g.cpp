/*
‘Crazy for Programming’
Nankai University Programming Contest VII
Problem C

author:hxz@acmteam
4/2/2011
compiled under g++/debian 6.0
*/
#include<iostream>
#define MAX_VALUE 4294967295
using namespace std;
int main()
{
	int i,j,N,k;
	while(cin>>N)
	{
		i=0,j=0,k=0;
       long  *a;
	   long  *X;
	   int n=0;
	   a=new long[N];
	   X=new long[N];
	   memset(a,0,sizeof(a));
	   memset(X,0,sizeof(X));
	   for(i=0;i<N;i++)
		   cin>>a[i];
	   for(k=1;k<N;k++)
	   {
		   if((a[k-1]-a[0])*0==(a[k]-a[0]))
			   continue;
		   else
			   break;
	   }
	   if((k==N)&&(a[0]<=0))
	   {
		   cout<<"YES"<<endl;
		   cout<<-a[0]<<endl;
		   goto al;
	   }
	   for(k=1;k<N;k++)
	   {
		   if((a[k-1]-a[1])*0==(a[k]-a[1]))
			   continue;
		   else
			   break;
	   }
	   if((k==N)&&(a[1]<=0))
	   {
		   cout<<"YES"<<endl;
		   cout<<-a[1]<<endl;
		   goto al;
	   }
	   for(k=1;k<N;k++)
	   {
		   if((a[k-1]-a[2])*0==(a[k]-a[2]))
			   continue;
		   else
			   break;
	   }
	   if((k==N)&&(a[2]<=0))
	   {
		   cout<<"YES"<<endl;
		   cout<<-a[2]<<endl;
		   goto al;
	   }
	   for(i=0;i<N-2;i++)
	   {
		   if(a[i+1]*a[i+1]-a[i]*a[i+2]==0)
		   {
			   if(a[i]+a[i+2]-2*a[i+1]==0)
				   X[n++]=MAX_VALUE;
			   else
				   X[n++]=0;
		   }
		   else
		   {
               if(a[i]+a[i+2]-2*a[i+1]==0)
			   {
				   cout<<"NO"<<endl;
				   cout<<endl;
				   break;
			   }
			   else
			   {
				   if((a[i+1]*a[i+1]-a[i]*a[i+2])%(a[i]+a[i+2]-2*a[i+1])!=0)
				   {
					   cout<<"NO"<<endl;
					   cout<<endl;
					   break;
				   }
				   else 
				   {
					   double temp;
					   temp=(a[i+1]*a[i+1]-a[i]*a[i+2])/(a[i]+a[i+2]-2*a[i+1]);
					   if(temp<0)
					   {
						   cout<<"NO"<<endl;
						   cout<<endl;
						   break;
					   }
					   else
						   X[n++]=temp;
				   }
			   }
		   }
	   }
	   for(i=0;i<n;i++)
	   {
		   if(X[i]!=MAX_VALUE)
		   {
			   j=i;
			   break;
			   
		   }
	   }
	   if(n==N-2)
	   {
		   for(i=0;i<N-2;i++)
		   {
			   
			   if((X[i]==X[j])||(X[i]==MAX_VALUE))
			   {
				   X[i]=X[j];
				   if(i==n-1){
					   i++;
				   }
			   }
			   else
			   {
				   cout<<"NO"<<endl;
				   cout<<endl;
				   break;
			   }
		   
			  if(i==N-2)
			  {
				 cout<<"YES"<<endl;
				 cout<<X[0]<<endl;
			  }
		   }
	   }
al:
	   delete []a;
	   delete []X;
		   
	}
	return 0;
}

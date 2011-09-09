/*
‘Crazy for Programming’
Nankai University Programming Contest VII
Problem B:Birds Attack 

author:hxz@cqu
4/2/2011
compiled under g++/debian 6.0
*/
#include<iostream>
#include<memory.h>
#include<cmath>
#include<iomanip>
using namespace std;
#define Max 90000
double s[Max];
int main()
{
    double theta;
    int n=0,i;
    double H,V,G;
    double MAX=0.0;
	  double x=0,y=0,z=0;
    memset(s,0,sizeof(s));
    cin>>H>>V>>G;
    //theta means v and y-axis
    for(theta=0;theta<=90;theta=theta+0.001)
    {
      //x means the top height - H
		x=V*V*cos(theta)*sqrt(3*sin(theta)*sin(theta)+1)/(2*G);
		y=V*V*sin(theta)*cos(theta)/G+sqrt(V*V*cos(theta)*cos(theta)+2*G*H)*V*sin(theta)/G;
		z=sqrt(y*y+H*H);
		if(x>z)
			s[n++]=x;
		else
			s[n++]=z;
    }
    for(i=0;i<n;i++)
    {
		if(s[i]>MAX)
			MAX=s[i];
    }
   cout<<setiosflags(ios::fixed)<<setprecision(4)<<MAX<<endl;
    return 0;
}

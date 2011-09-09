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
char str1[1002];
char str2[100002];
bool isequal(char str1[],char str2[],int len,int begin);
int main()
{
	int len1,len2,i,j;
	int num=0;
    cin>>str1>>str2;
    len1=strlen(str1);
	len2=strlen(str2);
	j=0;
    while(len2>=len1)
	{
		
		while(1)
		{
			
			if(isequal(str1,str2,len1,j++))
			{
				int a=j-1;				
				for(i=a+len1;i<len2;i++)
					str2[i-len1]=str2[i];
				len2-=len1;
				num++;
				j=0;
			}
		   if(len2-j<len1)
			   break;
		}
		if(len2-j<len1)
			break;
	}
cout<<num<<endl;
	return 0;
}
bool isequal(char str1[],char str2[],int len,int begin)
{
     int i;
	 for(i=0;i<len;i++)
		 if(str1[i]!=str2[begin++])
			 return 0;

		 return 1;
}

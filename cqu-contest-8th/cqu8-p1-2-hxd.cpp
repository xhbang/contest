#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
using namespace std;

bool function(char m[12][12],int a1,int b1){
int result=0;
if((m[a1-2][b1]==m[a1-1][b1]&&m[a1-2][b1]==m[a1][b1])
   ||(m[a1-1][b1]==m[a1][b1]&&m[a1-1][b1]==m[a1+1][b1])
   ||(m[a1][b1]==m[a1+1][b1]&&m[a1+2][b1]==m[a1][b1]))
   return true;
else if((m[a1][b1-2]==m[a1][b1-1]&&m[a1][b1-2]==m[a1][b1])
   ||(m[a1][b1-1]==m[a1][b1]&&m[a1][b1-1]==m[a1][b1+1])
   ||(m[a1][b1]==m[a1][b1+1]&&m[a1][b1+2]==m[a1][b1]))
   return true;
else return false;
}

int main(){
	
	ifstream inf;
	inf.open("B.in");                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
	char m[12][12]={0};
	int i;
	for(i=0;i<12;i++){
			
			m[0][i]='0';
			m[1][i]='0';
			m[10][i]='0';
			m[11][i]='0';
			m[i][0]='0';
			m[i][1]='0';
			m[i][10]='0';
			m[i][11]='0';
		}

	while(true){
		int i=0;
		inf.getline(m[2]+2,9,'\n');
		m[2][10]='0';
		if(m[2][2]=='@')
			break;
		for(i=1;i<8;i++){
			inf.getline(m[i+2]+2,9,'\n');
					m[i+2][10]='0';
		}
		int a1,b1,a2,b2;
		inf>>a1;
		inf>>b1;
		inf>>a2;
		inf>>b2;

		if((abs(a1-a2)==1&& b1-b2==0)||((abs(b1-b2)==1&&a1-a2==0))){
			char temp=0;
		temp=m[a1+1][b1+1];
		m[a1+1][b1+1]=m[a2+1][b2+1];
		m[a2+1][b2+1]=temp;		

		if(function(m,a1+1,b1+1)+function(m,a2+1,b2+1)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		}
		else{
		printf("NO\n");
		}
		inf.get();
	}
		inf.close();
		return 0;
}

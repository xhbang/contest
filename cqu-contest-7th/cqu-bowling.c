#include <stdio.h>
#include <memory.h>
#include <string.h>


int cal(char read){
	switch(read){
		case 'X':
			return 10;
		case '-':
			return 0;
		default:
			return read-'0';
	}
}

int main(){
	int point=0;
	char line[20];
	int val[10];
	//store how many u should store later
	int i,j,n;
	int a,b;
	memset(val,0,sizeof(val));
	//intitial!!!
	while(gets(line)){
		n=strlen(line);
		if(n==0)
			break;
		j=-1;
		for(i=0;i<10;i++){
			j++;
			//pointer in string
			if(i!=9){
				if(line[j]=='X'){
					//addtional
					if(line[j+2]=='/'){
						val[i]=20;
						continue;
					}else{
						val[i]=10+cal(line[j+1])+cal(line[j+2]);
						continue;
					}
				}
				if(line[j]=='-'){
					j++;
					if(line[j]=='-'){
						val[i]=0;
						continue;
					}else if(line[j]<='9'&&line[j]>='0'){ val[i]=line[j]-'0'; continue; }else{ //case '/'
						val[i]=10+cal(line[j+1]);
						continue;
					}
				}
				if(line[j]<='9'&&line[j]>=0){
					j++;
					if(line[j]=='-'){
						val[i]=line[j-1]-'0';
						continue;
					}else if(line[j]!='/'){
						//case number
						val[i]=line[j]-'0'+line[j-1]-'0';
						continue;
					}else{
						//case '/'
						val[i]=10+cal(line[j+1]);
						continue;
					}
				}
			}	
			else{
				if(line[j]=='X'){
					val[i]=10+(line[j+1]=='X'?10:(line[j+1]-'0'))+(line[j+2]=='X'?10:(line[j+2]-'0'));
					continue;
				}else if(line[j+1]=='/'){
					val[i]=10+(line[j+2]=='#'?10:(line[j+2]-'0'));
					continue;
				}else{
					val[i]=(line[j]=='X'?10:(line[j]-'0'))+(line[j+1]=='X'?10:(line[j+1]-'0'));
					continue;
				}
			}
		}
		for(i=0;i<10;i++){
			val[i+1]+=val[i];
			printf("val\t%d\n",val[i]);
		}
	}
	return 0;
}

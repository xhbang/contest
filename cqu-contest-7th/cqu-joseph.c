#include <stdio.h> 
#include <memory.h> 
//enum BOOL{FALSE=0,TRUE=!FALSE};
#define MAX 100

int main(){
	int n,i,j;
	int cut[MAX];
	int next[MAX];
	scanf("%d",&n);
	for(i=0;i<2*n;i++){
		next[i]=i+1;	
	}
	next[2*n]=1;
	int left=2*n;
	int from=0;
	memset(cut,0,sizeof(cut));
	while(left>n){
		j=from;
		int jump=0;
		while(jump<9){
			j=next[j];
			if(!cut[j])
				jump++;
		}
		cut[j]=1;
		printf("j is %d\n",j);
		from=j;
		left--;
	}
	for(i=1;i<2*n+1;i++){
		if(cut[i])
			putchar('+');
		else
			putchar('@');
	}
	printf("\n");
	return 0;
}

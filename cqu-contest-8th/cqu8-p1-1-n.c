#include <stdio.h>
#define N 100001

int main(){
	int i,j;
	int a,b;
	int n,m;
	int f[N];
	FILE *p;
	p=freopen("A.in","r",stdin);
	while(scanf("%d",&a)&&a!=-1){
		scanf("%d%d%d\n",&b,&n,&m);
		f[1]=a,f[2]=b;
		for(i=3;i<N;i++){
			f[i]=f[i-1]+f[i-2];
		}
		printf("%d\n",f[n]%m);
	}

}
/*input
1 1 5 100
2 3 10 67
-1
*/

#include <stdio.h>
#include <string.h>
int a[20],b[20],c[20],x[20],ax[20],y[20],z[20],use[20];

int max;

void dfs(int p){
	int i,j;
	for(i=1;i<=6;i++){
		//for each triangle
		if(use[i])
			continue;
		for(j=1;j<=3;j++){
			if(j==1){
				a[p]=x[i];
				b[p]=y[i];
				c[p]=z[i];
			}
			if(j==2){
				a[p]=y[i];
				b[p]=z[i];
				c[p]=x[i];
			}
			if(j==3){
				a[p]=z[i];
				b[p]=x[i];
				c[p]=y[i];
			}
			if(p!=1&&c[p]!=b[p-1])
				continue;
			if(p==1)
				ax[p]=a[p];
			else
				ax[p]=ax[p-1]+a[p];
			use[i]=1;
			if(p<6)
				dfs(p+1);
			else{
				if(b[p]==c[1]){
					if(max<ax[p])
						max=ax[p];
				}
			}
		}
		use[i]=0;
	}
}
int main(){
	char ch[10];
	int i;
	while(1){
		for(i=0;i<20;i++){
			use[i]=0;
		}
		for(i=1;i<=6;i++)
			scanf("%d%d%d",&x[i],&y[i],&z[i]);
		scanf("%s",ch);
		max=0;
		dfs(1);
		if(max==0)
			printf("none\n");
		else
			printf("%d\n",max);
		if(strcmp(ch,"$")==0)
			break;
	}
	return 0;
}

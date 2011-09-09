#include <stdio.h>
#define MAX 100

int main(){
	int height,up,down,i,j,day,factor;
	float h,u,sum;
	while(scanf("%d",&height)&&height){
		scanf("%d%d%d",&up,&down,&factor);
		int flag=0;
		sum=0.0;
		h=(float)height;
		u=(float)up;
		float k=(float)factor/100;
		float slip=up*k;
		int n=0;
		while(sum>=0){
			n++;
			sum+=u;
			if(sum>=h){
				flag=1;
				break;
			}
			u=u-slip;
			if(u<0)
				u=0;
			sum-=1;
		}
		if(flag)
			printf("success  on day %d\n",n);
		else
			printf("fail on day %d\n",n);
	}
}

#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 9

int main(){
	FILE *p;
	p=freopen("B.in","r",stdin);
	char m[N][N];
	int i;
	int x1,y1,x2,y2;
	char a,b;
	while((gets(m[0])!=NULL)&&m[0][0]!='@'){
		for(i=1;i<8;i++){
			gets(m[i]);                                                                                                                                                                                                                                                                                                                                                            
		}
		scanf("%d%d%d%d\n",&x1,&y1,&x2,&y2);
		if((abs(x1-x2)==0&&abs(y1-y2)==1)||(abs(x1-x2)==1&&abs(y1-y2)==0)){
			a=m[--x1][--y1];
			b=m[--x2][--y2];
			int flag=0;
			for(i=-2;i<1;i++){
				if((x1+i>0) && ((x1+2+i)<8)){
					if((m[x1+i][y1]==b)&&(m[x1+2+i][y1]==b)){
						flag=1;
						break;
					}
				}
				if((y1+i>0) && ((y1+2+i)<8)){
					if((m[x1][y1+i]==b)&&(m[x1][y1+i+2]==b)){
						flag=1;
						break;
					}
				}
				if((x2+i>0) && ((x2+2+i)<8)){
					if((m[x2+i][y2]==a)&&(m[x2+2+i][y2]==a)){
						flag=1;
						break;
					}
				}
				if((y1+i>0) && ((y1+2+i)<8)){
					if((m[x2][y1+i]==a)&&(m[x2][y2+i+2]==a)){
						flag=1;
						break;
					}
				}
			}
			if(flag)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			printf("NO\n");
	}
	return 0;
}
/* sample input
PBPOWBGW
RRPRYWWP
YGBYYGPP
OWYGGRWB
GBBGBGGR
GBWPPORG
PPGORWOG
WYWGYWBY
4 3 3 3
PBPOWBGW
RRPRYWWP
YGBYYGPP
OWYGGRWB
GBBGBGGR
GBWPPORG
PPGORWOG
WYWGYWBY
8 8 8 8
@
*/

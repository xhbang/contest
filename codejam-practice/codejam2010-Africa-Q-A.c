
/**
 *filename:codejam2010-Africa-Q-A.c
 *date:20  4月 2011
 *author:hang@sonix
 *email:sonicisdreaming # gmail.com
 *ac is fun!
 *compiled under g++/debian 6.0
 */
#include <stdio.h>
#include <stdlib.h>
#define N 2000

int price[N];
/*
int bSearch(int l,int r,int val){
     int m;
     while(l<=r){
	  m=(l+r)/2;
	  if(price[m] == val)
	       return m;
	  else if(price[m] < val)
	       l = m + 1;
	  else
	       r = m - 1; 
     }
     return -1;
}
*/
//int cmp(const void *a,const void *b){
//     return *(int *)a - *(int *)b;
//}

int main(){
  freopen("in.txt","r",stdin);
     int cases,n,total;
     int i,j;
     int counter = 1,pos;
     scanf("%d",&cases);
	  while(cases--){
	       scanf("%d",&total);
	       scanf("%d",&n);
		    for(i = 0; i < n; i++){
			 scanf("%d",&price[i]);
		    }
	       //qsort(price,n,sizeof(int),cmp);
        int flag = 1;
        /*
	       for(i = 0; i < n; i++){
		    pos=bSearch(i+1,n-1,total-price[i]);
		    if(pos != -1){
			 printf("Case #%d: %d %d\n",counter++,i+2,pos+1);
       break;
        }
	       }
          printf("NO %d\n",cases);
          */
        for(i=0; i<n-1 &&flag ;i++){
          for(j=i+1; j<n &&flag ;j++){
            if(price[i]+price[j] == total)
			        printf("Case #%d: %d %d\n",counter++,i+1,j+1);
          }
        }
	  }
    
     return 0;
}

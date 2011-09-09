#include <stdio.h>
#include <memory.h>
#define N 1000
#define MAX 100000

int main(){
  freopen("2156.txt","r",stdin);
  int i,j,k,n,m,q,f,t,dis;
  int d[N][N];
  //size of d too large
  scanf("%d%d%d",&n,&m,&q);
  memset(d,n,sizeof(d));
  for(i=0; i < m; ++i){
    scanf("%d%d%d",&f,&t,&dis);
    d[f][t]=dis;
  }
  for(i=0; i<n; ++i){
      d[i][i] = 0;
  }
  for(m=0; m < n; ++m){
    for(i=0; i < n; ++i){
      for(j=0; j < n; ++j){
        if(d[i][m]+d[m][j] < d[i][j])
          d[i][j]=d[i][m]+d[m][j];
      }
    }
  }
  for(i=0; i < q; ++i){
    scanf("%d%d",&f,&t);
    printf("%d\n",d[f][t]);
  }
  return 0;
}

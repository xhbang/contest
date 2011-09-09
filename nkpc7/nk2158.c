#include <stdio.h>
#define N 100000

#define max(a,b) ((a)>(b)?(a):(b))

int main(){
  int n,i,j;
  int time[N],space[N],m[N];
  int t,s,sum=0,count=0;
  scanf("%d",&n);
  for(i=0; i < n; ++i){
    scanf("%d%d",&time[i],&space[i]);
  }
  for(i=0; i < n - 1; ++i){
    for(j=i+1; j < n; ++j){
      t = time[j] - time[i];
      s = space[j] - space[i];
      m[count] = max(t,s);
      sum += m[count];
      count++;
      printf("Pair star %d and star %d: time span is %d, and space span is %d,the max span is %d.\n",i+1,j+1,t,s,m[count-1]);
      m[count] = max(-t,-s);
      sum += m[count];
      count++;
      printf("Pair star %d and star %d: time span is %d, and space span is %d,the max span is %d.\n",j+1,i+1,-t,-s,m[count-1]);
    }
  }
  printf("So the value of complexity of the universe is ");
  for(i=0; i < count; ++i){
    if(i)
      printf("+");
    printf("%d",m[i]);
  }
  printf("=%d\n",sum);
  return 0;
}

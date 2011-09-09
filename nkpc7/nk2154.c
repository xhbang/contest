/*
‘Crazy for ProGramminG’
Nankai University ProGramminG Contest VII
Problem A:All Star Game

author:soinc@cqu
4/2/2011
compiled under G++/debian 6.0

TODO:WA still,maybe fault on *
*/
#include <math.h>
#include <stdio.h>
#define N 90000

int main(){
  double H,V,G;
  scanf("%lf%lf%lf",&H,&V,&G);
  double vx,vy,alpha;
  double t,x,y;
  double ans[N];
  int i;
  for (i=0; i < N; ++i){
    vx = V * cos(i / 1000);
    vy = V * sin(i / 1000);
    //y means top - H
    y = V * V * sin(i) * sqrt(3 * cos(i) + 1) / (2 * G);
    //t means distance in hor
    t = vx * vy / G + vx * sqrt( vy * vy + 2 * H * G) / G;
    x = sqrt(H * H + t * t);
    ans[i] = (x > y?x : y);
  }
  /*
  int counter = 0;
  for(i = 0; i < N/1000; i += 0.001){
    vx = V * cos(i);
    vy = V * sin(i);
    y = V * V * sin(i) * sqrt(3 * cos(i) + 1) / (2 * G);
    t = vx * vy / G + vx * sqrt( vy * vy + 2 * H * G) / G;
    x = sqrt(H * H + t * t);
    ans[counter++] = (x > y?x : y);
  }
  */
  double max=0;
  for(i=0; i<N; ++i){
    if(max < ans[i])
      max = ans[i]; 
  }
  printf("%lf\n",max);

  return 0;
}

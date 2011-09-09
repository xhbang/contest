#include <stdio.h>
#include <string.h>

int main(){
  FILE *fp;
  fp=fopen("out.txt","w");
  char sad[10],line[100];
  gets(sad);
  gets(line);
  int flag,l1,l2,i,j;
  l1=strlen(sad);
  l2=strlen(line);
  int counter = 0;
  while(i!= l2 - l1 + 1){
    int t = l1;
    flag = 1;
    for(i=0; flag && i < l2 - l1 + 1 ; ++i){
      if (sad[0] == line[i]){
        for (j=1; j < t ; ++j){
          if (line[i+j] == '@'){
            t++;
            continue;
          }
          if (sad[j-(t - l1)] != line[i+j])
            break;
        }
        if (j == t){
          flag = 0;
          counter++;
        }
        //modified before
        t = l1;
        if (!flag){
          for (j=0; j < t; ++j){
            if (line[i+j] == '@'){
              t++;
              continue;
            }
            line[i+j] = '@';
          }
          continue;
        }
      }
    }
  }
  fprintf(fp,"%d\n",counter);
  return 0; 
}

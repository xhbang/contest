#include <string>

using namespace std;

class HowEasy

{

public:

  int pointVal(string param0)

  {

    int i=0,j=0,k=0,t=0,ac=0;

    for(;param0[i-1]!=0;i++)

      if(param0[i]==0||param0[i]==' ')

      {

        j++;

        ac+=(t==0)*k;

        t=k=0;

      }

      else

        if(t==0)

          if(param0[i]>57)

            k++;

          else

            if(!(param0[i]=='.'&& param0[i+1]==0&&k>0)&&!(param0[i]=='.'&& param0[i+1]==' '&&k>0))

              t=1;

    if(j==0)

      return(250);

    if(ac/j<=3)

      return(250);

    if(ac/j<=5)

      return(500);
    return(1000);
  }
};

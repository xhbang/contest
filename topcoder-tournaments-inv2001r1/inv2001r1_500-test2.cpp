#include <vector>
using namespace std;


class SquareDigits
{
public:
   int smallestResult(int param0);
private:
    int pow_and( int number );
};

int SquareDigits::pow_and( int number )
{
    int t = number;
    int result = 0;
    int tmp = 0;

    while ( (t = t/10) != 0 )
    {
       tmp = (t%10);
       result += tmp*tmp;
    }
    
    tmp = number%10;
    result += tmp*tmp;

    return result;
}

int SquareDigits::smallestResult(int param0)
{
    if ( param0 < 0 || param0 > 199 )
    {
        return 0;
    }

    int i = 0;

    vector <int> buffer;
    vector<int>::iterator pos;
    bool isfindsame = false;

    while( 1 )
    {
       int t1 = i;
   
       buffer.clear();
       isfindsame = false;

       do 
       {
           t1 = pow_and(t1);

           if ( t1 == param0 )
           {
               return i;
           }

            for ( pos = buffer.begin(); pos != buffer.end(); pos++ )
            {
                if ( t1 == *pos )
                {
                    isfindsame= true;
                }
            }

            buffer.push_back( t1 );

       } while ( !isfindsame );

       i++;
    }

}

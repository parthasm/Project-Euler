#include <iostream>

using namespace std;
int main()
{
    int sum = 0,UPPER_LIMIT  = 1000,limit_3,limit_5,limit_15;
    int counter_3=0,counter_5=0,counter_15=0;
    
    limit_3 = UPPER_LIMIT/3;
    limit_5 = (UPPER_LIMIT/5) - 1;
    limit_15= UPPER_LIMIT/15;
    
    while( counter_3 <= limit_3 )
    {
        if ( counter_3 <= limit_3 )
        {
            sum+= (3*counter_3);
            counter_3++;
        }
        
        if ( counter_5 <= limit_5 )
        {
            sum+= (5*counter_5);
            counter_5++;
        }
        
        if ( counter_15 <= limit_15 )
        {
            sum-= (15*counter_15);
            counter_15++;
        }
                
    }
    cout << "sum is " << sum << endl;
    return 0;
}
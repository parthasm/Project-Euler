#include <iostream>
 
using namespace std; 
int main()
{
    int sum_num=0,sum_of_sqr=0,lower_limit=1,upper_limit=100,i,num;
    
    for(i=lower_limit;i<=upper_limit;i++)
    {
        sum_num = sum_num+i;
        sum_of_sqr = sum_of_sqr + (i*i);
    }
    
    num = (sum_num*sum_num) - sum_of_sqr;
    
    cout << num << endl;
        return 0;
}
 
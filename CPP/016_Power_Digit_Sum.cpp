#include <iostream>

using namespace std;

int find(int number,int pow)
        {       
                short expo[334];
                int carry = 0;
                size_t sz = sizeof(expo)/sizeof(*expo);
                int i,j=sz-1;
                int num,num1,sum=0;
                for(i=0;i<sz;i++)
                        expo[i] = 0;
                
                expo[i-1]=1;
                
                for(i=1;i<=pow;i++)
                {
                        j=sz-1;
                        carry=0;
                        while(j>0)
                        {
                                num = expo[j];
                                num1 = (number*num)+carry;
                                expo[j]=(short)((num1%10));
                                carry = num1/10;     
                                j--;
        
                        }
                }
 
                for(i=0;i<sz;i++)
                {
                        
                        sum+=expo[i];
                }
                return sum;
        }

int main()
{
    cout << find(2,1000) << endl;
    return 0;
}
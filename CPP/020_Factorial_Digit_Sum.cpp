#include <iostream>

using namespace std;

int findSumOfDigits(size_t number);

        int main()
        {
                cout << findSumOfDigits(100) << endl;
        }
        
        int findSumOfDigits(size_t number)
        {
                short fact[270];
                int carry = 0,num,num1,sum=0;
                
                size_t fl=sizeof(fact)/sizeof(*fact);
                size_t i;
                int j=fl-1;
                for(i=0;i<fl;i++)
                        fact[i] = 0;
                
                fact[i-1]=1;
                
                for(i=2;i<=number;i++)
                {
                        j=fl-1;
                        carry=0;
                        while(j>0)
                        {
                                num = fact[j];
                                num1 = (i*num)+carry;
                                fact[j]=(short)(num1%10);
                                carry = num1/10;     
                                j--;
        
                        }
                }
 
                for(i=0;i<fl;i++)
                {
                        
                        sum+=fact[i];
                }
                return sum;
        }

#include <iostream>
 
using namespace std;
 
int findRank(int noOfDigits);
 
        int main()
        {
                cout << findRank(1000) << endl;
        }
        
        int findRank(int noOfDigits)
        {
                short sum[noOfDigits],num1[noOfDigits],num2[noOfDigits];
                int carry = 0,number,result,i,counter=2;
                for(i=0;i<noOfDigits;i++)
                {
                        sum[i] = 0;
                        num1[i] = 0;
                        num2[i] = 0;
                }
                num1[i-1]=1;
                num2[i-1]=1;
                
                while(sum[0]==0)
                {
                    carry=0;
                    for(i=noOfDigits-1;i>=0;i--)
                    {
                        number=num1[i]+num2[i];
                        result = (number%10)+carry;
                        carry=number/10;
                        sum[i]=(short)result;
                    }
                    for(i=noOfDigits-1;i>=0;i--)
                    {
                        num1[i]=num2[i];
                        num2[i]=sum[i];
                    }
                    counter++;
                }
                return counter;
        }
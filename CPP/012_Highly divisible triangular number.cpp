#include <iostream>
#include <cmath>

using namespace std;
 int no_of_factor(int n)
        {
            int no=2,f=2;
            
            while(f < sqrt(n))
            {
                if(n%f==0)
                    no++;
                f++;
            }
            if(f==sqrt(n))
            return (2*no)+1;
            else
            return (2*no);
        } 
         int no_of_factorPF(int n)
        {
            int prod=1,f=2,numFac=0;
            
            while(f <=(n))
            {
                
                if(n%f==0)
                    {
                        numFac++;
                        n=n/f;
                        if(n==1)
                        {
                            prod*=(numFac+1);
                            break;
                        }
                    }
                else
                    {
                        if(numFac>0)
                        {
                            prod*=(numFac+1);
                            numFac=0;
                        }
                        f++;
                    }
            
            }
            
            return prod;
        } 
int main()
{
    int num=1,counter=0;
    long long sum=0ll;
                    
                    while(counter<500)
                    {
                        sum+=(long)(long)num;
                        num++;
                        counter = no_of_factorPF(sum);
                    }
                    
                    cout << sum << endl;
                    //cout << no_of_factorPF(640) << endl;
    return 0;
}
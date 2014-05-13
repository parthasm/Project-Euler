#include <iostream>
#include <cmath>

using namespace std;

 bool isprime(long long n)
        {
                int f=2;
            bool flag=true;
            while(f <= sqrt(n))
            {
                if(n%f==0)
                {
                    flag = false;
                    break;
                }
                f++;
                
            }
            return flag;
        }
 


int main()
{
    long long num = 600851475143ll;
                    long long pf = num;
                    long long factor = 2ll;
                   
                    
                    while (factor < pf)
                    {
                        if(isprime(factor))
                        {
                            if(pf%factor==0ll)
                            {
                                pf = pf / factor;
                                
                                if(isprime(pf)==1)
                                    break;
                            }
                            else
                                factor++;
                            
                        }
                        else
                        factor++;
                    }
                    cout << "largest prime factor is " << pf << endl;
    return 0;
}
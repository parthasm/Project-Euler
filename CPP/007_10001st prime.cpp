#include <iostream>

using namespace std;
int main()
{
     bool prime[1000000];
                   size_t i,j,counter=0,prime_length = sizeof(prime)/sizeof(*prime);
                   for(i=2;i<prime_length;i++)
                        prime[i] = true;
                   
                   for(i=2;i<prime_length;i++)
                   {
                        if(!prime[i])
                                continue;
                        for(j=2*i;j<prime_length;j+=i)
                                prime[j] = false;                       
                   }    
                        i=2;
                    while(counter<10001)
                    {
                        if(prime[i])
                                counter++;
                        i++;
                    }   
                cout << --i << endl;
 
    return 0;
}
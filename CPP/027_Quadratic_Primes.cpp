#include <iostream>
#include <vector>
#include <map>

using namespace std;
int findProduct(int limit);        
        int main() 
        {
                
                cout << findProduct(1000) << endl;
        }
        int findProduct(int limit) 
        {
                int product=0;
                
                bool primeLarge[1000000];
                bool primeSmall[1000];
                size_t primeLargelength=sizeof(primeLarge)/sizeof(primeLarge[0]);
                size_t primeSmalllength=sizeof(primeSmall)/sizeof(primeSmall[0]);
                size_t counter,inner;
                int a,b=3,n=0,max=1;
                
                map<int,int> primesLarge;
                vector<int> primesSmall;
                
                //to check for primes
                for(counter=2;counter<primeLargelength;counter++)
                        primeLarge[counter]=true;
                
                for(counter=2;counter<primeLargelength;counter++)
                {
                        if(!primeLarge[counter])
                                continue;
                        for(inner=2*counter;inner<primeLargelength;inner+=counter)
                                primeLarge[inner]=false;
                }
                
                for(counter=2;counter<primeLargelength;counter++)
                {
                                if(primeLarge[counter])
                                        primesLarge[counter]=counter;
                }
                //to check for primes end
                
                
                //to check for b
                for(counter=2;counter<primeSmalllength;counter++)
                        primeSmall[counter]=true;
                
                for(counter=2;counter<primeSmalllength;counter++)
                {
                        if(!primeSmall[counter])
                                continue;
                        for(inner=2*counter;inner<primeSmalllength;inner+=counter)
                                primeSmall[inner]=false;
                }
                
                for(counter=2;counter<primeSmalllength;counter++)
                {
                                if(primeSmall[counter])
                                        primesSmall.push_back(counter);
                }
                //to check for b end
                int expression=0;
                for(counter=1;counter<primesSmall.size();counter++)
                {
                        b = primesSmall[counter];
                        a=999;
                        a*=-1;
                        for(;a<1000;a++)
                        {
                                n=0;
                                while(true)
                                {
                                        expression = (n*n)+a*n+b;
                                        if(primesLarge[expression]!=0)
                                        {
                                                n++;
                                        }
                                        else
                                        {
                                                break;
                                        }
                                }
                                if(--n>max)
                                {
                                        max=n;
                                        product=a*b;
                                }
                                
                        }
                }
                return product;
        }
 

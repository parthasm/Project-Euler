#include <iostream>
#include <map>
#include <cmath>

using namespace std;
 int findSum(int limit);
 int findSumOfFactors(int n);
        int main() 
        {

                cout << findSum(10000) << endl;
        }
        
        int findSum(int limit)
        {
                int counter,inner,i;
                int sum=0,j,k=0;
                map<int,int> noAndSum;
                bool prime[limit];
                for(counter=2;counter<limit;counter++)
                        prime[counter]=true;
                for(counter=2;counter<limit;counter++)
                {
                        if(!prime[counter])
                                continue;
                        for(inner=2*counter;inner<limit;inner+=counter)
                                prime[inner]=false;
                }
                for(counter=2;counter<limit;counter++)
                {
                        if(prime[counter])
                        {
                                continue;
                        }
                        
                        noAndSum[counter]=findSumOfFactors(counter);
                }
                for(map<int,int>::const_iterator it = noAndSum.begin();it!=noAndSum.end();++it)
                {
                        i = it->first;
                        j=noAndSum[i];
                        k=noAndSum[j];
                        if(k!=0)
                        {
                                if(i==k && j!=k)
                                {
                                        
                                        sum+=i;
                                }
                                
                        }
                      
                }
                
                return sum;
        }
        
        int findSumOfFactors(int n)
        {
                int f=2,sumFactor=1;
                while(f<sqrt(n))
                {
                        if(n%f==0)
                        {
                                sumFactor+=f;
                                sumFactor+=(n/f);
                        }
                        f++;
                }
                if(f==sqrt(n))
                        sumFactor+=f;
                return sumFactor;
        }
#include <iostream>
#include <map>
#include <vector> 
 
using namespace std;
 
int sumPrime();

int main()
{
    
    cout << sumPrime() << endl;
    return 0;
}
 
int sumPrime()
{
        vector<bool> primes(1000000,true);
		bool flag;
		vector<int> onlyPrimes;
        int loop=2,inner,l=0,sum,index,max=0;
 
        primes[0]=false;
        primes[1]=false;
 
        
 
        for(;loop<primes.size();loop++)
        {
                if(!primes[loop])
                        continue;
                for(inner=2*loop;inner<primes.size();inner+=loop)
                {
                        primes[inner]=false;
                }
        }

		for(loop=2;loop<primes.size();loop++)
		{
			if(primes[loop])
			{
				//cout << loop << " hi" << endl;
				onlyPrimes.push_back(loop);
			}
		}

		for(loop=0;loop<onlyPrimes.size()-1;loop++)
		{
			sum=onlyPrimes[loop];
			
			for(inner=loop+1;inner<onlyPrimes.size();inner++)
			{
				sum+=onlyPrimes[inner];
				if(sum>=primes.size())
				{
					break;
				}
				if(primes[sum] && inner+1-loop>l)
				{
					l=inner+1-loop;
					max=sum;
				}
			}
			

		}
		return max;
}
#include <iostream>
#include <vector>
 
 
using namespace std;
 
long long smallestNo();
 
int main()
{
    cout << smallestNo() << endl;
    return 0;
}

long long smallestNo()
{
	vector<bool> primes(1000000,true);
	bool flag;
	long long loop=2ll,inner,twice;

	primes[0]=false;
	primes[1]=false;

	

	for(;loop<primes.size();loop++)
	{
		if(!primes[loop])
			continue;
		for(inner=2ll*loop;inner<primes.size();inner+=loop)
		{
			primes[inner]=false;
		}
	}

	for(loop=3ll;loop<primes.size();loop+=2ll)
	{
		if(!primes[loop])
		{
			flag=false;
			for(inner=1ll;inner<primes.size();inner++)
			{
				twice=2ll*inner*inner;
				if(loop-twice<2)
					break;
				if(primes[loop-twice])
				{
					flag=true;
					break;
				}
			}
			if(!flag)
				return loop;
		}
	}
	
}
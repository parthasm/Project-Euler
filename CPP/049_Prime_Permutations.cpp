#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#include <sstream>

using namespace std;
 
string all3();
 
int main()
{
    cout << all3() << endl;
    return 0;
}
 
string all3()
{
        vector<bool> primes(10000,true);
        bool flag;
        vector<short> occurences(10,0);       
		vector<short> dummyOccurences(10,0);
		vector<short> dummyOccurences1(10,0);
        int loop=2,inner,temp1,temp2,temp3,innerMost;
		stringstream ans;
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

		for(loop=1000;loop<primes.size();loop++)
		{
			if(primes[loop])
			{
				for(inner=100;inner<5000;inner+=2)
				{
					if(loop+2*inner>=primes.size() || loop==1487)
					{
						break;
					}
					fill(occurences.begin(),occurences.end(),0);
					fill(dummyOccurences.begin(),dummyOccurences.end(),0);
					fill(dummyOccurences1.begin(),dummyOccurences1.end(),0);
					if(primes[loop+inner] && primes[loop+(2*inner)])
					{
						temp1=loop;
						temp2=loop+inner;
						temp3=loop+(2*inner);
						while(temp1>0)
						{
							
							dummyOccurences[temp1%10]++;
							temp1/=10;
						}

						while(temp2>0)
						{
							
							dummyOccurences1[temp2%10]++;
							temp2/=10;
						}

						while(temp3>0)
						{
							occurences[temp3%10]++;
							temp3/=10;
						}
						flag=true;
						for(innerMost=0;innerMost<10;innerMost++)
						{
							if(occurences[innerMost]>0 && (occurences[innerMost]!=dummyOccurences[innerMost] || occurences[innerMost]!=dummyOccurences1[innerMost] || dummyOccurences[innerMost]!=dummyOccurences1[innerMost]))
							{
								flag=false;
								break;
							}
						}
						if(flag)
						{
							ans << loop;
							ans << (loop+inner);
							ans << (loop+(2*inner));
							return ans.str();
						}
					}
				}
			}
		}
}
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int sideLength();
bool isPrime(int n);

int main() 
{
    cout << sideLength() << endl;
	return 0;
}

int sideLength()
{
    //vector<bool> primes(100000000,true);
    int len=0,loop,inner;
    /*primes[0]=false;
    primes[1]=false;
    for(loop=2;loop<primes.size();loop++)
    {
        if(primes[loop])
        {
            for(inner=2*loop;inner<primes.size();inner+=loop)
            {
                primes[inner]=false;
            }
        }
    }*/
    //cout << "Hi" ;
    int apru=1,aplu=1,apld=1,diffru=2,difflu=4,diffld=6,countPrime=0;
    double total;
    while(true)
    {
        /*if(apld<primes.size())
        {
            if(primes[apru])
            {
                countPrime++;
            }
        
            if(primes[aplu])
            {
                countPrime++;
            }
        
            if(primes[apld])
            {
                countPrime++;
            }
        }
        else
        {*/
            if(isPrime(apru))
            {
                countPrime++;
            }
        
            if(isPrime(aplu))
            {
                countPrime++;
            }
        
            if(isPrime(apld))
            {
                countPrime++;
            }
       // }
        len=(int)pow(apld+(apld-aplu),0.5);
        total=(2*len)-1;
        //cout << total ;
        if(countPrime>0 && countPrime<0.1*total)
        {
            return len;
        }
        apru+=diffru;
        aplu+=difflu;
        apld+=diffld;
        diffru+=8;
        difflu+=8;
        diffld+=8;
    }
    return 0;
}

bool isPrime(int n)
{
    int f=2;
    if(n<2)
    {
        return false;
    }
    
    while(f<(int)sqrt(n)+1)
    {
        if(n%f==0)
        {
            return false;
        }
        f++;
    }
    return true;
}
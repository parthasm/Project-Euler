#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

bool isAllcomboPrime(int a,int b);
bool isPrime(int n);
int findLowestSum();

int main()
{
    cout << findLowestSum() << endl;
    return 0;
}

int findLowestSum()
{
    vector<bool> primes(3000,true);
    vector<int> onlyPrimes;
    int inner,loop,min=9999999;
    primes[0]=false;
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
    }
    
    for(loop=2;loop<primes.size();loop++)
    {
        if(primes[loop])
        {
            onlyPrimes.push_back(loop);
        }     
    }
    int loop1,loop2,loop3,loop4,loop5;
    vector<int> numbers(5,0);
    
    for(loop1=1;loop1<onlyPrimes.size()-4;loop1++)
    {
        for(loop2=loop1+1;loop2<onlyPrimes.size()-3;loop2++)
        {
            if(onlyPrimes[loop1]+onlyPrimes[loop2]>min)
            {
                break;
            }
            if(!isAllcomboPrime(onlyPrimes[loop1],onlyPrimes[loop2]))
            {
                continue;
            }
            for(loop3=loop2+1;loop3<onlyPrimes.size()-2;loop3++)
            {
                if(onlyPrimes[loop1]+onlyPrimes[loop2]+onlyPrimes[loop3]>min)
                {
                    break;
                }
                if(!isAllcomboPrime(onlyPrimes[loop1],onlyPrimes[loop3]) || !isAllcomboPrime(onlyPrimes[loop2],onlyPrimes[loop3]))
                {
                    continue;
                }
                for(loop4=loop3+1;loop4<onlyPrimes.size()-1;loop4++)
                {
                    if(onlyPrimes[loop1]+onlyPrimes[loop2]+onlyPrimes[loop3]+onlyPrimes[loop4]>min)
                    {
                        break;
                    }
                    if(!isAllcomboPrime(onlyPrimes[loop1],onlyPrimes[loop4]) || !isAllcomboPrime(onlyPrimes[loop2],onlyPrimes[loop4]) || !isAllcomboPrime(onlyPrimes[loop3],onlyPrimes[loop4]))
                    {
                        continue;
                    }
                    for(loop5=loop4+1;loop5<onlyPrimes.size();loop5++)
                    {
                        if(onlyPrimes[loop1]+onlyPrimes[loop2]+onlyPrimes[loop3]+onlyPrimes[loop4]+onlyPrimes[loop5]>min)
                        {
                            break;
                        }
                        if(isAllcomboPrime(onlyPrimes[loop1],onlyPrimes[loop5]) && isAllcomboPrime(onlyPrimes[loop2],onlyPrimes[loop5]) && isAllcomboPrime(onlyPrimes[loop3],onlyPrimes[loop5]) && isAllcomboPrime(onlyPrimes[loop4],onlyPrimes[loop5]))
                        {
                            min=onlyPrimes[loop1]+onlyPrimes[loop2]+onlyPrimes[loop3]+onlyPrimes[loop4]+onlyPrimes[loop5];
                        }
                        
                    }
                }
            }
        }
    }
    return min;
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
/*
bool isAllcomboPrime(int a,int b)
{
    int t1,t2,t,noOfDigits;
    
            t1=a;
            t2=b;
            
            t=t2;
            noOfDigits=0;
            while(t>0)
            {
                noOfDigits++;
                t/=10;
            }
            t1*=(int)pow(10,noOfDigits);
            t1+=t2;
            if(!isPrime(t1))
            {
                return false;
            }
            t1=a;
            noOfDigits=0;
            t=t1;
            while(t>0)
            {
                noOfDigits++;
                t/=10;
            }
            t2*=(int)pow(10,noOfDigits);
            t2+=t1;
            if(!isPrime(t2))
            {
                return false;
            }
            return true;
}
*/
bool isAllcomboPrime(int a,int b)
{
    string num1,num2;
    int num;
     stringstream ss1;//create a stringstream
   ss1 << a;
   num1=ss1.str();
   ss1.str("");
   ss1 << b;
   num2=ss1.str();
   
   stringstream ss2(num1+num2);
   ss2 >> num;
   if(!isPrime(num))
   {
       return false;
   }
   num=0;
   stringstream ss3(num2+num1);
   ss3 >> num;
   if(!isPrime(num))
   {
       return false;
   }
   return true;
   
}

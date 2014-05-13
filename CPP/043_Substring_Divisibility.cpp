#include <iostream>
#include <vector>

using namespace std;

vector<bool> primes(80,true);
vector<int> onlyPrimes;
    
vector<int>& nextPerm(vector<int>& digits); 
vector<int>& findSum(vector<int>& sum);
bool isSpecialDivisible(const vector<int>& digits);
int findFactorial(int n);
void updateOnlyPrimes(int noOfDigits);

int main()
{
     //1406357289
   /* vector<int> digits;
    digits.push_back(0);
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(3);
    digits.push_back(4);
    digits.push_back(5);
    digits.push_back(6);
    digits.push_back(7);
    digits.push_back(8);
    digits.push_back(9);
    
    cout <<  isSpecialDivisible(digits) << endl;*/
	updateOnlyPrimes(10);
    vector<int> sum(20,0);
    sum=findSum(sum);
    for(int loop=0;loop<sum.size();loop++)
        cout << sum[loop] << " " ;
    return 0;
}

vector<int>& findSum(vector<int>& sum)
{
    vector<int> digits(10,0);
    int counter=0,limit,inner,number,carry,sumCounter;
    for(;counter<10;counter++)
    {
        digits[counter]=counter;
    }
    limit=findFactorial(10);
    for(counter=0;counter<limit;counter++)
    {
        if(isSpecialDivisible(digits))
        {
            carry=0;
            sumCounter=sum.size()-1;
            for(inner=digits.size()-1;inner>=0;inner--)
            {
                number=sum[sumCounter]+digits[inner]+carry;
                sum[sumCounter]=number%10;
                carry=number/10;
                sumCounter--;
            }
            while(carry>0)
            {
                sum[sumCounter--]=carry%10;
                carry/=10;
            }
        }
        digits=nextPerm(digits);
    }
    return sum;
}

bool isSpecialDivisible(const vector<int>& digits)
{
    
    int loop,number;
    for(loop=0;loop<onlyPrimes.size();loop++)
    {
        number=(100*digits[loop+1])+(10*digits[loop+2])+digits[loop+3];
        if(number%onlyPrimes[loop]!=0)
            return false;
    }
    
    return true;
}

void updateOnlyPrimes(int noOfDigits)
{
	int loop=2,inner,number=0,counter=1;
    
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
            onlyPrimes.push_back(loop);
            counter++;
            if(counter>noOfDigits-3)
                break;
        }
    }
}
vector<int>& nextPerm(vector<int>& digits)
{
    int pivot=-1,pivotPosition=-1,successor=-1,successorPosition=-1,loop=digits.size()-2;
    
    //finding pivot
    for(;loop>=0;loop--)
    {
        if(digits[loop]>digits[loop+1])
        {
            pivot=digits[loop];
            pivotPosition=loop;
            break;
        }
    }
    
    //if array in order, nothing to do here, so reverse numbers & start over
    if(pivotPosition==-1)
    {
        for(loop=0;loop<digits.size()/2;loop++)
        {
            digits[loop]=digits[loop]+digits[digits.size()-loop-1];
            digits[digits.size()-loop-1]=digits[loop]-digits[digits.size()-loop-1];
            digits[loop]=digits[loop]-digits[digits.size()-loop-1];
        }
        return digits;
    }
    
    //finding successor
    for(loop=digits.size()-1;loop>pivotPosition;loop--)
    {
        if(digits[loop]<pivot)
        {
            successor=digits[loop];
            successorPosition=loop;
            break;
        }
    }
    
    //exchanging successor & pivot
    digits[pivotPosition]=digits[pivotPosition]+digits[successorPosition];
    digits[successorPosition]=digits[pivotPosition]-digits[successorPosition];
    digits[pivotPosition]=digits[pivotPosition]-digits[successorPosition];
    
    int l=digits.size()-pivotPosition-1;
    
    //reversing numbers after pivotposition
    for(loop=0;loop<l/2;loop++)
    {
            digits[loop+pivotPosition+1]=digits[loop+pivotPosition+1]+digits[pivotPosition+l-loop];
            digits[pivotPosition+l-loop]=digits[loop+pivotPosition+1]-digits[pivotPosition+l-loop];
            digits[loop+pivotPosition+1]=digits[loop+pivotPosition+1]-digits[pivotPosition+l-loop];
    }
    return digits;
    
    
}

int findFactorial(int n)
{
    if(n<2)
        return 1;
    return n*findFactorial(n-1);    
}
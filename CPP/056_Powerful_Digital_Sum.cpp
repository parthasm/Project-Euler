#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxDigitalSum(int limit);

int main()
{
    cout << findMaxDigitalSum(100) << endl;
    return 0;
}

int findMaxDigitalSum(int limit)
{
    int max=0,sum=0,loop,temp,inner,a,b,carry=0;
    vector<int> number(200,0),pdt(200,0);
    
    for(a=2;a<100;a++)
    {
        temp=a;
        loop=199;
        fill(number.begin(),number.end(),0);
        while(temp>0)
        {
            number[loop--]=temp%10;
            temp/=10;
        }
        for(b=2;b<100;b++)
        {
            carry=0;
            fill(pdt.begin(),pdt.end(),0);
            for(loop=199;loop>0;loop--)
            {
                temp=(number[loop]*a)+carry;
                pdt[loop]=temp%10;
                carry=temp/10;
            }
            
            number.assign(pdt.begin(),pdt.end());
            sum=0;
            for(loop=0;loop<200;loop++)
            {
                sum+=pdt[loop];
            }
            if(max<sum)
            {
                max=sum;
            }
        }
    }
    return max;
}
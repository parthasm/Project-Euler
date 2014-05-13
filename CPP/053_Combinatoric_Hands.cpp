#include <iostream>
#include <vector>

using namespace std;

int findCombinator(int n,int r);
int noOfTerms(int limit);

int main()
{
    cout << noOfTerms(1000000) << endl;
    return 0;
}

int noOfTerms(int limit)
{
    int outer,inner,count=0,upper,lower;
    for(outer=23;outer<101;outer++)
    {
        for(inner=1;inner<(outer/2);inner++)
        {
            if(findCombinator(outer,inner)>limit)
            {
                break;
            }
        }
        lower=inner;
        upper = outer - inner;
        count+=(upper+1-lower);
    }
    return count;
}

int findCombinator(int n,int r)
{
    int C=1,loop;
    
    if(r>(n/2))
    {
        r=n-r;
    }
    
    if(r==0)
    {
        return 1;
    }
    
    for(loop=1;loop<=r;loop++)
    {
        C*=(n--);
        C/=loop;
    }
    
    return C;
}
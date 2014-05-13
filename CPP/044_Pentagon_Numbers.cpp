#include <iostream>
#include <cmath>


using namespace std;

bool isPentagonalNumber(long long n);
bool isWholeNumber(double d);
long long smallestDiff();

int main()
{
    cout << smallestDiff() << endl;
    return 0;
}
//no data structures like vector required
long long smallestDiff()
{
    int loop=0,inner;
    long long pent1,pent2,sum,diff=999999999ll;
    for(loop=1;loop<9999;loop++)
    {
        for(inner=loop+1;inner<10000;inner++)
        {
            pent1=loop*((3ll*loop)-1ll)/2ll;
            pent2=inner*((3ll*inner)-1ll)/2ll;
            if(isPentagonalNumber(pent2-pent1) && isPentagonalNumber(pent2+pent1))
            {
                if(diff>pent2-pent1)
                {
                    diff=pent2-pent1;
                }
            }
        }
    }
    
    
    
    
    return diff;
}

bool isWholeNumber(double d)
{
    long long n=(long long)d;
    double diff=d-n;
    bool flag=diff>0.0?false:true;
    return flag;
}

bool isPentagonalNumber(long long n)
{
    double d=sqrt((24ll*n)+1ll);
    d=d+1.0;
    d=d/6.0;
    bool ans=isWholeNumber(d);
    return ans;
}
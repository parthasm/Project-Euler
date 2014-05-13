#include <iostream>
#include <cmath>

using namespace std;

bool isWholeNumber(double d);
bool isPentagonalNumber(long long n);
bool isHexagonalNumber(long long n);
long long findNextTriPenHexNo();

int main()
{
    cout << findNextTriPenHexNo() << endl;
    return 0;
}

long long findNextTriPenHexNo()
{
    long long n=286ll,tri;
    
    while(true)
    {
        tri=n*(n+1ll)/2ll;
        if(isHexagonalNumber(tri) && isPentagonalNumber(tri))
        {
            return tri;
        }
        n++;
    }
}

bool isHexagonalNumber(long long n)
{
    double sq=sqrt((8ll*n)+1ll);
    sq=sq+1.0;
    sq=sq/4.0;
    bool ans=isWholeNumber(sq);
    return ans;
}

bool isPentagonalNumber(long long n)
{
    double sq=sqrt((24ll*n)+1ll);
    sq=sq+1.0;
    sq=sq/6.0;
    bool ans=isWholeNumber(sq);
    return ans;
}

bool isWholeNumber(double d)
{
    long long n=(long long)d;
    double diff = d-n;
    bool ans=diff>0.0?false:true;
    return ans;
}


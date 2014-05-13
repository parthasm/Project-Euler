#include <iostream>

using namespace std;
int main()
{
    int n1=0,n2=1,n3,sum=0;
    n3=n1+n2;
    
    while ( n3 < 4000000 )
    {
        if(n3%2==0)
            sum+=n3;
        n1=n2;
        n2=n3;
        n3=n1+n2;
    }
    cout << "sum is " << sum << endl;
    return 0;
}
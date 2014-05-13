#include <iostream>

using namespace std;
long long factorial(long long n)
        {
                if(n>1ll)
                        return n * factorial(n-1);
                
                        return 1ll;
                
        }
        long long noOfPaths(long long side)
        {
                long long upper = 2ll * side;
                long double result=1.0/factorial(side);
                long long counter = side;
                for(;counter>0ll;counter--)
                {
                        result*=(upper--);
                }
                
                return (long long)result;
        }
        int main()
        {
            cout << noOfPaths(10ll) << endl;
            return 0;
        }
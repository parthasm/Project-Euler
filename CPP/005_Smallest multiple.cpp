#include <iostream>

using namespace std;
long long hcf(long long n1,long long n2)
        {
            long long temp;
            if(n1<n2)
            {
                temp=n1;
                n1=n2;
                n2=temp;
            }
            else if(n1==n2)
            {
                return n1;
            }
            long long remaindr = n1%n2;
            
            if(remaindr==0)
            {
                return n2;
            }
            
            while(n2%remaindr!=0)
            {
                n1 = n2;
                n2 = remaindr;
                remaindr = n1%n2;
            }
            return remaindr;
        }
long long lcm_from_hcf(long long n1,long long n2)
        {
            long long prod = n1*n2;
            long long lcm_fh = prod/hcf(n1,n2);
            
            return lcm_fh;
        }
int main()
{
    long long small_factor = 1ll, large_factor = 20ll,i;
            long long num=small_factor;
            for(i=small_factor;i<=large_factor;i++)
            {
                num = lcm_from_hcf(num,i);
                
            }
            cout << num << endl;
    return 0;
    
}
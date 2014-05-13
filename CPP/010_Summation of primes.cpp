#include <iostream>

using namespace std;
int main()
{
    bool a[2000000];
                size_t i,j;
                long long sum=0ll;
                
                for(i=0;i<2000000;i++)
                        a[i]=true;
                
                a[0]=false;
                a[1]=false;
                
                for(i=2;i<2000000;i++)
                {
                        if(!a[i])
                                continue;
                        for(j=2*i;j<2000000;j+=i)
                                a[j]=false;
                }
                
                for(i=2;i<2000000;i++)
                {       
                        if(a[i])
                                sum+=(long long)(i);
                }
                        
               cout << sum << endl;
    return 0;
}
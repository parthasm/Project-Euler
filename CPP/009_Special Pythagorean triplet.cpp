#include <iostream>

using namespace std;
int main()
{
    int a,b,c;
    bool flag=true;
    
    for(b=1;b<1000;b++)
    {
        for(a=1;a<b;a++)
        {
            if( (2000*(a+b)) == (1000000 + (2*a*b)) )
            {
                flag=false;
                break;
            }
        }
        if(!flag)
            break;
    }
    c= 1000 - (a+b);
    
    cout << "a=" << a << "\nb=" << b << "\nc=" << c << endl;
        
        return 0;
}
 
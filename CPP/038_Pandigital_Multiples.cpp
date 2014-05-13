#include <iostream>
#include <vector>

using namespace std;
int maxPan[]={0,0};
void findLargestPandigital();
int main()
{
    findLargestPandigital();
    cout << maxPan[0] << maxPan[1] << endl;
    return 0;
}

void findLargestPandigital()
{
    int counter,inner,twice,temp,temp2;
    vector<bool> presentDigit(10,false);
    bool flag;
    
    for(counter=9123;counter<=9876;counter++)
    {
        twice=2*counter;
        for(inner=1;inner<=9;inner++)
        {
            presentDigit[inner]=false;
        }
        
        temp=counter;
        temp2=twice;
        while(temp>0)
        {
            presentDigit[temp%10]=true;
            temp/=10;
        }
        
        while(temp2>0)
        {
            presentDigit[temp2%10]=true;
            temp2/=10;
        }
        flag=true;
        for(inner=1;inner<=9;inner++)
        {
            if(presentDigit[inner]==false)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            maxPan[0]=counter;
            maxPan[1]=twice;
        }
        
    }
    //return max;
}
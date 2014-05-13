#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int count(int limit);

int main()
{
    cout << count(1000) << endl; 
    return 0;
}

int count(int limit)
{
    vector<int> n0(limit/2,0),n1(limit/2,0),n2(limit/2,0),d0(limit/2,0),d1(limit/2,0),d2(limit/2,0);
    //n0=1,n1=3,n2,d0=1,d1=2,d2
    //Formula: n2=(2*n1)+n0; n0=n1; n1=n2
    int count=0,loop,inner,temp,carryn,carryd;
    n0[n0.size()-1]=1;
    n1[n1.size()-1]=3;
    d0[d0.size()-1]=1;
    d1[d1.size()-1]=2;
    for(loop=1;loop<=1000;loop++)
    {
        for(inner=0;inner<n1.size();inner++)
        {
            if(n1[inner]!=0 && d1[inner]!=0)
            {
                break;
            }
            else if(n1[inner]!=0 && d1[inner]==0)
            {
                count++;
                break;
            }
        }
        carryn=0;
        carryd=0;
        for(inner=n1.size()-1;inner>-1;inner--)
        {
            temp = (n1[inner]*2)+n0[inner]+carryn;
            n2[inner] = temp%10;
            carryn=temp/10;
            
            temp = (d1[inner]*2)+d0[inner]+carryd;
            d2[inner] = temp%10;
            carryd=temp/10;
        }
        n0.assign(n1.begin(),n1.end());
        d0.assign(d1.begin(),d1.end());
        n1.assign(n2.begin(),n2.end());
        d1.assign(d2.begin(),d2.end());
        fill(n2.begin(),n2.end(),0);
        fill(d2.begin(),d2.end(),0);
    }
    return count;
}


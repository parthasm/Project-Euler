#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findSmallestNo();

int main()
{
    cout << findSmallestNo() << endl;   
    return 0;
}

int findSmallestNo()
{
    int number,temp,counter,loop,c=0;
    vector<vector<int> > digitCounts(6,vector<int>(10,0));
    bool f=true;
    for(number=1;number<16999999;number++)
    {
        fill(digitCounts.begin(),digitCounts.end(),vector<int>(10,0));
        for(counter=2;counter<=5;counter++)
        {
            temp = counter*number;
            while(temp>0)
            {
                digitCounts[counter-1][temp%10]++;
                temp/=10;
            }
            if(counter>2)
            {
                f=true;
                for(loop=0;loop<10;loop++)
                {
                    if(digitCounts[counter-1][loop]!=digitCounts[counter-2][loop])
                    {
                        f=false;
                        break;
                    }
                }
                if(!f)
                {
                    break;
                }
            }
            
        }
        if(f)
        {
            c++;
            f=false;
            if(c==2)
            {
            return number;
            }
        }
    
    }
    return 0;
}


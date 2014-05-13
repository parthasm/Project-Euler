#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int findProduct(int powerLimit);
int main()
{
    cout << findProduct(7) << endl;
    return 0;
}
int findProduct(int powerLimit)
{
    int loopCounter=1,rank=1,product=1,counter=1,sum=0,adjustedRank,outerRank,innerRank,number;
    vector<int> limits(powerLimit,0);
    
    for(;loopCounter<limits.size();loopCounter++)
    {
        sum+=(loopCounter*9*(int)pow(10,loopCounter-1));
        limits[loopCounter]=sum;
    }
    loopCounter=1;
    while(counter<powerLimit)
    {
        if(rank>limits[loopCounter])
        {
            loopCounter++;
        }
        else
        {   
            adjustedRank=rank-limits[loopCounter-1];
            cout << "adjusted "<< adjustedRank << endl;
            outerRank=(adjustedRank%counter==0)?adjustedRank/counter:(adjustedRank/counter)+1;
            cout << "Outer "<< outerRank << endl;
            innerRank=(adjustedRank%counter==0)?counter:adjustedRank%counter;
            cout << "inner "<< innerRank << endl;
            number=(int)pow(10,loopCounter-1)+outerRank-1;
            cout << "original "<< number << endl;
            number/=(int)pow(10,loopCounter-innerRank);
            number%=10;
            cout << "n "<< number <<"\n" <<endl;
            product*=number;
            counter++;
            rank=(int)pow(10,counter);
        }
    }
    return product;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int findSmallestPrime(int noOfFamilyMembers);
bool isPrime(int n);
int main()
{
    cout << findSmallestPrime(8) << endl;
    return 0;
}
//assuming no of family numbers greater than 7 & no. of digits being replaced is 3
int findSmallestPrime(int noOfFamilyMembers)
{
    int p1,p2,p3,startDigit,noOfDigits=6,number,positions,counter,d1,d2,d3,temp,c;
    vector<int> digitsNo(noOfDigits,0);
    vector<int> lastPositions(noOfDigits-3,0);
    lastPositions[2]=6;
    
    for(p1=1;p1<noOfDigits;p1++)
    {
        for(p2=p1+1;p2<noOfDigits;p2++)
        {
            for(p3=p2+1;p3<noOfDigits;p3++)
            {
                counter=0;    
                fill(lastPositions.begin(),lastPositions.end()-1,0);
                
                for(positions=1;positions<noOfDigits;positions++)
                {
                        if(positions!=p1 && positions!=p2 && positions!=p3)
                        {
                                lastPositions[counter++]=positions;
                        }
                }
                
                fill(digitsNo.begin(),digitsNo.end(),0);
               
                for(d1=0;d1<10;d1++)
                {
                    for(d2=0;d2<10;d2++)
                    {
                        for(d3=1;d3<10;d3+=2)
                        {
                            digitsNo[lastPositions[0]-1]=d1;
                            digitsNo[lastPositions[1]-1]=d2;
                            digitsNo[lastPositions[2]-1]=d3;
                            startDigit=0;
                            c=0;
                             while(startDigit<10)
                             {
                                 digitsNo[p1-1]=startDigit;
                                 digitsNo[p2-1]=startDigit;
                                 digitsNo[p3-1]=startDigit;
                                 number=0;
                                 for(counter=0;counter<digitsNo.size();counter++)
                                 {
                                     number+=((int)pow(10,noOfDigits-counter-1)*digitsNo[counter]);
                                 }
                                 if(isPrime(number) && digitsNo[0]!=0)
                                 {
                                     c++;
                                     if(c==1)
                                     {
                                         temp=number;
                                     }
                                 }
                                 startDigit++;
                             }
                             if(c>7)
                             {
                                 return temp;
                             }
                        }
                    }
                }
            }
        }
    }
}


bool isPrime(int n)
{
    int f=2;
    while(f<sqrt(n))
    {
        if(n%f==0)
            return false;
        f++;    
    }
    return true;
}
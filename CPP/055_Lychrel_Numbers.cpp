#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(const vector<int>& number,int limit);
int countLychrels(int limit);

int main()
{
    vector<int> third;
    int myints[] = {0,0,7,4,7,6};
    third.assign (myints,myints+6);
    //cout << isPalindrome(third,2) << endl;
    cout << countLychrels(10000) <<endl;
    return 0;
}

int countLychrels(int limit)
{
    vector<int> number(50,0),sum(50,0);
    int loop,temp,inner,firstDigit,counter,carry,count=0,loop1;
    bool flag=false,flLimit=false;
    for(loop=10;loop<=limit;loop++)
    {
        temp=loop;
        inner=49;
        fill(number.begin(),number.end(),0);
        
        while(temp>0)
        {
            number[inner--]=temp%10;
            temp/=10;
        }
        firstDigit=inner;
        flag=true;
        for(counter=0;counter<50;counter++)
        {
            carry=0;
            fill(sum.begin(),sum.end(),0);
            for(inner=49;inner>firstDigit;inner--)
            {
                temp=number[inner]+number[firstDigit+50-inner]+carry;
                sum[inner]=temp%10;
                carry=temp/10;
            }
        	flLimit=false;
            sum[inner]=carry;
			if(carry!=0)
			{
				flLimit=isPalindrome(sum,inner);
				firstDigit=inner-1;
			}
			else
			{
				flLimit=isPalindrome(sum,inner+1);
				firstDigit=inner;
			}
            /*for(loop1=0;loop1<50;loop1++)
            {
                cout << sum[loop1] ;
            }
            cout << endl;*/
            if(flLimit)
            {
                flag=false;
                break;
            }
            
            number.assign(sum.begin(),sum.end());
        }
        if(flag)
        {
            cout << loop << endl;
            count++;
        }
    }
	return count;
}
bool isPalindrome(const vector<int>& number,int limit)
{
    int loop,length=number.size()-limit;
    
    for(loop=0;loop<length/2;loop++)
    {
        if(number[number.size()-1-loop]!=number[number.size()+loop-length])
        {
            return false;
        }    
    }
    return true;
}
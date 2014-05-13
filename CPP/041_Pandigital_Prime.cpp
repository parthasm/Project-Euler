#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> factorials(8,1);

bool isPrime(int n);
vector<int>& allPerms(vector<short> digits,vector<int>& perms); 
vector<short>& nextPerm(vector<short>& digits);
void updateFactorials();
int findLargestPrimePandigital();

// no need to consider 8 digit & 9 digit pandigital nos. as they cant be prime. (sum of digits 36 & 45 respectively)
//therefore, divisible by 3

int main()
{
    updateFactorials();
    //vector<short> digits(1,1);
    //vector<int> perms;
    //digits.push_back(2);
    //digits.push_back(3);
    //digits.push_back(4);
    //perms = allPerms(digits);
    //digits.push_back(5);
    //perms = allPerms(digits,perms);
    //for(int counter=0;counter<perms.size();counter++)
   //     cout << perms[counter] << endl;
    cout << findLargestPrimePandigital() << endl;
    return 0;
}

int findLargestPrimePandigital()
{
    int max=0,loop;
    vector<short> digits(7,0);
    vector<int> perms;
    for(short counter=0;counter<digits.size();counter++)
    {
        digits[counter]=counter+1;
    }
    while(true)
    {
        if(max!=0)
        break;
        perms = allPerms(digits,perms);
        for(loop=0;loop<perms.size();loop++)
        {
            //cout << perms[loop] << " " << isPrime(perms[loop]) << endl;
            if(perms[loop] > max && isPrime(perms[loop]))
            {
                max=perms[loop];
            }
            if(loop>0 && max!=0)
            {
                break;
            }
            
        }
        //cout << " " << endl;
        digits.erase(digits.begin()+digits.size()-1);
    }
    return max;
}
vector<int>& allPerms(vector<short> digits,vector<int>& perms)
{
    int loop=1,number=0,inner;
    while(loop<=factorials[digits.size()])
    {
        number=0;
        for(inner=0;inner<digits.size();inner++)
            number=(10*number)+digits[inner];
        perms.push_back(number);
        digits=nextPerm(digits);
        loop++;
    }
    return perms;
}
vector<short>& nextPerm(vector<short>& digits)
{
    int pivot=-1,counter,pivotPosition=-1,successor=-1,succesorPosition=-1;
    for(counter=digits.size()-2;counter>=0;counter--)
    {
        if(digits[counter]>digits[counter+1])
        {
            pivot=digits[counter];
            pivotPosition=counter;
            break;
        }
    }
    if(pivotPosition==-1)
    {
        for(counter=0;counter<digits.size()/2;counter++)
        {
            digits[counter]=digits[counter]+digits[digits.size()-counter-1];
            digits[digits.size()-counter-1]=digits[counter]-digits[digits.size()-counter-1];
            digits[counter]=digits[counter]-digits[digits.size()-counter-1];
        }
        return digits;
    }
     for(counter=digits.size()-1;counter>=0;counter--)
     {
         if(digits[counter]<pivot)
         {
             successor=digits[counter];
             succesorPosition=counter;
             break;
         }
     }
     digits[pivotPosition]=digits[pivotPosition]+digits[succesorPosition];
     digits[succesorPosition]=digits[pivotPosition]-digits[succesorPosition];
     digits[pivotPosition]=digits[pivotPosition]-digits[succesorPosition];
     
     int l=digits.size()-pivotPosition-1,index;
     for(counter=0;counter<l/2;counter++)
     {
        
         digits[counter+pivotPosition+1]=digits[counter+pivotPosition+1]+digits[pivotPosition+l-counter];
         digits[pivotPosition+l-counter]=digits[counter+pivotPosition+1]-digits[pivotPosition+l-counter];
         digits[counter+pivotPosition+1]=digits[counter+pivotPosition+1]-digits[pivotPosition+l-counter];
     }
     return digits;
}
bool isPrime(int n)
{
    if(n<2)
    return false;
    
    int f=2;
    while(f<=(int)sqrt(n))
    {
        if(n%f==0)
        return false;
        f++;
    }
    
    return true;
}
void updateFactorials()
{
    int f=1,counter=1;
    for(;counter<factorials.size();counter++)
    {
        f*=counter;
        factorials[counter]=f;
        //cout << f << endl;
    }
}
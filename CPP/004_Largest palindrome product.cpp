#include <iostream>
#include <string>
#include <sstream>

using namespace std;
bool isPalindrome(int num)
{
     string check;
     stringstream ss;//create a stringstream
   ss << num;//add number to the stream
   check = ss.str();
                typedef string::size_type str_size;
                str_size i,len = check.size();
                for(i=0;i<len/2;i++)
                {
                        if(check[i]!=check[len-i-1])
                                return false;
                }
 
                return true;
}
int findLargestPalindrome()
{
    int max=0,product,num1,num2;
                for(num1=999;num1>899;num1--)
                {
                        for(num2 = 999; num2 > 899; num2--)
                        {
                                product = num1*num2;
                                if(!isPalindrome(product))
                                        continue;
                                if(product<max)
                                        break;
                                if(product>max )
                                        max = product;
                                
                        } 
                }       
                
                
                return max;
}
int main()
{
    int p = findLargestPalindrome();
    cout << "Largest Palindrome is " << p << endl;
    return 0;
}
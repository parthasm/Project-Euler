#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

bool isPalindromeNumber(int decimal);
bool isPalindromeBool(vector<bool> binary);
vector<bool> decToBinary(int num);
int findSum(int limit);

int main()
{
    //vector<bool> binary = decToBinary(63);
	//for(int counter=binary.size()-1;counter>-1;counter--)
		//cout << binary[counter] << " " ;
	cout << findSum(1000000) << endl;
	return 0;
}

int findSum(int limit)
{
	int sum=0,counter=0;
	for(;counter<limit;counter++)
	{
		if(isPalindromeNumber(counter) && isPalindromeBool(decToBinary(counter)))
		{
			sum+=counter;
		}
	}
	
	return sum;
}

bool isPalindromeNumber(int decimal)
{
     string check;
     stringstream ss;//create a stringstream
   ss << decimal;//add number to the stream
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
bool isPalindromeBool(vector<bool> binary)
{
	int counter;

	for(counter=0;counter<(binary.size())/2;counter++)
	{
		if(binary[counter]!=binary[binary.size()-counter-1])
			return false;
	}

	return true;
}

vector<bool> decToBinary(int num)
{
	vector<bool> binary;
	bool rem;
	int temp=num;
	while(temp>0)
	{
		rem=((temp%2)==1?true:false);
		binary.push_back(rem);
		temp=temp/2;
	}
	return binary;
}
#include <iostream>
#include <string>
#include <sstream>
#include <vector> 
#include <cmath>

using namespace std;

string::size_type findLengthOfNumber(int n);
vector<int> allRotations(int num);
int findNumberOfCircularPrimes(int limit);
int main()
{
    //vector<int> combos = allRotations(211);
	//cout << combos[0] << " " << combos[1] << " " << combos[2] << endl;
	cout << findNumberOfCircularPrimes(1000000) << endl; 	
	return 0;
}

int findNumberOfCircularPrimes(int limit)
{
	vector<bool> primes(limit,true);
	vector<int> rotations;
	primes[0]=false;
	primes[1]=false;
	int outer,inner,counter=0;
	bool flag;
	
	for(outer=2;outer<limit;outer++)
	{
		if(!primes[outer])
			continue;
		//cout << outer << endl;
		for(inner=2*outer;inner<limit;inner+=outer)
		{
			primes[inner]=false;
		}
	}
	
	for(outer=2;outer<limit;outer++)
	{
		if(primes[outer])
		{
			flag=true;
			rotations.resize(0);
			rotations=allRotations(outer);
			for(inner=0;inner<(rotations.size()-1);inner++)
			{
				//cout << "hi " <<  rotations[inner] << "\t" ;
				if(!primes[rotations[inner]])
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				//cout << outer << endl;
				counter++;
			}
		}
	}
	return counter;

}
string::size_type findLengthOfNumber(int n)
{
	string num;
	stringstream ss;
	ss << n;
	num=ss.str();

	return num.size();
}

vector<int> allRotations(int num)
{
	
	int len = findLengthOfNumber(num),counter,rem,tenToThePower;
	tenToThePower = (int)pow(10,len-1.0);
	vector <int> allRotations(len,0);
	

	for(counter=0;counter<len;counter++)
	{
		rem=num%10;
		num=num/10;
		num= (tenToThePower*rem)+num;
		allRotations[counter]=num;
	}

	return allRotations;
}
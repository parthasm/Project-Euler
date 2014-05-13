#include <iostream>
#include <cmath>
#include <map>
using namespace std;
 
int findNoWithMaxSolution(int limit);
bool ifWholeNumber(double num);
int main()
{
	cout << findNoWithMaxSolution(1000) << endl;
	//cout << ifWholeNumber(pow(9.0,0.5)) << endl;
    return 0;
}
 
int findNoWithMaxSolution(int limit)
{
	//a^2 + b^2 = c^2
	//we need to find p [1,1000] for which there are max solutions to the equation:p=a+b+c
	map<int,short> pCount;

	int a=3,b,diff=1,maxP=1,maxCount=0;
	double c;
	for(;a<270;a++)
	{
		for(b=a+1;b<500;b++)
		{
			c=pow((a*a)+(b*b),0.5);
			diff=((b+1)*(b+1))-(b*b);
			if(diff > (a*a))
				break;
			if(!ifWholeNumber(c))
				continue;
			if(a+b+(int)c <= limit)
			pCount[a+b+(int)c]++;
			//cout << a << " " << b << " " << c << " " << (a+b+(int)c) << endl;
			
		}

	}

	for(map<int,short>::const_iterator it=pCount.begin();it!=pCount.end();it++)
	{
		cout << it->first << "  " << it->second << endl;
		if(it->second>maxCount)
		{
			maxCount=it->second;
			maxP=it->first;
		}
	}

	return maxP;
}
bool ifWholeNumber(double num)
{
	double d=num;
	int i=(int)num;
	double diff=d-i;
	bool flag=diff>0.0?false:true;
    return flag;
}
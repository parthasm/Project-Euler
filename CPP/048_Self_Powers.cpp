#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<short> findSum(int limit);

int main()
{
	vector<short> sum=findSum(1000);
	for(int counter=0;counter<10;counter++)
		cout << sum[counter] << " ";
	return 0;
}

vector<short> findSum(int limit)
{
	vector<short> sum(10,0);
	vector<short> expo(10,0);
	int counter=1,number,loop,dummyCounter,inner,carry;

	for(;counter<=limit;counter++)
	{
		fill(expo.begin(),expo.end(),0);
		loop=9;
		dummyCounter=counter;
		if(counter%10!=0)
		{
			while (dummyCounter>0)
			{
				expo[loop--]=dummyCounter%10;
				dummyCounter/=10;
			}
			for(loop=2;loop<=counter;loop++)
			{
				carry=0;
				for(inner=9;inner>=0;inner--)
				{
					number=(expo[inner]*counter)+carry;
					expo[inner]=number%10;
					carry=number/10;
				}
			}
			carry=0;
			for(loop=9;loop>=0;loop--)
			{
				number=sum[loop]+expo[loop]+carry;
				sum[loop]=number%10;
				carry=number/10;
			}
		}
	}

	return sum;
}
#include <iostream>
#include <vector>

using namespace std;

int findNumberWithLongestCycle(int limit) ;
vector<short> findDecimalUpto4000digits(int number);

int main()
{
	//vector<short> dec = findDecimalUpto3000digits(7);
	//for(int counter=0;counter<dec.size();counter++)
		//cout << dec[counter];
    cout << findNumberWithLongestCycle(1000) << endl;
    //findDecimalUpto4000digits(7);
    return 0;
}

 
int findNumberWithLongestCycle(int limit) 
{
	int searchLength,maxLength=0,d,searchCounter,inner;
	bool flag=true;
	for(int number=limit-1;number>2;number--)
	{
		vector<short> arr = findDecimalUpto4000digits(number);
		searchLength=1;
		if(arr.size()==2)
			continue;
                        while(searchLength<1000)
                        {
							flag=true;
							for(searchCounter=0;searchCounter<searchLength;searchCounter++)
							{
								if(arr[searchCounter]==arr[searchCounter+searchLength] && arr[searchCounter]==arr[searchCounter+(2*searchLength)] && arr[searchCounter]==arr[searchCounter+(3*searchLength)])
								{

								}
								else
								{
									flag=false;
									break;
								}
							}
							if(!flag)
							{
									 searchLength++;
                                        continue;
							}
                                
                                
                                if(searchLength>maxLength)
                                {
                                        maxLength=searchLength;
                                        d=number;
                                        
                                }
                                break;
                        }

	}
	return d;
}
 
 vector<short> findDecimalUpto4000digits(int number)
 {
	 vector<short> dec(4000,0);
	 vector<short> dummy(2,0);
	 int remainder=0,quotient=0,counter,d=10;

	 for(counter=0;counter<dec.size();counter++)
	 {
		 quotient=d/number;
		 dec[counter]=quotient;
		 remainder=d%number;
		 if(remainder==0)
			 return dummy;
		 remainder*=10;
		 d=remainder;
	 }

	 return dec;
 }
 
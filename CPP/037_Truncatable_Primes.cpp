#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long findSum(int limit);
 vector<int> allTruncations(int num);
int main()
{

    //int counter;
	//vector<int> truncation=allTruncations(739397);
	//for(counter=0;counter<truncation.size();counter++)
		//cout << truncation[counter] << endl;
     cout << findSum(1000000) << endl;
        return 0;
}
 long long findSum(int limit)
 {
	 long long sum=0ll;
	 int outer,inner;
	 vector<bool> primes(limit,true);
	 vector<int> truncations;
	 bool flag;

	 primes[0]=false;
	 primes[1]=false;
	 
	 for(outer=2;outer<limit;outer++)
	 {
		 if(!primes[outer])
			 continue;

		 for(inner=2*outer;inner<limit;inner+=outer)
			 primes[inner]=false;
	 }
	 for(outer=11;outer<limit;outer++)
	 {
		 if(primes[outer])
		 {
			
			 truncations=allTruncations(outer);
			 flag=true;
			 for(inner=0;inner<truncations.size();inner++)
			 {
				 if(!primes[truncations[inner]])
				 {
					 //cout << outer << " "<< truncations[inner] <<endl;
					 flag=false;
					 break;
				 }
			 }
			 if(flag)
			 {
				 sum+=(long long)outer;
				 cout << "Tr " << outer << endl;
			 }
		 }

	 }

	 return sum;
 }
 vector<int> allTruncations(int num)
 {
	 int rightTemp=num/10;
	 int leftTemp=num,temp=num,len=0;
	 vector<int> truncations;
	 while(rightTemp>0)
	 {
		  truncations.push_back(rightTemp);
		 rightTemp/=10;
		 
	 }
	 //took in all right truncations

	 while (temp>0)
	 {
		 len++;
		 temp/=10;
	 }
	//found the length

	 len--;
	 int tenToThePower;
	 while(len>0)
	 {
		 tenToThePower=(int)pow(10,len);
		 truncations.push_back(leftTemp%tenToThePower);
		 len--;
	 }
	 //took left truncations


	 return truncations;
 }
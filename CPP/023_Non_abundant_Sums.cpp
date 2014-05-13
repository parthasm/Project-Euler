#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int findSum();
int sumOfFactors(int n); 

        int main() 
        {
                cout << findSum() << endl;
        }
        
        int findSum()
        {
                int sum=0;
                bool flag=true;
                int counter,num=0;
                int i;
                map<int,int> abundantNos;
                
                for(counter=12;counter<28123;counter++)
                {
                        if(counter<sumOfFactors(counter))
                                abundantNos[counter]=counter;
                }
                
                
                for(counter=1;counter<24;counter++)
                        sum+=counter;
                
                for(counter=25;counter<28123;counter++)
                {
                        flag=true;
                        for(map<int,int>::const_iterator it=abundantNos.begin();it!=abundantNos.end();++it)
                        {
                                i = it->first;
                                num = counter - i;
                                if(num>0 && abundantNos.find(num)!=abundantNos.end())
                                {
                                        flag=false;
                                        break;
                                }
                        }
                        if(flag)
                                sum+=counter;
                }
                        return sum;
        }
        /*
        Trade-off! Trade-off!
        the contains() {search function}takes O(n) (& is often better~constant) time for a set, which is great!
        but since set not ordered so can't restrict search to only numbers less than counter
        but contains() in ordered data structures take huge time.so....
        */
        int sumOfFactors(int n) 
        {
                int sumF=1,f=2;
                        while(f<sqrt(n))
                        {
                                if(n%f==0)
                                {
                                        sumF+=f;
                                        sumF+=(n/f);
                                }
                                f++;
                        }
                        if(f==sqrt(n))
                                sumF+=f;
                return sumF;
        }
 

 
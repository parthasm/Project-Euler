#include <iostream>
#include <map>

using namespace std;

int findSum();
/*
 * the total number of digits of product, multiplier, multiplicand must be 9
 * After extensive research:P
 * It was found that
 * only 1-digit X 4-digit & 2-digit X 3-digit produces no.s of requisite digits
 */
 
        int main() 
        {                
                cout <<findSum() << endl;
                return 0;
        }
 
        int findSum()
        {
                int sum=0,num1,num2,product=1,loopCounter,temp,temp1,temp2;
                bool flag;
                map<int,int> products;
                map<int,bool> numbers;
                
                
                for(num1=2;num1<9;num1++)
                {
    				
                        for(num2=1234;num2<4987;num2++)
                        {
                                product = num1*num2;
                                if(product>9876)
                                        break;
								//cout << product << endl;
                                for(loopCounter=1;loopCounter<10;loopCounter++)
                                {
                                    numbers[loopCounter]=false;
                                }
                                
                                temp=product;
                                temp1=num1;
								temp2=num2;
                                while(temp>0)
                                {
                                    numbers[temp%10]=true;
                                    temp=temp/10;
                                }
                               while(temp1>0)
                                {
                                    numbers[temp1%10]=true;
                                    temp1=temp1/10;
                                }
                               while(temp2>0)
                                {
                                    numbers[temp2%10]=true;
                                    temp2=temp2/10;
                                }
                                flag=true;
                                for(loopCounter=1;loopCounter<10;loopCounter++)
                                {
                                    if(numbers[loopCounter]==false)
                                    {
                                        flag=false;
                                         break;
                                    }
                                }
                                
                                if(flag)
                                {
                                        if(products[product]==0)
                                        products[product]=product;
                                        
                                }
                        }
                }
                
                
                
                
                
                for(num1=12;num1<99;num1++)
                {
                        for(num2=123;num2<839;num2++)
                        {
                               product = num1*num2;
                                if(product>9876)
                                        break;
                                
                                for(loopCounter=1;loopCounter<10;loopCounter++)
                                {
                                    numbers[loopCounter]=false;
                                }
                                
                                 temp=product;
                                temp1=num1;
								temp2=num2;
                                while(temp>0)
                                {
                                    numbers[temp%10]=true;
                                    temp=temp/10;
                                }
                               while(temp1>0)
                                {
                                    numbers[temp1%10]=true;
                                    temp1=temp1/10;
                                }
                               while(temp2>0)
                                {
                                    numbers[temp2%10]=true;
                                    temp2=temp2/10;
                                }
                                flag=true;
                                for(loopCounter=1;loopCounter<10;loopCounter++)
                                {
                                    if(numbers[loopCounter]==false)
                                    {
                                        flag=false;
                                         break;
                                    }
                                }
                                
                                if(flag)
                                {
                                        if(products[product]==0)
                                        products[product]=product;
                                        
                                }
                        }
                }
                for(map<int,int>::const_iterator i = products.begin();i!=products.end();i++)
                {
                        sum=sum+(i->second);
                }
                return sum;
        }

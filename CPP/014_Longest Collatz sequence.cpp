#include <iostream>

using namespace std;
int main()
{
     int num[999998];
                int i,counter,chain=0,longest_num=0;
                long long temp;
                
                for(i=0;i<999998;i++)
                {
                        temp = (long long)(i+2);
                        counter = 0;
                        while(temp>1l)
                        {
                                if(temp<(long long)(i+2))
                                {
                                        counter = counter + num[(int)(temp-2ll)];
                                        break;
                                }
                                
                                if(temp%2ll==0ll)
                                        temp = temp/2ll;
                                
                                else
                                        temp = (3ll*temp)+1ll;
                                counter++;
                        }
                        
                        num[i]=counter;
                        
                        if(chain<counter)
                        {
                                chain = counter;
                                longest_num = i+2;
                        }
                }
                cout << longest_num;
    return 0;
}
#include <iostream>

using namespace std;

 int findNoOfSundays();

int main()
        {
                cout << findNoOfSundays() << endl;
        }
        
        int findNoOfSundays()
        {
                int index, monthCounter=13,dayCounter=6,counter=0;
                int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
                while((monthCounter/12)<=100)
                {
                        index = (monthCounter%12)-1;
                        if(index==-1)
                                index = 11;
                        
                        if(index==1 && (monthCounter/12)%4==0)
                        {
                                if(dayCounter>(monthDays[index]+1))
                                {
                                        dayCounter-=(monthDays[index]+1);
                                        monthCounter++;
                                }
                        }
                        
                        else    
                        {
                                if(dayCounter>monthDays[index])
                                {
                                        dayCounter-=(monthDays[index]);
                                        monthCounter++;
                                }
                        }
                        
                        if(dayCounter==1)
                                counter++;
                        
                        dayCounter+=7;  
                }
                return counter;
        }
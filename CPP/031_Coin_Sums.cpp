#include <iostream>

using namespace std;

int noOfWays() ;
        int main() 
        {
                cout << noOfWays() << endl;
 
        }
        int noOfWays() 
        {
                //there can be (<=1) $2, (<=2) $1, (<=4)50p, (<=10) 20p, (<=20) 10p, (<=40) 5p, (<=100) 2p, (<=200) 1p
                int counter=8,sum=0;
                int loop[] = {0,0,0,0,0,0,0};
                for(loop[0]=0;loop[0]<2;loop[0]++)
                {
                        sum=loop[0]*100;
                        for(loop[1]=0;loop[1]<4;loop[1]++)
                        {
                                sum = (loop[0]*100) + (loop[1]*50);
                                if(sum>200)
                                        break;
                                for(loop[2]=0;loop[2]<10;loop[2]++)
                                {
                                        sum = (loop[0]*100) + (loop[1]*50) + (loop[2]*20);
                                        if(sum>200)
                                                break;
                                        for(loop[3]=0;loop[3]<20;loop[3]++)
                                        {
                                                sum = (loop[0]*100) + (loop[1]*50) + (loop[2]*20)+(loop[3]*10);
                                                if(sum>200)
                                                        break;
                                                for(loop[4]=0;loop[4]<40;loop[4]++)
                                                {
                                                        sum = (loop[0]*100) + (loop[1]*50) + (loop[2]*20)+(loop[3]*10)+(loop[4]*5);
                                                        if(sum>200)
                                                                break;
                                                        for(loop[5]=0;loop[5]<100;loop[5]++)
                                                        {
                                                                sum = (loop[0]*100) + (loop[1]*50) + (loop[2]*20)+(loop[3]*10)+(loop[4]*5)+(loop[5]*2);
                                                                if(sum>200)
                                                                        break;
                                                                for(loop[6]=0;loop[6]<200;loop[6]++)
                                                                {
                                                                        sum = (loop[0]*100) + (loop[1]*50) + (loop[2]*20)+(loop[3]*10)+(loop[4]*5)+(loop[5]*2)+(loop[6]);
                                                                        if(sum==200)
                                                                                counter++;
                                                                }
                                                        }
                                                }
                                        }       
                                }
                        }
                }
                return counter;
        }
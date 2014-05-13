#include <iostream>

using namespace std;

int findSumOfSpiralDiagonal(int squareSide); 
        
        int main() 
        {
                cout << findSumOfSpiralDiagonal(1001) << endl;
 
        }
        int findSumOfSpiralDiagonal(int squareSide) 
        {
                int sum=1,counter=1,loop;
                if(squareSide%2==0)
                        return 0;
                int limit = (squareSide-1)/2,difference=0;
                int series[] = {7,3,5,9};
                for(loop=0;loop<sizeof(series)/sizeof(series[0]);loop++)
                {
                        difference=series[loop]-1;
                        counter=1;
                        while(counter<=limit)
                        {       
                                sum+=series[loop];
                                difference+=8;
                                series[loop]+=difference;
                                counter++;
                        }
                }
                
                return sum;
        }
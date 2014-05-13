#include <iostream>
#include <cmath>

using namespace std;

int findNoOfTerms(int limit);
bool ifWholeNumber(double num);
int main()
{
    cout << findNoOfTerms(100) << endl;
   double rootD=pow(4,(1.0/2));
          int  rootI = (int)(pow(4,(1.0/2)));
            double diff = rootD-rootI;
            bool f=diff>0.0?false:true;
           // cout << diff<< "\t" << f << endl;
}

int findNoOfTerms(int limit)
{
    int a=2,b=2,counter=0,count=0,inner;
    bool roots[5],flag=false;
    for(counter=0;counter<5;counter++)
        {
            roots[counter]=false;
        }
    for(a=2;a<=100;a++)
    {
        for(counter=0;counter<5;counter++)
        {
            roots[counter] = ifWholeNumber(pow(a,(1.0/(counter+2))));
            //cout << a << "\t"<<roots[counter] << endl;
        }
        for(b=2;b<=100;b++)
        {
             for(counter=0;counter<5;counter++)
            {
                if(roots[counter])
                    {
                        // && ((counter+2)*b)<=100)
                        for(inner=counter+1;inner>0;inner--)
                        {
                            if(ifWholeNumber(((counter+2.0)*b)/inner))
                            {
                                if((((counter+2)*b)/inner)<=100.0)
                                {
                                    flag=true;
                                break;
                                }
                            }
                        }
                        if(flag)
                        break;
                    }
            }    
            if(!flag)
            count++;
            flag=false;
        }
        for(counter=0;counter<5;counter++)
        {
            roots[counter]=false;
        }
    }
    
    return count;
}
bool ifWholeNumber(double num)
{
            double rootD=num;
            int rootI = (int)(num);
            double diff = rootD-rootI;
            bool f=diff>0.0?false:true;
            return f;
}
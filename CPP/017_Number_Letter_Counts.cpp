#include <iostream>
#include <string>

using namespace std;

int main()
{
     string one_nineteen[] = {"one","two","three","four","five","six","seven",
                                "eight","nine","ten","eleven","twelve","thirteen","fourteen",
                                "fifteen","sixteen","seventeen","eighteen","nineteen"};
                string ten[] = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
                long long record = 0ll,record1 = 0ll;
                typedef string::size_type st;
                size_t counter,i;
                for(counter=0;counter<19;counter++)
                        record+=(long long)one_nineteen[counter].size();         //1-19
                // 1-19, 101-119 , ...,901-919
                record*=10ll;
                //101-119,..,901-919
                record+=(10ll*9ll*19ll);//10 - length of 'hundred' & 'and'; 9 - 101 to 901;19-1 to 19 
                        for(i=0;i<9;i++)
                        {
                                record+=(one_nineteen[i].size()*19ll);
                                record+=(one_nineteen[i].size()+7ll);//100, 200, 300,..,900
                        }
                        // 1-19, 101-119 , ...,901-919 end:-)
                        
                        //20 to 99
                        for(counter=0;counter<8;counter++)
                        {
                                record1+=(long long)ten[counter].size();
                                for(i=0;i<9;i++)
                                        record1+=(long long)(ten[counter].size()+one_nineteen[i].size());
                        }
                        record1*=10ll; // 120-199,220-299,...,920-999     
                        record1+=(10ll*9ll*80ll);//10 - length of 'hundred' & 'and'; 9 - 120 to 920;80-20 to 99
                        
                        for(i=0;i<9;i++)
                        {
                                record1+=(one_nineteen[i].size()*80ll);
                                
                        }
                        
                        cout << record+record1+11l << endl;
    return 0;
}

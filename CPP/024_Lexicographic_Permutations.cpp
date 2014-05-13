#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> findPermutation(vector<int> inputChars, int rank);
vector<char> findRank(vector<int> inputChars,int rank);

        int main() 
        {
                vector<char>::size_type i;
                vector<int> inputChars;
                for(int counter=0;counter<10;counter++)
                        inputChars.push_back(counter);
                
                int rank = 1000000;
                
                vector<char> answer = findPermutation(inputChars, rank);
                for(i=0;i<answer.size();i++)
                    cout << answer[i] << "\t";
                
        }
        
        vector<char> findPermutation(vector<int> inputChars, int rank) 
        {
                vector<char> ranks=findRank(inputChars, rank);
                int counter,individualRank=0;
                vector<char> finalOutput;
                for(counter=0;counter<ranks.size();counter++)
                {
                        individualRank=ranks[counter]-48;
                        finalOutput.push_back(inputChars[individualRank-1]+48);
                        inputChars.erase(inputChars.begin()+individualRank-1);
                }
                return finalOutput;
        }
 
        vector<char> findRank(vector<int> inputChars,int rank)
        {
                 vector<char> ranks,error;
                 error.push_back('e');
                 error.push_back('r');
                 error.push_back('r');
                 error.push_back('o');
                 error.push_back('r');
                int counter,individualRank=0,x;
                int factorial=1;
                vector<int> factorials;
                factorials.push_back(1);
                for(counter=1;counter<=inputChars.size();counter++)
                {
                        factorial*=counter;
                        factorials.push_back(factorial);
                }
                
                if(rank>factorials[factorials.size()-1])
                        return error;
                
                for(counter=factorials.size()-2;counter>=0;counter--)
                {
                        x = rank%factorials[counter];
                        if(x>0)
                        {
                                individualRank=(rank/factorials[counter])+1;
                        }
                        else
                        {
                                individualRank=(rank/factorials[counter]);
                                ranks.push_back(individualRank+48);
                                for(int inner=--counter;inner>=0;inner--)
                                {
                                        ranks.push_back(inner+49);
                                }
                                break;
                        }
                        ranks.push_back(individualRank+48);
                        rank=x;
                        
                }
                return ranks;
                
        }

 
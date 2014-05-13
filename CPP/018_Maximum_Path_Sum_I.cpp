#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std; 
struct Node 
{
        Node *left,*right,*next;
        int data;
};
 
Node * insertInGraph(int numbers[],size_t arrSize);
int calculateNoOfRows(int length) ;
 vector<int> findAllSums(Node *start) ;
int main()
{
                int numbers[] = {75,
                                95,64,
                                17,47,82,
                                18,35,87,10,
                                20,4,82,47,65,
                                19,1,23,75,3,34,
                                88,2,77,73,7,63,67,
                                99,65,4,28,6,16,70,92,
                                41,41,26,56,83,40,80,70,33,
                                41,48,72,33,47,32,37,16,94,29,
                                53,71,44,65,25,43,91,52,97,51,14,
                                70,11,33,28,77,73,17,78,39,68,17,57,
                                91,71,52,38,17,14,91,43,58,50,27,29,48,
                                63,66,4,68,89,53,67,30,73,16,69,87,40,31,
                                4,62,98,27,23,9,70,98,73,93,38,53,60,4,23};
                size_t arrSize = sizeof(numbers)/sizeof(*numbers),outer,inner;
                Node *n = insertInGraph(numbers,arrSize),*n1,*first;
                Node *n2 = n,*n3;
                int max=0;
                
                for(outer=0;outer<calculateNoOfRows(arrSize);outer++)
                {
                        for(inner=0;inner<=outer;inner++)
                        {
                                cout << n->data << "\t" ;
                                if(inner==0)
                                        first = n->left;
                                n = n->next;
                        }
                        n = first;
                        cout << endl;
                }
                vector<int> sums;
                typedef vector<int>::size_type vsz;
                
                sums = findAllSums(n2);
                
                vsz sumsSize = sums.size(),i;
                
                for(i=0;i!=sumsSize;i++)
                {
                        if(max<sums[i])
                                max = sums[i];
                        
                }
                cout << max;
                
        }
        Node * insertInGraph(int numbers[],size_t arrSize)
        {
                size_t arrIndex=0,counter,inner,rows=calculateNoOfRows(arrSize);
                
                
                Node *start;
                start= new Node;
                start->data = numbers[arrIndex];
                Node *n = start,*n1=start,*first,*d,*d1;
                
                for(counter=0;counter<(rows-1);counter++)
                {
                        d=0;
                        d1=0;
                        for(inner=0;inner<=counter;inner++)
                        {
                                n=n1;
                                if(!inner)
                                {
                                        arrIndex++;
                                        d = new Node;
                                        d->data = numbers[arrIndex];
                                }
                                else
                                        d = d1;
                                
                                n->left = d;
                                if(inner==0)
                                        first=n->left;
                                d1 = new Node;
                                d1->data = numbers[++arrIndex];
                                n->right=d1;
                                n->left->next=n->right;
                                n1 = n->next;
                                
                        }
                        n1=first;
                }
                return start;
                
        }
        
        int calculateNoOfRows(int length) 
        {
                int p = 8*length+1;
                p = sqrt(p);
                p--;
                p/=2;
                return p;
        }
         vector<int> findAllSums(Node *start) 
        {
                typedef vector<int>::size_type vsz;
                vsz i;
                vector<int> sum1,sum2,last;
                Node *left = start->left;
                Node *right = start->right;
                if(left!=0 && right!=0)
                {
                        sum1 = findAllSums(left);
                        sum2 = findAllSums(right);
                }
                else
                {
                        vector<int> x;
                        
                        x.push_back(start->data);
                        return x;
                }
                        for(i=0;i!=sum1.size();i++)
                        {
                                sum1[i] = sum1[i]+start->data;
                                
                        }
                        
                        for(i=0;i<sum2.size();i++)
                        {
                        
                                sum2[i] = sum2[i]+start->data;
                                        
                        
                        }
                        
                        for(i=0;i!=sum1.size();i++)
                                last.push_back(sum1[i]);
                        for(i=0;i!=sum2.size();i++)
                                last.push_back(sum2[i]);
                
                return last;
                
        }
#include <iostream>
#include <map>
#include <vector> 
 
using namespace std;
 
int firstOf4No();
//map<int,int>& primeFactor(map<int,int>& pfs,int n);

int main()
{
    //map<int,int> pfs;
	//pfs=primeFactor(pfs,23ll);
	//for(map<int,int>::const_iterator it=pfs.begin();it!=pfs.end();it++)
		//cout << it->first << endl;
    cout << firstOf4No() << endl;
    return 0;
}
 
int firstOf4No()
{
        vector<bool> primes(1000000,true);
		bool flag;
		map<int,int> pfs;
		int loop=2,inner,dummy,f,ins;
 
        primes[0]=false;
        primes[1]=false;
 
        
 
        for(;loop<primes.size();loop++)
        {
                if(!primes[loop])
                        continue;
                for(inner=2*loop;inner<primes.size();inner+=loop)
                {
                        primes[inner]=false;
                }
        }

		 for(loop=210;loop<primes.size();loop++)
		 {
			 pfs.erase(pfs.begin(),pfs.end());
			 if(!primes[loop])
			 {
				 dummy=loop;
				 f=2;
				 ins=1;
				 flag=false;
				 while(f<=dummy)
				{
		
					if(dummy%f==0)
					{
						ins*=f;
						dummy=dummy/f;
						if(dummy==1)
						pfs[ins]++;
					}

					else
					{
						if(ins>1)
						{
							pfs[ins]++;
						}
						ins=1;
						f++;
					}
				 }
			 }
			 if(flag || pfs.size()!=4)
			 {
				 continue;
			 }



			 if(!primes[loop+1])
			{
				 dummy=loop+1;
				 f=2;
				 ins=1;
				 flag=false;
				 while(f<=dummy)
				{
		
					if(dummy%f==0)
					{
						ins*=f;
						dummy=dummy/f;
						if(dummy==1)
						{
							pfs[ins]++;
							if(pfs[ins]>1)
							{
								flag=true;
								break;
							}
						}
					}

					else
					{
						if(ins>1)
						{
							pfs[ins]++;
							if(pfs[ins]>1)
							{
								flag=true;
								break;
							}
						}
						ins=1;
						f++;
					}
				 }
			 }
			 if(flag || pfs.size()!=8)
			 {
				 loop++;
				 continue;
			 }



			 if(!primes[loop+2])
			{
				 dummy=loop+2;
				 f=2;
				 ins=1;
				 flag=false;
				 while(f<=dummy)
				{
		
					if(dummy%f==0)
					{
						ins*=f;
						dummy=dummy/f;
						if(dummy==1)
						{
							pfs[ins]++;
							if(pfs[ins]>1)
							{
								flag=true;
								break;
							}
						}
					}

					else
					{
						if(ins>1)
						{
							pfs[ins]++;
							if(pfs[ins]>1)
							{
								flag=true;
								break;
							}
						}
						ins=1;
						f++;
					}
				 }
			 }
			 if(flag || pfs.size()!=12)
			 {
				 loop+=2;
				 continue;
			 }



			 if(!primes[loop+3])
			{
				 dummy=loop+3;
				 f=2;
				 ins=1;
				  flag=false;
				 while(f<=dummy)
				{
		
					if(dummy%f==0)
					{
						ins*=f;
						dummy=dummy/f;
						if(dummy==1)
						{
							pfs[ins]++;
							if(pfs[ins]>1)
							{
								flag=true;
								break;
							}
						}
					}

					else
					{
						if(ins>1)
						{
							pfs[ins]++;
							if(pfs[ins]>1)
							{
								flag=true;
								break;
							}
						}
						ins=1;
						f++;
					}
				 }
			 }



			 if(!flag && pfs.size()==16)
				 return loop;
			 loop+=3;
		 }

		 return 0;
		
}

/*map<int,int>& primeFactor(map<int,int>& pfs,int n)
{
	int f=2,ins=1,dummy=n;
	while(f<=dummy)
	{
		
		if(dummy%f==0)
		{
			ins*=f;
			dummy=dummy/f;
			if(dummy==1)
				pfs[ins]++;
		}

		else
		{
			if(ins>1)
			{
				/*if(pfs[ins]!=0)
				{
					pfs.erase(pfs.begin(),pfs.end());
					return pfs;
				}*/
					/*pfs[ins]++;
			}
			ins=1;
			f++;
		}

		/*if(pfs.size()>4)
		{
			pfs.erase(pfs.begin(),pfs.end());
			return pfs;
		}
	}

	return pfs;
}*/
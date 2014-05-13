class Version3 {

	
	public static void main(String[] args) 
	{
		int small_factor = 1, large_factor = 20,i;
	    long num=(long)small_factor;
	    for(i=small_factor;i<=large_factor;i++)
	    {
	        num = lcm_intrinsic(num,i);
	        //System.out.println(num);
	    }
	    
	    System.out.println("smallest required number is "+num);

	}
	

	
	public static int isprime(int n)
	{
	    int f=2,flag=1;
	    
	    while(f <= (n/2))
	    {
	        if(n%f==0)
	        {
	            flag=0;
	            break;
	        }
	        f++;
	    }
	    return flag;
	}

	public static long lcm_intrinsic(long n1,long n2)
	{
	    int pf = 2;
	    
	    long temp,lcm_i=1,n1_local=n1,n2_local=n2;
	    if(n1<n2)
	    {
	        temp=n1;
	        n1=n2;
	        n2=temp;
	    }
	    else if(n1==n2)
	    {
	        return n1;
	    }
	    
	    while(pf <= (n2/2))
	    {
	        if(isprime(pf)==1)
	        {
	            if(n1_local%pf==0 && n2_local%pf==0)
	            {
	                lcm_i = lcm_i*((long)pf);
	                n1_local = n1_local/((long)pf);
	                n2_local = n2_local/((long)pf);
	            }
	            else
	            {
	                pf++;
	            }
	        }
	        else
	        {
	            pf++;
	        }
	    }
	    //System.out.print(n1_local+"\t"+n2_local+"\t");
	    lcm_i = lcm_i*n1_local*n2_local;
	    
	    return lcm_i;
	}

}


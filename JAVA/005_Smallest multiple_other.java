class Version2 {

	
	public static void main(String[] args) 
	{
		int small_factor = 1, large_factor = 20,i;
	    long num=(long)small_factor;
	    for(i=small_factor;i<=large_factor;i++)
	    {
	        num = lcm_from_hcf(num,i);
	        //System.out.println(num);
	    }
	    
	    System.out.println("smallest required number is "+num);

	}
	
	public static long hcf(long n1,long n2)
	{
	    long temp;
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
	    long remaindr = n1%n2;
	    
	    if(remaindr==0)
	    {
	        return n2;
	    }
	    
	    while(n2%remaindr!=0)
	    {
	        n1 = n2;
	        n2 = remaindr;
	        remaindr = n1%n2;
	    }
	    return remaindr;
	}

	public static long lcm_from_hcf(long n1,int n2)
	{
	    long prod = n1*((long)n2);
	    long lcm_fh = prod/hcf(n1,n2);
	    
	    return lcm_fh;
	}

}

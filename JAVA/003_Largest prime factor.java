class Version1 {

	
	public static void main(String[] args) 
	{
		 long num = 600851475143l;
		    long pf = num;
		    long factor = 2l;
		   
		    
		    while (factor < pf)
		    {
		        if(isprime(factor)==1)
		        {
		            if(pf%factor==0l)
		            {
		                pf = pf / factor;
		                
		                if(isprime(pf)==1)
		                    break;
		            }
		            else
		                factor++;
		            
		        }
		        else
		        factor++;
		    }
		    
		    System.out.println(" largest prime factor is "+pf);

	}
	
	public static int isprime(long n)
	{
		int f=2;
	    int flag=1;
	    while(f <= (n/2))
	    {
	        if(n%f==0)
	        {
	            flag = 0;
	            break;
	        }
	        f++;
	        
	    }
	    return flag;
	}

}

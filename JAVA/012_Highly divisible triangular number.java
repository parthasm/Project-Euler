class Version1 
{
	public static int no_of_factor(int n)
	{
	    int no=2,f=2;
	    
	    while(f < Math.sqrt(n))
	    {
	        if(n%f==0)
	            no++;
	        f++;
	    }
	    
	    return (2*no);
	}    
	
	
	public static void main(String[] args) 
	{
		
		    int num=1,sum=0,counter=0;
		    
		    while(counter<500)
		    {
		        sum+=num;
		        num++;
		        counter = no_of_factor(sum);
		    }
		    
		    System.out.println(sum);
		    
		}

	

}

class Version2
{
	public static void main(String args[])
	{
		   boolean[] prime = new boolean[1000000];
		   int i,j,counter=0;
		   for(i=2;i<prime.length;i++)
			prime[i] = true;
		   
		   for(i=2;i<prime.length;i++)
		   {
			if(!prime[i])
				continue;
			for(j=2*i;j<prime.length;j+=i)
				prime[j] = false;			
		   }	
			i=2;
		    while(counter<10001)
		    {
			if(prime[i])
				counter++;
			i++;
		    }	
		System.out.println(--i);

	}
	
}

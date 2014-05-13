class Version3 
{
	public static void main(String[] args) 
	{
		boolean[] a = new boolean[2000000];
		int i,j;
		long sum=0l;
		
		for(i=0;i<2000000;i++)
			a[i]=true;
		
		a[0]=false;
		a[1]=false;
		
		for(i=2;i<2000000;i++)
		{
			if(!a[i])
				continue;
			for(j=2*i;j<2000000;j+=i)
				a[j]=false;
		}
		
		for(i=2;i<2000000;i++)
		{	
			if(a[i])
				sum+=(long)(i);
		}
			
		System.out.println(sum);
	}

}

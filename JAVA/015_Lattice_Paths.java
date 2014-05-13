class TestMain
{
	public static void main(String[] args)
	{
		System.out.println(noOfPaths(20l));
	}

	private static double noOfPaths(long side)
	{
		long upper = 2 * side;
		double result=1.0/factorial(side);
		long counter = side;
		for(;counter>0l;counter--)
		{
			result*=(upper--);
			System.out.println("r "+result);
		}
		
		return result;
	}
	
	private static long factorial(long n)
	{
		if(n>1)
			return n * factorial(n-1);
		
			return 1l;
		
	}
}
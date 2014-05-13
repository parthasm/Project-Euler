class TestMain 
{

	public static void main(String[] args) 
	{
		System.out.println("The largest Palindrome product of 2 3-digit numbers is "+findLargestPalindrome());

	}
	
	private static int findLargestPalindrome()
	{
		int a,b,c,max=0,product,num1,num2;
		for(num1=999;num1>899;num1--)
		{
			for(num2 = 999; num2 > 899; num2--)
			{
				product = num1*num2;
				if(!isPalindrome(product))
					continue;
				if(product<max)
					break;
				if(product>max )
					max = product;
				
			} 
		}	
		
		
		return max;
	}
	
	private static boolean isPalindrome(int num)
	{
		String check = num+"";
		int i,len = check.length();
		for(i=0;i<len/2;i++)
		{
			if(check.charAt(i)!=check.charAt(len-i-1))
				return false;
		}

		return true;
	} 
		
	

}

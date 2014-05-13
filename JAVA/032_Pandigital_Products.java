

import java.util.*;

/*
 * the total number of digits of product, multiplier, multiplicand must be 9
 * After extensive research:P
 * It was found that
 * only 1-digit X 4-digit & 2-digit X 3-digit produces no.s of requisite digits
 */
class TestMain 
{

	 
	public static void main(String[] args) 
	{
		
		System.out.println(findSum());
	}

	private static int findSum()
	{
		int sum=0,num1,num2,product,loopCounter;
		boolean flag;
		Set<Integer> products = new HashSet<Integer>();
		String numbers = "123456789";
		StringBuilder identityString = new StringBuilder();
		for(num1=2;num1<9;num1++)
		{
			for(num2=1234;num2<4987;num2++)
			{
				product = num1*num2;
				if(product>9876)
					break;
				flag=true;
				
				if(identityString.length()!=0)
					identityString.delete(0, identityString.length());
				
				identityString.append(product);
				identityString.append(num2);
				identityString.append(num1);
				
				for(loopCounter=0;loopCounter<numbers.length();loopCounter++)
				{
					if(identityString.indexOf(numbers.charAt(loopCounter)+"")==-1)
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					products.add(product);
					//System.out.println(identityString);
				}
			}
		}
		
		
		
		
		
		for(num1=12;num1<99;num1++)
		{
			for(num2=123;num2<839;num2++)
			{
				product = num1*num2;
				if(product>9876)
					break;
				flag=true;
				
				if(identityString.length()!=0)
					identityString.delete(0, identityString.length());
				
				identityString.append(product);
				identityString.append(num2);
				identityString.append(num1);
				
				for(loopCounter=0;loopCounter<numbers.length();loopCounter++)
				{
					if(identityString.indexOf(numbers.charAt(loopCounter)+"")==-1)
					{
						flag=false;
						break;
					}
				}
				if(flag)
				{
					products.add(product);
					//System.out.println(identityString);
				}
			}
		}
		for(Integer i:products)
			sum+=i;
		return sum;
	}
}

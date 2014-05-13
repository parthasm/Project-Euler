

import java.math.BigDecimal;

class V2 
{

    
	public static void main(String[] args) 
	{
		System.out.println(findSumOfDigits(100));

	}
	private static int findSumOfDigits(int n)
	{
		int sum = 0;
		BigDecimal result = getFactorial(new BigDecimal(n));
		BigDecimal zero = new BigDecimal(0);
		BigDecimal ten = new BigDecimal(10);
		while(result.compareTo(zero)>0)
		{
			sum+=result.remainder(ten).intValueExact();
			result = result.divideToIntegralValue(ten);
		}
		return sum;
	}
	private static BigDecimal getFactorial(BigDecimal b) 
	{
		BigDecimal one = new BigDecimal(1);
		if(b.compareTo(one)>0)
		return (b.multiply(getFactorial(b.subtract(one))));
		else
			return one;
	}
}

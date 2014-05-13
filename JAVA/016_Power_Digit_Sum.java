
import java.math.BigDecimal;

class V2 
{

	
	public static void main(String[] args) 
	{
		System.out.println(findSumOfDigits(2,1000));

	}
	private static int findSumOfDigits(int num,int expo) 
	{
		int sumDigit = 0;
		BigDecimal result = new BigDecimal(Math.pow(num, expo));
		BigDecimal zero = new BigDecimal(0);
		BigDecimal ten = new BigDecimal(10);
		while(result.compareTo(zero)>0)
		{
			sumDigit+=(result.remainder(ten)).intValueExact();
			
			result = result.divideToIntegralValue(ten);
			
		}
		return sumDigit;
	}
}

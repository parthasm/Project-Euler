import java.math.BigDecimal;

class TestMain 
{

    
	public static void main(String[] args) 
	{
		System.out.println(findRank(1000));

	}
	
	private static int findRank(int noOfDigits)
	{
		int counter=2;
		BigDecimal n1 = new BigDecimal(1);
		BigDecimal n2 = new BigDecimal(1);
		BigDecimal sum = new BigDecimal(0);
		while(sum.toString().length()<noOfDigits)
		{
			sum = n1.add(n2);
			n1 = n2;
			n2 = sum;
			counter++;
		}
		return counter;
	}

}

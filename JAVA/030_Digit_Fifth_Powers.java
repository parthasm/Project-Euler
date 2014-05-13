class TestMain 
{

    
	public static void main(String[] args) 
	{
		System.out.println(findSum());

	}
	private static int findSum() 
	{
		int sum=0,counter=0,num=0,sumDigit=0;
		int[][] digitWith5thPower = new int[2][10];
		for(counter=0;counter<digitWith5thPower[0].length;counter++)
		{
			digitWith5thPower[0][counter]=counter;
			digitWith5thPower[1][counter]= (int)Math.pow(counter, 5);
		}
		/*
		*If sum of 5th power of digits> number, within range
		* if sum of 5th power of digits< number,out of range
		*/
		for(counter=300;counter<328013;counter++)
		{
			num=counter;
			sumDigit=0;
			while(num>0)
			{
				sumDigit+=digitWith5thPower[1][num%10];
				if(sumDigit>counter)
					break;
				num/=10;
			}
			if(sumDigit==counter)
				sum+=counter;
		}
		return sum;
	}

}

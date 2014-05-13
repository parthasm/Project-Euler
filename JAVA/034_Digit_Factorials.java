class TestMain 
{

    
	public static void main(String[] args) 
	{
		System.out.println(findSum());

	}
	private static int findSum() 
	{
		int sum=0,counter=0,num=0,sumDigit=0,factorial=1;
		int[][] digitWithFactorial = new int[2][10];
		digitWithFactorial[0][0]=0;
		digitWithFactorial[1][0]=1;
		for(counter=1;counter<digitWithFactorial[0].length;counter++)
		{
			factorial*=counter;
			digitWithFactorial[0][counter]=counter;
			digitWithFactorial[1][counter]= factorial;
		}
		/*
		*If sum of factorials of digits> number, within range
		* if sum of factorials of digits< number,out of range
		*/
		for(counter=10;counter<2540160;counter++)
		{
			num=counter;
			sumDigit=0;
			while(num>0)
			{
				sumDigit+=digitWithFactorial[1][num%10];
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


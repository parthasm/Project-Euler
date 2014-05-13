class TestMain 
{

    public static void main(String[] args) 
	{
		System.out.println(findSumOfSpiralDiagonal(1001));

	}
	private static int findSumOfSpiralDiagonal(int squareSide) 
	{
		int sum=1,counter=1,loop;
		if(squareSide%2==0)
			return 0;
		int limit = (squareSide-1)/2,difference=0;
		int[] series = {7,3,5,9};
		for(loop=0;loop<series.length;loop++)
		{
			difference=series[loop]-1;
			counter=1;
			while(counter<=limit)
			{	
				sum+=series[loop];
				difference+=8;
				series[loop]+=difference;
				counter++;
			}
		}
		
		return sum;
	}

}

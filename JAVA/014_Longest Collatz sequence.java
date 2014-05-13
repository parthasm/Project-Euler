class Version2 
{

	public static void main(String[] args) 
	{
		int[] num = new int[999998];
		int i,counter,chain=0,longest_num=0;
		long temp;
		
		for(i=0;i<999998;i++)
		{
			temp = (long)(i+2);
			counter = 0;
			while(temp>1l)
			{
				if(temp<(long)(i+2))
				{
					counter = counter + num[(int)(temp-2l)];
					break;
				}
				
				if(temp%2l==0l)
					temp = temp/2l;
				
				else
					temp = (3l*temp)+1l;
				counter++;
			}
			
			num[i]=counter;
			
			if(chain<counter)
			{
				chain = counter;
				longest_num = i+2;
			}
		}
		System.out.println(longest_num);

	}

}

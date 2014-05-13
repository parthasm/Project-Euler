class TestMain
{
	public static void main(String[] args)
	{
		System.out.println(findSumOfDigits(100));
	}
	
	private static int findSumOfDigits(int number)
	{
		char[] fact = new char[270];
		int carry = 0;
                int i,j=fact.length-1,num,num1,sum=0;
                for(i=0;i<fact.length;i++)
                        fact[i] = '0';
                
                fact[i-1]='1';
                
                for(i=2;i<=number;i++)
                {
                        j=fact.length-1;
                        carry=0;
                        while(j>0)
                        {
                                num = (int)(fact[j]-48);
                                num1 = (i*num)+carry;
                                fact[j]=(char)((num1%10)+48);
                                carry = num1/10;     
                                j--;
        
                        }
                }
 
                for(i=0;i<fact.length;i++)
                {
                        
                        sum+=(fact[i]-48);
                }
                return sum;
	}
}
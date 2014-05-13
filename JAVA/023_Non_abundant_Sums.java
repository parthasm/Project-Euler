import java.util.HashSet;
import java.util.Set;

class TestMain 
{

	
	public static void main(String[] args) 
	{
		
		System.out.println(findSum());

	}
	private static long findSum()
	{
		long sum=0l;
		boolean flag=true;
		int counter,num=0;
		
		Set<Integer> abundantNos = new HashSet<Integer>();
		
		for(counter=12;counter<28123;counter++)
		{
			if(counter<sumOfFactors(counter))
				abundantNos.add(counter);
		}
		
		
		for(counter=1;counter<24;counter++)
			sum+=counter;
		
		for(counter=25;counter<28123;counter++)
		{
			flag=true;
			for(Integer i:abundantNos)
			{
				num = counter - i;
				if(num>0 && abundantNos.contains(num))
				{
					flag=false;
					break;
				}
			}
			if(flag)
				sum+=counter;
		}
			return sum;
	}
	/*
	Trade-off! Trade-off!
	the contains() {search function}takes O(n) (& is often better~constant) time for a set, which is great!
	but since set not ordered so can't restrict search to only numbers less than counter
	but contains() in ordered data structures take huge time.so....
	*/
	private static int sumOfFactors(int n) 
	{
		int sumF=1,f=2;
			while(f<Math.sqrt(n))
			{
				if(n%f==0)
				{
					sumF+=f;
					sumF+=(n/f);
				}
				f++;
			}
			if(f==Math.sqrt(n))
				sumF+=f;
		return sumF;
	}

}

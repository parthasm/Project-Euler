import java.util.HashMap;
import java.util.Map;
import java.util.Set;

class V1 
{

	
	public static void main(String[] args) 
	{
		//System.out.println(findSumOfFactors(36));
		System.out.println(findSum(10000));
	}
	private static long findSum(int limit)
	{
		int counter,inner;
		long sum=0l; 
		Integer j,k=null;
		Map<Integer,Integer> noAndSum = new HashMap<Integer, Integer>();
		boolean[] prime = new boolean[limit];
		for(counter=2;counter<limit;counter++)
			prime[counter]=true;
		for(counter=2;counter<limit;counter++)
		{
			if(!prime[counter])
				continue;
			for(inner=2*counter;inner<limit;inner+=counter)
				prime[inner]=false;
		}
		for(counter=2;counter<limit;counter++)
		{
			if(prime[counter])
			{
				//System.out.println(counter);
				continue;
			}
			
			noAndSum.put(counter, findSumOfFactors(counter));
		}
		for(Integer i:noAndSum.keySet())
		{
			
			j=noAndSum.get(i);
			k=noAndSum.get(j);
			if(k!=null)
			{
				if(i.equals(k) && !j.equals(k))
				{
					//System.out.println(i+" "+j+" "+k);
					sum+=i;
				}
				
			}
			//System.out.println(i+" "+j+" "+k);
		}
		//System.out.println(noAndSum.get(220));
		return sum;
	}
	private static int findSumOfFactors(int n)
	{
		int f=2,sumFactor=1;
		while(f<Math.sqrt(n))
		{
			if(n%f==0)
			{
				sumFactor+=f;
				sumFactor+=(n/f);
			}
			f++;
		}
		if(f==Math.sqrt(n))
			sumFactor+=f;
		return sumFactor;
	}

}
//V2 will be without the prime checking
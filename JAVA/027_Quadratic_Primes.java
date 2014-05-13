import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class TestMain 
{

    
	public static void main(String[] args) 
	{
		
		System.out.println(findProduct(1000));
	}
	private static long findProduct(int limit) 
	{
		long product=0l;
		
		boolean[] primeLarge = new boolean[1000000];
		boolean[] primeSmall = new boolean[1000];
		int counter,inner,a,b=3,n=0,max=1;
		
		Set<Integer> primesLarge = new HashSet<Integer>();
		List<Integer> primesSmall = new ArrayList<Integer>();
		
		//to check for primes
		for(counter=2;counter<primeLarge.length;counter++)
			primeLarge[counter]=true;
		
		for(counter=2;counter<primeLarge.length;counter++)
		{
			if(!primeLarge[counter])
				continue;
			for(inner=2*counter;inner<primeLarge.length;inner+=counter)
				primeLarge[inner]=false;
		}
		
		for(counter=2;counter<primeLarge.length;counter++)
		{
				if(primeLarge[counter])
					primesLarge.add(counter);
		}
		//to check for primes end
		
		
		//to check for b
		for(counter=2;counter<primeSmall.length;counter++)
			primeSmall[counter]=true;
		
		for(counter=2;counter<primeSmall.length;counter++)
		{
			if(!primeSmall[counter])
				continue;
			for(inner=2*counter;inner<primeSmall.length;inner+=counter)
				primeSmall[inner]=false;
		}
		
		for(counter=2;counter<primeSmall.length;counter++)
		{
				if(primeSmall[counter])
					primesSmall.add(counter);
		}
		//to check for b end
		Integer expression=0;
		for(counter=1;counter<primesSmall.size();counter++)
		{
			b = primesSmall.get(counter);
			a=999;
			a*=-1;
			for(;a<1000;a++)
			{
				n=0;
				while(true)
				{
					expression = (n*n)+a*n+b;
					if(primesLarge.contains(expression))
					{
						n++;
					}
					else
					{
						break;
					}
				}
				if(--n>max)
				{
					max=n;
					product=a*b;
				}
				
			}
		}
		return product;
	}

}

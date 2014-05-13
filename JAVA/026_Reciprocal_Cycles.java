import java.math.BigDecimal;
import java.util.*;

class TestMain 
{

    
	public static void main(String[] args) 
	{
		
		System.out.println(findNumberWithLongestCycle(1000));
	}
	private static int findNumberWithLongestCycle(int limit) 
	{
		int d=2;
		BigDecimal one = new BigDecimal(1);
		BigDecimal dBigDecimal = new BigDecimal(d);
		BigDecimal limitBigDecimal = new BigDecimal(limit);
		List<BigDecimal> recurrs = new ArrayList<BigDecimal>();
		while(dBigDecimal.compareTo(limitBigDecimal)<=0)
		{
			try
			{
				one.divide(dBigDecimal);
			}
			catch (ArithmeticException e) 
			{
				recurrs.add(dBigDecimal);
			}
			dBigDecimal = dBigDecimal.add(one);
		}
		int counter,maxLength=1,searchLength=1;
		
		d=999;
		
		StringBuilder str = new StringBuilder(500);
		StringBuilder searchString = new StringBuilder(500);
		StringBuilder compareString = new StringBuilder(500);
		for(counter=recurrs.size()-1;counter>=0;counter--)
		{
			if(str.length()!=0)
			str.delete(0, str.length());
			str.append(one.divide(recurrs.get(counter), 3100, 0).toString().substring(32));
		
			searchLength=1;
			while(searchLength<1000)
			{
				if(searchString.length()!=0)
				searchString.delete(0, searchString.length());
				searchString.append(str.substring(0, searchLength));
				
				if(compareString.length()!=0)
					compareString.delete(0, compareString.length());
				
				compareString.append(str.substring(searchLength, 2*searchLength));
		
				if(!searchString.toString().equals(compareString.toString()))
				{
					searchLength++;
					continue;
				}
				compareString.delete(0, compareString.length());
				compareString.append(str.substring(2*searchLength, 3*searchLength));
				if(!searchString.toString().equals(compareString.toString()))
				{
					searchLength++;
					continue;
				}
				if(searchLength>maxLength)
				{
					maxLength=searchLength;
					d=recurrs.get(counter).intValue();
					
				}
				break;
			}
			
			
		}
		System.out.println("Maximum Length "+maxLength);
		return d;
	}

}

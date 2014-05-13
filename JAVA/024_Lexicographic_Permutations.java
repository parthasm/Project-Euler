

import java.util.ArrayList;
import java.util.List;

class TestMain 
{

	
	public static void main(String[] args) 
	{
		List<Integer> inputChars = new ArrayList<Integer>();
		for(int counter=0;counter<10;counter++)
			inputChars.add(counter);
		
		int rank = 1000000;
		
		System.out.println(findPermutation(inputChars, rank));
		
	}
	
	private static String findPermutation(List<Integer> inputChars, int rank) 
	{
		String ranks=findRank(inputChars, rank);
		int counter,individualRank=0;
		StringBuilder finalOutput = new StringBuilder();
		for(counter=0;counter<ranks.length();counter++)
		{
			individualRank=ranks.charAt(counter)-48;
			finalOutput.append(inputChars.remove(individualRank-1));
			
		}
		return finalOutput.toString();
	}

	private static String findRank(List<Integer> inputChars,int rank)
	{
		StringBuilder ranks=new StringBuilder();
		int counter,individualRank=0,x;
		int factorial=1;
		List<Integer> factorials = new ArrayList<Integer>();
		factorials.add(1);
		for(counter=1;counter<=inputChars.size();counter++)
		{
			factorial*=counter;
			factorials.add(factorial);
		}
		
		if(rank>factorials.get(factorials.size()-1))
			return "error";
		
		for(counter=factorials.size()-2;counter>=0;counter--)
		{
			x = rank%factorials.get(counter);
			if(x>0)
			{
				individualRank=(rank/factorials.get(counter))+1;
			}
			else
			{
				individualRank=(rank/factorials.get(counter));
				ranks.append(individualRank);
				for(int inner=--counter;inner>=0;inner--)
				{
					ranks.append(inner+1);
				}
				break;
			}
			ranks.append(individualRank);
			rank=x;
			
		}
		return ranks.toString();
		
	}
}

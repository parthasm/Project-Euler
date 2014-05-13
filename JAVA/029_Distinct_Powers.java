import java.math.BigDecimal;
import java.util.HashSet;
import java.util.Set;

class TestMain 
{

    public static void main(String[] args) 
	{
		System.out.println(getNoOfTerms(2, 100));

	}
	
	private static int getNoOfTerms(int lower,int upper)
	{
		Set<BigDecimal> terms = new HashSet<BigDecimal>();
		BigDecimal term = new BigDecimal(0);
		BigDecimal base = new BigDecimal(0);
		int inner,outer;
		for(outer=lower;outer<=upper;outer++)
		{
			for(inner=lower;inner<=upper;inner++)
			{
				base = new BigDecimal(outer);
				term = base.pow(inner);
				terms.add(term);
			}
		}
		return terms.size();
	}

}

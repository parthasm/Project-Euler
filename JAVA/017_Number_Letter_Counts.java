class TestMain 
{

	
	public static void main(String[] args) 
	{
		String[] one_nineteen = {"one","two","three","four","five","six","seven",
				"eight","nine","ten","eleven","twelve","thirteen","fourteen",
				"fifteen","sixteen","seventeen","eighteen","nineteen"};
		String[] ten = {"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
		long record = 0l,record1 = 0l;
		int counter,i;
		for(counter=0;counter<one_nineteen.length;counter++)
			record+=one_nineteen[counter].length(); 	//1-19
		// 1-19, 101-119 , ...,901-919
		record*=10;
		//101-119,..,901-919
		record+=(10*9*19);//10 - length of 'hundred' & 'and'; 9 - 101 to 901;19-1 to 19 
			for(i=0;i<9;i++)
			{
				record+=(one_nineteen[i].length()*19);
				record+=(one_nineteen[i].length()+7);//100, 200, 300,..,900
			}
			// 1-19, 101-119 , ...,901-919 end:-)
			
			//20 to 99
			for(counter=0;counter<ten.length;counter++)
			{
				record1+=ten[counter].length();
				for(i=0;i<9;i++)
					record1+=(ten[counter].length()+one_nineteen[i].length());
			}
			record1*=10; // 120-199,220-299,...,920-999	
			record1+=(10*9*80);//10 - length of 'hundred' & 'and'; 9 - 120 to 920;80-20 to 99
			
			for(i=0;i<9;i++)
			{
				record1+=(one_nineteen[i].length()*80);
				
			}
			
			System.out.println(record+record1+11);
	}
	

}

class TestMain
{
        public static void main(String[] args)
        {
                System.out.println(find(2,1000));
        }       
 
        private static int find(int number,int pow)
        {       
                char[] expo = new char[334];
                int carry = 0;
                int i,j=expo.length-1,num,num1,sum=0;
                for(i=0;i<expo.length;i++)
                        expo[i] = '0';
                
                expo[i-1]='1';
                
                for(i=1;i<=pow;i++)
                {
                	j=expo.length-1;
                	carry=0;
                        while(j>0)
                        {
                                num = (int)(expo[j]-48);
                                num1 = (number*num)+carry;
                                expo[j]=(char)((num1%10)+48);
                                carry = num1/10;     
                                j--;
        
                        }
                }
 
                for(i=0;i<expo.length;i++)
                {
                	
                        sum+=(expo[i]-48);
                }
                return sum;
        }
}

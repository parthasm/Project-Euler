#include <iostream>

using namespace std;

int getDeno();
int getHCF(int num1,int num2);
int main()
{
	cout << getDeno() << endl;
	return 0;
}

int getDeno()
{
	int nume,deno,numeProduct,denoProduct,numDigitTen,numDigitOne,denoDigitTen,denoDigitOne,counter=0;
	int numers[4],denos[4];
	float temp1,temp2;
	for(nume=11;nume<100;nume++)
	{
		if(nume%10!=0)
		{
			for(deno=nume+1;deno<100;deno++)
			{
				if(deno%10!=0)
				{
					numDigitTen=nume/10;
					numDigitOne=nume%10;
					denoDigitTen=deno/10;
					denoDigitOne=deno%10;
					temp1 = ((float)nume)/deno;
					if (numDigitOne==denoDigitOne)
					{
						temp2 = ((float)numDigitTen)/denoDigitTen;
						if(temp1==temp2)
						{
							numers[counter]=nume;
							denos[counter++]=deno;
							cout << nume << "\t" << deno << "\n" << endl;
						}
					}

					if(numDigitOne==denoDigitTen)
					{
						temp2 = ((float)numDigitTen)/denoDigitOne;
						if(temp1==temp2)
						{
							numers[counter]=nume;
							denos[counter++]=deno;
							cout << nume << "\t" << deno << "\n" << endl;
						}
					}

					if(numDigitTen==denoDigitTen)
					{
						temp2 = ((float)numDigitOne)/denoDigitOne;
						if(temp1==temp2)
						{
							numers[counter]=nume;
							denos[counter++]=deno;
							cout << nume << "\t" << deno << "\n" << endl;
						}
					}

					if(numDigitTen==denoDigitOne)
					{
						temp2 = ((float)numDigitOne)/denoDigitTen;
						if(temp1==temp2)
						{
							numers[counter]=nume;
							denos[counter++]=deno;
							cout << nume << "\t" << deno << "\n" << endl;
						}
					}
				}
			}
		}
		}
	numeProduct=numers[0]*numers[1]*numers[2]*numers[3];
	denoProduct=denos[0]*denos[1]*denos[2]*denos[3];
	int hcf = getHCF(numeProduct,denoProduct);
	denoProduct=denoProduct/hcf;
	return denoProduct;
}
int getHCF(int num1,int num2)
{
	int remainder;
	if(num1==num2)
		return num1;
	if(num1<num2)
	{
		num1=num1+num2;
		num2=num1-num2;
		num1=num1-num2;
	}

	remainder=num1%num2;
	if(remainder==0)
	return num2;

	while(remainder!=0)
	{
		num1=num2;
		num2=remainder;
		remainder=num1%num2;
	}

	return num2;
}
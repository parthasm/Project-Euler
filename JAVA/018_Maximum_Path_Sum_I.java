import java.util.ArrayList;
import java.util.List;


class Version2_Graph
{
	public static void main(String[] a)
	{
		int[] numbers = {75,
				95,64,
				17,47,82,
				18,35,87,10,
				20,4,82,47,65,
				19,1,23,75,3,34,
				88,2,77,73,7,63,67,
				99,65,4,28,6,16,70,92,
				41,41,26,56,83,40,80,70,33,
				41,48,72,33,47,32,37,16,94,29,
				53,71,44,65,25,43,91,52,97,51,14,
				70,11,33,28,77,73,17,78,39,68,17,57,
				91,71,52,38,17,14,91,43,58,50,27,29,48,
				63,66,4,68,89,53,67,30,73,16,69,87,40,31,
				4,62,98,27,23,9,70,98,73,93,38,53,60,4,23};
		Version2_Graph obj = new Version2_Graph();
		Node n = obj.insertInGraph(numbers),n1=null,first=null;
		Node n2 = n,n3;
		int outer,inner,max=0;
		
		for(outer=0;outer<obj.calculateNoOfRows(numbers.length);outer++)
		{
			for(inner=0;inner<=outer;inner++)
			{
			//	System.out.print(n.getData()+"\t");
				if(inner==0)
					first = n.getLeft();
				n = n.getNext();
			}
			n = first;
			//System.out.println();
		}
		List<Integer> sums = new ArrayList<Integer>();
		sums = obj.findAllSums(n2);
		for(Integer i:sums)
		{
			if(max<i)
				max = i;
			//System.out.println("individual "+i);
		}
		System.out.println(max);
		
	}
	private Node insertInGraph(int[] numbers)
	{
		int arrIndex=0,counter=0,inner,rows=calculateNoOfRows(numbers.length);
		
		
		Node start = new Node(numbers[arrIndex]);
		Node n = start,n1=start,first=null,d,d1=null;
		
		for(;counter<(rows-1);counter++)
		{
			d=null;
			d1=null;
			for(inner=0;inner<=counter;inner++)
			{
				n=n1;
				if(inner==0)
				{
					//System.out.println("a"+arrIndex);
					arrIndex++;
					d = new Node(numbers[arrIndex]);
				}
				else
					d = d1;
				//System.out.println(d.getData());
				n.setLeft(d);
				if(inner==0)
					first=n.getLeft();
				d1 = new Node(numbers[++arrIndex]);
				n.setRight(d1);
				n.getLeft().setNext(n.getRight());
				n1 = n.getNext();
				
			}
			n1=first;
		}
		return start;
		
	}
	
	private int calculateNoOfRows(int length) 
	{
		int p = 8*length+1;
		p = (int)Math.sqrt(p);
		p--;
		p/=2;
		return p;
	}
	private List<Integer> findAllSums(Node start) 
	{
		int i;
		List<Integer> sum1=null,sum2=null,last=new ArrayList<Integer>();
		Node left = start.getLeft();
		Node right = start.getRight();
		if(left!=null && right!=null)
		{
			sum1 = findAllSums(left);
			sum2 = findAllSums(right);
		}
		else
		{
			List<Integer> x = new ArrayList<Integer>();
			
			x.add(start.getData());
			return x;
		}
			for(i=0;i<sum1.size();i++)
			{
				//System.out.print("l "+sum1.get(i));
				sum1.set(i, sum1.get(i)+start.getData());
				//System.out.println(" l "+sum1.get(i));
			}
			
			for(i=0;i<sum2.size();i++)
			{
			//	System.out.print("r "+sum2.get(i));
				sum2.set(i, sum2.get(i)+start.getData());
					
				//System.out.println("r "+sum2.get(i));
			}
			
			for(Integer t:sum1)
				last.add(t);
			for(Integer t:sum2)
				last.add(t);
		
		return last;
		
	}
public class Node 
{
	private Node left = null,right=null,next=null;
	private int data;
	
	public Node(int data) 
	{
		this.data = data;
	}

	public Node getLeft() {
		return left;
	}

	public int getData() {
		return data;
	}

	public void setLeft(Node left) {
		this.left = left;
	}

	public void setRight(Node right) {
		this.right = right;
	}

	public Node getRight() {
		return right;
	}

	public void setNext(Node next) {
		this.next = next;
	}

	public Node getNext() {
		return next;
	}
	
	
	
	
	
}

}

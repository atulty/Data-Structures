import java.util.Scanner;
public class AdjacencyList {
	
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		LinkedListHashing hashing = new LinkedListHashing();
		
		int A[] = {21,4,35,65,31,75,54,88,77,99},n,ch,key,i;
		n = A.length;
		
		for(i = 0 ; i < 10 ; i++)
	        hashing.bins[i] = null;
		
		hashing.OpenHashing_Chaining(A,n);
	    while (true)
	    {
	        System.out.println("Enter a key \n");
	        key = sc.nextInt();
	            System.out.println("\nEnter Choice\n1.To Search\n2.To Delete\n");
	            ch = sc.nextInt();
	        if(ch == 1)
	        {
	            if(hashing.search(key) != 0)
	            	System.out.println("key is found\n");
	            else
	            	System.out.println("key not found\n");
	        }
	        else
	        {
	            int res = hashing.delete(key);
	            if(res != 0)
	            	System.out.println("key "+res+" is deleted\n");
	            else
	            	System.out.println("key not found\n");
	        }
	    }
		
		
		
	}

}

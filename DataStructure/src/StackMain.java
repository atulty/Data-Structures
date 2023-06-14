import java.util.Scanner;
public class StackMain {
	private static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
    {
        
        StackUsingLL obj = new StackUsingLL();
        boolean ch = true;
        int choice;
        
        while(ch) {
        	System.out.println("\n1. PUSH ");
            System.out.println("2. POP ");
            System.out.println("3. DISPLAY STACK ");
            System.out.println("4. EXIT ");
            System.out.println("\n Enter Your Option: ");
            choice = sc.nextInt();
        	switch(choice)
        	{
        	   case 1 :System.out.println("Enter the value to be added to the stack: ");
               			int val=sc.nextInt();
               			obj.push(val);
               				break;
        	   case 2:obj.pop();
        	   			break;
        	   case 3 : obj.display();break;
        	   case 4 : ch = false;
        	   			break;
        	}
        }
}

}

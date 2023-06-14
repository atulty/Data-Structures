
import java.util.Scanner;

public class BinarySearchTreeMain {
	
	private static Scanner scanner=new Scanner(System.in);
	
	public static void main(String args[]) {
		BinarySearchTreePresentation binarySearchTreePresentation=new BinarySearchTreePresentation();
		
		while(true) {
			binarySearchTreePresentation.showMenu();
			System.out.println("Enter Choice : ");
			int choice=scanner.nextInt();
			binarySearchTreePresentation.performMenu(choice);
		}
		
	}

}

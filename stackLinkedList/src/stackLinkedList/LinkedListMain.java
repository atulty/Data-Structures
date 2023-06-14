package stackLinkedList;

import java.util.Scanner;

public class LinkedListMain {
	
	private static Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedList<>();
		
		
		while(true) {
			System.out.println("1. Push(Data)");
			System.out.println("2. Pop()");
			System.out.println("3. Display");
			System.out.println("4. Exit");
			
			int ch = scanner.nextInt();
			
			switch (ch) {
			case 1:
				System.out.println("Enter Data: ");
				int data = scanner.nextInt();
				list.push((data));
				break;
			case 2:
				list.pop();
				break;
			case 3:
				list.displayList();
				break;
			case 4:
				System.exit(0);
			default:
				break;
			}
		}
		
		
	}

}

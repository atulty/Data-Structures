import java.util.Scanner;

public class BinarySearchTreePresentation {
	
	private static Scanner scanner=new Scanner(System.in);
	
	private BinarySearchTree binarySearchTree=new BinarySearchTree();
	
	public void showMenu() {
		System.out.println("1. Add element");
		System.out.println("2. Inorder Traversal");
		System.out.println("3. Minimum element\n 4. Max element\n 5. Delete an element\n 6.Count leaf nodes \n 7. Exit");
	}
	
	public void performMenu(int choice) {
		
		int key;
		
		switch (choice) {
		case 1:
			System.out.println("Enter Element : ");
			binarySearchTree.insert(scanner.nextInt());
			System.out.println("Value Inserted");
			break;

		case 2:
			binarySearchTree.inorderTraversal();
			break;
			
		case 3 :
			System.out.println("Min element is "+binarySearchTree.findMin(binarySearchTree.root));
			break;
		case 4 :
			System.out.println("Max element is "+binarySearchTree.findMax(binarySearchTree.root));
		case 5 :System.out.println("Enter element to be deleted\n");
				key = scanner.nextInt();
				binarySearchTree.deleteKey(key);
			System.out.println("Deleted "+key);
			break;
			
		case 6 : System.out.println("Total leaf nodes are : "+binarySearchTree.getLeafCount());
				break;
			
		case 7:
			System.out.println("Thanks for using Binary Search Tree");
			System.exit(0);
			
			
		default:
			System.out.println("Invalid Choice");
		}
	}

}

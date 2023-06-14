
public class BinarySearchTree {
	
TreeNode root;
	
	public int countInternal(TreeNode node) {
		
		if(node == null) {
			return 0;
		}
		if(node .left != null || node.right != null) {
			return 1 + countInternal(node.left) + countInternal(node.right);
		}
		
		return 0;
	}
	
	public int height(TreeNode node) {
		if(node == null) {
			return 0;
		}
		
		if(node.left == null && node.right == null) {
			return 0;
		}
		
		return 1 + Math.max(height(node.right), height(node.left));
		
	}
	
	public static void main(String[] args) {
		BinarySearchTree bst = new BinarySearchTree();
		/*
		 * 		9
		 * 	   /  \
		 *    4    14
		 *   / \  /  \
		 *  3  5 12   15
		 * 
		 */
		
		TreeNode head = new TreeNode(9);
		head.left = new TreeNode(4);
		head.right = new TreeNode(14);
		head.left.left = new TreeNode(3);
		head.left.right = new TreeNode(5);
		head.right.left = new TreeNode(12);
		head.right.right = new TreeNode(15);
		bst.root = head;
		
		System.out.println("Total Internal Nodes: " + bst.countInternal(head));
		System.out.println("Height of Tree is: " + bst.height(head));
		
	}


}

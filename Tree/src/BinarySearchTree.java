
public class BinarySearchTree {
	
	class Node{
		int key;
		Node left,right;
		public Node(int key) {
			super();
			this.key = key;
		}
		
	}
	
	Node root;
	
	public void insert(int key) {
		root=insertRec(root, key);
	}
	private Node insertRec(Node root,int key) {
		//if the tree is empty
		if(root==null) {
			root=new Node(key);
			return root;
		}
		if(key<root.key)
			root.left=insertRec(root.left, key);
		else if(key>root.key)
			root.right=insertRec(root.right, key);
		
		return root;
	}
	
	public void inorderTraversal() {
		inorderRec(root);
	}
	
	//Left,root,right
	private void inorderRec(Node root) {
		if(root!=null) {
			inorderRec(root.left);
			System.out.println(root.key);
			inorderRec(root.right);
		}
	}
	
	public int findMin(Node node)
	{
	    if (node == null)
	        return Integer.MAX_VALUE;
	 
	    int res = node.key;
	    int lres = findMin(node.left);
	    int rres = findMin(node.right);
	 
	    if (lres < res)
	        res = lres;
	    if (rres < res)
	        res = rres;
	    return res;
	}
	
	public int findMax(Node node)
    {
        if (node == null)
            return Integer.MIN_VALUE;
 
        int res = node.key;
        int lres = findMax(node.left);
        int rres = findMax(node.right);
 
        if (lres > res)
            res = lres;
        if (rres > res)
            res = rres;
        return res;
    }
	
	
	void deleteKey(int key) {
		root = deleteRec(root, key);
	}
	
	 
    Node deleteRec(Node root, int key)
    {
        //Base Case
        if (root == null)
            return root;
 
        //Otherwise
        if (key < root.key)
            root.left = deleteRec(root.left, key);
        else if (key > root.key)
            root.right = deleteRec(root.right, key);
 
       
        else {
            
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;
 
            
            root.key = findMin(root.right);
 
          
            root.right = deleteRec(root.right, root.key);
        }
 
        return root;
    }
    
    int getLeafCount()  
    { 
        return getLeafCount(root); 
    } 
   
    int getLeafCount(Node node)  
    { 
        if (node == null) 
            return 0; 
        if (node.left == null && node.right == null) 
            return 1; 
        else
            return getLeafCount(node.left) + getLeafCount(node.right); 
    }

}

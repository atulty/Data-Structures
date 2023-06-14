
	
	
	public class WordFrequency {
		
		Node root;

		public void add(Node newNode, Node rootNode) {
			
			Node current = rootNode;
			
			if(this.root == null) {
				this.root = newNode; 
				return;
			}
			
			else if(current.data.compareTo(newNode.data) > 0) {
				if(current.left == null) {
					current.left = newNode;
				}
				else {
					add(newNode, current.left);
				}
			}
			
			else if(current.data.compareTo(newNode.data) < 0) {
				if(current.right == null) {
					current.right = newNode;
				}
				else {
					add(newNode, current.right);
				}
			}
			
			else if(current.data.compareTo(newNode.data) == 0) {
				current.increaseCount();
			}
		}
		
		public void inOrder(Node current) {
			if(current == null) {
				return;
			}
			
			inOrder(current.left);
			System.out.println("Data: " + current.data + " Frequency: " + current.count);
			inOrder(current.right);
		}
		
	}


	
	class Node {
		
		String data;
		int count;
		Node left;
		Node right;
		
		Node(String data) {
			
			this.data = data;
			this.count = 1;
			this.left = null;
			this.right = null;
		}
		
		public void increaseCount() {
			this.count = this.count + 1;
		}
	}

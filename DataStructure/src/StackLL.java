import static java.lang.System.exit;

public class LinkedList<T> {

	class Node {
		T data;
		Node next;
		
		public Node() {
			
		}
		
		public Node(T data) {
			super();
			this.data = data;
			this.next = null;
		}
		
	}
	
	Node head = new Node();
	
	public void push(T data) {
		Node node = new Node(data);
		
		if (head == null) {
			head.next = node;
		}
		else {
			node.next = head.next;
			head.next = node;
		}
	}
	
	public void pop() {
		if (head.next == null) {
			return;
		}
		else {
			Node tempNode = head.next;
			head.next = head.next.next;
			tempNode.next = null;
		}
		
	}
	
	public void displayList() {
		Node currentNode=head;
		while(currentNode.next != null) {
			System.out.println(currentNode.next.data);
			currentNode = currentNode.next;
		}
	}
}


public class LinkedListHashing {
	
	class Node{
		int data;
		Node next;
	//Node(){}
	
	 Node(int data){
		this.data=data;
		this.next = null;
	}
}
	
	Node first = null;
	Node[] bins = new Node[10];
	
	
	public int Index(int x){
		return x%10;
	}
	
	public void insert(int x,int idx) {
		Node temp = new Node(x),p = bins[idx];
		if(bins[idx] == null) {
			bins[idx] = temp;
		}
		else
		{
			Node q = null;
			while(p != null && x > p.data) {
				q = p;
				p = p.next;
			}
			q.next = temp;
			temp.next = p;
		}
	}
	public int search(int key) {
		int idx = Index(key);
		Node p = bins[idx];
		while(p != null && key >= p.data) {
			if(p.data == key) {
				return key;
			}
			else
				p = p.next;
		}
		return 0;
	}
	
	public int delete(int key) {
		int idx = Index(key),x = 0;
		Node p = bins[idx],q = null;
		if(bins[idx] == null)
			return x;
		else {
			while (p != null && key >= p.data)
	        {
	            q = p;
	            if(q == p && key == p.data)
	            {
	                bins[idx] = p.next;
	                x = p.data;
	            }
	            else if(key == p.data)
	            {
	                q.next = p.next;
	                x = p.data;
	                
	            }
	            p = p.next;
	        }
		}
		return x;
	}
	
	void OpenHashing_Chaining(int A[],int n)
	{
	    int i,idx;
	    for(i = 0 ; i < n ; i++)
	    {
	        idx = Index(A[i]);
	        insert(A[i],idx);
	    }
	}

}

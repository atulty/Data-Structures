
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		
		String space = " ";
		String regex = "[.,;/]";
		WordFrequency wf = new WordFrequency();
		Scanner scan = new Scanner(new File("text.txt"));
		
		while(scan.hasNext()) {
			
			String nextWord = scan.next().toLowerCase().replaceAll(regex, space).trim();
			Node node = new Node(nextWord);
			wf.add(node, wf.root);
	
		}
		
		wf.inOrder(wf.root);
	
	}
}


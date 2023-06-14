
public class HashMap {

      private final static int TABLE_SIZE = 10;

 

      LinkedHashEntry[] bins;

 

      HashMap() {

            bins = new LinkedHashEntry[TABLE_SIZE];

            for (int i = 0; i < TABLE_SIZE; i++)

                  bins[i] = null;

      }
      
      public static void main(String[] args) {
		
	}

}

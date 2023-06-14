
public class ColorDecorator {
	
	public ColorDecorator(Shape decoratedShape) {
	      super(decoratedShape);		
	   }

	   @Override
	   public void draw() {
	      decoratedShape.draw();	       
	      setRed(decoratedShape);
	   }
	   
	   //Method to set color;
	   private void setRed(Shape decoratedShape){
	      System.out.println("Color: Red");
	   }

}

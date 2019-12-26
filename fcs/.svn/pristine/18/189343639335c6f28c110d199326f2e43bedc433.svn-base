import java.util.Scanner;

class Rectangle extends Shape{
	//attributes
	private int width;
	private int height;

	//constructors
	Rectangle(){}
	Rectangle(int width, int height){
		this.width = width;
		this.height = height;
	}

	//methods
	public void display(){
		System.out.println("width: "+this.width+"\nheight: "+this.height);
	}
}

class RectangleArea extends Rectangle{
		public int n;
		public int m;

	//method
	public void read_input(){
		Scanner reader = new Scanner(System.in);  // Reading from System.in
		System.out.println("input: ");
		//try and catach for the following
		try{
			n = reader.nextInt(); // Scans the next token of the input as an int.once finished
			m = reader.nextInt();
			if (n<1||n>1000||m<1||m>1000){
				System.out.println("input value is out of boundaries!!!");
			}
		}catch(Exception e){
			System.out.println("we got an input error");
			throw e;	//if the input has a problem, the error will be presented
		}
		reader.close();
	}

	public void display(){
		System.out.println("\noutput:\n"+n+" "+m+"\n"+n*m);
	}

}

public class problem07{
	public static void main(String[] args) {
		RectangleArea ra = new RectangleArea();
		ra.read_input();
		ra.display();
	}
}

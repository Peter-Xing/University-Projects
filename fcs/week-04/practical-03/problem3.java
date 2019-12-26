import java.util.Scanner;

public class problem3{
	public static void main(String [] args){
		Scanner reader = new Scanner(System.in); 
		System.out.println("Please, insert a number: ");
		int n = 0;
		try{
			n = reader.nextInt(); // Scans the next token of the input as an int.once finished
		}catch(Exception e){
			System.out.println("the input n has error");
			throw e;	//if the input has a problem, the error will be presented
		}
		Scanner reader2 = new Scanner(System.in); 
		System.out.println("Please, insert a number: ");
		int m = 0;
		try{
			m = reader2.nextInt(); // Scans the next token of the input as an int.once finished
		}catch(Exception e){
			System.out.println("the input m has error");
			throw e;	//if the input has a problem, the error will be presented
		}
		reader.close();
		reader2.close();
	

		

		//compare the two numbers
		int result = n-m;
		if(result>0){
			System.out.println("The bigger number is "+n);
		}
		else if(result == 0){
			System.out.println("The two numbers are identical");
		}
		else {System.out.println("The bigger number is "+m);}
	}
}

import java.util.Scanner;
import java.lang.UnsupportedOperationException;

public class problem02{
	public static void main(String [] args){
		Scanner reader = new Scanner(System.in);  // Reading from System.in
		System.out.println("Please, insert a number: ");
		int n = 0;
		//try and catach for the following
		try{
			n = reader.nextInt(); // Scans the next token of the input as an int.once finished
		}catch(Exception e){
			System.out.println("we got an input error");
			throw e;	//if the input has a problem, the error will be presented
		}
		reader.close();
		

		//check if the input number is prime or not
		int a = 0;
		for(int i = 2; i < n; i++){
			int r = n%i;
			if(r == 0){
				a++;
			}
			else{
				a = a;
			}
		}

		//give the correct output
		if(a!=0 || n<=1){
			System.out.println("Your number is not prime");
		}
		else {
			System.out.println("Your number is prime");
		}
	}
}
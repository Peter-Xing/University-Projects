//==================================
// Foundations of Computer Science
// Student: Luoyang Xing    
// id: a1756195
// Semester: 2
// Year: 2018
// Practical : 04
//===================================
import java.util.Scanner;
import java.util.InputMismatchException;

class Human extends Player{

	//constructor
	Human(){}


	//method
	//use user input to get human player's choice
	public String performMove(){
		Scanner scanner = new Scanner(System.in);
    	System.out.print("type in your choice from 1(Rock),2(Paper),3(Scissors): ");
    	int mo = 0;
    	//if user does not enter 1,2 and 3, it should be an invalid input
    	try{
    		mo = scanner.nextInt();
    		if(mo != 1 && mo != 2 &&mo!= 3){
                throw new InputMismatchException();
    		}
    	}catch(Exception e){
        }

    	//use  1,2,3 to represent the choices rock, paper and scissors
    	if(mo == 1){
    		System.out.println("\nyou chose Rock");
    		return "Rock";
    	}
    	else if(mo == 2){
    		System.out.println("\nyou chose Paper");
    		return "Paper";
    	}
    	else if(mo == 3){
    		System.out.println("\nyou chose Scissors");
    		return "Scissors";
    	}
    	else{
    		return null;
    	}
	}
}

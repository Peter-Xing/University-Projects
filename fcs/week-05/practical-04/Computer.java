//==================================
// Foundations of Computer Science
// Student: Luoyang Xing	
// id: a1756195
// Semester: 2
// Year: 2018
// Practical : 04
//===================================
import java.util.Random;

class Computer extends Player{

	//constructor
	Computer(){}

	//method
	public String performMove(){
		String [] choices = {"Rock","Paper","Scissors"};
		//use random number to choose randomly from rock ppper scissors, each has 1/3 probbility
		Random rn = new Random();
		int t = rn.nextInt(3);
		System.out.println("Computer chose "+choices[t]);
		return choices[t];
	}
}
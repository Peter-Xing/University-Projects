//*********************************************
//Course: Foundations of Computer Science
//Semester: 2
//Year: 2018
//Name: Luoyang Xing
//Student ID: a1756195
//Exam: Final Practical Exam
//problem-01/BasicProgram.java
//**********************************************

import java.lang.*;


public class BasicProgram{
	//the following is the addition function of two integers
	//that will return the sum of them
	public int sum(int a, int b){
		int c = a+b;
		return c;
	}
	//the following is the division function of two integers
	//that will return the divided result
	//if b is 0, it will print out an error message and throw the error
	public double div(int a, int b){
		try{
			double c = a/b;
			return c;
		}
		catch(UnsupportedOperationException e){
			System.out.println("Not possible division by zero.");
			throw e;
		}
	}
	//the next method is to display an array
	public void displayArray(int []array){
		try{
			if(array.length == 0){
				System.out.println("No elements.");
			}
		}
		catch(UnsupportedOperationException e){
				throw e;
		}
		System.out.print("[ ");
		for (int i = 0; i < array.length-1; i++){
			System.out.print(array[i]+", ");
		}
		System.out.print(array[array.length-1]+"];\n");

	}
}
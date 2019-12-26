//==================================
// Foundations of Computer Science
// Student: Luoyang Xing
// id: a1756195
// Semester: 2
// Year: 2018
// Practical Exam Number: 02
//===================================

public class Calculator{
	public int sum(int numA, int numB){ //function sum
		int a = 0;
		a = numB + numA;
		return a;
	}

	public int sub(int numA, int numB){ //function subtraction
		int a = 0;
		a = numA - numB;
		return a;
	}

	public float multiply(float numA, float numB){//function multiplication
		float a = 0;
		a = numB*numA;
		return a;
	}

	public float division(float numA, float numB){//function division
		float a = 0;
		if(numB == 0){
			return -99;
		}
		a = numA/numB;
		return a;
	}
}
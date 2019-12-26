/*==================================
Foundations of Computer Science
Student: Luoyang Xing
id: a1756195
Semester: 2
Year: 2018
Practical Exam Number: 03
===================================*/

public class Ferrari extends Petrol{
	//constructor
	Ferrari(){
		super(5);
	}

	public void move(){
		super.power = 15;
		super.fuel = super.fuel - 3; 
		super.kms = super.kms+15;
	}

	public void reFill(){
		if(super.fuel == 55){
		}
		else{
			super.setFuel(55);
		}
	}

	public void displayTravel(){
		System.out.println("kms traveled is "+super.kms+"\nremaining fuel is" +super.fuel);
  	}
}
/*==================================
Foundations of Computer Science
Student: Luoyang Xing
id: a1756195
Semester: 2
Year: 2018
Practical Exam Number: 03
===================================*/
public class Tesla extends Electric{
	//constructor
		Tesla(){
		super(10);
	}

	public void move(){
		super.power = 10;
		super.fuel = super.fuel - 1; 
		super.kms = super.kms+10;
	}

	public void reFill(){
		if(super.fuel == 100){
		}
		else{
			super.setFuel(100);
		}
	}

	public void displayTravel(){
		System.out.println("kms traveled is "+super.kms+"\nremaining fuel is" +super.fuel);
  	}
}
/*==================================
Foundations of Computer Science
Student: Luoyang Xing
id: a1756195
Semester: 2
Year: 2018
Practical Exam Number: 03
===================================*/
public class Porche extends Petrol{
	//constructor
	Porche(){
		super(4.2F);
	}

	public void move(){
		super.power = 14;
		super.fuel = super.fuel - 14F/4.2F; 
		super.kms = super.kms+14;
	}

	public void reFill(){
		if(super.fuel == 60){
		}
		else{
			super.setFuel(60);
		}
	}

	public void displayTravel(){
		System.out.println("kms traveled is "+super.kms+"\nremaining fuel is" +super.fuel);
  	}
}
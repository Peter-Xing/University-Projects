
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



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

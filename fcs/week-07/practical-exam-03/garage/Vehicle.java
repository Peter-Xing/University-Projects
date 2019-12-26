

public abstract class Vehicle{
	//attributes
	protected float fuel; //this attribute is the amount of fuel that each vehicle can store
  	protected float kms; //this attribute is the amount of kms traveled by the vehicle during the race
  	protected float power;//this attribute is the power of the vehicle, each round the vehicle moves the number of kms in power;

  	//constructor
  	Vehicle(){
  		this.fuel = 0.0F;
  		this.kms = 0.0F;
  		this.power = 0.0F;
  	}

  	Vehicle(float fuel, float kms, float power){
  		this.fuel = fuel;
  		this.kms = 0.0F;
  		this.power = power;
  	}

  	//accessors
  	public float getFuel(){
  		return this.fuel;
  	}

  	public float getPower(){
  		return this.power;
  	}

  	public float getKms(){
  		return this.kms;
  	}

  	//mutators
  	public void setFuel(float fuel){
  		this.fuel = fuel;
  	}

  	public void setPower(float power){
  		this.power = power;
  	}

  	public void setKms(float kms){
  		this.kms = kms;
  	}


  	//methods
  	public void displayTravel(){
  
  	}
}

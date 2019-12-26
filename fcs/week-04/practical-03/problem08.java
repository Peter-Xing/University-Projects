//abstract class VehicleAbstract
abstract class VehicleAbstract{
	//attributes
	private String color;
	private int year;
	private int numberGears;
}

//interface
interface Vehicle{
	public void changeGear(double gear);
	public void checkBreak(double b);
}

//base class
class Bicycle extends VehicleAbstract{
	//attributes
	private boolean is_serviced;
	private String inDate;
	private String outDate;
	private String serviceResponsible;

	//constructor
	Bicycle(){}
	Bicycle(boolean s, String inDate, String outDate, String serviceResponsible){
		this.is_serviced = s;
		this.inDate = inDate;
		this.outDate = outDate;
		this.serviceResponsible = serviceResponsible;
	}

	//method
	public boolean checkoutService(){
		return this.is_serviced;
	}
}

//subclasses of Bicycle
class ElectricBike extends Bicycle implements Vehicle{
	//attributes
	private int battery; 

	//constructor
	ElectricBike(){}
	ElectricBike(int battery){
		this.battery = battery;
	}

	//method
	public void changeGear(double gear){
		System.out.println("the bike needs to change "+gear+" gears");
	}
	public void checkBreak(double b){
		System.out.println("the bike needs to check "+b+" breaks");
	}
	public void chargeBike(){
		System.out.println("the bike's battery is charging...");
	}
}

class MountainBike extends Bicycle implements Vehicle{
	//attributes
	private String suspension;
	private String forks;

	//methods
	public void changeGear(double gear){
		System.out.println("the bike needs to change "+gear+" gears");
	}
	public void checkBreak(double b){
		System.out.println("the bike needs to check "+b+" breaks");
	}
}

class RoadBike extends Bicycle implements Vehicle{
	//attributes
	private String tyres;

	//methods
	public void changeGear(double gear){
		System.out.println("the bike needs to change "+gear+" gears");
	}
	public void checkBreak(double b){
		System.out.println("the bike needs to check "+b+" breaks");
	}
}

class Hibrid extends Bicycle implements Vehicle{
	//attributes
	private String suspension;

	//methods
	public void changeGear(double gear){
		System.out.println("the bike needs to change "+gear+" gears");
	}
	public void checkBreak(double b){
		System.out.println("the bike needs to check "+b+" breaks");
	}
}
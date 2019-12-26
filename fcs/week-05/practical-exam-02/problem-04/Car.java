

// filename: Car.java
public class Car{
	//+ properties: 
	private String model;
	private int numGears;
	private float literTank;
	private int yearManufacture;

	//constructors
	Car(){}
	Car(String m, int n, float l, int y){
		this.model = m;
		this.numGears = n;
		this.literTank = l;
		this.yearManufacture = y;
	}

	//accessors
	public String getModel(){
		return this.model;
	}
	public String getNumbergears(){
		return this.numGears;
	}
	public String getLitertank(){
		return this.literTank;
	}
	public String getYearmanufacture(){
		return this.yearManufacture;
	}

	//mutators
	public void setModel(String m){
		this.model = m;
	}
	public void setNumbergears(int n){
		this.numGears = n;
	}
	public void setLitertank(float l){
		this.literTank = l;
	}
	public void setYearmanufacture(int y){
		this.yearManufacture = y;
	}
}

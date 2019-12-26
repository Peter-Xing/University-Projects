//==================================
// Foundations of Computer Science
// Student: Luoyang Xing
// id: a1756195
// Semester: 2
// Year: 2018
// Practical Exam Number: 02
//===================================

// filename: Cake.java
public class Cake{
	//properties: 

	private String name;
	private float qtSugar;
	private float qtFlour
	private float qtYeast;
	private double timePrepare;

	//constructors
	Cake(){}
	Cake(String name, float qtSugar, float qtFlour, float qtYeast, double timePrepare){
		this.name = name;
		this.qtSugar = qtSugar;
		this.qtFlour = qtFlour;
		this.qtYeast = qtYeast;
		this.timePrepare = timePrepare;
	}

	//accessors
	public String getName(){
		return this.name;
	}
	public float getSuger(){
		return this.qtSugar;
	}
	public float getFlo(){
		return this.qtFlour;
	}
	public float getYeast(){
		return this.qtYeast;
	}
	public double getTime(){
		return this.timePrepare;
	}

	//mutators
	public void setName(String name){
		this.name = name;
	}
	public void setSugar(float s){
		this.qtSugar = s;
	}
	public void setFlour(float f){
		this.qtFlour = f;
	}
	public void setYeast(float y){
		this.qtYeast = y;
	}
	public void setTime(double t){
		this.timePrepare = t;
	}
}


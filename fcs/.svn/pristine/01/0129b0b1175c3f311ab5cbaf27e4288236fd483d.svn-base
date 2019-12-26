class Student extends Person{ // the class student
	//attributes
	private double [] marks;
	private String [] disciplines;

	//constructors
	Student(){}

	Student(double [] m, String [] d){
		this.marks = m;
		this.disciplines = d;
	}

	//accessors
	public double [] getMarks(){
		return this.marks;
	}
	public String [] getDisciplines(){
		return this.disciplines;
	}

	//mutators
	public void setMarks(double [] m){
		this.marks = m;
	}
	public void setDisciplines(String [] d){
		this.disciplines = d;
	}

	//methods
	public double averageMarks(){
		double sum = 0;
		for (int i = 0; i < this.marks.length; i++){
			sum += this.marks[i];
		}
		double avg = sum/this.marks.length;
		return avg;
	}

	public void displayDisciplines(){
		for (int i =0; i<this.disciplines.length; i++){
			System.out.println(this.disciplines[i]);
		}
	}
}

//the class Lecturer
class Lecturer extends Person{
	//attributes
	private double salary;
	private String [] disciplines;

	//constructors
	Lecturer(){}

	Lecturer(double sa, String [] dis){
		this.salary = sa;
		this.disciplines = dis;
	}

	//accessors
	public double getSalary(){
		return this.salary;
	}
	public String [] getDisciplines(){
		return this.disciplines;
	}

	//mutators
	public void setSalary(double sa){
		this.salary = sa;
	}
	public void setDisciplines(String [] d){
		this.disciplines = d;
	}

	//methods
	public double annualSalary(){
		double a = this.salary*12;
		return a;
	}

	public void displayDisciplines(){
		for (int i =0; i<this.disciplines.length; i++){
			System.out.println(this.disciplines[i]);
		}
	}
}

//class of Doctor
class Doctor extends Person{
	//attributes
	private String speciality;

	//constructors
	Doctor(){}

	Doctor(String speciality){
		this.speciality = speciality;
	}

	//accessors
	public String getSpeciality(){
		return this.speciality;
	}

	//mutator
	public void setSpeciality(String speciality){
		this.speciality = speciality;
	}
}

//class patient
class Patient extends Person{
	//attributes
	private String diagnostic;
	private String inTime;
	private String prevTime;

	//constructors
	Patient(){}

	Patient(String diagnostic, String inTime, String prevTime){
		this.diagnostic = diagnostic;
		this.inTime = inTime;
		this.prevTime = prevTime;
	}

	//accessors
	public String getDiag(){
		return this.diagnostic;
	}
	public String getIntime(){
		return this.inTime;
	}
	public String getPrevTime(){
		return this.prevTime;
	}

	//mutators
	public void setDiagnostic(String diagnostic){
		this.diagnostic = diagnostic;
	}
	public void setInTime(String inTime){
		this.inTime = inTime;
	}
	public void setPrevTime(String prevTime){
		this.prevTime = prevTime;
	}
}

//classes of shape
//class rectangle
class Rectangle extends Shape{

	//methods
	public double area(){
		double a = super.getWidth()*super.getLength();
		return a;
	}
}

//class Circle
class Circle extends Shape{
	//constructor
	Circle(){
	super(); //call super constructor
	}

	//methods
	public double area(){
		double a = Math.PI*Math.pow(super.getRadius(),2);
		return a;
	}
}

//class Triangle
class Triangle extends Shape{

	//methods
	public double area(){
		double a = super.getWidth()*super.getHeight()*0.5;
		return a;
	}
}

//classes of Book
//class eBook
class eBook extends Book{
	//attributes
	private String url;

	//constructors
	eBook(){}

	eBook(String url){
		this.url = url;
	}

	//accessors
	public String getUrl(){
		return this.url;
	}

	//mutatos
	public void setUrl(String url){
		this.url = url;
	}
}

//class physicalBook
class physicalBook extends Book{
	//attributes
	private int shelf;
	private int ala;
	private int floor;

	//constructors
	physicalBook(){}

	physicalBook(int shelf, int ala, int floor){
		this.shelf = shelf;
		this.ala = ala;
		this.floor = floor;
	}

	//accessors
	public int getShelf(){
		return this.shelf;
	}
	public int getAla(){
		return this.ala;
	}
		public int getFloor(){
		return this.floor;
	}

	//mutators
	public void setShelf(int shelf){
		this.shelf = shelf;
	}
	public void setAla(int ala){
		this.ala = ala;
	}
	public void setFloor(int floor){
		this.floor = floor;
	}

	//method
	public void displayBookLocation(){
		System.out.println("shelf: "+this.shelf+" ala: "+this.ala+" floor: "+this.floor);
	}
}

//classes of animals
//class Lion
class Lion extends Animal{
	//method
	public void makeSound(){
		System.out.println("Rrrrrr");
	}
}

//class Turtle
class Turtle extends Animal{
	//method
	public void makeSound(){
		System.out.println("turtle's sound");
	}
}

//class Camaleon
class Camaleon extends Animal{
	//method
	public void makeSound(){
		System.out.println("Camaleon's sound");
	}
}
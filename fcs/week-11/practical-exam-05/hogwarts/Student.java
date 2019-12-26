
public class Student{
	//attributes
	private String name; //student's name
	private int age; //student's age
	private int period; //the academic year the student is currently at

	//constructors
	public Student(){ //no input, just set name to unknown and age,period to 0
		this.name = "unknown";
		this.age = 0;
		this.period = 0;
	}

	//with all the student's information, input them into a student object
	public Student(String tmpName, int tmpAge, int tmpPeriod){
		this.name = tmpName;
		this.age = tmpAge;
		this.period = tmpPeriod;
	}

	//accessors and mutators
	//get and change the name of a student
	public String getName(){
		return this.name;
	}
	public void setName(String name){
		this.name = name;
	}
	//get and change the age of a student
	public int getAge(){
		return this.age;
	}
	public void setAge(int age){
		this.age = age;
	}
	//get and change the period of a student
	public int getPeriod(){
		return this.period;
	}
	public void setPeriod(int period){
		this.period = period;
	}

}

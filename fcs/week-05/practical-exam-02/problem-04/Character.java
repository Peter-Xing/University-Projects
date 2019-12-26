//==================================
// Foundations of Computer Science
// Student: Luoyang Xing
// id: a1756195
// Semester: 2
// Year: 2018
// Practical Exam Number: 02
//===================================

public class Character{
	//attributes
	private String name;//this attribute storage the character name;
	private int age;// this attribute storage the character age;
	private String gender; // this attribute storage the character gender
	private String occupation;// this attribute storage the character occupation
	private String familyRole;// this attribute storage the family role
	private float rate;// this attribute storage the character overall rate by fans;

	//constructors
	Character(){}
	Character(String name, int age, String gender, String occupation, String familyRole,float rate){
		this.name = name;
		this.age = age;
		this.gender =gender;
		this.occupation = occupation;
		this.familyRole = familyRole;
		this.rate = rate;
	}

	//accessors
	public String getName(){
		return this.name;
	}
	public int getAge(){
		return this.age;
	}
	public String getGender(){
		return this.gender;
	}
	public String getOccupation(){
		return this.occupation;
	}
	public String getFamilyrole(){
		return this.familyRole;
	}
	public float getRate(){
		return this.rate;
	}

	//mutators
	public void setName(String name){
		this.name = name;
	}
	public void setAge(int age){
		this.age = age;
	}
	public void setGender(String gender){
		this.gender = gender;
	}
	public void setOccupaion(String occupation){
		this.occupation = occupation;
	}
	public void setFamilyrole(String familyRole){
		this.familyRole = familyRole;
	}
	public void setRate(int rate){
		this.rate = rate;
	}
}
class Person{
	//fields
	private String givenName;
	private String lastName;
	private int age;
	private String gender;
	private String citizenship;

	//basic constructor
	Person(){}

	//parametric constructor
	Person(String a, String b, int c, String d, String e){
		this.givenName = a;
		this.lastName = b;
		this.age = c;
		this.gender = d;
		this.citizenship = e;
	} 

	//accessors 
	public String getName(){
		return this.givenName;
	}
	public String getName2(){
		return this.lastName;
	}
	public int getAge(){
		return this.age;
	}
	public String getGender(){
		return this.gender;
	}
	public String getCitizenship(){
		return this.citizenship;
	}

	//mutators
	public void setName(String a){
		this.givenName = a;
	}
	public void setName2(String b){
		this.lastName = b;
	}
	public void setAge(int c){
		this.age = c;
	}
	public void setGender(String d){
		this.gender = d;
	}
	public void setCitizenship(String e){
		this.citizenship = e;
	}
}
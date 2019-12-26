//*********************************************
//Course: Foundations of Computer Science
//Semester: 2
//Year: 2018
//Name: Luoyang Xing
//Student ID: a1756195
//Exam: Final Practical Exam
//problem-03/PersonAbstract.java
//**********************************************
public abstract​​ class PersonAbstract implements Personable{
	protected int age;
	protected String name;
	protected String address;
	public abstract​​ void display();

	public abstract​​ void setAge( int _age);
	public abstract​​ void setName(String _name);
	public abstract​​ void setAddress(String _address);
	public abstract​​ int getAge();
	public abstract​​ String getName();
	public abstract​​ String getAddress();
}
//Note: your file ​ PersonAbstract​​ .java will be replaced with the testing
//script. Therefore, don’t add other code to this file.


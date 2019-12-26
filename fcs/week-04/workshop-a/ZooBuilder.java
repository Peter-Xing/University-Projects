import java.util.ArrayList;

class Animal {
	private String name;
	public int age;
	public String favoritefood;

	public String getName(){
		return this.name;
	}

	public void setName(String tName){
		this.name = tName;
	}
}

class Panda extends Animal{
	public void playing(){
		System.out.println("Panda is playing with friends");
	}
}

class Elephant extends Animal{
	public void eating(){
		System.out.println("Elephant is eating");
	}
}

class Lion extends Animal{
	public void hunt(){
		System.out.println("Lion is hunting");
	}
}

public class ZooBuilder {
	public static void main(String[] args){
		Panda p1 = new Panda();
		p1.setName("panda one");
		p1.age = 5;
		p1.favoritefood = "bamboo";

		Elephant e1 = new Elephant();
		e1.setName("Elephant a");
		e1.age = 11;
		e1.favoritefood = "banana";

		Lion lo1 = new Lion();
		lo1.setName("lion one");
		lo1.age = 15;
		lo1.favoritefood = "you";

		System.out.println(p1.getName());
		System.out.println(e1.getName());
		System.out.println(lo1.getName());

	}
}

public class Node{
	//attributes
	private Student info;//contains student information
	private Node next; //linked to next node

	//constructors
	Node(){//when there is no input, set info and next to null
		this.info = null;
		this.next = null;
	}
	//input the student information to the current node's info
	Node(Student tmpStudent){
		this.info = tmpStudent;
		this.next = null;
	}

	//accessors and mutators
	//get and change the information of a node
	public Student getInfo(){
		return this.info;
	}
	public void setInfo(Student tmpStudent){
		this.info = tmpStudent;
	}
	//get and change the next node of a current node
	public Node getNext(){
		return this.next;
	}
	public void setNext(Node next){
		this.next = next;
	}

}

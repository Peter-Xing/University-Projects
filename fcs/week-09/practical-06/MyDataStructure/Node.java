public class Node{
	//attributes
	private String data; //the data saved in the node
	private Node next; // reference to the next node

	//constructors
	public Node(){
		this.data = null;
		this.next = null;
	}

	public Node(String data){
		this.data = data;
		this.next = null;
	}

	public Node(String data, Node next){
		this.data = data;
		this.next = next;
	}

	//accessors
	public String getData(){
		return this.data;
	}

	public Node getNext(){
		return this.next;
	}

	//mutators
	public void setData(String data){
		this.data = data;
	}

	public void setNext(Node next){
		this.next = next;
	}

	//methods
	//print the data saved in the node
	public void printNode(){
		System.out.println("Node data: "+"\""+ this.data + "\"");
	}

}
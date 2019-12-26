//Course: Foundation of Computer Science
//Semester: 2018 Semester 2
//Name: Luoyang Xing
//ID: a1756195
//exam: practical exam-05
public class Queue{
	//attributes
	//back is the last node of the queue
	private Node back;


	//constructors
	Queue(){
		this.back = null;

	}

	//accessors and mutators
	//get and change the back node of the queue
	public Node getBack(){
		return this.back;
	}
	public void setBack(Node back){
		this.back = back;
	}

	//methods
	public void enqueue(Student tmpStudent){
		if (back == null){
			//if the queue is empty, insert student info in back node
			back = new Node(tmpStudent);
		}
		else{
			//else, insert the student info in the back's next node
			back = back.getNext();
			back.setInfo(tmpStudent);
		}
	}

	public void dequeue(){
		//when the queue is empty
		if(back == null){
			System.out.println("the queue is empty");
		}
		//when the queue has only one node in it
		else if(back.getNext() == null){
			back = null;
		}
		//when the queue has greater than or equal to two nodes
		else{
			back = back.getNext();
			
		}
	}

	public void displayQueue(){
		//display the nodes in the queue in first in first out order
		Node n = back;
		while(n != null){
			Student s = n.getInfo();
			System.out.println(s.getName()+", "+s.getAge()+" years old, "+s.getPeriod()+" year in Hogwarts;");
			n = n.getNext();
		}
		
	}


}
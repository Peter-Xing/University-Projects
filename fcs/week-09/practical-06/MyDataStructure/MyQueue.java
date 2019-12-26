public class MyQueue{
	//Attributes:
	private Node front, rear; // The reference to the first and last node in this queue

	

	//Methods:
	// initialise the an empty queue in the constructor.
	public MyQueue(){
		this.front = new Node();
		this.rear = new Node();
	}

	// Insert one node at the end of the queue.
	// 2 situations: queue is empty; queue has at least one node.
	public void enqueue(Node node){
		//when there is no node in the queue, front and rear are both the 1st node entered
		if(isEmpty()){ 
			front = node;
			rear = node;
			front.setNext(rear);
		}
		// more than one node entered
		else{
			rear.setNext(node);
			rear = node;
		}
	}

	// Get and remove the front node from the queue. 
	// Return Null and print "Queue is empty" when the queue is empty
	public String dequeue(){
		if(isEmpty()){
			System.out.println("Queue is empty");
			return null;
		}
		//when there is only one node, set the data to null after dequeue
		else if(front.getNext() == null){
			String tmp = front.getData();
			front.setData(null);
			return tmp;
		}
		//when there are at least two nodes, set the front to the next node
		else{
			String tmp = front.getData();
			front = front.getNext();
			return tmp;
		}
	}

	// Return TRUE when the queue is empty, otherwise, return FALSE.
	public boolean isEmpty(){
		if(front.getData() == null){
			return true;
		}
		else{
			return false;	
		}
	}

	// Print out the data saved in nodes from the first to the last. 
	// Return and print "Queue is empty" when the queue is empty
	// You should call printNode() to print each node in this method.
	public void displayQueue(){
		if(isEmpty()){
			System.out.println("Queue is empty");
		}else{
			Node p = front;
			while (p != null) {
				p.printNode();
				p = p.getNext();
			}
		}  

	}
	
}


public class MyStack{
	//attributes
	private Node top;//the reference to the top node in the stack

	//constructor
	public MyStack(){
		this.top = new Node();
	}

	//methods
	//push a node into a stack
	public void push(Node node){
		if(isEmpty()){
			top = node;
		}else{
			node.setNext(this.top);
			top = node;
		}

	}

	// Get and remove the top node from this stack.
	// Return Null and print "Stack is empty" when the stack is empty.
	public Node pop(){
		if(isEmpty()){
			System.out.println("Stack is empty");
			return null;
		}
		else if(top.getNext() == null){
			Node tmp = this.top;
			top = new Node();
			return tmp;
		}
		else{
			Node tmp = this.top;
			this.top = this.top.getNext();
			return tmp;
		}

	}

	// Get the top node in this stack. 
	// Return Null and print "Stack is empty" when the stack is empty.
	public Node peek(){
		if(this.isEmpty() == true){
			System.out.println("Stack is empty");
			return null;
		}
		else{
			return this.top;
		}
	} 

	// Return TRUE when the stack is empty, otherwise, return FALSE.
	public boolean isEmpty(){
		if(top.getData() == null){
			return true;
		}else{
			return false;	
		}
	}

}
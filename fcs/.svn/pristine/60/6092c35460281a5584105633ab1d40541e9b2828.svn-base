public class Main{

	public static boolean bracketsMatching(String input){
		return false;
	}

	public static MyQueue reverseQueue(MyQueue queue){
		MyQueue result = new MyQueue();
		MyStack stack = new MyStack();
		//put the nodes in the queue in reverse order in a stack
		while (queue.isEmpty() == false) {
			String a = queue.dequeue();
			Node a1 = new Node(a);
			stack.push(a1);
		}
		//then put the nodes from the stack into a queue
		while (stack.isEmpty() == false) {
			Node b = stack.pop();
			result.enqueue(b);
		}
		return result;
	}

	public static void main(String[] args) {
		Node n = new Node("alpha");
		Node n1 = new Node("beta");
		Node n2 = new Node("cigma");
		Node n3 = new Node("delta");
		Node n4 = new Node("epsilon");
		Node n5 = new Node("theta");
		Node n6 = new Node("omega");
		
		MyQueue a = new MyQueue();
		MyQueue rev = new MyQueue();
		a.enqueue(n);
		a.enqueue(n1);
		a.enqueue(n2);
		a.enqueue(n3);
		a.enqueue(n4);
		a.enqueue(n5);
		a.enqueue(n6); 
		
		a.dequeue();
		a.dequeue();
		System.out.println("\nfollowing is the queue: ---------------------------------------   ");
		a.displayQueue();
		
		rev = reverseQueue(a);
		System.out.println("\nfollowing is the reversed queue: ------------------------------   ");
		rev.displayQueue();
	}
}
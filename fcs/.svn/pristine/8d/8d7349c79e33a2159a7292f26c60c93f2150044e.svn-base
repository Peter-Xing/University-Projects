public class MyBST{
	//Attributes:
	private Node root; // The reference to the root node in this tree

	//Methods:
	// You should initialise an empty tree in the constructor.
	public MyBST(){
		this.root = null;
	}

	// Insert a new value into the tree. This method calls insertRec()
	public void insert(int value){
		if (root == null){
			root = insertRec(root, value);
		}else if(value < root.getData()){
			root.setLeft(insertRec(root.getLeft(),value));
		}else if(value > root.getData()){
			root.setRight(insertRec(root.getRight(),value));
		}else{
			System.out.println("Node is in the tree");
		}
	}

	// This is a recursive function to insert a new value in the tree.
	private Node insertRec(Node current, int value){
		//empty tree, just insert in the root
		if(current == null){
			current = new Node(value);
			return current;
		}
		//if value is less than current data, recurse to the left
		else if(value < current.getData()){
		
			return insertRec(current.getLeft(), value);
		}
		//if value is already in the tree, print node in the tree
		else if (value == current.getData()){
			System.out.println("Node is in the tree");
			return null;
		}
		//if value is larger than current data, recurse to the right
		else if(value > current.getData()){
	
			return insertRec(current.getRight(), value);
		}
		return null;
	}

	// Search a node in the tree. This method calls searchRec()
	public boolean search(int value){
		return searchRec(root, value);
	}

	// This is a recursive function to search a node in the tree.
	private boolean searchRec(Node current, int value){
		//if the current node is null, the value is not in the tree
		if(current == null){
			System.out.println("value is not in the tree");
			return false;
		}
		//if current node's data is equal to value, means value found
		else if (current.getData() == value){
			System.out.println("value is found");
			return true;
		}
		//if the value is less than the current data, recurse to the left node
		else if(value < current.getData()){
			return this.searchRec(current.getLeft(), value);
		}
		//if the value is greater than the current data, recurse to the right node
		else{
			return this.searchRec(current.getRight(), value);
		}

	}
} 


public class Main{
	
	public static void main(String[] args) {
		MyBST a = new MyBST();
		a.insert(20);
		a.insert(10);
		a.insert(15);
		a.insert(26);
		a.insert(22);
		a.insert(1);

		a.search(20);
		a.search(22);
		a.search(15);
		a.search(1);
		a.search(26);
		a.search(10);
		//a.search(100);


	}
}
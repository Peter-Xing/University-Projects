public class BaseOperations{
	//the following three functions are all printArray with different inputs
	public static void printArray(int [] array){
		System.out.print("[");
		for (int i = 0; i<array.length-1; i++){
			System.out.print(array[i]+",");
		}
		System.out.println(array[array.length-1]+"]");
	}

	public static void printArray(String [] array){
		System.out.print("[");
		for (int i = 0; i<array.length-1; i++){
			System.out.print(array[i]+",");
		}
		System.out.println(array[array.length-1]+"]");
	}

	public static void printArray(Float [] array){
		System.out.print("[");
		for (int i = 0; i<array.length-1; i++){
			System.out.print(array[i]+",");
		}
		System.out.println(array[array.length-1]+"]");
	}

	//the following three funcitons are all reverse functions with different inputs
	public static int [] reverseArray(int [] array){
		int [] a = new int [array.length];
		for(int i = 0; i<array.length; i++){
			a[i] = array[array.length-1-i];
		}
		return a;
	}

	public static String [] reverseArray(String [] array){
		String [] a = new String [array.length];
		for(int i = 0; i<array.length; i++){
			a[i] = array[array.length-1-i];
		}
		return a;
	}

	public static Float [] reverseArray(Float [] array){
		Float [] a = new Float [array.length];
		for(int i = 0; i<array.length; i++){
			a[i] = array[array.length-1-i];
		}
		return a;
	}

	// the following is main function with some test cases
	public static void main (String args []){
		int [] a = {1,2,3,4};
		String [] b = {"pe","sa","st","Lo"};
		Float [] c = {1.2f,2.6f,3.3f,4.5f};
		printArray(a);
		printArray(b);
		printArray(c);
		int [] r = reverseArray(a);
		printArray(r);
		String [] w = reverseArray(b);
		printArray(w);
		Float [] p = reverseArray(c);
		printArray(p);
	}

}

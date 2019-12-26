//*********************************************
//Course: Foundations of Computer Science
//Semester: 2
//Year: 2018
//Name: Luoyang Xing
//Student ID: a1756195
//Exam: Final Practical Exam
//problem-04/DataStructure.java
//**********************************************
public class DataStructure implements Structurable{

	//sort method
	public int [] sort(int [] array){
		try{
			if(array.length == 0){
				System.out.println("No elements.");
			}
		}
		catch(UnsupportedOperationException e){
			throw e;
		}
		int [] a = array;
		int c = 0;
		for(int i = 1; i<a.length; i++){
			for(int j = 0; j<i; j++)
			while (a[i]>a[j]) {
				c = a[j];
				a[j] = a[i];
				a[i] = c;
			}
		}
		return a;
	}

	//search method
	//returns the index of the search value
	public int search(String [] array, String value){
		try{
			if(array.length == 0){
				System.out.println("No elements.");
			}
		}
		catch(UnsupportedOperationException e){
			throw e;
		}
		int n = 0;
		for(int i = 0; i<array.length; i++){
			if(array[i] == value){
				n = i;
			}
			else{
				return -99;
			}
		}
		return n;
	}

}
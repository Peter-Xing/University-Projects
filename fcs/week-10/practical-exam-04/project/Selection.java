/*
*   Foundations of Computer Science
*   2018, Semester 01
*   Practical-Exam-04
*
*   student (id): a111111
*   student (name): John Smitth
*
* Note: in order to finish your exam you need to make changes in this class
* Problem 03
*/
public class Selection extends Sort{

	@Override
	public int [] sortIntByIndex(int [] arr){
		int [] index = this.getIndex(arr.length);

		for(int i = 1; i < arr.length; i++){
			int key = arr[i];
			int keyIndex = index[i];
			int j = i - 1;
			
			if(arr[j] > key){
					arr[j+1] = arr[j];
					index[j+1] = index[j];
					j--;
				}
			arr[j+1] = key;
			index[j+1] = keyIndex;
		}
		return index;
	}

	@Override
	public int [] sortInt(int [] arr){
		throw new java.lang.UnsupportedOperationException("Not implemented yet!");
	}


	@Override
	public int [] sortStringByIndex(String [] arr){
		throw new java.lang.UnsupportedOperationException("Not implemented yet!");
	}

	@Override
	public String [] sortString(String [] arr){
		throw new java.lang.UnsupportedOperationException("Not implemented yet!");
	}
}

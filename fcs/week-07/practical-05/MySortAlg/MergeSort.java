
public class MergeSort extends MySortAlg{
	//merge sort in descending order
	//@override
	public int[] sort(int[] array){
		int n = array.length-1;	//position of last element
		sorting(array, 0, n);
		//this.printArray(array);
		return array;

	}

	private void sorting(int[] array,int low, int high){
		//while there are multiple elements in an array
		if(low < high){			
			//middle position of an array	
			int middle = low + (high-low) / 2; 
			//split the array into two arrays
			sorting(array, low, middle);	   
			sorting(array, middle+1, high);
			//use a merge function to sort elements and combine arrays
			merge(array, low, middle, high);
		}else{}	
	}

	private void merge(int[] array, int low, int middle, int high){
	int[] helper = new int[array.length];
	for (int i = low; i <= high; i++) {
		helper[i] = array[i];	//helper is the copy of input array
	}
	
	int i = low;	//position of the begining of first array
	int j = middle+1; //position of the begining of second array
	int index = low;//position of the original array
	
	while (i <= middle && j <=high) {
		if(helper[i] <= helper[j]){
			array[index] = helper[j];//put element in helper back to array
			j++;					//move to the next element in the right array
			//this.printArray(array);
		}else{
			array[index] = helper[i];	//put element in helper back to array
			i++;						//move to the next element in the left array
			//this.printArray(array);		
		}
		index ++;						//move to the next position in the original array
	}
	
	//if one array is longer than the other, copy the rest of the array back to the original array
	while (i<=middle){			
		array[index] = helper[i];
		index++;
		i++;
	}

	while (j<=high) {
		array[index] = helper[j];
		index++;
		j++;
	}
}
}





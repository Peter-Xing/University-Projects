
public class Main{
	//test if the sorting algorithm is correct
	private static boolean test(int[] result, int[] ans){
		for(int i = 0; i<ans.length;i++){
			if(result[i] != ans[i]){
				return false;
			}
		}
		return true;
	}
	//compare if two arrays contain same set of elements
	private static boolean compare(int[] arr1, int[] arr2){
		InsertionSort a = new InsertionSort();
		int [] ar = a.sort(arr1);
		int [] ar2 = a.sort(arr2);
		for(int i = 0; i<ar.length;i++){
			if(ar[i] != ar2[i]){
				return false;
			}
		}
		return true;
	}
	//get the smallest sum of two elements in an array
	private static int findSmallestSum(int[] array){
		InsertionSort a = new InsertionSort();
		int [] ar = a.sort(array);
		int sum = ar[ar.length-1]+ar[ar.length-2];
		return sum;
	}

	public static void main(String[] args) {
		//create three instances of the algorithms
		//and the original array and its sorted form
		InsertionSort a = new InsertionSort();
		MergeSort b = new MergeSort();
		QuickSort q = new QuickSort();
		int [] arr = {1,2,6,9,15,26};
		int [] ans = {26,15,9,6,2,1};
		int [] arr2 = {1,6,2,26,9,15};
		//create 3 results of different sorting algorithms
		int [] result = a.sort(arr);
		int [] result1 = b.sort(arr);
		int [] result2 = q.sort(arr);
		//print the results of testing the algorithms
		System.out.println(test(result, ans)+" "+test(result1, ans)+" "+test(result2, ans)); 
		System.out.println(compare(arr,arr2));
		System.out.println("smallest sum is "+findSmallestSum(arr2));
	}
}

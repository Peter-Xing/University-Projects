
public class HandlingArrays {

    public static void printArray(double [] testArray) { //use print to print the array
          System.out.print("printing Array: [");
          for (int i = 0; i<testArray.length-1; i++){
          	System.out.print(testArray[i]+",");
          }
          System.out.print(testArray[testArray.length-1]+"]\n");
    }

    public static double[] sumElements(double [] firstArray, double [] secondArray) { // add each element of the two arrays
    	if(firstArray.length == secondArray.length){
    		for(int i = 0; i<firstArray.length; i++){
    			firstArray[i] = firstArray[i]+secondArray[i];
    		}
    		return firstArray; 
    	}
    	else{System.out.print("Error - Arrays different shape.\n");	
    	}
    	return firstArray;   
    }

    public static double[] reverseArray(double [] testArray) { // create an array that has reverse partition of the testArray
    	double [] x = new double [testArray.length];
        for (int i = 0; i<testArray.length; i++){
        	x[i] = testArray[testArray.length-1-i];
        }
        return x;
    }

}

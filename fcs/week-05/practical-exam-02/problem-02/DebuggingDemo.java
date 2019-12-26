
public class DebuggingDemo {
	/*the bugmethod created an integer array with 4 elements, but tried to 
	print out a 6th element in the array. so in order for this to work, I changed
	it to the last element of the array, which is num[3]
	*/
    public void bugMethod() {
         int num[] = {1, 2, 3, 4};
         System.out.println(num[3]);
     }

     /*the bugmethod2 didn't synchronize the data type of all input and output
     so I add F in the end of 0.0 to make ans float. And the return type is also
     changed to float
     */
    public float bugMethod2() {
            float ans = 0.0F;
            System.out.println("This method had a bug!");
            return ans;
     }
}

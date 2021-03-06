
public class Factorial{
	//the method returns the factorial of x
	public int find(int x){
		
		//base case 1
		if(x == 0){
			return 1;
		}
		//base case 2
		else if(x == 1){
			return 1;
		}
		//recursion case
		else if(x > 1){
			return x*find(x-1);
		}
		//error case
		else{
			try{
				if(x < 0){
					System.out.println("Not defined.");
				}
			}catch (UnsupportedOperationException e){
			
				throw e;
			}
			return -99;
		}
	}
}

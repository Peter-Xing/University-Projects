public class ATM{
	public static String run(int n){
		String result = "."; 
		if (n%50 == 0){       		// the case when cash is multiples of 50
			int Y = n/50;
			int X = 0;
			result = "Here is "+X+" $20 notes and "+Y+" $50 notes.";
		}

		else if(n%20 == 0){			// the case when cash is multiples of 20 but not 50
			if(n/100 == 0){
				int X = n/20;
				int Y = 0;
				result = "Here is "+X+" $20 notes and "+Y+" $50 notes.";
			}

			else{					// the case when cash is multiples of 50 and 20
				int Y = n/50;
				int X = (n - 50*Y)/20;
				result = "Here is "+X+" $20 notes and "+Y+" $50 notes.";
			}
			
		}

		else {						// the case when cash is not multiples of 50 nor 20
			result = "Sorry, the value you input cannot be withdrawed.";
		}
		return result;
	}

	public static void main(String[] args) {	// testing cases here
		System.out.println(run(60));
		System.out.println(run(100));
		System.out.println(run(120));
	}
}
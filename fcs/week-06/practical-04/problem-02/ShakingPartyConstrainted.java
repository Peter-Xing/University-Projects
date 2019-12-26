//==================================
// Foundations of Computer Science
// Student: Luoyang Xing
// id: a1756195
// Semester: 2
// Year: 2018
// Practical Number: 04 part 2
//===================================
public class ShakingPartyConstrainted extends ShakingParty{
	//attributes
	private int nCouples;

	//constructors
	ShakingPartyConstrainted(){
		int x = (int)(Math.random()*20)+1;
		this.nCouples = x;

	}

	ShakingPartyConstrainted(int nTmp){
		super(nTmp);
		this.nCouples = nTmp;
	}

	//method 
	public int countHandShakes(){
		if (this.nCouples<=1){ //use n people to do self recursion to know total hand shakes
			return 0;
		}
		else{
			this.nCouples -=1;
			return this.nCouples+countHandShakes();

		}
		// also we can use return super.countHandShakes(); to use parent class method to do the same thing
	}
}
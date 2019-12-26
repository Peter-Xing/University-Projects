//==================================
// Foundations of Computer Science
// Student: Luoyang Xing
// id: a1756195
// Semester: 2
// Year: 2018
// Practical Number: 04 part 2
//===================================
public class ShakingParty{
	//attributes
	private int nPeople;

	//constructor
	ShakingParty(){
		this.nPeople = (int)(Math.random()*20)+1;
	}

	ShakingParty(int nTmp){
		this.nPeople = nTmp;
	}

	//method
	public int countHandShakes(){
		if (this.nPeople<=1){ //use n people to do self recursion to know total hand shakes
			return 0;
		}
		else{
			this.nPeople -=1;
			return this.nPeople+countHandShakes();

		}
	}
}
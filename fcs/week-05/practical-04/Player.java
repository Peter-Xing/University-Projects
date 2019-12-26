//==================================
// Foundations of Computer Science
// Student: Luoyang Xing	
// id: a1756195
// Semester: 2
// Year: 2018
// Practical : 04
//===================================
class Player{
	//attribute
	private String move;

	//constructors
	Player(){}
	Player(String move){
		this.move = move;
	}

	//accessor
	public String getMove(){
		return this.move;
	}

	//mutator
	public void setMove(String move){
		this.move = move;
	}

	//method
	public String performMove(){
		return this.move;
	}
}
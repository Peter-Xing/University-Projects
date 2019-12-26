//==================================
// Foundations of Computer Science
// Student: Luoyang Xing	
// id: a1756195
// Semester: 2
// Year: 2018
// Practical : 04
//===================================
class Main{
	public static void main(String[] args) {
		//get human player and computer's choices and use them in referee class
		//to decide who wins 
		Human h = new Human();
		Computer c = new Computer();
		Referee r = new Referee();
		String h1 = h.performMove();
		String c1 = c.performMove();
		System.out.println("the answer is----------------"+r.decide(c1,h1));
	}
}
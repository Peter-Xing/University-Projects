//==================================
// Foundations of Computer Science
// Student: Luoyang Xing
// id: a1756195
// Semester: 2
// Year: 2018
// Practical Number: 04 part 2
//===================================
public class HanoiTower{
	//attributes
	private	int [] p1;
	private int [] p2;
	private int [] p3;

	//constructors, initialize the number of disks
	HanoiTower(int [] p1, int [] p2, int [] p3){
		this.p1 = p1;
		this.p2 = p2;
		this.p3 = p3;
	}

	HanoiTower(int dTmp){
	}

	public void solve(){
		for(int i = 0; i<3; i++){
			this.p2[2-i] = this.p1[i];
			this.p1[i] = 0; 
		}
		for (int j = 0; j<3; j++){
			this.p3[2-j] = this.p2[j];
		}
	
	}

}
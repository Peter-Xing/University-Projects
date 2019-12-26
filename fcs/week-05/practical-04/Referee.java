
class Referee{
	//attributes
	private String cin;
	private String hin;

	//the decide method takes two input values, which are both players' choices
	//and decide which player wins
	public String decide(String cin, String hin){
		if (cin == "Rock"){
			if(hin == "Rock"){
				return "~equal round~";
			}
			else if(hin == "Paper"){
				return "Player wins!!!";
			}
			else if(hin == "Scissors"){
				return "Computer wins!";
			}
			else{
				return "Invalid player input!";
			}	
		}
		else if (cin == "Paper"){
			if(hin == "Rock"){
				return "Computer wins!";
			}
			else if(hin == "Paper"){
				return "~equal round~";
			}
			else if(hin == "Scissors"){
				return "Player wins!";
			}
			else{
				return "Invalid player input!";
			}	
		}
		else{
			if(hin == "Rock"){
				return "Player wins!";
			}
			else if(hin == "Paper"){
				return "Computer wins!";
			}
			else if(hin == "Scissors"){
				return "~equal round~";
			}
			else{
				return "Invalid player input!";
			}	
		}
	}
	
}

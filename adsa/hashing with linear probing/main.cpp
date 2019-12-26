
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

//return the index number of slot of a key
//we change a to z into integer numbers 0 to 25
int slotnum(string key){
	char k = key.back();
	int index = (int)k - 97;
	return index;
}

//return false not found, return true if found
bool search(string key, int index, vector<string> v, vector<string> v2){
	if (v[index] == "never used")//never used, so not in table
	{
		return false;
	}else if (v[index] == "occupied" && v2[index] == key)
	{
		return true;
	}else if ((v[index] == "occupied" && v2[index] != key) || v[index] == "tombstone")
	{	//if it is occupied by other keys, the objective key may be in other slot
		int next = (index + 1)%26; 
		return search(key, next, v, v2);
	}else{
		return false;
	}
}


int main(int argc, char const *argv[])
{
	//initialize a vector of slots and a vector of status
	std::vector<string> status(26);
	std::vector<string> htable(26);
	for (size_t i = 0; i < status.size(); ++i)
	{
		status[i] = "never used";
	}
	for (size_t j = 0; j < htable.size(); ++j)
	{
		htable[j] = "E";
	}

	//add all the modification moves into a vector
	//where v[0] is the first move in string format
	vector<string> v;
	string str;
	getline(cin, str);
	string delimiter = " ";
	size_t pos = 0;
	string token;
	while ((pos = str.find(delimiter)) != string::npos) {
		token = str.substr(0, pos);
   		v.push_back(token);
    	str.erase(0, pos + delimiter.length());
		}
		v.push_back(str);

	//loop the vector to make changes
	for (size_t i = 0; i < v.size(); ++i)
	{
	/* if it starts with A, D,
	do different moves, split A,D and the remaining of the string,
	then use Insert function or Delete function  */
		string Head;//let it be the first letter of the move
		string word;//let it be the rest of string of the move
		Head = v[i].at(0);
		word = v[i].substr(1);

		//if it is a insert move
		if (Head == "A")
		{
			int x = slotnum(word);
			if (search(word, x, status, htable) == false)
			{
				while(status[x] == "occupied"){
					x = (x + 1)%26;
				}
				//now x is the index number in htable not occupied
				if (status[x] ==  "never used"|| status[x] == "tombstone")
				{
					htable[x] = word;
					status[x] = "occupied";
				}
			}
		}else if(Head == "D")
		{	//y is the index of word in htable
			int y = slotnum(word);
			//if found, delete it and change status to tombstone
			if (search(word, y, status, htable) == true){
				while(htable[y] != word){
					y = (y+1)%26;
				}
				//now y is the index with the object word
				status[y] = "tombstone";
				htable[y] = "E";
			}
		}	
	}
	//print out the hash table
	for (size_t i = 0; i < status.size(); ++i)
	{
		if (htable[i] != "E")
		{
			cout<<htable[i]<<" ";
		}		
	}
	return 0;
}


//accepts 3 input text files att, query and acc
//output aa
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

int main(int argc, char *argv[])
{
	fstream inFile;
	string line;
	//input att
	inFile.open(argv[1]);

	//create two vectors storing label and name of attributes
	vector<string> lab;
	vector<string> na;
	while(getline(inFile, line))
	{
		istringstream iss(line);
		string x, y;
		iss>>x>>y;
		lab.push_back(x);
		na.push_back(y);	
	}
	inFile.close(); 


	//input query
	inFile.open(argv[2]);
	//query vector q with q[i-1] equals to query i
	vector<string> que;
	while(getline(inFile, line))
	{
		que.push_back(line);
	}
	inFile.close();


	//input acc
	inFile.open(argv[3]);
	//get the length of string to know the number of columns in the acc matrix
	getline(inFile, line);

	int c = 1;
	for (int i = 0; i < line.length(); ++i)
	{
		if (line[i] == ' ' && line[i+1]=='S')
		{
			c = c+1;
		}
		else{c = c+0;}
	}
	//so c is the number of columns 
	//make a vector of string containing each element row by row in the acc matrix
	vector<string> col;
	string delimiter = " ";
	while(getline(inFile, line))
	{
		size_t pos = 0;
		string token;
		while ((pos = line.find(delimiter)) != string::npos) {
   		token = line.substr(0, pos);
   		col.push_back(token);
    	line.erase(0, pos + delimiter.length());
		}
		col.push_back(line);
	}
	inFile.close();

	//make it a vector of integer acc
	vector<int> acc;
	for (int ii = 0; ii < que.size(); ++ii)
	{
		for (int i = 1; i < c; ++i)
		{
			int a = stoi(col[i+ii*c]);
			acc.push_back(a);
		}
	}



	//now we have lab and na vectors containing attribute label and name,
	//que vector containing one query per element
	//and col vector having all elements in acc matrix
	//So, first we need to obtain the attribute usage matrix through query and att
	vector<int> usage; //usage is the usage vector
	int len = na.size(); //len -1 is the number of attributes
	int num = que.size();// num is the number of queries

	for(int i = 0; i < num; ++i){
		for (int j = 1; j < len; ++j)
		{
			size_t posi = que[i].find(na[j]);
			int l = na[j].size();
			string q = que[i];
			if(posi != string::npos && (q[posi-1] < 'A' || q[posi-1] > 'Z'))
			{
				
				usage.push_back(1);
				
				
			}
			else
			{
				usage.push_back(0);
			}
		}
	}



	//now we use formula to calculate affinity measure at each position
	vector<int> aa;
	double result;
	double result1;
	int result2;

	//AA matrix
	for (int i = 1; i < len; ++i)
	{
		for (int j = 1; j < len; ++j)
		{	
			//next is each affinity measure
			//the dividend part
			//sum k
			int use;
			int use2;
			int divi = 0;

			for (int k = 1; k <= num; ++k)
			{
				//Aik
				int sum = 0;

				use = usage[(len-1)*(k-1)+i-1];//either 0 or 1
				if (use == 0)
				{
					sum = 0;
				}
				else
				{
					int s1 = 0;
					for (int m = 1; m <= c-1; ++m)
					{
						s1 = acc[(k-1)*(c-1)+m-1];
						sum = sum + s1;
					}
				}

				//Ajk
				int sum2 = 0;
				use2 = usage[(len-1)*(k-1)+(j-1)];//either 0 or 1
				if (use2 == 0)
				{
					sum2 = 0;
				}
				else
				{
					int s2 = 0;
					for (int m = 1; m <= c-1; ++m)
					{
						s2 = acc[(k-1)*(c-1)+m-1];
						sum2 = sum2 + s2;
					}
				}
			
				int res = sum * sum2;
				divi = divi + res;

			}

		
			//divi is the dividend
			//next is the divisor part
			int res1 = 0;
			int res2 = 0;
			int u;
			int u2;
			//sum Aik
			for (int k = 1; k <= num; ++k)
			{
				int total = 0;
				u = usage[(len-1)*(k-1)+(i-1)];
				if (u == 0)
				{
					total = 0;
				}
				else
				{
					for (int m = 1; m <= c-1; ++m)
					{
						int s3 = acc[(k-1)*(c-1)+m-1];
						total = total + s3;
					}
				}
				res1 = res1 + total;
			}

			//sum Ajk
			for (int k = 1; k <= num; ++k)
			{
				int total2 = 0;
				u2 = usage[(len-1)*(k-1)+(j-1)];
				if (u2 == 0)
				{
					total2 = 0;
				}
				else
				{
					for (int m = 1; m <= c-1; ++m)
					{
						int s = acc[(k-1)*(c-1)+m-1];
						total2 = total2 + s;
					}
				}
				res2 = res2 + total2;


			}
			
			//multiplication of sum Aik and sum Ajk
			int resu = res1 * res2;
			//sqrt of multiplication
			result = sqrt(resu);
			//then we obthain the final result of aff(Ai,Aj)
			if (divi == 0)
			{				
				aa.push_back(0);
			}
			else
			{
			result1 = divi/result;
			//rounding
			result2 = ceil(result1);
			aa.push_back(result2);
			}

						
		}
	}
	
	//output the aa matrix
	for (int ii = 0; ii < len-1; ++ii)
	{
		for (int i = 0; i < len-1; ++i)
		{
			cout<<aa[i+ii*(len-1)]<<" ";
		}
		cout<<endl;
	}
	


	return 0;
}



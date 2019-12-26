

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	fstream inFile;
	string line;
	//input file 1 packets info
	inFile.open(argv[1]);

	//create 7 vectors storing every attribute of packet info
	vector<string> sa;
	vector<string> sp;
	vector<string> da;
	vector<string> dp;
	vector<string> ptc;
	vector<string> time;
	vector<string> pktleng;
	//delete the first line
	getline(inFile,line);
	while(getline(inFile, line))
	{
		istringstream iss(line);
		string a, b, c, d, e, f, g;
		iss>>a>>b>>c>>d>>e>>f>>g;
		sa.push_back(a);
		sp.push_back(b);
		da.push_back(c);
		dp.push_back(d);
		ptc.push_back(e);
		time.push_back(f);
		pktleng.push_back(g);	
	}
	inFile.close(); 

	//input file2
	inFile.open(argv[2]);
	vector<string> k;
	vector<string> init;
	getline(inFile, line);
	k.push_back(line);

	string delimiter = " ";
	while(getline(inFile, line))
	{
		size_t pos = 0;
		string token;
		while ((pos = line.find(delimiter)) != string::npos) {
   		token = line.substr(0, pos);
   		init.push_back(token);
    	line.erase(0, pos + delimiter.length());
		}
		init.push_back(line);
	}
	inFile.close(); 

	//creating flow.txt
	//comparing from index 0 to n - 2
	vector<float> avgtime;
	vector<float> avglength;
	vector<int> arrival;
	vector<int> leng;
	vector<int> used_index;

	for (size_t i = 0; i < sa.size(); ++i)
	{
		if (std::find(used_index.begin(), used_index.end(), i) != used_index.end())
		{//index already used, do nothing
		}
		else
		{	//index not found in used_index
			//put i th time and length into vectors
			int ti = stoi(time[i]);
			int le = stoi(pktleng[i]);
			arrival.push_back(ti);
			leng.push_back(le);

			for (size_t j = i+1; j < sa.size(); ++j)
			{
				if (sa[i]==sa[j] && sp[i]==sp[j]
					&& da[i]==da[j] && dp[i]==dp[j] && ptc[i]==ptc[j])
				{
					int ti = stoi(time[j]);
					int le = stoi(pktleng[j]);
					arrival.push_back(ti);
					leng.push_back(le);
					//mark the already used index
					int ind = static_cast<int>(j);
					used_index.push_back(ind);
				}
			}

			//now arrival and leng have 1 or more elements
			// if more than 1 element, we can see it as a flow
			if (arrival.size() > 1)
			{
				float total = 0;
				float total2 = 0;
				for (size_t i = 0; i < arrival.size() - 1; ++i)
				{
					total = arrival[i+1] - arrival[i] + total;
				}
				for (size_t i = 0; i < leng.size(); ++i)
				{
					total2 = leng[i] + total2;
				}
				float result;
				float result2;
				//result is avg time, result2 is avg pkt length
				result = total/(arrival.size() - 1);
				result2 = total2/leng.size();
			
				avgtime.push_back(result);
				avglength.push_back(result2);
				
			}

			//clear the vecotrs arrival and leng
			arrival.clear();
			leng.clear();
		}
		
	}



	//output flow 
	vector<int> v;
	for (size_t i = 0; i < avglength.size(); ++i)
	{
		v.push_back(i);
	}
	ofstream fout;//cout
 	fout.open ("Flow.txt");
 	for (size_t i = 0; i < avgtime.size(); ++i)
 	{
 		fout<<v[i]<<" ";
 		fout<<fixed<< setprecision(2)<<avgtime[i]<<" ";
 		fout<<fixed<< setprecision(2)<<avglength[i]<<endl;
 		
 	}
 	fout.close();




 	//initial medoid, stored in vector of string init convert to vector of int
 	vector<int> imed;
 	for (size_t i = 0; i < init.size()-1; ++i)
 	{	
 		int nu = std::stoi(init[i]);
 		imed.push_back(nu);
 	}

 	//cluster is an array of vectors of medoids and their objects
 	std::vector<int> cluster[imed.size()];


 	double E = 0;
 	bool change = true;
 	while(change == true){
 		change = false;
 		//STEP 2
 		//put imed medoids into cluster
 		for (size_t i = 0; i < imed.size(); ++i)
 		{
 			cluster[i].push_back(imed[i]);
 		}

 		//get absolute error, assign each data point to the closet initial medoid first
 		double sum = 0;//sum is initial medoids' absolute error E
 	
 		for (size_t i = 0; i < v.size(); ++i)//index 0 to 36
 		{
 			//if object is not an initial medoid, calculate mahanttan distance
 			//of it with every medoid and assign to the smallest distance medoid 
 			if (std::find(imed.begin(), imed.end(), i) != imed.end())
 			{
 			//initial medoid, do nothing, need to use non-medoid to get distance
 			}
 			else{
 				//loop to the non-medoid
 				//get distance with every medoid in vector imed
 				std::vector<double> rdist;
 				for (size_t j = 0; j < imed.size(); ++j)
 				{
 					double dif1, dif2, s;
 					double a = avgtime[imed[j]];
 					double b = avglength[imed[j]];
 					double c = avgtime[i];
 					double d = avglength[i];
 					if (a>c)
 					{
 						dif1 = a - c;
 					}else{
 						dif1 = c - a;
 					}
 					if (b>d)
 					{
	 					dif2 = b - d;
	 				}else{
 						dif2 = d - b;
 					}
 					s = dif1 + dif2;//manhanttan distance 
 					rdist.push_back(s);
 				}
 				//find the minimum distance from rdist, assign medoid, clear the rdist vector
 				double least = rdist[0];
	 			for (size_t i = 0; i < rdist.size(); ++i)
	 			{
 					if (rdist[i] < least)
 					{
 						least = rdist[i];
 					}
 				}
 				sum = sum + least;
 				int ind; //it is the index of least in rdist which is index 0 to 11 in imed
 				std::vector<double>::iterator itr = std::find(rdist.begin(), rdist.end(), least);
 				if (itr != rdist.end())
 				{
 					ind = std::distance(rdist.begin(), itr);
 				}
 				//put i th index into cloest medoid's vector
 				cluster[ind].push_back(v[i]);
 				rdist.clear();

 			}
 		}

 		//STEP 3
 		//swapping step
 		// non-medoid h from 0 to n-1 , when loop, skip current medoid id
 		// medoid i from 0 to k-1 

 		for (size_t h = 0; h < v.size(); ++h)
 		{
 			if (std::find(imed.begin(), imed.end(), h) != imed.end())
 			{
 			//h is a medoid, do nothing
 			}
 			else
 			{
 				for (size_t i = 0; i < imed.size(); ++i)
 				{
 					//calculate new E use new medoid list, if it is less than original E
 					//do the replacement
 					double sumtemp = 0;
 					int temp = imed[i];
 					imed[i] = v[h];

 					for (size_t j = 0; j < v.size(); ++j)
 					{ 
 					if (std::find(imed.begin(), imed.end(), j) != imed.end())
 					{
 					}
 					else
 					{
 						std::vector<double> dt;
 						for (size_t x = 0; x < imed.size(); ++x)
 						{
 							double dif3, dif4, s2;
 							double a2 = avgtime[imed[x]];
 							double b2 = avglength[imed[x]];
 							double c2 = avgtime[j];
 							double d2 = avglength[j];
 							if (a2>c2)
 							{
 								dif3 = a2 - c2;
 							}else{
 								dif3 = c2 - a2;
 							}
 							if (b2>d2)
 							{
	 							dif4 = b2 - d2;
	 						}else{
 								dif4 = d2 - b2;
 							}
 							s2 = dif3 + dif4;//manhanttan distance 
 							dt.push_back(s2);
 						}
 						//find the minimum distance from rdist, assign medoid, clear the rdist vector
 						double least2 = dt[0];
	 					for (size_t i = 0; i < dt.size(); ++i)
	 					{
 							if (dt[i] < least2)
 							{
 								least2 = dt[i];
 							}
 						}
 						sumtemp = sumtemp + least2;
 						dt.clear();
 					}
 					}

 					if (sumtemp < sum)
 					{
 						change = true;
 						break;
 					}
 					else
 					{
 						imed[i] = temp;
 						change = false;
 					}
 					//if replacement is necessary, replace i by h, update imed vector, 
 					//clear cluster cluster.clear() goto build-step , use 2 break. 
 					// while change is true, do E and cluster again
 				}	
 			}
 			//if change is made, set change to true, break.
 			//to get new E and re-assign objects to new medoids
 			if (change)
 			{
 				for (size_t i = 0; i < imed.size(); ++i)
 				{
 					cluster[i].clear();
 				}
 				break;
 			}
 		}

 		E = sum;
 	}


 	//sort each cluster in order from small to large
 	for (size_t i = 0; i < imed.size(); ++i)
 	{
 		sort(cluster[i].begin(), cluster[i].end());
 	}


 	//out put Kmedoid.txt
 	ofstream fout1;//cout
 	fout1.open ("KMedoidsClusters.txt");
 	fout1<<fixed<< setprecision(2)<<E<<endl;
 	for (int i = 0; i < imed.size(); ++i)
 	{
 		fout1<<imed[i]<<" ";
 	}
 	fout1<<endl;
 	for (size_t i = 0; i < imed.size(); ++i)
 	{
 		for (int j = 0; j < cluster[i].size(); ++j)
 		{
 			fout1<<cluster[i][j]<<" ";
 		}
 		fout1<<endl;
 	}
 	fout1.close();


	return 0;
}


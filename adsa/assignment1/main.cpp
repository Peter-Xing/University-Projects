#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


//school method of addition
	vector<int> add(vector<int> v1, vector<int> v2, int B){
		vector<int> s; //sum vector
		int c = 0;	//initial carry = 0 

		if (v1.size() == v2.size()) // with equal size, add from index 0 to n-1
		{
			for (int i = v1.size()-1 ; i>=0; --i) 
			{
				int sum = v1[i]+v2[i]+c;
				if (sum >= B) 
				{
					sum = sum - B;
					c = 1;
				}
				else{
					c = 0;
				}
				s.push_back(sum);
			}
		}
	
		else if (v1.size() < v2.size()) //when the v1 has less digits
		{
			int dif = v2.size()-v1.size(); 
			for (int i = v2.size()-1 ; i>=0; --i) 
			{
				if (i - dif >= 0)	//when v1 still has digits
				{
					int sum = v1[i-dif]+v2[i]+c;
					if (sum >= B) 
					{
						sum = sum - B;
						c = 1;
					}
					else{
						c = 0;
					}
					s.push_back(sum);
				}
				else{ //when v1 has no digits left
					int sum = v2[i]+c;
					if (sum >= B) 
					{
						sum = sum - B;
						c = 1;
					}
					else{
						c = 0;
					}
					s.push_back(sum);
				}
			
			}
		}
		else //when the v2 has less digits
		{
			for (int i = v1.size()-1 ; i>=0; --i) 
			{
				int dif = v1.size()-v2.size();
				if (i - dif >= 0)	//when v2 still has digits
				{
					int sum = v1[i]+v2[i-dif]+c;
					if (sum >= B) 
					{
						sum = sum - B;
						c = 1;
					}
					else{
						c = 0;
					}
					s.push_back(sum);
				}
				else{	//when v2 has no digits left
					int sum = v1[i]+c;
					if (sum >= B) 
					{
						sum = sum - B;
						c = 1;
					}
					else{
						c = 0;
					}
					s.push_back(sum);
				}
			
			}
		}
	
		//in the end, if there is a carry = 1, we need to add 1 in the sum vector
		if (c==1) 
		{
			s.push_back(c);
		}

		//need to reverse sum vector
		reverse(s.begin(), s.end());
		return s;
	}

	//school method of Subtraction with no negative situation
	vector<int> sub(vector<int> v1, vector<int> v2, int B){
		vector<int> r; 
		int c = 0;
		int res = 0;


		if (v1.size() == v2.size()) // with equal size, add from index 0 to n-1
		{
			for (int i = v1.size()-1 ; i>=0; --i) 
			{
				if (v1[i] >= v2[i] && c == 0)
				{
					res = v1[i] - c - v2[i];
					c = 0;
				}
				else 
				{
					res = v1[i]+B-c-v2[i];
					c = 1;
				}
			
				r.push_back(res);
			}
		}
	
		else if(v1.size() > v2.size())
		{
			for (int i = v1.size()-1 ; i>=0; --i) 
			{
				int dif = v1.size()-v2.size();
				if (i - dif >= 0)	//when v2 still has digits
				{
					if (v1[i]>=v2[i-dif] && c ==0)
					{
						res = v1[i] - c - v2[i-dif];
						c = 0;
					}
					else
					{
						res = v1[i]+B-c-v2[i-dif];
						c = 1;
					}	
			
					r.push_back(res);
				}
				else{	//when v2 has no digits left
					if (v1[i] >= c ) 
					{
						res = v1[i] - c;
						c = 0;
					}
					else{
						res = v1[i]+B-c;
						c = 1;
					}
					r.push_back(res);
				}
			
			}
		}

		//get rid of the leading 0s
		for (size_t i = 0; i < r.size(); ++i)
		{
			if (r[r.size()-1-i] == 0)
			{
				r.pop_back();
			}
			else{
				break;
			}
		}

		//need to reverse res vector
		reverse(r.begin(), r.end());
		return r;
	}


	//karatsuba algorithm of multiplication
	vector<int> mult(vector<int> a, vector<int> b, int B)
	{
		//define product vector
		vector<int> pr;
		vector<int> pr1;
		vector<int> p;
		vector<int> p0;
		vector<int> p1;
		vector<int> p2;
		vector<int> result;
		vector<int> result1;
		int carry = 0;

		//divide a and b into a1, a0, b1, b0
		if (a.size() > b.size())
		{
		//add 0s in the fromt of b vector
			int dif = a.size() - b.size();
			reverse(b.begin(), b.end());
			for (int i = 0; i < dif; ++i)
			{
				b.push_back(0);
			}
			reverse(b.begin(), b.end());
		}
		else if(a.size() < b.size())
		{
		//add 0s in front of a vector
			int dif = b.size() - a.size();
			reverse(a.begin(), a.end());
			for (int i = 0; i < dif; ++i)
			{
				a.push_back(0);
			}				
			reverse(a.begin(), a.end());
		}

		int k = a.size()/2; //floor
		if (k >= 1 && a.size()%2==1)	
		{

			//split a into a1 and a0
			vector<int> a1(a.begin(), a.begin()+k+1); //begin is inclusive, last one not inclusive 
			vector<int> a0(a.begin()+k+1, a.end());
			//split b into b1 and b0
			vector<int> b1(b.begin(), b.begin()+k+1); //begin is inclusive, lbst one not inclusive 
			vector<int> b0(b.begin()+k+1, b.end());
			//compute the three products recursively
			p2 = mult(a1,b1,B);
			p0 = mult(a0,b0,B);
			p1 = mult(add(a1,a0,B),add(b1,b0,B),B);
			//get the final rsult 
			//p = p2*B^(2*k)+[p1-(p2+p0)]*B^k+p0 using fuctions
			result1 = sub(p1,add(p2,p0,B),B);
			//get p2*B^2k
			for (int i = 0; i < 2*k; ++i)
			{
				p2.push_back(0);
			}
			//get [p1-(p2+p0)]*B^k
			for (int j = 0; j < k; ++j)
			{
				result1.push_back(0);
			}
			//check if any of the three parts is equal to 0
			int total = 0;
			int total2 = 0;
			int total3 = 0;
			for (size_t i = 0; i < p0.size(); ++i)
			{
				total = total + p0[i];
			}
			for (size_t i = 0; i < p2.size(); ++i)
			{
				total2 = total2 + p2[i];
			}
			for (size_t i = 0; i < result1.size(); ++i)
			{
				total3 = total3 + result1[i];
			}
			//adding the non-zero parts 
			if (total == 0 && total2 != 0 && total3 != 0)
			{
				pr = add(p2,result1,B);
				return pr;
			}
			else if (total != 0 && total2 == 0 && total3 != 0)
			{
				pr = add(result1,p0,B);
				return pr;
			}
			else if (total != 0 && total2 != 0 && total3 == 0)
			{
				pr = add(p2,p0,B);
				return pr;
			}
			else if (total == 0 && total2 == 0 && total3 != 0)
			{
				return result1;
			}
			else if (total == 0 && total2 != 0 && total3 == 0)
			{
				return p2;
			}
			else if (total != 0 && total2 == 0 && total3 == 0)
			{
				return p0;
			}
			else if (total != 0 && total2 != 0 && total3 != 0)
			{
				
				pr1 = add(add(p2,result1,B),p0,B);
				return pr1;
			}
			else{
				pr.push_back(0);
				return pr;
			}
		}

		else if(k>=1 && a.size()%2==0)
		{
			//split a into a1 and a0
			vector<int> a1(a.begin(), a.begin()+k); //begin is inclusive, last one not inclusive 
			vector<int> a0(a.begin()+k, a.end());
			//split b into b1 and b0
			vector<int> b1(b.begin(), b.begin()+k); //begin is inclusive, lbst one not inclusive 
			vector<int> b0(b.begin()+k, b.end());
			//compute the three products recursively
			p2 = mult(a1,b1,B);
			p0 = mult(a0,b0,B);
			p1 = mult(add(a1,a0,B),add(b1,b0,B),B);
			//get the final rsult
			//p = p2*B^(2*k)+[p1-(p2+p0)]*B^k+p0
			result = add(p2,p0,B);
			result1 = sub(p1,result,B);
			//get p2*B^2k
			for (int i = 0; i < 2*k; ++i)
			{
				p2.push_back(0);
			}
			//get [p1-(p2+p0)]*B^k
			for (int j = 0; j < k; ++j)
			{
				result1.push_back(0);
			}
			//check if any of the three parts is equal to 0
			int total = 0;
			int total2 = 0;
			int total3 = 0;
			for (size_t i = 0; i < p0.size(); ++i)
			{
				total = total + p0[i];
			}
			for (size_t i = 0; i < p2.size(); ++i)
			{
				total2 = total2 + p2[i];
			}
			for (size_t i = 0; i < result1.size(); ++i)
			{
				total3 = total3 + result1[i];
			}
			//adding the non-zero parts 
			if (total == 0 && total2 != 0 && total3 != 0)
			{
				pr = add(p2,result1,B);
				return pr;
			}
			else if (total != 0 && total2 == 0 && total3 != 0)
			{
				pr = add(result1,p0,B);
				return pr;
			}
			else if (total != 0 && total2 != 0 && total3 == 0)
			{
				pr = add(p2,p0,B);
				return pr;
			}
			else if (total == 0 && total2 == 0 && total3 != 0)
			{
				return result1;
			}
			else if (total == 0 && total2 != 0 && total3 == 0)
			{
				return p2;
			}
			else if (total != 0 && total2 == 0 && total3 == 0)
			{
				return p0;
			}
			else if (total != 0 && total2 != 0 && total3 != 0)
			{
				pr = add(p2,result1,B);
				pr1 = add(pr,p0,B);
				return pr1;
			}
		}

		else if (k == 0)
		{
		//when k = 0, a and b are both 1-digit number
			int product = a[0]*b[0];
			if (product >= B)
			{
				carry = product/B;
				product = product%B;
				p.push_back(carry);
				p.push_back(product);
				return p;
			}
			else if (product!=0)
			{
				carry = 0;
				p.push_back(product);
				return p;
			}
			else if(product == 0)
			{
				p.push_back(0);
				return p;
			}
		}
		
			return p;
	}
	
	


int main(){
	string x, y; //numbers are stored as string of digits
	int B;		//base is an integer
	cin>>x;
	cin>>y;
	cin>>B;

	vector<int> v1;
	for (size_t i = 0; i < x.size(); ++i){  //convert two numbers to vectors
		v1.push_back(x[i] - '0');			//of int digits
	}
	vector<int> v2;
	for (size_t ii = 0; ii < y.size(); ++ii){
		v2.push_back(y[ii] - '0');
	}

	vector<int> addresult;
	addresult = add(v1,v2,B);

	vector<int> subtra;
	subtra = sub(v1,v2,B);

	vector<int> mul;
	mul = mult(v1,v2,B);

	//output the sum and product
	for (size_t i = 0; i < addresult.size(); ++i)
	{
		cout<<addresult[i];
	}
	cout<<" ";
	for (size_t q = 0; q < mul.size(); ++q)
	{
		cout<<mul[q];
	}
	cout<<endl;


	return 0;
}
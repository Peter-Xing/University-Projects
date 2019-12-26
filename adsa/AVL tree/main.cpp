
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

//define class node
class Node{
public:
	int e; //the element in the node
	int height;// the height of this node
	Node *left; //pointer to the left child node
	Node *right;//pointer to the right child node
};

//create new node function that uses a given element
//and set left and right pointers NULL
Node *createN(int e){
	Node *node = new Node(); 
	node->e = e;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

//height function
int getH(Node *N){
	if (N == NULL)
	{
		return 0;
	}else{
		return N->height;
	}
}

//Balance function
int Balance(Node *N){
	if (N == NULL){
		return 0;  
	}  
	int dif;
	dif = getH(N->left) - getH(N->right);
    return dif;  
}

//right rotate 
Node *rRotate(Node *z){
	//set the x and z pointers
	Node *y = z->left;
	z->left = y->right;
	y->right = z;  
 
    //update heights
    z->height = max(getH(z->left), getH(z->right)) + 1;  
    y->height = max(getH(y->left), getH(y->right)) + 1;  
    //return new root
    return y;
}

//left rotate
Node *lRotate(Node *z)  
{  
    Node *y = z->right;  
    z->right = y->left;  
    y->left = z;  
  
    // Update heights  
    z->height = max(getH(z->left), getH(z->right)) + 1;  
    y->height = max(getH(y->left), getH(y->right)) + 1;  
  
    // Return new root  
    return y;  
}  

//left right rotate
Node *lrRotate(Node *z)  
{  
    z->left = lRotate(z->left);
  
    // Return new root
    return rRotate(z);  
} 

//right left rotate
Node *rlRotate(Node *z)  
{  
    z->right = rRotate(z->right);
  
    // Return new root
    return lRotate(z);  
} 

//return the node with largest element value
//in the tree. so the left child is the 
//input node pointer, we need to recurse to 
//its right child as far as possible
Node *largestValue(Node* node){
	Node *temp = node;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

//Insert function
Node* Insert(Node* node, int e){
	//insert the first node as root
    if (node == NULL){
    	return(createN(e)); 
    }  
    //go to the left or right child and do recursion
    if (e < node->e){
    	 node->left = Insert(node->left, e);  
    } else if (e > node->e){
    	node->right = Insert(node->right, e);  
    }   
    //if it exists in the tree, do not insert, just return it
    else{
        return node;  
    }

    //update the height 
    node->height = 1 + max(getH(node->left), getH(node->right));  

    //get the balance of the node to see if it is unbalanced
    int b = Balance(node);

    //4 unbalanced cases
    if (b > 1) 
    {	//left left case
    	if (e < node->left->e)
    	{
    		return rRotate(node);
    	}
    	// Left Right Case  
    	else if (e > node->left->e)
    	{
        	return lrRotate(node);
    	}
    	
    }
    else if (b < -1) 
    {	//right right case
    	if (e > node->right->e)
    	{
    		return lRotate(node); 
    	}
    	// Right Left Case 
    	else if (e < node->right->e)
    	{  
        	return rlRotate(node);  
    	}	 
    } 
    //return node pointer
    return node; 
}


//Delete function
Node *Delete(Node *node2, int e){
	//if it is an empty tree return the empty tree
	if (node2 == NULL)
	{
		return node2;
	}

	//if e is smaller, recurse in the left child of node2
	if (e < node2->e)
	{
		node2->left = Delete(node2->left, e);
	}
	//if e is greater, recurse in the right child of node2
	else if (e > node2->e)
	{
		node2->right = Delete(node2->right, e);
	}
	//if e is equal to the node2's e, delete it
	else{
		//node with no child
		if ((node2->left == NULL) && (node2->right == NULL))
		{
			node2 = NULL;
		}
		//node with one child
		else if((node2->left != NULL) && (node2->right == NULL)){
			Node *tem = node2->left;
			*node2 = *tem;
			free(tem);
		}else if ((node2->left == NULL) && (node2->right != NULL))
		{
			Node *temp = node2->right;
			*node2 = *temp;
			free(temp);
		}
		else if ((node2->left != NULL) && (node2->right != NULL))
		{
			//node with two children
			//need to find the largest number in its left tree
			Node* tem = largestValue(node2->left);
			//copy the largest value smaller than e to e's node
			node2->e = tem->e;
			//delete the node with previous copied value, do recursion
			node2->left = Delete(node2->left,tem->e);
		}
		
	}
	//after deletion, if it is null return node2
	if (node2 == NULL){
		return node2;	 	
	 }  

	//update heights 
	node2->height = 1 + max(getH(node2->left), getH(node2->right));

	//get balance to see if it needs rebalancing
	int b = Balance(node2);

	//there are 4 unbalanced cases

	if (b > 1)
	{	//left left case
		if (Balance(node2->left) >= 0)
		{
			return rRotate(node2);
		}
		else
		{
			//left right case
			return lrRotate(node2);
		}
		
	}else if (b < -1)
	{
		// Right Right Case
		if (Balance(node2->right) <= 0)
		{
			return lRotate(node2);  
		}
		else{        
    		// Right Left Case    
        	return rlRotate(node2);
		}
	}
    return node2;  
}


//following is three print method
//pre order print
void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->e << " ";  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
   
}  

//post order print
void postOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        postOrder(root->left);  
        postOrder(root->right); 
        cout << root->e << " ";   
    } 
   
}  

//In order print
void inOrder(Node *root)  
{  
    if(root != NULL)  
    {  
    	inOrder(root->left);
        cout << root->e << " ";  
        inOrder(root->right);  
    }  
   
}  

//main function
int main(int argc, char *argv[])
{
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

	//initialize the empty AVL tree
	Node *AVL = NULL;

	//loop the vector to make changes
	for (size_t i = 0; i < v.size()-1; ++i)
	{
	/* if it starts with A, D, or(POST, IN, PRE)
	do different moves, split A,D and the remaining
	of the string, convert the remaining into integer.
	then use Insert function, Delete function or Finishing function */

		string Head;//let it be the first letter of the move
		string num;//let it be the rest of string of the move
		Head = v[i].at(0);
		num = v[i].substr(1);

		//if it is a insert move
		if (Head == "A")
		{
			int n = stoi(num);
			AVL = Insert(AVL, n);
		}
		// a delete move
		else if (Head == "D")
		{
			int n = stoi(num);
			AVL = Delete(AVL, n);
		}
	}
	//if the AVL is empty just print out empty, 
 	//else print according to the finishing string
	int last = v.size()-1;
	if (AVL == NULL)
	{
		cout<<"EMPTY";
	}else if (v[last] == "POST")
	{
		postOrder(AVL);
	}
	else if (v[last] == "PRE")
	{
		preOrder(AVL);
	}
	else if (v[last] == "IN")
	{
		inOrder(AVL);
	}

	return 0;
}

#ifndef BINARYSEARCHT_H
#define BINARYSEARCHT_H

#include <string>
#include <iostream>
using namespace std ;

class TreeNode
{  
public:
	string name ;
	TreeNode *ptrLeft, *ptrRight ;

	TreeNode() ;
	TreeNode(string a) ;
} ;
			
typedef TreeNode* TreeNodeptr ;

class BinarySearchT
{
private:
	TreeNodeptr root ;

public:	
	BinarySearchT() ;
	~BinarySearchT() ;  
	BinarySearchT(const BinarySearchT & obj);
	void Insert (string a) ;
	bool Find (string a) ;
	int Height () ;
	int Size ();
	string Traverse ();

private:	
	// Recursive Functions
	// These recursive functions require the functions' arguments to be references to the pointer
	// The reason is that these functions want to change the pointer, i.e., where it points to.
	void Del (TreeNodeptr& ptr); 
	void CopyNode (const TreeNodeptr & ptr) ;
	void RInsert (string a, TreeNodeptr& ptr) ;
	bool RFind (string a, TreeNodeptr& ptr) ;
	int RHeight (TreeNodeptr& ptr) ;
	int RSize (TreeNodeptr& ptr) ;
	string RTraverse (TreeNodeptr ptr) ;
} ;
#endif

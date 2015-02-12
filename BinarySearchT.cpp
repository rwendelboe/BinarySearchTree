#include "BinarySearchT.h"

TreeNode::TreeNode()
{
	ptrLeft = NULL ;
	ptrRight = NULL ;
}

TreeNode::TreeNode(string a)
{
	name = a ;
	ptrLeft = NULL ;
	ptrRight = NULL ;
}

BinarySearchT::BinarySearchT()
{
	root = NULL ;
}

BinarySearchT::~BinarySearchT()
{	
	Del(root);
}

void BinarySearchT::Del (TreeNodeptr& ptr)
{
	if (ptr->ptrLeft != NULL)	
	{	
		Del(ptr->ptrLeft);
	}
	if (ptr->ptrRight != NULL)	
	{	
		Del(ptr->ptrRight);
	}
	delete ptr;			
	ptr = NULL;
}

BinarySearchT::BinarySearchT(const BinarySearchT & obj)
{   
	root = NULL;
	if(obj.root == NULL)
	{
			return;
	}
	CopyNode (obj.root);
}

void BinarySearchT::CopyNode (const TreeNodeptr & ptr) 
{	
	if (ptr == NULL) return;
	else
	{	
		RInsert(ptr->name, root);
		CopyNode (ptr->ptrLeft);
		CopyNode (ptr->ptrRight);
	}
}

void BinarySearchT::Insert (string a)
{	
	RInsert (a, root);
}

bool BinarySearchT::Find (string a)
{
	return RFind(a, root) ;
}

int  BinarySearchT::Height ()
{
	return RHeight (root);
}

int BinarySearchT::Size ()
{
	return RSize (root);
}
string BinarySearchT::Traverse ()
{	
	cout << "Postoder traversal " << endl ;
	return RTraverse(root);
}
void BinarySearchT::RInsert (string a, TreeNodeptr& ptr)
{	
	if (ptr == NULL)  
	{
		ptr = new TreeNode(a);
	}
	else
	{
		if (a <= ptr->name)
		{
			RInsert (a, ptr->ptrLeft); 
		}
		else 
		{
			RInsert (a, ptr->ptrRight);  
		}
	}
}

bool BinarySearchT::RFind (string a, TreeNodeptr& ptr)
{
	if (ptr == NULL)
		return false ;
	else if (a == ptr->name)
		return true ;
	else if (a > ptr->name)
		return RFind(a, ptr->ptrRight) ;
	else 
		return RFind(a, ptr->ptrLeft) ;
}
int BinarySearchT::RHeight (TreeNodeptr& ptr) 
{
	int Lheight = 0;
	int Rheight = 0;
	if( ptr == NULL) return -1;
	if( ptr->ptrLeft != NULL)
	{
		Lheight = RHeight(ptr->ptrLeft); 
	}
	if( ptr->ptrRight != NULL)
	{
		Rheight = RHeight(ptr->ptrRight); 
	}
	if(Lheight > Rheight) return Lheight + 1;
	else return Rheight + 1;
}
int BinarySearchT::RSize (TreeNodeptr& ptr)
{
	int count = 1;
	if( ptr == NULL) return 0;
	count += RSize(ptr->ptrLeft);
	count += RSize(ptr->ptrRight);
	return count;
}

string BinarySearchT::RTraverse (TreeNodeptr ptr)
{	

	string ls, rs;
	
	if (ptr == NULL)
		return " " ;
	else
	{	
		ls = RTraverse(ptr->ptrLeft);
		rs = RTraverse(ptr->ptrRight);
		cout << "Intermediate Result: " << ptr->name << endl ;
		return (ls + ptr->name + " " + rs);
	}	
}


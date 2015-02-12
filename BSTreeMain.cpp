#include "BinarySearchT.h"
#include <fstream>
#include <vector>
#include <algorithm> 
using namespace std;

int main()
{	

	string word ;
	string test;
	vector <string> obj;
	ifstream file;
	file.open ("dictionary.txt", ios::in);
	while (file>> word)
	{
		obj.push_back(word);
		random_shuffle(obj.begin(), obj.end());
	}
	////testng 10 rendomized strings;
	//obj.push_back("abandons");
	//obj.push_back("and");
	//obj.push_back("want");
	//obj.push_back("school");
	//obj.push_back("yor");
	//obj.push_back("that");
	//obj.push_back("sleep");
	//obj.push_back("light");
	//obj.push_back("bad");
	//obj.push_back("grass");

	BinarySearchT tree ;

	for (int i = 0; i<obj.size() /* whe tesing 10 rendom use 10 for size*/; i++)
	{
		tree.Insert(obj[i]);
	}
	cout<< "The SIZE of the tree is: " << tree.Size() << endl;
	cout<< "The  HEIGHT of the tree is: " << tree.Height() << endl;
	
	ifstream fin;
	fin.open ("letter.txt", ios::in);
	fin>> test;
	while(!fin.eof())
	{
		
		string temp;
		for (int i= 0; i< test.size(); i++)
		{

			if(test[i] != '“' && test[i] != ',' && test[i] !=  ':' && test[i] != '.' && test[i] !=  '!' && test[i] != '?' && test[i] !=  '(' && test[i] !=  ')')
			{
				temp+= tolower(test[i]);
			}
		}
		test = temp;
		if( tree.Find(test) == false)
		{ 
			cout << "The misspelled words are: " << endl;
			cout << test << endl;
		}
		fin>>test;
	}
	cout<< "Prining the inomation of the original tree: " << endl;
	tree.Traverse();
	cout<< "Testing the Copy Constructor: " << endl;
	BinarySearchT branch(tree) ;
	cout<< "Prining the inomation of the copied tree: " << endl;
	branch.Traverse();
	system("pause") ;

	return 0 ;
}
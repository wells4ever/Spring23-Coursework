#include <iostream>
#include <vector>	



using std::endl;
using std::string;
using std::cout;
using std::cin;

//TREENODE1/2---template<typename T>
//class TreeNode
//{
//public:
//	//member vars:
//	T nodeValue;
//	TreeNode<T>* left, * right; //add more links for general tree
//	
//	TreeNode() {};
//
//	TreeNode(const T& nodeValue)
//	{
//		this->nodeValue = nodeValue;
//	}
//	bool isLeaf()
//	{
//		if (left == nullptr && right == nullptr) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//}; 

struct File
{
	string name;
	string dateModified;
	File() {};
	File(string n, string dm)
	{
		name = n;
		dateModified = dm;
	}

	friend std::ostream& operator << (std::ostream& os, const File& fl)
	{
		os << fl.name << '/' << fl.dateModified << endl;
		return os;
		
	}
	//insert other fields, if desired
	//insert constructors, overloaded << operator, etc....
};//Let’s not distinguish between “file” and “folder”/directory

template <typename T>
class nAryTreeNode //TREENODE3
{
public:
	//member vars
	T nodeValue;
	std::vector<nAryTreeNode<T>*> childrenLinks;

	nAryTreeNode() {};
	nAryTreeNode(T nodeValue)
		:nodeValue(nodeValue)
	{};

	//dynamic array (vector) allows arbitrary number of children
	//std::map is probably a more “natural” choice here ...
	//(map inherits from <xtree>)

	auto createFileNode()
	{
		nAryTreeNode<File>* newNode = new nAryTreeNode<File>;
		cout << "\n\nEnter file/folder name and date modified:";
		string filename;
		string dateModifed;
		cin >> filename >> dateModifed;
		newNode->nodeValue.name = filename;
		newNode->nodeValue.dateModified = dateModifed;
		return newNode;
	} //end createFileNode()

	void addChildFile(nAryTreeNode<File>* parentFile)
	{
		cout << "\nAdding file number "
			<< parentFile->childrenLinks.size() << " to parent named : "
			<< parentFile->nodeValue.name << endl;
		//print statement (for clarity) is optional
		nAryTreeNode<File>* childFile = createFileNode();
		parentFile->childrenLinks.push_back(childFile);
	}


};



int main()
{
	/*TREENODE1---TreeNode<int>* root, * leftNode, * rightNode;
	root = new TreeNode<int>(1);
	leftNode = new TreeNode<int>(2);
	rightNode = new TreeNode<int>(3);*/

	//TREENODE2---TreeNode<char>* root, * leftNode, * rightNode;
	//	root->left = leftNode;
	//root->right = rightNode;
	//cout << root->isLeaf() << endl;
	//cout << leftNode->isLeaf() << endl;
	////alternative to rightNode->isLeaf():
	//cout << root->right->isLeaf() << endl; 
	//	

	//TreeNode<char>* root = new TreeNode<char>('a');
	////add a constructor that only takes one arg (T nodeValue)
	////first level nodes:
	//root->left = new TreeNode<char>('b');
	//root->right = new TreeNode<char>('c');
	//
	//	//second level nodes:
	//	root->left->left = new TreeNode<char>('d');
	//root->left->right = new TreeNode<char>('e');
	//root->right->left = new TreeNode<char>('f');
	//root->right->right = new TreeNode<char>('g');
	////third level nodes:
	//root->right->left->left = new TreeNode<char>('h');
	//root->right->left->right = new TreeNode<char>('i');

	cout << "Creating root folder ..." << endl;
	nAryTreeNode<File>* rootFolderNode = createFileNode();
	addChildFile(rootFolderNode);
	addChildFile(rootFolderNode);
	addChildFile(rootFolderNode);

	addChildFile(rootFolderNode->childrenLinks.at(0));

	cout << "\n\nRoot folder and its contents: " << endl;
	cout << rootFolderNode->nodeValue << endl;
	for (int i = 0; i < rootFolderNode->childrenLinks.size(); i++)
	{
		cout << "---" << rootFolderNode->childrenLinks[i]->nodeValue << endl;
		if (rootFolderNode->childrenLinks[i]->childrenLinks.size() != 0)
		{
			cout << "------"
				<< rootFolderNode->childrenLinks[0]
				->childrenLinks[0]
				->nodeValue << endl;
		}
	}
}
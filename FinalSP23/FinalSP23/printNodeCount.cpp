#include <iostream>
#include <queue>

using std::cout;
using std::endl;

template <typename T>
class TreeNode
{
public:
	
	T nodeValue;
	TreeNode<T>* left, * right;
	TreeNode() {};
	TreeNode(const T& nodeValue)
	{
		this->nodeValue = nodeValue;
	}
	bool isLeaf()
	{
		if (left == nullptr && right == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
};


template <typename T>
void levelOrderTraverse(TreeNode<T>* root)
{
	std::queue<TreeNode<T>*> treeNodeQueue;
	
	treeNodeQueue.push(root);
	int nodeCount = 1;
	while (!treeNodeQueue.empty())
	{
		TreeNode<T>* current;
		current = treeNodeQueue.front();
		treeNodeQueue.pop();
		//cout << current->nodeValue << endl;
		if (current->left != nullptr)
		{
			nodeCount++;
			treeNodeQueue.push(current->left);
		}
		if (current->right != nullptr)
		{
			nodeCount++;
			treeNodeQueue.push(current->right);
		}
	}
	cout << "Node Count: " << nodeCount;
}

//int main()
//{
//	TreeNode<char>* root = new TreeNode<char>('a');
//	
//	root->left = new TreeNode<char>('b');
//	root->right = new TreeNode<char>('c');
//
//		//second level nodes:
//		root->left->left = new TreeNode<char>('d');
//	root->left->right = new TreeNode<char>('e');
//	root->right->left = new TreeNode<char>('f');
//	root->right->right = new TreeNode<char>('g');
//	//third level nodes:
//	root->right->left->left = new TreeNode<char>('h');
//	root->right->left->right = new TreeNode<char>('i');
//	levelOrderTraverse(root);
//}
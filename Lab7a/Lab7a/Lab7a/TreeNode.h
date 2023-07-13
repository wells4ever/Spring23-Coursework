#pragma once

#include <queue>
#include <stack>

using std::cout;
using std::endl;

template<typename T>
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

template<typename T>
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
		cout << current->nodeValue << endl;

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
}

template<typename T>
void inorderTraverse(TreeNode<T>* root)
{
	if (root != nullptr)
	{
		inorderTraverse(root->left);
		cout << root->nodeValue << " ";
		inorderTraverse(root->right);
	}
}

template<typename T>
int getLeafCount(TreeNode<T>* root)
{
	if (root == nullptr)
	{
		return 0;
	}

	int leafCount = 0;
	std::stack<TreeNode<T>*> nodeStack;
	nodeStack.push(root);

	while (!nodeStack.empty())
	{
		TreeNode<T>* current = nodeStack.top();
		nodeStack.pop();

		if (current->left != nullptr) {
			nodeStack.push(current->left);
		}
		if (current->right != nullptr) {
			nodeStack.push(current->right);
		}
		if (current->isLeaf()) {
			leafCount++;
		}
	}
	return leafCount;
}

template<typename T>
TreeNode<T>* insertBSTNode(TreeNode<T>* root, T insertedValue)
{
	if (root == nullptr) 
	{
		root = new TreeNode<T>(insertedValue);
	}

	else if (insertedValue < root->nodeValue)
	{
		
		root->left = insertBSTNode(root->left, insertedValue);
	}
	else
	{
		root->right = insertBSTNode(root->right, insertedValue);
	}
	return root;
}

template<typename T>
int getNodeLevel(TreeNode<T>* root, T targetValue, int level)
{
	if (root == nullptr)
	{
		return -1;
	}
	if (root->nodeValue == targetValue)
	{
		return level;
	}

	int leftLevel = getNodeLevel(root->left, targetValue, level + 1);
	int rightLevel = getNodeLevel(root->right, targetValue, level + 1);
	if (leftLevel == -1)
	{
		return rightLevel;
	}
	else
	{
		return leftLevel;
	}
}
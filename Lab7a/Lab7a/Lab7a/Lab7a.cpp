#include <iostream>
#include <vector>
#include "TreeNode.h"

using std::endl;
using std::cout;
using std::string;
using std::cin;



int main()
{
	int searchVal;
	int level;
	std::vector<int> nums =
	{ 1,4,2,7,9,3,0,6,5,8 };

	TreeNode<int>* root = new TreeNode<int>(1);

	for (int i = 1; i < nums.size(); i++) {
		insertBSTNode(root, nums[i]);
	}

	levelOrderTraverse(root);
	cout << endl;

	inorderTraverse(root);
	cout << endl << endl;

	int count = getLeafCount(root);
	cout << "There are " << count << " leaves on the tree." << endl;

	cout << "Please input an integer, 0 - 9, to search which level it is in." << endl;
	cin >> searchVal;

	if (searchVal <= 9 && searchVal >= 0)
	{
		level = getNodeLevel(root, searchVal, 0);
		cout << "The value " << searchVal << " is on level " << level << "." << endl;
	}
	else
	{
		cout << "That is not 0 - 9, setting search value to '7'." << endl;
		searchVal = 7;
		level = getNodeLevel(root, searchVal, 0);
		cout << "The value " << searchVal << " is on level " << level << "." << endl;
	}
	
	return 0;
}
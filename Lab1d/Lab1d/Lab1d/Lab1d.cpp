#include <iostream>
#include "MyArray.h"
#include "MyVector.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
	MyArray <int, 4> nums;
	nums.modifyElement(0, 1);
	nums.modifyElement(1, 2);
	nums.modifyElement(2, 3);
	nums.modifyElement(3, 4);
	
	cout << "Original Array of numbers: " << endl;
	nums.print();

	MyArray <int, 4> copyOfNums = nums;
	cout << "\n Copied array:" << endl;
	copyOfNums.print();

	cout << "Altering array 'nums'.." << endl;
	nums.modifyElement(2, 6);

	cout << "Original Array of numbers: " << endl;
	nums.print();

	cout << "\n Copied array:" << endl;
	copyOfNums.print();

	MyVector <int> nums2;
	nums2.pushBack(1);
	nums2.pushBack(2);
	nums2.pushBack(3);
	nums2.pushBack(4);

	cout << "\nOriginal Vector: " << endl;
	nums2.print();

	MyVector <int> copyOfNums2 = nums2;

	cout << "\nCopied Vector: " << endl;
	copyOfNums2.print();

	cout << "\nAltering Vector..." << endl;
	nums2.popBack();

	cout << "\nOriginal Vector: " << endl;
	nums2.print();

	cout << "\nCopied Vector: " << endl;
	copyOfNums2.print();

	MyVector <int> copy2OfNums2(nums2);

	nums2.pushBack(4);

	cout << "\nOriginal Vector: " << endl;
	nums2.print();

	cout << "\nCopied Vector(via copy constructor): " << endl;
	copy2OfNums2.print();

	cout << "\n Altering Original Vector.." << endl;
	nums2.pushBack(5);

	cout << "\nOriginal Vector: " << endl;
	nums2.print();

	cout << "\nCopied Vector(via copy constructor): " << endl;
	copy2OfNums2.print();

	return 0;
}
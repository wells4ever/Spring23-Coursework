#include <iostream>
#include <map>

using std::cout;
using std::string;
using std::cin;
using std::endl;

struct ContactRecord
{

	string name;
	int phoneNumber;
	string address;

	ContactRecord(){}
	ContactRecord(string n, int pn, string ad)
	{
		name = n;
		phoneNumber = pn;
		address = ad;
	}

	friend std::ostream& operator << (std::ostream& os, const ContactRecord& cr)
	{
		os << "Name: " << cr.name << "\nPhone: " << cr.phoneNumber << "\nAddress: " << cr.address << endl;
		return os; //ERROR POINT
	}
};


int main()
{
	std::map<string, ContactRecord> contactMap;
	std::map<string, ContactRecord>::iterator itr;

	string contactToView;
	int contactOption;
	int progressInt;
	string addName;
	int addPhone;
	string addAddress;
	float loopIterator = 0;
	do
	{
		cout << "Contact List --- Select Function." << endl;
		cout << "1 - Add Contact" << endl;
		cout << "2 - View Contact List" << endl;
		cout << "3 - View Contact" << endl;
		cout << "4 - Exit" << endl;
		cin >> progressInt;
		switch (progressInt)
		{
		case 1:
			//add contact
			cout << "Please enter the contact name." << endl;
			cin >> addName;
			cout << "\nPlease enter contact phone number(numbers only, parenthesis or special symbols)." << endl;
			cin >> addPhone;
			cout << "\nPlease enter contact address." << endl;
			cin >> addAddress;
			contactMap.insert({ addName,
								ContactRecord(addName, addPhone, addAddress) });
			break;
		case 2:
			//view contact list
			for (itr = contactMap.begin(); itr != contactMap.end(); itr++)
			{
				cout << itr->first << endl;
			}
			break;
		case 3:
			//view contact details
			cout << "Which contact would you like to view? (enter name)" << endl;
			cin >> contactToView;
			if ((itr = contactMap.find(contactToView)) != contactMap.end())
				cout << itr->second << endl;
			cout << "Select Function:" << endl;
			cout << "1 - Delete Contact" << endl;
			cout << "2 - Exit Contact Info" << endl;
			cin >> contactOption;
			switch (contactOption)
			{
			case 1:
				contactMap.erase(contactToView);
				cout << "Contact deleted." << endl;
					break;
			case 2:
				cout << "Returning to main menu." << endl;
					break;
			}
			break;
		case 4:
			//exit
			cout << "Closing contact list.";
			loopIterator = INFINITY;
			break;
		}
	} while (loopIterator < INFINITY);
}
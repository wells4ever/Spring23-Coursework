#include <iostream>
#include <queue>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::queue;

struct Customer
{
public:
	string name;
	int itemCount;

	Customer()
	{
		name = "n/a";
		itemCount = 0;
	}

	Customer(string n, int items)
	{
		name = n;
		itemCount = items;
	}

	void scanItems()
	{
		int itemsScanned = rand() % itemCount;
		if (itemCount == 1)
		{
			itemsScanned = 1; //eliminate constant state of ItemCount = 1;
		}
		int newCount = itemCount - itemsScanned;
		itemCount = newCount;
	}

	friend std::ostream& operator << (std::ostream& osObj, const Customer& custObj)
	{
		osObj << custObj.name << "\t\t" << custObj.itemCount;
		return osObj;
	}

};


void serviceLine(queue<Customer>& custQueue)
{
	Customer currentCust(custQueue.front());
	currentCust.scanItems();
	if (currentCust.itemCount == 0)
	{
		custQueue.pop();

	}
	else 
	{
		custQueue.front() = currentCust;
	}
}

void printQueue(queue<Customer> q)
{
	while (!q.empty()) {
		cout << " " << q.front() << endl;
		q.pop();
	}
	cout << endl;
}



int main()
{
	queue<Customer> lane1;
	queue<Customer> lane2;

	Customer cust1("Adam", 5);
	Customer cust2("Brad", 15);
	Customer cust3("Cherie", 8);
	Customer cust4("Daniel", 4);
	Customer cust5("Elanor", 2);
	Customer cust6("Fran", 8);
	Customer cust7("Gavin", 9);
	Customer cust8("Harold", 24);

	lane1.push(cust1);
	lane1.push(cust2);
	lane1.push(cust3);
	lane1.push(cust4);

	lane2.push(cust5);
	lane2.push(cust6);
	lane2.push(cust7);
	lane2.push(cust8);

	cout << "Initial state of checkout lanes:" << endl;
	cout << "\n----Lane 1----" << endl;
	cout << "\nName        Item Count" << endl;
	cout << "\n----------------------" << endl;
	printQueue(lane1);

	cout << "Initial state of checkout lanes:" << endl;
	cout << "\n----Lane 2----" << endl;
	cout << "\nName        Item Count" << endl;
	cout << "\n----------------------" << endl;
	printQueue(lane2);
	
	char input;
	bool proceed = true;
	while(proceed)
	{
		
		cout << "Press 'C' to continue.." << endl;
		cin >> input;
		if (input == 'C')
		{
			proceed = true;
		}
		

		serviceLine(lane1);
		serviceLine(lane2);

		cout << "Items scanned by customers." << endl;
		cout << "Current state of lanes: " << endl;

		cout << "\n----Lane 1----" << endl;
		cout << "\nName        Item Count" << endl;
		cout << "\n----------------------" << endl;
		printQueue(lane1);

		cout << "\n----Lane 2----" << endl;
		cout << "\nName        Item Count" << endl;
		cout << "\n----------------------" << endl;
		printQueue(lane2);


		if (lane1.size() == 0 && lane2.size() == 0)
		{
			proceed = false;
		}
	}

}
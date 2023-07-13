#include <iostream>
#include <forward_list>
#include <deque>
#include <map>

using namespace std;

template<typename K, typename V>
void print_map(map<K, V> const& m)
{
	for (auto const& pair : m) {
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
};

int main()
{
	forward_list <int> Numbers{7,8,9};
	deque <string> Tickets{"A40 ","B75 ","C127 "};
	map <string, int> Components{ {"CPU",1} , {"RAM",16} , {"GPU",1}};

	//Forward List Manipulation
	forward_list <int> Numbers2{ 1,2,3 };
	cout << "List 1: " << endl;
	for (int k : Numbers)
		cout << k << endl;
	cout << "List 2: " << endl;
	for (int k : Numbers2)
		cout << k << endl;
	Numbers.merge(Numbers2);
		cout << "Merged: " << endl;
	for (int k : Numbers)
		cout << k << endl;
	Numbers.push_front(4);
	cout << "Element Inserted: " << endl;
	for (int k : Numbers)
		cout << k << endl;
	Numbers.sort();
	cout << "Sorted: " << endl;
	for (int k : Numbers)
		cout << k << endl;

	//DEQue Manipulation
	cout << "deque before manip.: " << endl;
	for (string n : Tickets)
		cout << n;
	Tickets.push_front("D185 ");
	Tickets.push_back("E903 ");
	cout << "\ndeque after inserting elements to front and back: " << endl;
	for (string n : Tickets)
		cout << n;
	Tickets.clear();
	
	cout << "\ndeque cleared: " << endl;
	for (string n : Tickets)
		cout << n;


	//Map Manipulation
	cout << "Initial Map: " << endl;
	print_map(Components);
	Components.insert_or_assign("SSD", 10);
	cout << "Map after element insertion: " << endl;
	print_map(Components);
	Components["RAM"] = 32;
	Components["CPU"] = 2;
	cout << "Map after altering values: " << endl;
	print_map(Components);
	Components.clear();
	cout << "Map after clearing: " <<  endl;
	print_map(Components);

	return 0;

}
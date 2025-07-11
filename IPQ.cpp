#include "IPQ.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Initialize vectors using push_back()
    vector<string> tasks;
    vector<int> priorities;
    IPQ<int> ipq(tasks, priorities);
	cout<< "Is empty? " << (ipq.isEmpty() ? "Yes" : "No") <<endl;
    // Test insert, size, isEmpty
    ipq.insert("TaskA", 3);
	ipq.insert("TaskB", 1);
	ipq.insert("TaskC", 2);
	ipq.insert("TaskD", 4);
	ipq.insert("TaskE", 5);

    cout<< "Size after insertion: " << ipq.size() <<endl;
    cout<< "Is empty? " << (ipq.isEmpty() ? "Yes" : "No") <<endl;
	cout<< "\n\n\n";

    // Test deleteMin, getMin
    cout<< "Minimum task: " <<ipq.getMin() <<endl;
    cout<< "Deleted task: " <<ipq.deleteMin() << endl;
	cout << "Size after delete: " <<ipq.size() <<endl;
    
	// Test updatePriority
    cout<< "Updating priority of TaskD" <<endl;
    ipq.updatePriority("TaskD", 0);

	
	cout << "\n\n\nMinimum task: " << ipq.getMin() <<endl;

    // Test remove
    ipq.remove("TaskB");
    cout<< "Size after remove: " <<ipq.size() <<endl;

    // Test clear
    ipq.clear();
    cout << "Size after clear: " <<ipq.size() <<endl;

    system("pause");
    return 0;
}
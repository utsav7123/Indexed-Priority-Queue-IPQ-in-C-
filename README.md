# 🏗️ Indexed Priority Queue (IPQ) in C++

A custom implementation of an **Indexed Priority Queue** (IPQ) data structure in C++.  
Supports dynamic priority updates, direct item access by ID, and all typical heap operations.

---

## 📚 Overview

This project provides a reusable, template-based IPQ that supports efficient:
- Insertion of tasks/items with priority
- Deletion of the minimum (highest-priority) item
- Priority update of arbitrary elements by ID
- Removal of tasks/items by ID
- Querying minimum item and queue size
- Clearing the queue

All while maintaining the fast logarithmic properties of a binary heap, but extended to allow direct access via a unique task identifier.

---

## ⚙️ Core Files

- `IPQ.h` &mdash; Main header file, contains the `IPQ<T>` class template and implementation.
- `IPQ.cpp` &mdash; Example/test driver showing all major IPQ operations.
- `makefile` &mdash; For compiling the program (supports common make tools).

---

## 🧑‍💻 Class Design Highlights

- **HeapNode**: Stores a task's priority and its unique string ID.
- **Heap**: Internal min-heap array with percolate-up/down logic for maintaining heap property.
- **IPQ<T>**: Template class with a hash map (`unordered_map<string, size_t>`) mapping each ID to its heap position, enabling O(1) lookup for updates and deletes.

Key methods:
- `insert(taskID, priority)`
- `deleteMin()`
- `getMin()`
- `updatePriority(taskID, newPriority)`
- `remove(taskID)`
- `isEmpty()`, `size()`, `clear()`

---

## 🚀 How to Build & Run

Make sure you have a C++ compiler and `make` installed.

```bash
make
./IPQ
```
If the output binary is named differently, use that name.
# 📝 Example Usage (from IPQ.cpp)
```cpp
// Initialize and insert tasks
IPQ<int> ipq;
ipq.insert("TaskA", 3);
ipq.insert("TaskB", 1);
ipq.insert("TaskC", 2);

// Get and delete the minimum
cout << "Minimum task: " << ipq.getMin() << endl;
cout << "Deleted task: " << ipq.deleteMin() << endl;

// Update priorities, remove, clear, and check size
ipq.updatePriority("TaskC", 0);
ipq.remove("TaskA");
ipq.clear();
cout << "Size after clear: " << ipq.size() << endl;
```
# 💡 Features
- Efficient Heap Operations: O(log n) for insert, deleteMin, update, remove.

- Indexed Access: O(1) lookup for updates and removals via string IDs.

- Flexible: Fully templated for generic priority types.

- Clear Test Output: Example driver (main) shows how to use and test all features.
# 📦 Sample Output
```yaml
Is empty? Yes
Inserted TaskA with the priority: 3
Inserted TaskB with the priority: 1
Inserted TaskC with the priority: 2
Size after insertion: 3
Is empty? No

Minimum task: TaskB
Deleted task: TaskB
Size after delete: 2

Updating priority of TaskC

Minimum task: TaskC
Size after remove: 1
Size after clear: 0
```
#🛠️ Technical Notes
- Uses C++ STL containers: ```vector```, ```unordered_map```, ```string```

- All heap balancing logic (percolate up/down) is written from scratch

- Clear separation of heap logic and index mapping for educational clarity
# 👨‍💻 Author

Utsav Patel

Email:usp@sfu.ca

Simon Fraser University
#License

This project is open for educational and demonstration purposes. Attribution is appreciated!
<p align="center"> <b>🌟 If you like this project, please star the repo! 🌟</b> </p> 

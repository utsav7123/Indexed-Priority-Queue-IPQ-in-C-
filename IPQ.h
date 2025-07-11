#ifndef IPQ_H
#define IPQ_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

template<typename T>
class IPQ
{
private:

    class HeapNode
    {
    public:
        int priority;
        string taskID;
        HeapNode(int Priority, const string& id) : priority(Priority), taskID(id){}
        
    };

    class Heap
    {
    private:

        vector<HeapNode> heap_array;
        void percolate_up( int index);
        void percolate_down(int index);

    public:
        Heap(){}
        void insert (int priority, const string& taskID);
        string& deleteMin();
        string& getMin();
        void update (int node_number, int new_priority);
        void remove (int node_number);
        bool isEmpty() const {return heap_array. empty();}
        size_t size() const { return heap_array.size();}
        void clear(){ heap_array.clear(); }
        void reserve(size_t size){ heap_array.reserve(size);}

    };

    Heap heap;
    unordered_map< string, size_t> M;
public:
    IPQ(){}
    IPQ ( const vector<string>& task, const vector<int>& priorities);
    void insert (const string& tid, int priority);
    string& deleteMin();
    string& getMin(){return heap.getMin();}
    void updatePriority (const string& tid, int Priority);
    void remove(const string& tod);
    bool isEmpty() const {return heap.isEmpty();}
    size_t size() const {return heap.size();}
    void clear() {
        heap. clear();
        M.clear();
        }
    void reserve(size_t i){ heap.reserve(i);} 

};

template<typename T>
void IPQ<T>::Heap::percolate_up(int index)
{
    if(index==0)
    return;

    int temp= (index-1)/2;
    if(heap_array[index].priority<heap_array[temp].priority)
    {
        swap(heap_array[index], heap_array[temp]);
        percolate_up(temp);
    }
}

template<typename T>
void IPQ<T>::Heap::percolate_down(int index)
{
    int left_child =2 * index+1;
    int right_child = 2* index+2;
    int smallest = index;

    if (left_child < static_cast<int>(heap_array.size()) &&heap_array[left_child].priority <heap_array[ smallest].priority)
        smallest =left_child;
    if (right_child < static_cast<int >(heap_array.size()) && heap_array[ right_child].priority < heap_array[smallest].priority)
        smallest =right_child;

    if (smallest != index)
    {
        swap(heap_array[index], heap_array[smallest]);
        percolate_down(smallest);
    }

}

template<typename T>
void IPQ<T>::Heap::insert(int priority, const string& taskID)
{
    heap_array.push_back(HeapNode(priority, taskID));
    percolate_up(heap_array.size()-1);
}

template<typename T>
string& IPQ<T>::Heap::deleteMin()
{
    string& min_taskID= heap_array[0]. taskID;
    heap_array[0]= heap_array.back();
    heap_array.pop_back();
    percolate_down(0);
    return min_taskID;

}

template<typename T>
string& IPQ<T>::Heap::getMin()
{
    return heap_array[0].taskID;
}

template<typename T>
void IPQ<T>::Heap::update(int node_number, int new_priority)
{
    cout << "Updating priority of Node at index: " << node_number <<endl;
    int old_priority =heap_array[node_number]. priority;
    cout << "Old priority: " << old_priority << ", New priority: " << new_priority <<endl;
    heap_array[node_number]. priority = new_priority;

    if(new_priority< old_priority)
    {
        percolate_up(node_number);
    }
    else{
        percolate_down(node_number);
    }
}

template<typename T>
void IPQ<T>::Heap::remove(int node_number)
{
    heap_array[node_number]= heap_array.back();
    heap_array.pop_back();

    if(static_cast<size_t>(node_number)< heap_array.size())
    {
        percolate_up(node_number);
        percolate_down(node_number);

    }
}

template<typename T>
IPQ<T>::IPQ(const vector<string>& task, const vector<int>& priority)
{
    reserve(task.size());
    for(size_t i=0; i<task.size(); ++i)
    {
        insert(task[i], priority[i]);
    }
}

template<typename T>
void IPQ<T>::insert(const string& tid, int priority)
{
    heap.insert(priority, tid);
    M[tid] = heap.size()-1;
    cout<<"Inserted " <<tid<< " with the priority: "<<priority<<endl;

}

template<typename T>
string& IPQ<T>::deleteMin()
{
    string& min_taskID= heap.deleteMin();
    size_t lastNode = heap.size();
    if(lastNode >0)
    {
        M[heap.getMin()]=0;
        M[min_taskID]=lastNode-1;
    }
    return min_taskID;
}

template<typename T>
void IPQ<T>::updatePriority(const string& tid, int priority)
{
    typename unordered_map<string, size_t>:: iterator temp= M.find(tid);
    int node_number=temp->second;
    heap.update(node_number, priority); 
}

template<typename T>
void IPQ<T>::remove (const string& tid)
{   
    size_t node_number =M[tid];
    heap.remove(static_cast<int>(node_number));
    M.erase(tid);
}

#endif

#include <iostream>
#include <vector>
#include <utility>  // For std::pair
#include <string>
#include <functional>  // For std::function
#include "heap.cpp"   

using namespace std;

// Compare function to determine priority (for a min-heap or max-heap)
template <typename T>
bool comparePQ(const pair<int, T>& a, const pair<int, T>& b) {
    return a.first < b.first;  // Use `first` for priority comparison
}

template <typename T>
class PriorityQueue {
private:
    Heap<pair<int, T>> heap;  

public:
    // Constructor to initialize the priority queue with a comparator
    PriorityQueue(function<bool(const pair<int, T>&, const pair<int, T>&)> comp)
        : heap(comp) {}

    // Insert an element with a given priority
    void insert(int priority, const T& value) {
        heap.insert({priority, value});
    }

    // Extract the element with the highest priority
    pair<int, T> extractMax() {
        heap.extractMax();  

    }

    // Get the element with the highest priority without removing it
    pair<int, T> top() {
        return heap.top();  
    }
};


int main() {

    // Create a max-priority queue for strings
    PriorityQueue<string> pq(comparePQ<string>);

    pq.insert(3, "Low priority");
    pq.insert(5, "High priority");
    pq.insert(1, "Very low priority");

    cout << "Top element: (" << pq.top().first << " , " << pq.top().second << ")" << endl;  // Output: High priority

    pq.extractMax();
    cout << "Top element after extracting max: (" << pq.top().first << " , " << pq.top().second << ")" << endl;  // Output: Low priority

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <limits>
using namespace std;

template <typename T>
class Heap {
private:
    vector<T> heap;
    function<bool(T, T)> compare;  // Comparison function

    // Restore the heap property after insertion.
    void heapifyUp(int index) {
        while (index > 0 && compare(heap[parent(index)], heap[index])) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Restore the heap property after removal.
    void heapifyDown(int index) {
        int leftChild = left(index);
        int rightChild = right(index);
        int target = index;  // Index of the smallest/largest element

        if (leftChild < heap.size() && compare(heap[target], heap[leftChild])) {
            target = leftChild;
        }
        if (rightChild < heap.size() && compare(heap[target], heap[rightChild])) {
            target = rightChild;
        }

        if (target != index) {
            swap(heap[index], heap[target]);
            heapifyDown(target);
        }
    }

    // Helper functions for parent and child indices.
    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return 2 * index + 1; }
    int right(int index) { return 2 * index + 2; }

public:
    // Constructor to initialize with a comparison function.
    Heap(function<bool(T, T)> comp) : compare(comp) {}

    // Insert a new element into the heap.
    void insert(const T& element) {
        heap.push_back(element);
        heapifyUp(heap.size() - 1);  // Use the correct size
    }

    // Remove the root element from the heap (for max-heap or min-heap).
    void extractMax() {
        if (heap.empty()) {
            cout << "Heap is empty" << endl;
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);  // Restore heap property if the heap is not empty
        }
    }

    // Get the root element of the heap (e.g., min or max depending on the comparator).
    T top() const {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap.front();
    }

    // Extract and return the minimum element from the heap.
    T extractMin() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }

        // Find the minimum element by scanning the heap.
        int minIndex = 0;
        for (int i = 1; i < heap.size(); ++i) {
            if (compare(heap[i], heap[minIndex])) {
                minIndex = i;
            }
        }

        // Swap the minimum element with the last element and store its value.
        swap(heap[minIndex], heap.back());
        T minValue = heap.back();
        heap.pop_back();

        // Restore the heap property if needed.
        if (minIndex < heap.size()) {
            heapifyDown(minIndex);
        }

        return minValue;
    }
    // Build a max heap from an array of elements.
    void buildMaxHeap(const vector<T>& elements) {
        heap = elements;
        for (int i = heap.size() / 2 - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }
    // Function to sort an array using the heap.
    vector<T> heapSort(const vector<T>& elements) {
        buildMaxHeap(elements);
        vector<T> sortedArray;
        while (!heap.empty()) {
            sortedArray.push_back(heap.front());
            heap[0] = heap.back();
            heap.pop_back();
            if (!heap.empty()) {
                heapifyDown(0);
            }
        }
        reverse(sortedArray.begin(), sortedArray.end());
        return sortedArray;
    }
    
    // Check if the heap is empty.
    bool empty() const {
        return heap.empty();
    }

    // Get the current size of the heap.
    int getSize() const {
        return heap.size();
    }
};

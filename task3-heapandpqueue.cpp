#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Heap
{
private:
    vector<T> heap;
    function<bool(T, T)> compare; // Comparison function

    // Restore the heap property after insertion.
    void heapifyUp(int index)
    {
        while (index > 0 && compare(heap[parent(index)], heap[index]))
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    // Restore the heap property after removal.
    void heapifyDown(int index)
    {
        int leftChild = left(index);
        int rightChild = right(index);
        int target = index; // Index of the smallest/largest element

        if (leftChild < heap.size() && compare(heap[target], heap[leftChild]))
        {
            target = leftChild;
        }
        if (rightChild < heap.size() && compare(heap[target], heap[rightChild]))
        {
            target = rightChild;
        }

        if (target != index)
        {
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
    void insert(const T &element)
    {
        heap.push_back(element);
        heapifyUp(heap.size() - 1); // Use the correct size
    }

    // Remove the root element from the heap (for max-heap or min-heap).
    void extractMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty" << endl;
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
        {
            heapifyDown(0); // Restore heap property if the heap is not empty
        }
    }

    // Get the root element of the heap (e.g., min or max depending on the comparator).
    T top() const
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }
        return heap.front();
    }

    // Extract and return the minimum element from the heap.
    T extractMin()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }

        // Find the minimum element by scanning the heap.
        int minIndex = 0;
        for (int i = 1; i < heap.size(); ++i)
        {
            if (compare(heap[i], heap[minIndex]))
            {
                minIndex = i;
            }
        }

        // Swap the minimum element with the last element and store its value.
        swap(heap[minIndex], heap.back());
        T minValue = heap.back();
        heap.pop_back();

        // Restore the heap property if needed.
        if (minIndex < heap.size())
        {
            heapifyDown(minIndex);
        }

        return minValue;
    }
    // Build a max heap from an array of elements.
    void buildMaxHeap(const vector<T> &elements)
    {
        heap = elements;
        for (int i = heap.size() / 2 - 1; i >= 0; --i)
        {
            heapifyDown(i);
        }
    }
    // Function to sort an array using the heap.
    vector<T> heapSort(const vector<T> &elements)
    {
        buildMaxHeap(elements);
        vector<T> sortedArray;
        while (!heap.empty())
        {
            sortedArray.push_back(heap.front());
            heap[0] = heap.back();
            heap.pop_back();
            if (!heap.empty())
            {
                heapifyDown(0);
            }
        }
        reverse(sortedArray.begin(), sortedArray.end());
        return sortedArray;
    }

    // Check if the heap is empty.
    bool empty() const
    {
        return heap.empty();
    }

    // Get the current size of the heap.
    int getSize() const
    {
        return heap.size();
    }
};

// Compare function to determine priority (for a min-heap or max-heap)
template <typename T>
bool comparePQ(const pair<int, T> &a, const pair<int, T> &b)
{
    return a.first < b.first; // Use `first` for priority comparison
}

template <typename T>
class PriorityQueue
{
private:
    Heap<pair<int, T>> heap;

public:
    // Constructor to initialize the priority queue with a comparator
    PriorityQueue(function<bool(const pair<int, T> &, const pair<int, T> &)> comp)
        : heap(comp) {}

    // Insert an element with a given priority
    void insert(int priority, const T &value)
    {
        heap.insert({priority, value});
    }

    // Extract the element with the highest priority
    pair<int, T> extractMax()
    {
        heap.extractMax();
    }

    // Get the element with the highest priority without removing it
    pair<int, T> top()
    {
        return heap.top();
    }
};
int main()
{

    // Heap test starts here
    // Create a max heap and perform operations
    Heap<int> h((std::less<int>()));

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(15);
    h.insert(35);
    cout << "Top element: " << h.top() << endl;
    h.extractMax();
    cout << "Top element after extracting max: " << h.top() << '\n';
    h.extractMin();
    cout << "Top element after extracting min: " << h.top() << '\n';

    // Build a max heap from an array of items
    Heap<int> itemHeap((std::less<int>()));
    itemHeap.buildMaxHeap({20, 10, 5, 30, 15, 40});
    cout << "Top element: " << itemHeap.top() << '\n';

    // Sort the items in descending order
    Heap<int> sortHeap((std::greater<int>()));
    vector<int> v = sortHeap.heapSort(vector<int>{10, 20, 5, 30, 15, 35});
    for (const auto &i : v)
        cout << i << " ";
    // Heap Test ends here

    // Priority queue test starts here
    // Create a max-priority queue for strings
    PriorityQueue<string> pq(comparePQ<string>);

    pq.insert(3, "Low priority");
    pq.insert(5, "High priority");
    pq.insert(1, "Very low priority");

    cout << "Top element: (" << pq.top().first << " , " << pq.top().second << ")" << '\n'; // Output: High priority

    pq.extractMax();
    cout << "Top element after extracting max: (" << pq.top().first << " , " << pq.top().second << ")" << '\n'; // Output: Low priority

    // Priority queue test ends here
}

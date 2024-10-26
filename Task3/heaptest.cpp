#include "heap.cpp"
using namespace std;
int main() {
    
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
    cout << "Top element after extracting max: " << h.top() << endl;
    h.extractMin();
    cout << "Top element after extracting min: " << h.top() << endl;


    // Build a max heap from an array of items
    Heap<int> itemHeap((std::less<int>()));
    itemHeap.buildMaxHeap({20, 10, 5, 30, 15, 40});
    cout << "Top element: " << itemHeap.top() << endl;
    
    
    // Sort the items in descending order
    Heap<int> sortHeap((std::greater<int>()));
    vector<int> v = sortHeap.heapSort(vector<int>{10, 20, 5, 30, 15, 35});
    for (const auto& i : v) {
        cout << i << " ";
    }


    return 0;
}

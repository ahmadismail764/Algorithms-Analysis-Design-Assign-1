#include <iostream>
#include <vector>

using namespace std;

int Sequential_Search(const vector<int> &input, int target) {
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == target)return i;
    }
    return -1;
};

int Recursive_Sequential_Search(const vector<int> &input, int target, int index = 0) {
    if (index == input.size()) { return -1; }
    if (input[index] == target) { return index; }
    return Recursive_Sequential_Search(input, target, ++index);
}

int Binary_Search(const vector<int> &input, int target) {
    int l = 0, r = input.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (input[mid] == target)return mid;
        else if (input[mid] > target) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int Recursive_Binary_Search(const vector<int> &input, int target, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (input[mid] == target)return mid;
    else if (input[mid] > target) return Recursive_Binary_Search(input, target, low, mid - 1);
    else return Recursive_Binary_Search(input, target, mid + 1, high);
}

int main() {
    vector<int> list = {1, 2, 4, 5, 6, 8};
    int index;
//--------------------------------Sequential_Search---------------------------------------------------
//    index = Sequential_Search(list,5);
//    index = Sequential_Search(list,7);


//--------------------------------Recursive_Sequential_Search---------------------------------------------------
//    index = Recursive_Sequential_Search(list,5);
//    index = Recursive_Sequential_Search(list,7);


//--------------------------------Binary_Search---------------------------------------------------
//    index = Binary_Search(list, 5);
//    index = Binary_Search(list, 7);


//--------------------------------Recursive_Binary_Search---------------------------------------------------
//     index = Recursive_Binary_Search(list,5,1,5);
//     index = Recursive_Binary_Search(list,7,1,5);

    (index == -1) ? cout << "the item doesnt Exist!" : cout << "Item found at index: " << index << '\n';
    return 0;
}

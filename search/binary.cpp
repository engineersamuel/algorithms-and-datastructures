#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int binSearch(vector<int>*, int, size_t, size_t);

int binSearch(vector<int>* arr, int num, size_t low, size_t high) {
    int mid = (int)(low + ((high - low) / 2));
    if ((*arr)[mid] == num) return mid;
    if (low > high) return -1;

    if (num < (*arr)[mid]) {
        return binSearch(arr, num, low, mid - 1);
    }
    return binSearch(arr, num, mid + 1, high);
}

int main(){
    vector<int> arr {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    for (auto &num : arr) {
        int idx = binSearch(&arr, num, 0, arr.size() - 1);
        cout << num << " is at position: " << idx << ", true? " <<  (arr.at(idx) == num) << endl;
    }

    return 0;
}

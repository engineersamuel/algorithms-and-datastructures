#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

void shellSort(vector<int>*);

void shellSort(vector<int>* arr) {
    vector<int>& A = *arr;
    // Calculate the gap initially, this can be arr / 2 or 3
    int gap = static_cast<int>(floor(arr->size() / 2));
    // We want to calculate the gap to 1
    while (gap >= 1) {
        // Count up so we have a sliding window
        for (int i = 0; i < static_cast<int>(arr->size()) - gap; i++) {
            int pos = i + gap;
            // For each sliding window position filter the lowest value down the chain
            while (pos-gap >= 0 && A[pos] < A[pos - gap]) {
                swap(A[pos], A[pos-gap]);
                pos -= gap;
            }
        }
        gap = gap / 2;
    }
}

//vector<int> nums { 8, 9, 7, 5, 2, 4, 6, 1, 3, -1 };
//shellSort(&nums);
//printVector(nums);

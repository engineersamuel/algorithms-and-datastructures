#include <vector>
#include <iostream>
using namespace std;
#include "insertion.hpp"

void insertionSort(vector<int>* arr) {
    vector<int> &A = *arr;
    for (int i=1; i<A.size(); i++) {
        int idx = i;
        while (idx >= 0 && (A[idx] < A[idx-1])) {
            swap(A[idx], A[idx-1]);
            idx--;
        }
    }
}

//vector<int> nums { 8, 9, 7, 5, 2, 4, 6, 1, 3 };
//insertionSort(&nums);

#include <vector>
#include <iostream>
using namespace std;
#include "sorting.hpp"

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

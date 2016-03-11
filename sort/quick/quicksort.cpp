#include <vector>
#include <math.h>

using namespace std;

void quickSort(vector<int>*, int, int);
int partition(vector<int>*, int, int);

void quickSort(vector<int>* arr, int start, int end) {
    if (start < end) {
        int pIdx = partition(arr, start, end);
        quickSort(arr, start, pIdx - 1);
        quickSort(arr, pIdx + 1, end);
    }

}
int partition(vector<int>* arr, int start, int end) {
    vector<int>& A = *arr;
    int pIdx = start;
    int pivot = A[end];

    for (int i = start; i < end; i++) {
        if (A[i] <= pivot) {
            swap(A[pIdx], A[i]);
            pIdx++;
        }
    }
    swap(A[pIdx], A[end]);
    return pIdx;
}

//vector<int> nums { 8, 9, 7, 5, 2, 4, 6, 1, 3, -1 };
//quickSort(&nums, 0, (int)nums.size() - 1);
//printVector(nums);

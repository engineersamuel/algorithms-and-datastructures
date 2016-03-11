#include <vector>
#include <iostream>

#include "merge.hpp"

using namespace std;

void mergeSort(vector<int>* arr, long low, long high) {
    if (low < high) {
        long mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(vector<int>* arr,  long low, long mid, long high) {

    vector<int>& ref = *arr;
    vector<int> temp (static_cast<unsigned>(high - low + 1));

    long left = low;
    long right = mid + 1;
    int k = 0;

    // While there are unsorted items
    while (left <= mid && right <= high) {
        if (ref[left] <= ref[right]) {
            temp[k] = ref[left];
            left += 1;
        } else {
            temp[k] = ref[right];
            right += 1;

        }
        k += 1;
    }

    // If there any remaining items, copy those in
    if (left <= mid) {
        while (left <= mid) {
            temp[k] = ref[left];
            left += 1;
            k += 1;
        }
    } else if (right <= high) {
        while (right <= high) {
            temp[k] = ref[right];
            right += 1;
            k += 1;
        }
    }

    // Now copy the temp array back into the main array
    for (int i = 0; i < temp.size(); i++) {
        ref[low + i] = temp[i];
    }
}

int main() {
    vector<int> arr = {8, 9, 7, 5, 2, 4, 6, 1, 3};
    mergeSort(&arr, 0, arr.size() - 1);
    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}

#include <vector>
#include <iostream>
using namespace std;

void selectionSort(vector<int>*);

void selectionSort(vector<int>* arr) {
    vector<int> &A = *arr;
    for (int i=0; i<A.size(); i++) {
        int min = i;
        for (int j=i+1; j<A.size(); j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        swap(A[i], A[min]);
    }
}

//vector<int> nums { 8, 9, 7, 5, 2, 4, 6, 1, 3 };
//selectionSort(&nums);

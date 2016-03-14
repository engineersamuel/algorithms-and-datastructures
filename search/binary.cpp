#include <vector>
#include "binarysearch.hpp"

using namespace std;

int binarysearch_rec(std::vector<int> *, int, int, int);
int binarysearch_itr(std::vector<int> *, int, int, int);

int binarysearch_rec(vector<int> *arr, int num, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (num == arr->at(mid)) return mid;

    if (num < arr->at(mid)) {
        return binarysearch_rec(arr, num, low, mid - 1);
    } else {
        return binarysearch_rec(arr, num, mid + 1, high);
    }

}

int binarysearch_itr(vector<int> *arr, int num, int low, int high) {
    int idx = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (num == arr->at(mid)) {
            idx = mid;
            break;
        }

        if (num < arr->at(mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return idx;
}

int main() {
    vector<int> arr {3, 4, 5, 6, 7, 8, 9, 10};
    int num = 3;
    int idx = binarysearch_rec(&arr, num, 0, arr.size());
    cout << "Num: " << num << " is at idx: " << idx << endl;
    idx =   binarysearch_itr(&arr, num, 0, arr.size());
    cout << "Num: " << num << " is at idx: " << idx << endl;

    return 0;
}

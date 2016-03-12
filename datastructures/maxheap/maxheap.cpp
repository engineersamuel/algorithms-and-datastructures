#include <iostream>
#include <vector>

using namespace std;
#include "maxheap.hpp"


void MaxHeap::maxHeapify() {
    for (auto i = this->N / 2; i > 0; i--) {
        this->down(i);
    }
}

void MaxHeap::down(unsigned long k) {
    while (2*k <= this->N) {

        auto child = 2*k;

        // Set the child to the right leaf it is bigger
        if (2*k+1 <= this->N && this->arr[child] < this->arr[child+1]) {
            child += 1;
        }

        // if the parent is larger than the largest child, break
        if (this->arr[k] > this->arr[child]) break;

        // Otherwise, swap k with the largest child
        swap(this->arr[k], this->arr[child]);

        // the largest child idx now becomes k and w 'recurse'
        k = child;
    }

}

char MaxHeap::removeMax() {
    // Remove the top of the vector
    char c = this->arr[1];

    // Swap the bottom with the top
    swap(this->arr[this->N], this->arr[1]);

    // Remove the elem from th vector completely
    this->arr.pop_back();

    // decrement the size by 1
    this->N -= 1;

    // Sink down the first element
    this->down(1);

    return c;
}

void MaxHeap::insert(char c) {
    this->arr.push_back(c);
    this->N += 1;
    this->up(this->N);
}

void MaxHeap::up(unsigned long k) {

    // While we aren't at 1 and the parent is greater than the child
    while (k >= 1 and this->arr[k/2] < this->arr[k]) {

        // swap the parent and child valus so the parent is now greater
        swap(this->arr[k/2], this->arr[k]);

        // set k to the parent value.
        k = k / 2;
    }
}

void MaxHeap::print() {
    for (auto i = 1; i <= N; i++) {
        cout << this->arr[i] << " ";
    }
    cout << endl;
}

int main() {
    MaxHeap maxHeap;
    maxHeap.insert('P');
    maxHeap.insert('Q');
    maxHeap.insert('E');
    maxHeap.print();
    cout << "removeMax: " << maxHeap.removeMax() << endl;
    maxHeap.print();
    maxHeap.insert('X');
    maxHeap.insert('A');
    maxHeap.insert('M');
    maxHeap.print();
    cout << "removeMax: " << maxHeap.removeMax() << endl;
    maxHeap.print();
    maxHeap.insert('P');
    maxHeap.insert('L');
    maxHeap.insert('E');
    maxHeap.print();
    cout << "removeMax:" << maxHeap.removeMax() << endl;
    maxHeap.print();

    // Final ordr will be P, M, L, A, E, E
    return 0;
}


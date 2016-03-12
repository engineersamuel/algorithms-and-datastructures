#ifndef EPI_MAXHEAP_HPP
#define EPI_MAXHEAP_HPP

class MaxHeap {
private:
    unsigned long N = 0;
    vector<char> arr {'z'};
public:
    void maxHeapify ();
    void down(unsigned long);
    void insert(char);
    char removeMax();
    void up(unsigned long);
    void print();
};

#endif //EPI_MAXHEAP_HPP

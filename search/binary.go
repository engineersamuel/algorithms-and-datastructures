package main

import "fmt"

func binarysearch_rec(arr []int, num int, low int, high int) int {
    if low > high {
        return -1
    }

    mid := low + (high - low) / 2

    if num == arr[mid] {
        return mid;
    } else if num < arr[mid] {
        return binarysearch_rec(arr, num, low, mid - 1)
    } else {
        return binarysearch_rec(arr, num, mid + 1, high)
    }

}

func binarysearch_itr(arr []int, num int, low int, high int) int {

    for low <= high {
        mid := low + (high - low) / 2
        if num == arr[mid] {
            return mid
        } else if num < arr[mid] {
            high = mid - 1
        } else {
            low = mid + 1
        }

    }
    return -1
}

func main() {
    var num int;
    var idx int;

    fmt.Printf("Hello, world.\n")
    arr := []int { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
    num = 5
    idx = binarysearch_rec(arr, num, 0, len(arr) - 1)
    fmt.Println(fmt.Sprintf("Num: %d is at idx %d\n", num, idx))
    idx = binarysearch_itr(arr, num, 0, len(arr) - 1)
    fmt.Println(fmt.Sprintf("Num: %d is at idx %d\n", num, idx))
}

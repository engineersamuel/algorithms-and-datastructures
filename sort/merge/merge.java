public class Main {

    public static void mergeSort(int[] arr, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    public static void merge(int[] arr, int low, int mid, int high) {

        int[] temp = new int[high - low + 1];
        int left = low;
        int right = mid + 1;
        int k = 0;

        // While there are any unsorted elements, merge in the left and right hand sides into temp
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp[k] = arr[left];
                left += 1;
            } else {
                temp[k] = arr[right];
                right += 1;
            }
            k += 1;
        }

        // If there are any left overs, copy those over to the end
        if (left <= mid) {
            while (left <= mid) {
                temp[k] = arr[left];
                left += 1;
                k += 1;
            }
        } else if (right <= high) {
            while (right <= high) {
                temp[k] = arr[right];
                right += 1;
                k += 1;
            }
        }

        // Now copy over the original array with the sorted elements
        System.arraycopy(temp, 0, arr, low, temp.length);
    }

    public static void main(String[] args) {
        System.out.println("Hello World!");
        int[] arr = {8, 9, 7, 5, 2, 4, 6, 1, 3};
        mergeSort(arr, 0, arr.length - 1);
        for (int x : arr) {
            System.out.print(x + " ");
        }
    }
}

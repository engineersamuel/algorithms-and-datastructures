public class Main {

    static void quickSort(int[] arr, int start, int end) {
        if (start < end) {
            int pIdx = partition(arr, start, end);
            // All items to the left of the pivot will be less than the pivot
            quickSort(arr, start, pIdx - 1);
            // All items to the right of the pivot will be greater than the pivot
            quickSort(arr, pIdx + 1, end);
        }
    }

    public static int partition(int[] arr, int start, int end) {
        // As a naive implementation the pivot to the value at the end
        int pivot = arr[end];

        // Start at the start
        int pIdx = start;

        // Compare each value from the start of the array to the pivot.  If less than swap with pIdx.
        for (int i = start; i < end; i++) {

            // For any value that is less than the selected number (the end in this case) filter it to the left
            if (arr[i] <= pivot) {
                int temp = arr[pIdx];
                arr[pIdx] = arr[i];
                arr[i] = temp;

                // Move the pIdx up one tick
                pIdx += 1;
            }
        }

        // Now do a final swap of the end var.  We know that everything before pIdx is less than arr[end] and everything
        // to the right of pIdx is greather than arr[end]
        int temp = arr[pIdx];
        arr[pIdx] = arr[end];
        arr[end] = temp;

        return pIdx;

    }

    public static void main(String[] args) {
        int[] arr =  {8, 9, 7, 5, 2, 4, 6, 1, 3, -1};
        quickSort(arr, 0, arr.length - 1);
        for(int i = 0; i < arr.length; i++) System.out.print(arr[i] + " ");
        assert arr == new int[] {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    }
}

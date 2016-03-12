public class Main {

    public static void maxHeapfiy(Comparable[] arr, int N) {

        for (int i = N / 2; i >= 1; i--) {
            down(arr, i, N);
        }
    }

    public static void down(Comparable[] arr, int k, int N) {

        while (2*k <= N) {

            // Left child
            int child = 2*k;
            if (child+1 <= N && arr[child+1].compareTo(arr[child]) > 0) {
                child += 1;
            }

            // If the greatest child is already less than the parent, break
            if (arr[child].compareTo(arr[k]) < 0) break;

            // Swap the parent and child
            Comparable t = arr[child];
            arr[child] = arr[k];
            arr[k] = t;

            // k now equals the child
            k = child;
        }
    }

    public static void sort(Comparable[] arr, int N) {
        // While the current N idx > 1, i.e. work backwards
        while (N > 1) {

            // Swap 1 and N
            Comparable t = arr[1];
            arr[1] = arr[N];
            arr[N] = t;

            // Decrement N since N now contains the max in the 1...N array
            N -= 1;

            // 1 will contain the lowest or next to lowest element, so push it down
            down(arr, 1, N);
        }
    }

    public static void main(String[] args) {
        Integer[] arr =  {0, 8, 9, 7, 5, 2, 4, 6, 1, 3, -1};
        maxHeapfiy(arr, arr.length - 1);
        for(int i = 1; i < arr.length - 1; i++) System.out.print(arr[i] + " ");
        System.out.println();
        sort(arr, arr.length - 1);
        for(int i = 1; i < arr.length - 1; i++) System.out.print(arr[i] + " ");
        System.out.println();
    }
}

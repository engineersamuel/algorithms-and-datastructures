public class Main {

    static void shellSort(int[] arr) {

        int gap = (int)Math.floor(arr.length / 2);
        while (gap >= 1) {
            for (int i = 0; i < arr.length - gap; i++) {
                int pos = i + gap;
                while (pos - gap >= 0 && arr[pos] < arr[pos - gap]) {
                    // Java has no swap syntax for arrays, only lists
                    int temp = arr[pos];
                    arr[pos] = arr[pos - gap];
                    arr[pos - gap] = temp;
                    pos -= gap;
                }
            }
            gap = (int)Math.floor(gap / 2);
        }
    }

    public static void main(String[] args) {
        int[] arr =  {8, 9, 7, 5, 2, 4, 6, 1, 3, -1};
        shellSort(arr);
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        assert arr == new int[] {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    }
}

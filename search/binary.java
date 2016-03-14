public class Main {

    public static int binarysearch_itr(Comparable[] arr, Comparable item, int low, int high) {
        int idx = -1;

        int mid;

        while (low <= high) {
             mid = low + ((high - low) / 2);

            if (arr[mid].compareTo(item) == 0) {
                idx = mid;
                break;
            }

            // If the value is less than the mid
            if (item.compareTo(arr[mid]) < 0) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return idx;
    }

    public static int binarysearch_rec(Comparable[] arr, Comparable item, int low, int high) {
        if (low > high) return -1;

        int mid = low + ((high - low) / 2);
        if (arr[mid].compareTo(item) == 0) return mid;
        if (item.compareTo(arr[mid]) < 0) {
            return binarysearch_rec(arr, item, low, mid - 1);
        }
        return binarysearch_rec(arr, item, mid + 1, high);
    }

    public static void main(String[] args) {
        Integer[] arr = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        Comparable item = 3 ;
        int idx = binarysearch_rec(arr, item, 0, arr.length - 1);
        System.out.println("Item: " + item + " is located at index: " + idx);
        idx = binarysearch_itr(arr, item, 0, arr.length - 1);
        System.out.println("Item: " + item + " is located at index: " + idx);
    }
}

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void selection(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int min = i;

            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[i]) {
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    public static void selection(List<Integer> lst) {
        for (int i = 1; i < lst.size(); i++) {
            int min = i;

            for (int j = i + 1; j < lst.size(); j++) {
                if (lst.get(j) < lst.get(i)) {
                    min = j;
                }
            }
            // Can only use Collections.swap on List
            Collections.swap(lst, i, min);
        }
    }

    public static void main(String[] args) {
        int[] arr =  {8, 9, 7, 5, 2, 4, 6, 1, 3};
        List<Integer> lst = Arrays.asList(8, 9, 7, 5, 2, 4, 6, 1, 3);
        selection(arr);
        selection(lst);
        assert arr == new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert lst == Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9);
    }
}

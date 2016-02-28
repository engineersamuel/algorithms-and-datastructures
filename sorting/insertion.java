import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {

    public static void insertion(List<Integer> arr) {
        for (int i = 1; i < arr.size(); i++) {
            int ctr = i;
            while (ctr > 0 && arr.get(i) < arr.get(i - 1)) {
                Collections.swap(arr, i, i - 1);
                ctr++;
            }
        }
    }

    public static void main(String[] args) {
        List<Integer> arr = Arrays.asList(8, 9, 7, 5, 2, 4, 6, 1, 3);
        insertion(arr);
        assert arr == Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9);
    }
}

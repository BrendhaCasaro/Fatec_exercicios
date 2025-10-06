
public class BuscaBinaria {

    public static void sort(String[] arr) {
        String temp;

        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i].compareTo(arr[j]) > 0) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    public static int binarySearch(String[] arr, String target) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = left + ((right - left) / 2);

            if (arr[mid].equals(target)) {
                return mid;
            } else if (arr[mid].compareTo(target) < 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        String[] arr = {"BRENDHA", "CARLOS", "AMANDA", "KELLY", "ANA"};

        sort(arr);

        System.out.println("Lista ordenada:");
        for (String name : arr) {
            System.out.printf("%s \n", name);
        }
        int index = binarySearch(arr, "brendha".toUpperCase());

        System.out.printf("Indice retornado do binary search: %d \n", index);

        System.err.printf("Nome encontrado no indíce: %s \n", arr[index]);
    }

}

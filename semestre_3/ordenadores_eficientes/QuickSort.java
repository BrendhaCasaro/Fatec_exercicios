package ordenadores_eficientes;

import java.util.Arrays;

public class QuickSort {

    public static int partition(int[] array, int inicio, int fim) {
        int pivo = array[fim];
        int i = inicio-1;

        for (int j = inicio; j < fim; j++) {
          if (array[j] <= pivo) {
              i++;

              int temp = array[i];
              array[i] = array[j];
              array[j] = temp;
          }
        }

        int temp = array[i+1];
        array[i+1] = array[fim];
        array[fim] = temp;
        return i+1;
    }

    public static void quickSort(int [] array, int inicio, int fim) {
        if (inicio < fim) {
            int p = partition(array, inicio, fim);
            quickSort(array, inicio, p-1);
            quickSort(array, p+1, fim);
        }
    }


    static void main() {
        int [] array = {5, 2, 1, 3, 8, 7, 9, 4,6};

        quickSort(array, 0, array.length-1);

        for (int i=0; i<array.length; ++i)
            System.out.print(array[i]+" ");
    }
}

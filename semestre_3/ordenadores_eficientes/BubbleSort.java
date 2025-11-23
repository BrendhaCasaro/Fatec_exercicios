package ordenadores_eficientes;

import java.util.Arrays;

public class BubbleSort {

   public static int [] bubbleSort(int [] temps){
       int [] diasSemana = {1, 2, 3, 4, 5, 6, 7};

       for(int i=0;i<temps.length;i++){
           for(int j=i+1;j<temps.length;j++) {
               if (temps[i]>temps[j]){
                   int auxTemps = temps[j];
                   temps[j] = temps[i];
                   temps[i] = auxTemps;

                   int auxDias = diasSemana[j];
                   diasSemana[j] = diasSemana[i];
                   diasSemana[i] = auxDias;
               }
           }
       }

       return diasSemana;
   }


    static void main() {
        int [] array = {30, 22, 25, 23, 21,20, 40};

        System.out.println(Arrays.toString(bubbleSort(array)));

    }
}

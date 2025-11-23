package buscas_eficientes;

public class BuscaLinear {

    public static int buscaLinear(int [] array, int target) {
        for  (int i = 0; i < array.length; i++) {
            if (array[i] == target) {
                return i;
            }
        }

        return -1;
    }

    public static int buscaLinearRobos(int [] bateriaRobos) {
        for(int i = 0; i < bateriaRobos.length; i++) {
            if (bateriaRobos[i] <= 20) {
                return i;
            }
        }

        return -1;
    }


    static void main() {
        int [] array = {98, 78, 2, 25, 10, 1};

        System.out.println(buscaLinearRobos(array));
    }
}

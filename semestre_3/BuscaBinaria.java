
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
        String[] arr = {
            "FERNANDA", "ZANZA", "BRENDHA", "CARLOS", "AMANDA", "KELLY", "ANA",
            "ROBERTO", "MARCOS", "PATRICIA", "JOAO", "LUCAS", "MARIANA", "ANDRE",
            "RAFAELA", "PEDRO", "JULIANA", "GABRIEL", "CAMILA", "RICARDO",
            "VITORIA", "FABIO", "ISABELA", "SANDRA", "THIAGO", "NATALIA",
            "PAULO", "TATIANA", "RENATO", "LUANA", "ALINE", "DIEGO", "GUSTAVO",
            "CRISTINA", "BRUNO", "DANIELA", "MAURICIO", "EDUARDA", "HENRIQUE",
            "VANESSA", "RAUL", "BRENDA", "SERGIO", "SUZANA", "LEONARDO", "PAULA",
            "ARTHUR", "ELAINE", "RODRIGO", "MONICA", "CAIO", "LARISSA", "ANTONIO",
            "SILVIA", "EVANDRO", "FABIANA", "CESAR", "REGINA", "ALBERTO", "CARLA",
            "VIVIANE", "MATEUS", "ADRIANA", "FELIPE", "BEATRIZ", "EDSON", "HELOISA",
            "RAIMUNDO", "BIANCA", "WELLINGTON", "GISELE", "FELICIANO", "JESSICA",
            "MURILO", "ROBERTA", "TALITA", "CLAUDIO", "DÉBORA", "CRISTIANO",
            "ANGELA", "LUIZ", "ROSA", "ELIANA", "JONAS", "MARCELA", "OTAVIO",
            "PRISCILA", "IGOR", "KARINA", "ALEXANDRE", "SIMONE", "FÁBIO",
            "LEANDRO", "ELISA", "RAFAEL", "VICTOR", "SAMARA", "HUDSON", "TAIS"
        };

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

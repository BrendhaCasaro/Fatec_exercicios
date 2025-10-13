
import java.util.Scanner;

public class Sort {

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
        Scanner sc = new Scanner(System.in);
        String[] vetor = new String[10];
        boolean vetorPreenchido = false;

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Inserir 10 elementos no vetor");
            System.out.println("2. Ordenar vetor e imprimir");
            System.out.println("3. Buscar elemento (busca binária)");
            System.out.println("4. Sair");
            System.out.print("Escolha uma opção: ");

            int opcao = sc.nextInt();
            sc.nextLine();

            switch (opcao) {
                case 1:
                    for (int i = 0; i < vetor.length; i++) {
                        System.out.print("Digite o elemento " + (i + 1) + ": ");
                        vetor[i] = sc.nextLine();
                    }
                    vetorPreenchido = true;
                    break;

                case 2:
                    if (!vetorPreenchido) {
                        System.out.println("Vetor não preenchido ainda!");
                        break;
                    }

                    sort(vetor);

                    System.out.println("Vetor ordenado:");
                    for (String s : vetor) {
                        System.out.println(s);
                    }
                    break;

                case 3:
                    if (!vetorPreenchido) {
                        System.out.println("Vetor não preenchido ainda!");
                        break;
                    }

                    System.out.print("Digite o elemento a buscar: ");
                    String target = sc.nextLine();

                    sort(vetor);

                    int index = binarySearch(vetor, target);
                    if (index != -1) {
                        System.out.println("Elemento encontrado na posição: " + index);
                        System.out.printf("Elemento buscado: %s", vetor[index]);
                    } else {
                        System.out.println("Elemento não encontrado.");
                    }
                    break;

                case 4:
                    System.out.println("Saindo...");
                    sc.close();
                    return;

                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }
        }
    }
}

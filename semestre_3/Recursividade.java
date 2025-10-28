
import java.util.ArrayList;

public class Recursividade {

    private static int[][] memo;
// 1

    public static boolean helperPalindromo(String s, int index) {
        int l = index;
        int r = s.length() - (index + 1);

        if (l == r) {
            return true;
        }

        if (s.charAt(l) != s.charAt(r)) {
            return false;
        }

        return helperPalindromo(s, index + 1);
    }

    public static boolean palindromo(String s) {
        return helperPalindromo(s, 0);
    }

// 2
    public static int helperContadorC(String s, char cTarget, int index, int contador) {

        if (index >= s.length()) {
            return contador;
        }

        if (s.charAt(index) == cTarget) {
            contador++;
        }

        return helperContadorC(s, cTarget, index + 1, contador);

    }

    public static int contadorC(String s, char c) {
        return helperContadorC(s, c, 0, 0);

    }

// 3
    public static int somaN(int n) {
        if (n == 1) {
            return n;
        }

        return n + somaN(n - 1);
    }

// 4
    public static void tower_of_hanoi(int n) {
        helperHanoi(n, "A", "B", "C");

    }

    public static void helperHanoi(int n, String tSource, String tAuxiliary, String tTarget) {
        if (n == 1) {
            System.out.println("Mover disco 1 da torre " + tSource + " para a torre " + tTarget + "\n");
            return;
        }

        helperHanoi(n - 1, tSource, tTarget, tAuxiliary);
        System.out.println("Mover disco " + n + " da torre " + tSource + " para a torre " + tTarget + "\n");
        helperHanoi(n - 1, tAuxiliary, tSource, tTarget);
    }

// 5
    public static int knapsack(int capacidade, int[] pesos, int[] valores, int n) {
        if (n == 0 || capacidade == 0) {
            return 0;
        }
        if (memo[n][capacidade] != -1) {
            return memo[n][capacidade];
        }
        if (pesos[n - 1] > capacidade) {
            memo[n][capacidade] = knapsack(capacidade, pesos, valores, n - 1);
        } else {
            memo[n][capacidade] = Math.max(
                    valores[n - 1] + knapsack(capacidade - pesos[n - 1], pesos, valores, n - 1),
                    knapsack(capacidade, pesos, valores, n - 1));
        }
        return memo[n][capacidade];
    }

    public static ArrayList<String> getSelectedItems(int capacidade, int[] pesos, int[] valores, String[] nomes, int n) {
        ArrayList<String> itensSelecionados = new ArrayList<>();
        int w = capacidade;

        for (int i = n; i > 0; i--) {
            if (memo[i][w] != memo[i - 1][w]) {
                itensSelecionados.add(nomes[i - 1]);
                w -= pesos[i - 1];
            }
        }

        return itensSelecionados;
    }

    public static void main(String[] args) {
        // System.out.printf("%d\n", somaN(5));
        //System.out.printf("%b\n", palindromo("arara"));
        //System.out.printf("%b\n", palindromo("carlos"));

        // System.out.printf("%d\n", contadorC("arara", 'a'));
        // System.out.printf("%d\n", contadorC("banana", 'n'));
        // tower_of_hanoi(2);
        int[] valores = {20, 5, 10, 40};
        int[] pesos = {1, 2, 3, 8};
        String[] nomes = {"ItemA", "ItemB", "ItemC", "ItemD"};
        int capacidade = 5;
        int n = valores.length;

        memo = new int[n + 1][capacidade + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= capacidade; j++) {
                memo[i][j] = -1;
            }
        }

        int valorMaximo = knapsack(capacidade, pesos, valores, n);
        System.out.println("Valor máximo no caminhão: " + valorMaximo);

        ArrayList<String> itensNoCaminhao = getSelectedItems(capacidade, pesos, valores, nomes, n);
        System.out.println("Itens adicionados ao caminhão: " + itensNoCaminhao);
    }

}

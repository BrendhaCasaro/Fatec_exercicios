import java.util.Scanner;

class Agenda {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] nomes = new String[5];
        String[] telefones = new String[5];

        int opcao;

        do {
            System.out.println("\n=== MENU ===");
            System.out.println("1 - Cadastrar agenda");
            System.out.println("2 - Procurar pessoa");
            System.out.println("3 - Ver todos");
            System.out.println("4 - Sair");
            System.out.print("Escolha uma opção: ");
            opcao = sc.nextInt();
            sc.nextLine();

            switch (opcao) {
                case 1:
                    System.out.println("\nCadastro da agenda:");
                    for (int i = 0; i < nomes.length; i++) {
                        System.out.print("Digite o nome " + (i + 1) + ": ");
                        nomes[i] = sc.nextLine();

                        System.out.print("Digite o telefone de " + nomes[i] + ": ");
                        telefones[i] = sc.nextLine();
                    }
                    System.out.println("Agenda cadastrada com sucesso!");
                    break;

                case 2:
                    System.out.print("\nDigite o nome para buscar: ");
                    String busca = sc.nextLine();
                    boolean encontrado = false;

                    for (int i = 0; i < nomes.length; i++) {
                        if (nomes[i] != null && nomes[i].equalsIgnoreCase(busca)) {
                            System.out.println("Telefone de " + nomes[i] + ": " + telefones[i]);
                            encontrado = true;
                            break;
                        }
                    }

                    if (!encontrado) {
                        System.out.println("Pessoa não encontrada na agenda.");
                    }
                    break;

                case 3:
                    System.out.println("\nLista da agenda:");
                    for (int i = 0; i < nomes.length; i++) {
                        if (nomes[i] != null) {
                            System.out.println((i + 1) + " - " + nomes[i] + " : " + telefones[i]);
                        }
                    }
                    break;

                case 4:
                    System.out.println("Saindo... até logo!");
                    break;

                default:
                    System.out.println("Opção inválida, tente novamente.");
            }

        } while (opcao != 4);

        sc.close();
    }
}


import java.util.*;

public class AgendaContatos {

    public static void main(String[] args) {
        Map<String, Contato> agenda = new HashMap<>();

        Scanner sc = new Scanner(System.in);
        int option;

        do {
            System.out.println("\n=== MENU ===");
            System.out.println("1 - Inserir contato");
            System.out.println("2 - Listar todos os contatos");
            System.out.println("3 - Deletar contato");
            System.out.println("4 - Sair");
            System.out.print("Escolha uma opção: ");

            option = sc.nextInt();
            sc.nextLine();

            switch (option) {
                case 1:
                    System.out.println("Digite o nome do contato\n");
                    String nome = sc.nextLine().toUpperCase();

                    System.out.println("Digite o telefone do contato\n");
                    String telefone = sc.nextLine();

                    System.out.println("Digite o endereço do contato");
                    String endereco = sc.nextLine();

                    agenda.put(nome, new Contato(telefone, endereco));
                    break;

                case 2:
                    for (String chave : agenda.keySet()) {
                        Contato elemento = agenda.get(chave);
                        System.out.println(chave + ": " + elemento.telefone + ", " + elemento.endereco);
                    }
                    break;

                case 3:
                    System.out.println("Digite o nome do contato que você deseja deletar.\n");
                    String nomeDeletar = sc.nextLine();

                    if (agenda.get(nomeDeletar.toUpperCase()) == null) {
                        System.out.println("O contato não existe\n");
                        break;
                    }

                    agenda.remove(nomeDeletar.toUpperCase());
                    break;

                case 4:
                    System.out.println("Tchau tchau!");
                    break;

                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }
        } while (option != 4);

        sc.close();
    }
}

class Contato {

    String telefone;
    String endereco;

    Contato(String telefone, String endereco) {
        this.telefone = telefone;
        this.endereco = endereco.toUpperCase();
    }
}

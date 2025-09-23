
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;
import java.util.Scanner;

public class FilaAtendimento {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int option;
        Triagem triagem = new Triagem();
        Medico medico = new Medico();

        do {
            System.out.println("\n=== MENU ===");
            System.out.println("1 - Gerar código de atendimento para triagem");
            System.out.println("2 - Chamar próximo da fila da triagem");
            System.out.println("3 - Chamar próximo da fila do Médico");
            System.out.println("4 - Ver fila da triagem");
            System.out.println("5 - Ver fila do atendimento médico");
            System.out.println("6 - Sair");
            System.out.print("Escolha uma opção: ");

            option = sc.nextInt();
            sc.nextLine();

            switch (option) {
                case 1:
                    triagem.codigoAtendimento();
                    System.out.println("Código de atendimento gerado e adicionado à fila de triagem.");
                    break;
                case 2:
                    triagem.atendimento(medico);
                    break;
                case 3:
                    medico.atendimento();
                    break;
                case 4:
                    if (triagem.listaTriagem.isEmpty()) {
                        System.out.println("Fila de triagem vazia.");
                    } else {
                        System.out.println("Fila de triagem: " + triagem.listaTriagem);
                    }
                    break;
                case 5:
                    if (medico.listaMedico.isEmpty()) {
                        System.out.println("Fila do atendimento médico vazia.");
                    } else {
                        System.out.println("Fila do atendimento médico: " + medico.listaMedico);
                    }
                    break;
                case 6:
                    System.out.println("Saindo do programa...");
                    break;
                default:
                    System.out.println("Opção inválida! Tente novamente.");
            }

        } while (option != 6);

        sc.close();
    }
}

class Triagem {

    int codigo = 0;
    Queue<Integer> listaTriagem = new LinkedList<>();

    public void codigoAtendimento() {
        this.listaTriagem.offer(++codigo);
    }

    public void atendimento(Medico medico) {
        if (this.listaTriagem.isEmpty()) {
            System.out.println("Fila de triagem vazia\n");
            return;
        }

        Random random = new Random();

        int atual = this.listaTriagem.element();

        System.out.printf("Cliente %d em atendimento...\n", atual);
        try {
            Thread.sleep(random.nextInt(2000) + 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.printf("Fim do atendimento do cliente %d\n", atual);

        medico.adicionar();
        System.out.printf("Cliente %d encaminhado para fila do atendimento médico\n", atual);

        this.listaTriagem.poll();
    }
}

class Medico {

    Queue<Integer> listaMedico = new LinkedList<>();
    int codigo = 0;

    public void adicionar() {
        this.listaMedico.add(++codigo);
    }

    public void atendimento() {
        if (listaMedico.isEmpty()) {
            System.out.println("Fila de atendimento médico vazia\n");
            return;
        }

        Random random = new Random();

        int atual = this.listaMedico.element();

        System.out.printf("Cliente %d em atendimento\n", atual);
        try {
            Thread.sleep(random.nextInt(2000) + 1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.printf("Fim do atendimento do cliente %d", atual);
    }
}

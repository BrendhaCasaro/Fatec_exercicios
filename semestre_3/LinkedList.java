
import java.util.Scanner;

public class LinkedList {

    Element head;
    Element tail;

    LinkedList() {
        this.head = null;
        this.tail = null;
    }

    void add(Task value) {
        Element newElement = new Element(value);
        if (this.head == null && this.tail == null) {
            this.head = newElement;
            this.tail = newElement;
            return;
        }

        if (value.isUrgent == true) {
            Element old = this.head;
            newElement.next = old;
            this.head = newElement;
            return;
        }

        this.tail.next = newElement;
        this.tail = newElement;
    }

    void listAll() {
        if (this.head == null && this.tail == null) {
            System.out.println("Lista vazia");
            return;
        }

        Element current = head;
        System.out.println(head.data.description);

        while (current.next != null) {
            current = current.next;
            System.out.println(current.data.description);
        }
    }

    void concludeCurrentTask() {
        Element completed = this.head;
        this.head = this.head.next;
        completed.next = null;
    }

    void cleanList() {
        this.head = null;
        this.tail = null;
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();

        Scanner sc = new Scanner(System.in);
        int option;

        do {
            System.out.println("\n=== MENU ===");
            System.out.println("1 - Inserir tarefa");
            System.out.println("2 - Listar todas as tarefas");
            System.out.println("3 - Concluir a primeira tarefa");
            System.out.println("4 - Inserir tarefa urgente");
            System.out.println("5 - Limpar a lista");
            System.out.println("6 - Sair");
            System.out.print("Escolha uma opção: ");

            option = sc.nextInt();
            sc.nextLine();

            switch (option) {
                case 1:
                    System.out.println("Digite a descrição da tarefa:");
                    String taskDescription = sc.nextLine();

                    list.add(new Task(taskDescription, false));
                    System.out.println("Tarefa adicionada!");
                    break;

                case 2:
                    System.out.println("Todas as tarefas na lista:");
                    list.listAll();
                    break;

                case 3:
                    System.out.println("Tarefa: " + list.head.data.description + " deletada!");
                    list.concludeCurrentTask();
                    break;

                case 4:
                    System.out.println("Digite a descrição da tarefa urgente:");
                    String taskUrgentDescription = sc.nextLine();

                    list.add(new Task(taskUrgentDescription, true));
                    break;

                case 5:
                    System.out.println("Lista de tarefas limpa!");
                    list.cleanList();
                    break;

                case 6:
                    System.out.println("Finalizando execução!");
                    break;

                default:
                    System.out.println("Opção inválida, tente novamente.");
            }
        } while (option != 6);
        sc.close();
    }
}

class Task {

    String description;
    boolean isUrgent;

    Task(String description, boolean isUrgent) {
        this.description = description;
        this.isUrgent = isUrgent;
    }
}

class Element {

    Task data;
    Element next;

    Element(Task data) {
        this.data = data;
        this.next = null;
    }
}

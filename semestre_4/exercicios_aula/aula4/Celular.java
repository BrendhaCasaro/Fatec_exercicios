public class Celular {
    private Bateria bateria;
    private Status status;

    public Celular(Bateria bateria, Status status) {
        this.bateria = bateria;

        this.status = status;

        if(this.bateria.carga == 0) {
            this.status = Status.Desligado;
        }
    }

    public void recarregar() {
        //verificar se está cheio
        this.bateria.recarregar();
    }

    public void mostrarBemVindo(){
        // verificar se está vazio a bateria
        // trocar para desligado se estiver
        if(this.status == Status.Desligado) {
            System.out.println("Celular desligado");
            return;
        }
        this.bateria.descarregar();

        System.out.println("Bem Vindo!");
    }

    public void desligar() {
        // poderia ser uma função, diminuiria as linhas do if
        // bateria.estaVazio()
        // trocar para desligado se estiver
        if(this.status == Status.Desligado) {
            System.out.println("Celular já está desligado");
            return;
        }
        this.status = Status.Desligado;
        System.out.println("Tchau");
    }

    public void ligar() {
        // verificar se está vazio a bateria
        if(this.status == Status.Ligado) {
            System.out.println("Celular já ligado");
            return;
        }

        this.bateria.descarregar();
        this.status = Status.Ligado;
    }

    void mostrarInfos() {
        System.out.println(this.bateria.carga);
        System.out.println(this.status);
    }

    // em vez de usar numeros e verificações diretas, usar métodos
}

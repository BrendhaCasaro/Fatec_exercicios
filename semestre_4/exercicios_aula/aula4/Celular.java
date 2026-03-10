public class Celular {
    private Bateria bateria;
    private Status status;

    public Celular(Bateria bateria, Status status) {
        this.bateria = bateria;

        if(this.bateria.carga == 0) {
            this.status = Status.Desligado;
        }
        this.status = status;
    }

    public void recarregar() {
        this.bateria.recarregar();
    }

    public void mostrarBemVindo(){
        if(this.status == Status.Desligado) {
            System.out.println("Celular desligado");
            return;
        }
        this.bateria.descarregar();

        System.out.println("Bem Vindo!");
    }

    public void desligar() {
        if(this.status == Status.Desligado) {
            System.out.println("Celular já está desligado");
            return;
        }
        this.status = Status.Desligado;
        System.out.println("Tchau");
    }

    public void ligar() {
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
}

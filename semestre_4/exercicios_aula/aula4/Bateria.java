public class Bateria {
    public int carga;

    public Bateria(int carga) {
        this.carga = carga;
    }

    public void recarregar() {
        // poderia ser uma função, diminuiria as linhas do if
        // bateria.estaCheio()
        if(this.carga == 100) {
            System.out.println("Bateria cheia!");
            return;
        }
        this.carga++;
    }

    public void descarregar() {
        // verificar se já está vazio
        // poderia ser uma função, diminuiria as linhas do if
        if(this.carga == 0) {
            System.out.println("Bateria totalmente descarregada!");
            return;
        }
        this.carga--;
    }

}

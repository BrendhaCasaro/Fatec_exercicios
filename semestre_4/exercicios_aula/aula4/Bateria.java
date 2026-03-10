public class Bateria {
    public int carga;

    public Bateria(int carga) {
        this.carga = carga;
    }

    public void recarregar() {
        if(this.carga == 100) {
            System.out.println("Bateria cheia!");
            return;
        }
        this.carga++;
    }

    public void descarregar() {
        if(this.carga == 0) {
            System.out.println("Bateria totalmente descarregada!");
            return;
        }
        this.carga--;
    }

}

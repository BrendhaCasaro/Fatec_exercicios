public class Bateria {
    public int carga;

    public Bateria(int carga) {
        this.carga = carga;
    }

    public void recarregar() {
        this.carga++;
    }

    public void descarregar() {
        this.carga--;
    }

}

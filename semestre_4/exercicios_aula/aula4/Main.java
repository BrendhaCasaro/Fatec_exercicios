public class Main {
    public static void main(String[] args) {
        Celular celular = new Celular(new Bateria(100), 
        Status.Desligado);

        celular.ligar();
        celular.mostrarInfos();
        celular.mostrarBemVindo();
        celular.mostrarInfos();
        celular.recarregar();
        celular.mostrarInfos();
        celular.desligar();
    }

}

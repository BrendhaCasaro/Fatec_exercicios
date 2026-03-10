public class Main {
    public static void main(String[] args) {
        Celular celular = new Celular(new Bateria(0), 
        Status.Ligado);

        celular.mostrarInfos();

        /*
        celular.ligar();
        celular.mostrarInfos();
        celular.mostrarBemVindo();
        celular.mostrarInfos();
        celular.recarregar();
        celular.mostrarInfos();
        celular.desligar();
        */
    }

}

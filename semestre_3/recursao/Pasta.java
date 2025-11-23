package recursao;

public class Pasta {
    String nome;
    Pasta pasta_um;
    Pasta pasta_dois;

    Pasta(String nome) {
        this.nome = nome;
    }

    public static int contarPastas(Pasta pasta, String pastasAlvo) {
        if (pasta == null) {
            return 0;
        }

        if (pasta.nome.contains(pastasAlvo)) {
            return 1 + contarPastas(pasta.pasta_um, pastasAlvo) + contarPastas(pasta.pasta_dois, pastasAlvo);
        } else {
            return contarPastas(pasta.pasta_um, pastasAlvo) + contarPastas(pasta.pasta_dois, pastasAlvo);
        }
    }

    public static void main(String[] args) {
        Pasta p1 = new Pasta("videos_gato");

        p1.pasta_um = new Pasta("musicas_gato");

        p1.pasta_dois = new Pasta("jogos_cachorro");
        p1.pasta_dois.pasta_um = new Pasta("musicas_praia");
        p1.pasta_dois.pasta_dois = new Pasta("jogos_praia");

        System.out.println(contarPastas(p1, "videos"));
    }
}

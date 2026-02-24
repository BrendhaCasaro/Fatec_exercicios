package br.com.brendha.semestre4;

public class Cartao {
    double fatura;
    Fidelidade fidelidade;

    public Cartao(double fatura, Fidelidade fidelidade) {
        this.fatura = fatura;
        this.fidelidade = fidelidade;
    }

    public void descontoFatura() {
        double valorFinal;
        switch (this.fidelidade) {
            case GOLD:
                valorFinal = fatura * 0.98;
                System.out.println(valorFinal);
                break;
            case PLATINUM:
                valorFinal = fatura * 0.97;
                System.out.println(valorFinal);
                break;
            case BLACK:
                valorFinal = fatura * 0.95;
                System.out.println(valorFinal);
                break;
        }
    }
}
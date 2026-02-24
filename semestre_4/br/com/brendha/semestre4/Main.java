package br.com.brendha.semestre4;

public class Main {
    void main() {
        Cartao cartao = new Cartao(1000, Fidelidade.GOLD);

        cartao.descontoFatura();
    }
}

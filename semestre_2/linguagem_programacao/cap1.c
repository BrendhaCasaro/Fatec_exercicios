/*
1 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
     variável auxiliar.

2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
     long, int, float, double e um char e imprima-os no video no seguinte
     formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char

3 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
     multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
     teclado.
    Ex: menor multiplo de 13 maior que 100. Resultado: 104.

4 - Escreva um programa que receba via teclado um tempo em segundos e converta
     para horas, minutos e segundos.
     Ex.: recebe 3850 segundos que converte para 1h 4min 10s.

5 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
     outro número formado pelos dígitos invertidos do número lido.
     Ex:   NúmeroLido = 123
              NúmeroGerado = 321
*/

#include <stdio.h>

#define ex5

#ifdef ex1
int main()
{
    char opcao;

    do
    {
        int a = 10;
        int b = 20;

        printf("Valor inicial de A: %d Valor inicial de B: %d\n", a, b);

        a = a ^ b;
        b = a ^ b;
        a = b ^ a;

        printf("Valor permutado de A: %d\n Valor permutado B: %d\n", a, b);

        printf("Deseja executar novamente? (s/n): ");
        scanf(" %c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}
#endif // ex1

#ifdef ex2

int main()
{
    short s;
    char opcao;

    do
    {
        long l;
        int i;
        float f;
        double d;
        char c;

        printf("Digite um valor para short: ");
        scanf("%hd", &s);

        printf("Digite um valor para long: ");
        scanf("%ld", &l);

        printf("Digite um valor para int: ");
        scanf("%d", &i);

        printf("Digite um valor para float: ");
        scanf("%f", &f);

        printf("Digite um valor para double: ");
        scanf("%lf", &d);

        printf("Digite um caractere: ");
        scanf(" %c", &c); // O espaço antes de %c evita problemas com o buffer

        printf("\n     10       20        30        40        50        60\n");
        printf("12345678901234567890123456789012345678901234567890123456789012345\n");
        printf("%10hd %20ld %20d\n", s, l, i);
        printf("%20.2f %20.2lf %20c\n", f, d, c);

        printf("Deseja executar novamente? (s/n): ");
        scanf(" %c", &opcao);
    } while (opcao == 's' || opcao == 'S');
    return 0;
}
#endif // ex2

#ifdef ex3
int main()
{
    char opcao;

    do
    {
        int numero, limite, multiplo;

        printf("Digite um numero inteiro: ");
        scanf("%d", &numero);

        printf("Digite o limite minimo: ");
        scanf("%d", &limite);

        multiplo = ((limite / numero) + 1) * numero;

        printf("Menor multiplo de %d maior que %d: %d\n", numero, limite, multiplo);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}
#endif // ex3

#ifdef ex4
int main()
{
    int totalSegundos, horas, minutos, segundos;
    char opcao;

    do
    {
        printf("Digite o tempo em segundos: ");
        scanf("%d", &totalSegundos);

        horas = totalSegundos / 3600;
        minutos = (totalSegundos % 3600) / 60;
        segundos = totalSegundos % 60;

        printf("Tempo convertido: %dh %dmin %ds\n", horas, minutos, segundos);
        printf("Deseja executar novamente? (s/n): ");
        scanf(" %c", &opcao);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}
#endif // ex4

#ifdef ex5

int main()
{
    char opcao;

    do
    {
        int numero, invertido;

        printf("Digite um número inteiro positivo de três dígitos: ");
        scanf("%d", &numero);

        if (numero < 100 || numero > 999)
        {
            printf("Erro: O número deve ter exatamente três dígitos.\n");
            return 1;
        }

        invertido = (numero % 10) * 100 + ((numero / 10) % 10) * 10 + (numero / 100);

        printf("Número invertido: %d\n", invertido);
    } while (opcao == 's' || opcao == 'S');

    return 0;
}
#endif // ex5

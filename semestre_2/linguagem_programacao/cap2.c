/*
1 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.

2 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.

3 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.

4 - As ligacoes telefonicas são cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.

5 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!
*/

#include <stdio.h>
#include <string.h>

char option = 'n';

#define ex5
#ifdef ex1

int main()
{
    int begin = 1;
    int end = 99;
    char input;

    puts("Pense em um número para que o programa adivinhe");

    do
    {
        do
        {
            int middle = (begin + end) / 2;

            printf("Seu número é <, > ou = à %d\n", middle);
            scanf(" %c", &input);

            if (input == '=')
            {
                printf("Número encontrado: %d\n", middle);
                break;
            }

            else if (input == '>')
            {
                begin = middle + 1;
            }

            else
            {
                end = middle - 1;
            }

        } while (begin <= end);

        puts("Você deseja executar novamente? Digite y/n");
        scanf(" %c", &option);

    } while (option != 'n');
}
#endif // ex1

#ifdef ex2

int main()
{
    do
    {
        int i = 0;
        int begin = 1;
        int end = 99;
        char input;

        do
        {
            int middle = (begin + end) / 2;

            printf("Seu número é <, > ou = à %d\n", middle);
            scanf(" %c", &input);

            switch (input)
            {
            case '>':
                begin = middle + 1;
                i++;
                continue;

            case '<':
                end = middle - 1;
                i++;
                continue;

            default:
                printf("Número encontrado: %d\n", middle);
                printf("Número de execuções do loop: %d\n", i);
            }
            break;

        } while (begin <= end);

        puts("Você deseja executar novamente? Digite y/n");
        scanf(" %c", &option);

    } while (option != 'n');
}

#endif // ex2

#ifdef ex3
int main()
{

    do
    {
        int current = 0;
        int recived = 0;
        int count = 0;
        do
        {
            puts("Digite um número positivo:");
            scanf("%d", &recived);

            if (recived > 0)
            {
                current = current + recived;
                printf("current: %d\n", current);
                printf("recived: %d\n", recived);

                count++;
                printf("count: %d\n", count);
            }

        } while (recived > 0);

        current = current / count;
        printf("media: %d\n", current);

        puts("Você deseja executar novamente? Digite y/n");
        scanf(" %c", &option);

    } while (option != 'n');
}
#endif // ex3

#ifdef ex4

int main()
{
    do
    {
        char *nome[3] = {"horas", "minutos", "segundos"};
        int teto[3] = {24, 60, 60};
        int iniciais[3];

        puts("Digite abaixo o momento em que a ligação foi iniciada");
        for (int i = 0; i < 3; i++)
        {
            do
            {
                printf("Digite %s: ", nome[i]);
                scanf("%d", &iniciais[i]);
            } while (iniciais[i] < 0 || iniciais[i] > teto[i]);
        }

        int finais[3];

        printf("Digite abaixo o momento em que a ligação foi finalizada\n");
        for (int i = 0; i < 3; i++)
        {
            do
            {
                printf("Digite %s: ", nome[i]);
                scanf("%d", &finais[i]);
            } while (finais[i] < 0 || finais[i] > teto[i]);
        }

        int diff[3];

        if (finais[2] < iniciais[2])
        {
            finais[2] += 60;
            finais[1] -= 1;
        }
        diff[2] = finais[2] - iniciais[2];

        if (finais[1] < iniciais[1])
        {
            finais[1] += 60;
            finais[0] -= 1;
        }
        diff[1] = finais[1] - iniciais[1];

        if (finais[0] < iniciais[0])
        {
            finais[0] += 24;
        }
        diff[0] = finais[0] - iniciais[0];

        printf("A duração levou %d horas, %d minutos e %d segundos\n", diff[0], diff[1], diff[2]);

        puts("Você deseja executar novamente? Digite y/n");
        scanf(" %c", &option);
    } while (option != 'n');
}

#endif // ex4

#ifdef ex5
int main()
{
    do
    {
        float distancia, litros;
        puts("Digite quantos quilometros foram percorridos");
        scanf("%f", &distancia);

        puts("Digite quantos litros de gasolina foram consumidos");
        scanf("%f", &litros);

        float consumo = distancia / litros;
        printf("Consumo em km/l: %g\n", consumo);

        if (consumo <= 7)
        {
            puts("Venda o carro!");
        }
        else if (consumo >= 8 && consumo <= 14)
        {
            puts("Econômico!");
        }
        else
        {
            puts("Super econômico!");
        }

        puts("Você deseja executar novamente? Digite y/n");
        scanf(" %c", &option);

    } while (option != 'n');
}

#endif // ex5
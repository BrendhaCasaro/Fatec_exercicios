#include <stdio.h>
#include <locale.h>
#define teste
#define forzao(t) for(int i = 0; i < t; i++)

float pick_write_f(char* txt)
{
    float geral;
    printf(txt);
    scanf("%f", &geral);

    return geral;
}
int pick_write_i(char* txt)
{
    int geral;
    printf(txt);
    scanf("%d", &geral);

    return geral;
}

#define alimentArray(vet, t, txt, format)\
{\
    for(int i = 0; i < t; i++)\
    {\
        printf(txt);\
        scanf(format, &vet[i]);\
    }\
    return vet;\
}

void teste(int *vet, int t)
{
    for(int i = 0; i < t; i++)
    {
        vet[i] = i;
    }
    return vet;
}

void printArray_i(int *vet, int t, char *txt)
{
    puts(txt);
    for(int i = 0; i < t; i++)
    {
        printf("%d ", vet[i]);
    }
    puts("");
}

void printArray_f(float *vet, int t, char *txt)
{
    puts(txt);
    for(int i = 0; i < t; i++)
    {
        printf("%g ", vet[i]);
    }
    puts("");
}

//void TipoVar(void *tipo){
//    return tipo;
//}

#ifdef teste
int main ()
{
    int vetT[2];
    alimentArray(vetT, 2, "Digite dois numeros", "%d");

    for(int i = 0; i < 2; i++)
    {
        printf("%d\n", vetT[i]);
    }
}


#endif // teste
#ifdef ex1

int main ()
{
    int A[12];
    for(int i = 0; i < 12; i++)
    {
        do
        {
            printf("Digite o %d numero: \n", i + 1);
            scanf("%d", &A[i]);

            if(A[i] < 0)
            {
                printf("Numero invalido");
            }
        }
        while(A[i] < 0);
    }
    for(int i = 0; i < 12; i++)
    {
        if(A[i] > 121)
        {
            printf("%d\n", A[i]);
        }
    }
    return 0;
}
#endif //ex1

#ifdef ex19
int main()
{
    int vetA[6], vetB[6], vetC[12];

    for(int i = 0; i < 6; i++)
    {
        do
        {
            printf("Digite o numero par: ");
            scanf("%d", &vetA[i]);
            if(vetA[i] %2 != 0)
            {
                printf("Numero invalido, ele � impar\n");
            }
        }
        while(vetA[i] %2 != 0);

    }

    for(int i = 0; i < 6; i++)
    {
        do
        {
            printf("Digite o numero impar: ");
            scanf("%d", &vetB[i]);
            if(vetB[i] %2 == 0)
            {
                printf("Numero invalido, ele � par\n");
            }
        }
        while(vetB[i] %2 == 0);
    }

    for(int i = 0, j = 6; i < 12, j < 12; i++, j++)
    {
        vetC[i] = vetA[i];
        vetC[j] = vetB[i];
    }
    for(int i = 0; i < 12; i++)
    {
        printf("%d\n", vetC[i]);
    }
}
#endif //ex19

#ifdef ex18
//Leia 8 elementos (valores inteiros) para os vetores A e B de uma dimens�o do tipo vetor. Construir
//vetores C e D de mesmo tipo e dimens�o. O vetor C deve ser formado pelos elementos de �ndice
//�mpar dos vetores A e B, e O vetor D deve ser formado pelos elementos de �ndice par dos vetores
//A e B. Apresente os conte�dos de todos os vetores.

int main ()
{
    int vetA[8], vetB[8], vetC[8], vetD[8];
    setlocale(LC_ALL,"");

    alimentArray(int, vetA, 8, "Digite 8 n�meros para o vetor A: ", "%i");

    alimentArray(int, vetB, 8, "Digite 8 n�meros para o vetor B: ", "%i");

    for(int i = 0, j = 0, k = 0; i < 8 && j < 8; i++)
    {
        if(i %2 != 0)
        {
            vetC[j] = vetA[i];
            vetC[j + 1] = vetB[i];
            j = j + 2;
        }
        else
        {
            vetD[k] = vetA[i];
            vetD[k + 1] = vetB[i];
            k = k + 2;
        }
    }

    printf("Valores do vetor C:\n");
    for (int k = 0; k < 8; k++)
    {
        printf("%d ", vetC[k]);
    }
    printf("\n");

    printf("Valores do vetor D:\n");
    for (int k = 0; k < 8; k++)
    {
        printf("%d ", vetD[k]);
    }
    printf("\n");
}
#endif // ex18


#ifdef ex17
//Receba o sal�rio e o n�mero de identifica��o gerado pelo programador contendo no m�ximo 13
//pessoas. A quantidade de indiv�duos ser� definida pelo usu�rio. Armazene esses dados em dois
//vetores, o primeiro contendo os sal�rios e o segundo contendo os n�meros de identifica��o.
//Calcule e mostre:
//a) Armazene em um vetor os n�meros de identifica��o de todas as pessoas que apresentam
//a maior sal�rio.
//b) Armazene num outro vetor os n�meros de identifica��o de todas as pessoas que
//apresentam a menor sal�rio encontrado. Mostre o conte�do de todos os vetores.


int main ()
{
    setlocale(LC_ALL, "");
    float salario[13];
    int id[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int users;
    float maior = 0, menor;

    do
    {
        users = pick_write_i("Informe a quantidade de usu�rios: ");
        if(users < 0)
        {
            puts("Valor inv�lido");
        }
    }
    while(users < 0);

    for(int i = 0; i < users; i++)
    {
        do
        {
            salario[i] = pick_write_f("Digite o sal�rio do usu�rio: ");
            if(salario[i] <= 0)
            {
                puts("Valor inv�lido");
            }
        }
        while(salario[i] <= 0);
    }

    menor = salario[0];

    for(int i = 0; i < users; i++)
    {
        float atual = salario[i];
        printf("%g\n", atual);

        if(atual < menor)
        {
            menor = atual;
        }
        if(atual > maior)
        {
            maior = atual;
        }
//        printf("Maior: %g\n Menor: %g\n", maior, menor);
    }

    int contMaior = 0, contMenor = 0;
    forzao(users)
    {

        if(salario[i] == maior)
        {
            contMaior++;
        }
        if(salario[i] == menor)
        {
            contMenor++;
        }
    }
//    printf("Maior: %i\n Menor: %i\n", contMaior, contMenor);

    int vetID_maior[contMaior];
    int vetID_menor[contMenor];

    int I_maior = 0, I_menor = 0;
    forzao(users)
    {
        int userID_atual = id[i];
        float userSal_atual = salario[i];

        if(userSal_atual == maior)
        {
            vetID_maior[I_maior] = userID_atual;
            I_maior++;
        }
        if(userSal_atual == menor)
        {
            vetID_menor[I_menor] = userID_atual;
            I_menor++;
        }
    }
    printArray(float, salario, users, "Sal�rios: ", "%g ");
    printArray(int, vetID_maior, contMaior, "IDs dos maiores sal�rios: ", "%d ");
    printArray(int, vetID_menor, contMenor, "IDs dos menores sal�rios: ", "%d ");
    printArray(int, id, users, "Todos os IDs dispon�veis: ","%d ");
}
#endif // ex17


#ifdef ex16
//Leia 12 elementos inteiros para o vetor A e construa o vetor B com a mesma dimens�o,
//observando a seguinte lei de forma��o: �Todo elemento do vetor A que for �mpar deve ser
//multiplicado por 2; caso contr�rio, o elemento do vetor A deve permanecer constante�. Exiba o
//conte�do dos dois vetores.

int main ()
{
    int vetA[12], vetB[12];

    alimentArray(vetA, 6, "Digite 12 valores:", "%i ");

//    teste(vetA, 12);
    printArray_i(vetA, 12, "");
    forzao(12)
    {
        if(vetA[i] %2 != 0)
        {
            vetB[i] = vetA[i] * 2;
        }
        else
        {
            vetB[i] = vetA[i];
        }
    }
    printArray_i(vetA, 12, "Vetor A: ");
    printArray_i(vetB, 12, "Vetor B: ");
}
#endif // ex16

#ifdef ex15
//Efetue a leitura de dez elementos para o vetor A. No final, apresente a somat�ria de todos os
//elementos do vetor A que sejam �mpares. Armazene no vetor B a posi��o em que est�o
//armazenados os n�meros �mpares. Mostre o conte�do dos dois vetores.

int main ()
{
    int vetA[10], vetB[10] = {0}, impares[10] = {0}, somaImpares;

    teste(vetA, 10);

    forzao(10)
    {
        int j = 0;
        if(vetA[i] %2 != 0)
        {
            impares[i] = vetA[i];
            vetB[i] = i;
            j++;
        }
        somaImpares = somaImpares + vetA[i];
    }
    printArray_i(vetA, 10, "Valores do vetor A: ");
    printArray_i(impares, 10, "Valores impares do vetor A: ");
    printArray_i(vetB, 10, "Vetor B: ");
    printf("Soma dos valores impares do vetor A: %d", somaImpares);
}
#endif // ex15

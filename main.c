#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#define LINHAS 7
#define COLUNAS 14
#include <time.h>
#include <windows.h>

int eixoX, eixoY, contador, opcao, contador2;
int rng[15], rngmaster, tempo1, tempo2, tempo3, opcao2;
#include "enemy_movement.c"

void printcomandos()
{
    printf("\n\nCOMANDOS:\n");
    printf("W - Cima\n");
    printf("A - Esquerda\n");
    printf("S - Baixo\n");
    printf("D - Direita\n");
    printf("5 - Sair do jogo");

}
void ganhoubot(char image[LINHAS][COLUNAS])
{
    contador2 = 0;
    printf("\nO inimigo ganhou em %d segundos.\n", tempo1);
    printf("\n\nAgora eh a sua vez, tente fazer o menor tempo que conseguir.\n");
    getch();
    opcao2 = 1;
    system("cls");
    zeraPosicao();
    preencheMatrix(image);
    verificador(image);
    random(image);

    while (contador != 0)
    {
        if (contador2 > 0)
        {
            opcao = 0;
            while (opcao != '4' && opcao != '5')
            {
                printf("Voce perdeu,digite:\n1 - Tentar novamente\n2 - Encerrar o jogo");
                opcao = getch() + 3;
                system("cls");
            }
            if (opcao == '4')
            {
                system("cls");
                system("color 7");
                zeraPosicao();
                preencheMatrix(image);
                verificador(image);
                random(image);
                contador2 = 0;
            }
            else if (opcao == '5')
                return 0;
        }
        jogar(image);
    }
    return main();
}

void random(char image[LINHAS][COLUNAS])
{
    int quantosrand = 0, randx = 0, randy = 0;
    srand(time(NULL));

    quantosrand = 10 + rand() % 4;

    for (int i = 0; i <= quantosrand; i++)
    {
        randx = rand() % 20;
        randy = rand() % 9;
        image[randy][randx] = '+';
    }
    if (image[0][0] == '+')
        image[0][0] = 'M';
}

void verificador(char image[LINHAS][COLUNAS])
{

    int i, j, contador2 = 0;
    contador = 0;

    if (opcao == '5')
        return 0;

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (image[i][j] == '#')
                contador++;
        }
    }

    if (contador == 0 && opcao == '1')
        ganhou(image);
    if (contador == 0 && opcao == '2' && opcao2 == 0)
        ganhoubot(image);
    else if (contador == 0 && opcao2 == 1)
        ganhou(image);
}

void ganhou()
{
    printf("\n\n\nParabens, voce terminou o jogo");
    if (opcao2 == 1)
    {
        printf("\n\nVoce terminou em %d segundos", tempo2);

        if (tempo2 > tempo1)
            printf("\n\n\n\tVOCE PERDEU PARA O BOT");

        if (tempo2 < tempo1)
            printf("\n\n\n\tVOCE GANHOU DO BOT");
    }
    else
    {
        printf("\n\nVoce terminou em %d segundos", tempo3);
    }

    printf("\n\n\nPressione qualquer botao para encerrar o programa");

    getch();

    opcao2 = 1;
    opcao = '5';

    return main();
}

void perdeu(char image[LINHAS][COLUNAS])
{
    if (opcao != '1')
        contador2 = 1;
    else
    {
        system("cls");
        system("color 4");
        printf("\n\t  Voce perdeu");
        printf("\n\nPressione qualquer botao para tentar novamente\n\n");
        printMatrix(image);
        getch();
        system("color 7");
        eixoX = 0;
        eixoY = 0;
        contador = 0;
        preencheMatrix(image);
        random(image);
        return 0;
    }
}

void zeraPosicao()
{
    eixoX = 0;
    eixoY = 0;
    contador = 0;
}

void preencheMatrix(char image[LINHAS][COLUNAS])
{
    int i, j;
    strcpy(image[0], "M####################");
    strcpy(image[1], "#####################");
    strcpy(image[2], "#####################");
    strcpy(image[3], "#####################");
    strcpy(image[4], "#####################");
    strcpy(image[5], "#####################");
    strcpy(image[6], "#####################");
    strcpy(image[7], "#####################");
    strcpy(image[8], "#####################");
}

void printMatrix(char image[LINHAS][COLUNAS])
{
    int i, j;
    if (opcao == '1')
    {
        tempo3 = clock() / CLOCKS_PER_SEC;
        printf("X:%d,Y:%d \t\t%d segundos\n", eixoX, eixoY, tempo3);
    }
    if (opcao != '1' && opcao2 == 0)
    {
        tempo1 = (clock() / CLOCKS_PER_SEC) - tempo3;
        printf("X:%d,Y:%d \t\t%d segundos\n", eixoX, eixoY, tempo1);
    }
    else if (opcao != '1' && opcao2 == 1)
    {
        tempo2 = (clock() / CLOCKS_PER_SEC) - (tempo1 + tempo3);
        printf("X:%d,Y:%d \t\t%d segundos\n", eixoX, eixoY, tempo2);
    }

    for (i = 0; i < LINHAS; i++)
    {
        for (j = 0; j < COLUNAS; j++)
        {
            if (j == 0)
            {
                printf("\t\t\t\t\t");
            }
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
}

void cima(char image[LINHAS][COLUNAS])
{
    image[eixoY][eixoX] = '-';
    if (image[eixoY - 1][eixoX] == '+')
        perdeu(image);
    else
    {
        image[eixoY - 1][eixoX] = 'M';
        eixoY--;
    }
}

void baixo(char image[LINHAS][COLUNAS])
{
    image[eixoY][eixoX] = '-';
    if (image[eixoY + 1][eixoX] == '+')
        perdeu(image);
    else
    {
        image[eixoY + 1][eixoX] = 'M';
        eixoY++;
    }
}

void esquerda(char image[LINHAS][COLUNAS])
{
    image[eixoY][eixoX] = '-';
    if (image[eixoY][eixoX - 1] == '+')
        perdeu(image);
    else
    {
        image[eixoY][eixoX - 1] = 'M';
        eixoX--;
    }
}

void direita(char image[LINHAS][COLUNAS])
{
    image[eixoY][eixoX] = '-';
    if (image[eixoY][eixoX + 1] == '+')
        perdeu(image);
    else
    {
        image[eixoY][eixoX + 1] = 'M';
        eixoX++;
    }
}

void jogar(char image[LINHAS][COLUNAS])
{
    int movimento = 0;

    printMatrix(image);
    printcomandos();
    verificador(image);
    movimento = getch();
    switch (movimento)
    {
    case 'w':

        if (eixoY > 0)
        {
            cima(image);
        }

        break;

    case 's':

        if (eixoY < LINHAS - 1)
        {
            baixo(image);
        }

        break;

    case 'a':

        if (eixoX > 0)
        {
            esquerda(image);
        }

        break;

    case 'd':

        if (eixoX < COLUNAS - 1)
        {
            direita(image);
        }
        break;

    case '5':
        opcao2=1;
        opcao='5';
        main();
        break;
    }

    system("cls");
}

int menu()
{
    printf("Menu:\n");
    printf("1 - Jogar solo\n");
    printf("2 - Jogar contra o computador\n");
    printf("3 - Sair\n");
    printf("Digite uma opcao: ");
    opcao = getch();
    return opcao;
}

int main()
{
    char image[LINHAS][COLUNAS];
    int movimento = 0;

    system("color 7");
    system("cls");

    eixoX = 0;
    eixoY = 0;
    contador = 0;
    contador2 = 0;

    if (opcao2 == 1 || opcao == '5')
    {
        return 0;
    }
    else
    {
        opcao = menu();
    }

    preencheMatrix(image);
    random(image);

    while (opcao != '3' && opcao != '2' && opcao != '1')
    {
        printf("\n\nDigite uma opcao valida");
        opcao = getch();
    }
    switch (opcao)
    {
    case '1':
        system("cls");
        while (opcao2 != 1)
            jogar(image);
        break;

    case '2':

        while (opcao == '2' && contador2 == 0)
        {
            cheatengine(image);
            if (tempo1 >= 45){
                printf("\n\nO tempo de termino do bot sera estimado...\n\n");
                ganhoubot(image);
            }
        }
    }

    return 0;
}

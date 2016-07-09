#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define VAZIO ' '
#define PAREDE '|'
#define OBSTACULO 'o'
#define JOGADOR '^'

void inicializa_mapa(char m[20][20])
{
    int i, j;

    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            m[i][j] = VAZIO;
            if(j == 4 || j == 15)
                m[i][j] = PAREDE;
            //printf("%c", m[i][j]);
        }
        //printf("\n");
    }
}

void desenha_mapa(char m[20][20], int coluna_jogador)
{
    int i, j;
    system("cls");
    for(i = 0; i < 20; i++){
        for(j = 0; j < 20; j++){
            if((i == 19) && (j == coluna_jogador))
                printf("%c", JOGADOR);
            else
                printf("%c", m[i][j]);
        }
        printf("\n");
    }

}

void atualiza_mapa(char m[20][20])
{

    int i, j, pos_helicoptero;

        for(i = 18; i >= 0; i--)
            for(j = 0; j < 20; j++)
                m[i+1][j] = m[i][j];

        for(i = 0; i < 20; i++)
           m[0][i] = VAZIO;

        m[0][4] = PAREDE;
        m[0][15] = PAREDE;

        if((rand() % 100) < 30) {
        pos_helicoptero = 5 + (rand() % 10);
        m[0][pos_helicoptero] = OBSTACULO;
        }
}


int main()
{
    char dig, mapa[20][20];
    int  parede,coluna = 10;

    inicializa_mapa(mapa);

    desenha_mapa(mapa, coluna);
    while(mapa[19][coluna] != OBSTACULO)
        {
            dig = getch();
            if((dig == 'a' || dig == 'A') && (coluna >5))
            {
                coluna--;
                atualiza_mapa(mapa);
                desenha_mapa(mapa, coluna);

            }

            if((dig == 'd' || dig == 'D') && (coluna < 14))
            {
                coluna++;
                atualiza_mapa(mapa);
                desenha_mapa(mapa, coluna);

            }


            if((dig == 'w' || dig == 'W'))
            {
                atualiza_mapa(mapa);
                desenha_mapa(mapa, coluna);

            }

        }

    return 0;
}
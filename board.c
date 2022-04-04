#include "board.h"

int c=0, i=0, j=0, tam=0;
int x=0, y=0;
char posicao[4];
//gay

int createboard(void)
{
    c=linhas, i=0, j=0;
    int meio = linhas/2;

    ptr = malloc((c * c) * sizeof(int) * sizeof(int));

    for (i=0; i < c; i++) {
        for (j=0; j < c; j++){
            ptr[i*c+j] = '.';

            if( (i==0 && (j==0 || j == c-1)) || (i==c-1 && (j==0 || j == c-1)) ){
                ptr[i*c+j] = '$';   // i = numero de linha menos 1 ; j = numero de coluna menos um
            }

            if( (i==j && (i!=0 && i!=c-1)) || (i==c-j-1 && (i!=0 && i!=c-1)) ){
                ptr[i*c+j] = '2';
            }

            if( (i==meio && (j==0 || j==c-1)) || (j==meio && (i==0 || i==c-1)) ){
                ptr[i*c+j] = '3';
            }

            if( ((i==1 || i==c-2) && (j==meio-1 || j==meio+1)) || ((j==1 || j==c-2) && (i==meio-1 || i==meio+1)) ){
                ptr[i*c+j] = '#';
            }
        }
    }

    //ptr[ml*c+mc] = 'a';

    return 0;
}

void printboard(void)
{
    c=linhas;

    for (i=0; i < c; i++) {

        if (i<9) printf(" %d ", i+1);
        else printf("%d ", i+1);

        for (j=0; j < c; j++)
            printf("%c ", ptr[i * c + j]);

        printf("\n");
    }
    printf("   %.*s", linhas*2, "A B C D E F G H I J K L M N O");
    printf("\n");
}


int pontos()
{
    int points=0, z=0;
    printf("\n%c\n", jogada[0]);
    for (i=0 ; i < tam ; i++) {
        if (jogada[i] == 'a'){
            points = points + 1;
        }
        if (jogada[i] == 'b'){
            points = points + 3;
        }
        if (jogada[i] == 'c'){
            points = points + 3;
        }
        if (jogada[i] == 'd'){
            points = points + 2;
        }
        if (jogada[i] == 'e'){
            points = points + 1;
        }
        if (jogada[i] == 'f'){
            points = points + 4;
        }
        if (jogada[i] == 'g'){
            points = points + 2;
        }
        if (jogada[i] == 104){
            points = points + 4;
        }
        if (jogada[i] == 105){
            points = points + 1;
        }
        if (jogada[i] == 106){
            points = points + 8;
        }
        if (jogada[i] == 107){
            points = points + 5;
        }
        if (jogada[i] == 108){
            points = points + 1;
        }
        if (jogada[i] == 109){
            points = points + 3;
        }
        if (jogada[i] == 110){
            points = points + 1;
        }
        if (jogada[i] == 111){
            points = points + 1;
        }
        if (jogada[i] == 112){
            points = points + 3;
        }
        if (jogada[i] == 113){
            points = points + 10;
        }
        if (jogada[i] == 114){
            points = points + 1;
        }
        if (jogada[i] == 115){
            points = points + 1;
        }
        if (jogada[i] == 116){
            points = points + 1;
        }
        if (jogada[i] == 117){
            points = points + 1;
        }
        if (jogada[i] == 118){
            points = points + 4;
        }
        if (jogada[i] == 119){
            points = points + 4;
        }
        if (jogada[i] == 120){
            points = points + 8;
        }
        if (jogada[i] == 121){
            points = points + 4;
        }
        if (jogada[i] == 122){
            points = points + 10;
        }
        if (jogada[i]<97 || jogada[i]>122){
            z =z + 1;
        }

    }
    printf("%d\n", points);

}

void inputwords(void)
{
    int counter=0;

    if(posicao[2] == 'H'){
        for(j=x; j<x+tam; j++){
            ptr[y * linhas + j] = jogada[counter];
            counter++;
        }
    }
     if(posicao[2] == 'V'){
        for(j=y; j<y+tam; j++){
            ptr[j * linhas + x] = jogada[counter];
            counter++;
        }
    }
    pontos();
}


int validation()
{
    int err=0, hashtags=0;
    int meio = linhas/2;
    c = linhas;
    do{
        hashtags=0;
        printf("Insira uma jogada (por exemplo: A4H jogada): \n");
        scanf("%s %s", &posicao, &jogada);

        x = posicao[0] - 65; //coluna j
        y = posicao[1] - 49; //linha i
        tam = strlen(jogada);
        if(posicao[2] == 'H'){
            if(x + tam > linhas){
                printf("Jogada inválida\n");
                err++;
            }else inputwords();
        }
        if(posicao[2] == 'V'){
            if(y + tam > linhas){
                printf("Jogada inválida\n");
                err++;
            }else inputwords();
        }
        for (i=0; i < c; i++) {
            for (j=0; j < c; j++){
                if(ptr[i*c+j] == '#'){
                    hashtags++;
                }
            }
        }
        if(hashtags != 8){
            printf("Jogada inválida\n%d\n", hashtags);
            createboard();
        }
        printboard();
    }while(posicao[0] != 'x');
    return 0;
}

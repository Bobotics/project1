#include "main.h"
#include "board.h"


int main()
{
    printf("Insira um numero de linhas impar do tabuleiro (7-15): ");
    scanf("%d", &linhas);

    while(linhas < 7 || linhas > 15 || linhas % 2 == 0){
        printf("Insira um número correto de linhas: ");
        scanf("%d", &linhas);
    }

    createboard();
    printboard();

    read();

    //compare();

    validation();

    printboard();

    free(ptr);


    return 0;

}

void read()
{

//inserir ficheiro "/usr/share/dict/linux.words"

    int i = 0;
    int tot = 0;
    char dicname[3];

    printf("\nDiga que linguagem quer usar (eng ou pt): ");
    scanf("%s", &dicname);

    if(strcmp(dicname, "eng") == 0){
        fr = fopen("dic.txt", "r");
        }else if(strcmp(dicname, "pt") == 0){
            fr = fopen("dicpt.txt","r");
        }



    int chr = getc(fr);

    while (chr != EOF)
    {
        //Count whenever new line is encountered
        if (chr == '\n'){
            count_lines++;
        }
        //take next character from file.
        chr = getc(fr);
    }
    fclose(fr);
    printf("\n%d\n", count_lines);

    if(strcmp(dicname, "eng") == 0){
        fr = fopen("dic.txt","r");
    }else fr = fopen("dicpt.txt","r");

    while(fgets(line[i], LSIZ, fr))
	{
        line[i][strlen(line[i]) - 1] = '\0';
        i++;
    }
    tot = i;
	printf("\n The content of the file <dic.txt>  are : \n");
    for(i = 0; i < tot; ++i)
    {
        printf(" %s\n", line[i]);
    }
    printf("\n");

    printf("%s\n", line[3]);


}

void compare()
{
    int v = 0, i=0;
    char jogada[20];
    printf("Insira uma palavra: ");
    scanf("%s", &jogada);
    for(i = 0; i < count_lines; i++){
        if(strcmp(line[i], jogada) == 0){
            printf("yes\n");
            v++;
        }else printf("no\n");
    }
    if(v != 0){
        printf("Jogada válida");
    }else printf("Jogada inválida");
}







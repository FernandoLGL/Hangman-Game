#ifndef SCOREBOARD_H
    #define SCOREBOARD_H


#include <stdio.h>
#include <stdlib.h>

scoreboard()
{
system("cls");
    // Titulo
    printf("\n");
    linhah("Jogo da Forca",'-');
    puts("\t\t\tJogo da Forca");
    linhah("Jogo da Forca",'-');

    //subtitulo
    printf("\n\n");
    linhah("Scoreboard",'-');
    puts("Scoreboard");
    linhah("Scoreboard",'-');

    // menu
    char linha [50];
    FILE * fptr;
    fptr = fopen("scoreboard.txt", "r");
   

    while(!feof(fptr)){
        fgets(linha, 50, fptr);
        printf("%s", linha);
    }

    fclose(fptr);
  
    //

    printf("\n\n\n\n");
    printf("Digite qualquer tecla para retornar ao menu.\n");
    getch();
    main();

}
void addscore(int pontos){

    FILE *scoreboardFile = fopen("scoreboard.txt", "a");

    struct scoreboard
    {
        char nome[20];
        int pontos;
    }jogador;


    jogador.pontos = pontos;

    printf("\n\nDiga seu nome: ");
    scanf("%s",&jogador.nome);

    printf("Parabens, %s, voce fez %d pontos!\n\nDigite qualquer tecla para sair.", jogador.nome, jogador.pontos);
    getch();

    fprintf(scoreboardFile, "%s : %d Pontos.\n", jogador.nome, jogador.pontos);
    fclose(scoreboardFile);

}


#endif

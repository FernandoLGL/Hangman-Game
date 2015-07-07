#include <stdio.h>
config(comando)
{
system("cls");
    // Titulo
    printf("\n");
    linhah("Jogo da Forca",'-');
    puts("\t\t\tJogo da Forca");
    linhah("Jogo da Forca",'-');

    //subtitulo
    printf("\n\n");
    linhah("Configuracoes",'-');
    puts("Configuracoes");
    linhah("Configuracoes",'-');

    // menu
    printf("\n\n\n");
    puts("\t\t\t1 - Opcao1\n");
    puts("\t\t\t2 - Opcao2\n");
    puts("\t\t\t3 - Opcao3\n");
    puts("\t\t\t4 - Retornar ao menu");
    //

    //escolha
    printf("\n\n\n\n\n\n\n");
    printf("Digite o comando: ");
    comando = getche();
    switch(comando){
    case '1': system("cls"); jogo(); break;
    case '2': system("cls"); config(); break;
    case '3': system("cls"); scoreboard(); break;
    case '4': return 0;
    default : system("cls"); printf("\n\t\t\tComando Invalido.\n"); return 0;}
}


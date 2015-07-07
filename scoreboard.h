#include <stdio.h>
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
    char lugar[0][10];
    printf("\n\n\n");
    printf("\t\t\t1 - %s\n", lugar[0]);
    printf("\t\t\t2 - %s\n", lugar[1]);
    printf("\t\t\t3 - %s\n", lugar[2]);
    printf("\t\t\t4 - %s\n", lugar[3]);
    printf("\t\t\t5 - %s\n", lugar[4]);					// <<<< VER DEPOIS COMO FAZER
    printf("\t\t\t6 - %s\n", lugar[5]);
    printf("\t\t\t7 - %s\n", lugar[6]);
    printf("\t\t\t8 - %s\n", lugar[7]);
    printf("\t\t\t9 - %s\n", lugar[8]);
    printf("\t\t\t10 - %s\n", lugar[9]);
    //

    printf("\n\n\n\n");
    printf("Digite qualquer tecla para retornar ao menu.\n");
    getch();
    main();

}

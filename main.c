#include "scoreboard.h"
#include "config.h"
#include "desenho.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sorte,score,vidas,tpalavra;
char continuar;
char iuser[11];
int acertos,vacertos, fix;
score = 0;
vidas = 6;
acertos = 0;

linhah(n,x)
{
    int i;
    if ( n == "Jogo da Forca")
    {
        printf("\t\t\t");
    }
    for (i=0; i<strlen(n); i++)
    {
        printf("%c",x);
    }
    printf("\n");
}

char palavra[][11]=
{

    "Bolo",
    "Computador",
    "Monitor",
    "Celular",
    "Cimento",
    "Laranja"
};

char dica[][20]=
{

    "Sobremesa",
    "Maquina",
    "Saida de Video",
    "Aparelho Eletronico",
    "Construcao",
    "Fruta"
};

jogo(){

	char arriscar[11];

	srand(time(0));

	sorte = rand() % 6; // 6 = numero de palavras


	tpalavra = strlen(palavra[sorte]);


    char palavradavez[11] = { 0,0,0,0,0,0,0,0,0,0,0 };



    while(acertos < tpalavra){



    	if(vidas == 6){
    		system("cls");
    		inicio();
    	}

		if (vidas == 5){
			system("cls");
	  		cabeca();
  		}
  		else if ( vidas == 4){
  			system("cls");
	  		corpo();
  		}
  		else if (vidas == 3){
  			system("cls");
	  		bracoe();
  		}
  		else if (vidas == 2){
  			system("cls");
	  		bracod();
  		}
  		else if ( vidas == 1 ){
  			system("cls");
	  		pernae();
  		}
  		else if ( vidas == 0 ){
  			system("cls");
  			pernad();
  			puts("\n\n\t\t\t Voce Perdeu!!!");
  			return 0;
  		}


    	printf("\t\t\t");

    	for(i=0; i < tpalavra; i++){


	  		if(palavradavez[i] == 1){

	  			printf("%c", palavra[sorte][i]);
	  			putchar(' ');

	  		} else {
	  			putchar('_');
	  			putchar(' ');

	  		}
	  	}

	  	printf("\n");

    	printf("\n\n\t\tDica: %s\n\n", dica[sorte]);
    	printf("\t\tA palavra possui %d letras\n\n",tpalavra);
    	puts("Se quiser arriscar a palavra inteira, digite 'arriscar'\n Se quiser sair, digite 'sair'\n\n");
	    puts("Digite uma letra:");

	    fgets(iuser, 11, stdin );

	  	if(strncmp(iuser, "arriscar", 8) == 0 ){

	  		puts("Digite a palavra:\n");

	  		fgets(arriscar, 11, stdin);

	  		if(strcmp(arriscar, palavra[sorte]) == 0){

	  			puts("\n\n\t\t\tParabens!! Voce venceu!! Digite qualquer tecla para continuar. \n");

	  			score = tpalavra * 3;

	  			getch();

	  			//score();


	  		}

	  		else {

	  			puts("Voce perdeu.");

	  			score = 0;

	  			return 0;
	  		}

	  	}

	  	while(strncmp(iuser, "sair", 4) == 0){

	  		puts("Sair no meio da partida ocasionara na perda de seus pontos. Continuar?(Y/N)\n");
	  		continuar = getch();

	  		switch(tolower(continuar)){
	  			case 'y':
	  				return 0;
	  			case 'n':
	  				break;
	  		}
	  		break;
	  	}


	  	vacertos = acertos;

	  	for(i=0; i < tpalavra; i++){

	  			// se o caractere já foi transformado pra 1, então ele já foi reconhecido antes
	  		if(palavradavez[i] == 1){
	  			fix = 0;
	  				 // tentativa de fix 2 certas seguidas = erro
	  			continue;
	  		}

	  			// iuser[0] primeira letra do que o usuario digitar

	  		if(iuser[0] == palavra[sorte][i]){
	  			palavradavez[i] = 1;
	  			acertos = acertos + 1;
	  				//usuario acertou

	  		}

	  		else {
	  			fix = 1;
	  		}


	  	}
	  		// o numero de acertos não mudou, então o usuário errou.
	  	if ((vacertos == acertos) && (fix == 1)) {

	  			vidas = vidas - 1; // usuario errou

		  	}


    }

    puts("\n\n\t\t\tParabens! Voce venceu!\n");

}



main(comando)
{

    //titulo

    linhah("Jogo da Forca",'-');
    puts("\t\t\tJogo da Forca");
    linhah("Jogo da Forca",'-');
    //

    // menu
    printf("\n\n\n\n\n");
    puts("\t\t\t1 - Jogar\n");
    puts("\t\t\t2 - Configuracoes\n");
    puts("\t\t\t3 - Scoreboard\n");
    puts("\t\t\t4 - Sair");
    printf("\n\n\n\n\n\n\n");
    //

    // escolhas
    printf("Digite o comando: ");
    comando = getche();
    switch(comando){
    case '1': system("cls"); jogo(); break;
    case '2': system("cls"); config(); break;
    case '3': system("cls"); scoreboard(); break;
    case '4': return 0;
    default : system("cls"); printf("\n\t\t\tComando Invalido.\n"); return 0;}
}

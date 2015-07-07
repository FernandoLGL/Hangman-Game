#ifndef FUNCOESJF_H
	#define FUNCOESJF_H


	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>

	char A[20][20];

	char continuar;

	char iuser[11];

	int sorte,j,i,score,vidas,tpalavra;

	int acertos,vacertos, fix;

	score = 0;

	vidas = 6;

	acertos = 0;


	char palavra[][11]= {

			"Bolo",
			"Computador",
			"Monitor",
			"Celular",
			"Cimento",
			"Laranja"
		};

	char dica[][20]={

			"Sobremesa",
			"Maquina",
			"Saida de Video",
			"Aparelho Eletronico",
			"Construcao",
			"Fruta"
		};


linhah(n,x){
    int i;
    if ( n == "Jogo da Forca"){
	printf("\t\t\t");
	}
	for (i=0; i<strlen(n); i++){
		printf("%c",x);
	}
	printf("\n");
}

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


config(comando){
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
	if (comando == '1'){
		jogo();
	}
	else if(comando == '2'){
		config();
	}
	else if(comando == '3'){
		scoreboard();
	}
	else if(comando == '4'){
		printf("\n");
		mainmenu();
	}
	else{
		printf("\n\t\t\tComando Invalido.\n");
		return 0;
	}

}

scoreboard(){
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
	mainmenu();

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


void inicio()
{


    for(i=0; i<20; i++)
        for(j=0; j<20; j++)
        {
            A[i][j]=' ';
        }
    for(i=0; i<20-3; i++)
        for(j=0; j<20-3; j++)
        {
            if(i==0)
                A[i][j]=196;
            else
                A[i][0]=179;
        }
    for(j=13; j<20; j++)
        A[1][j]=196;
    A[0][0]=218;
    A[0][16]=191;
    A[1][16]=193;
    A[17][0]=193;

    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void cabeca()
{
    for(i=2; i<7; i++)
        for(j=13; j<20; j++)
        {
            if(i==2 || i==6)
                A[i][j]=196;
            if(j==13 || j==20-1)
                A[i][j]=179;
        }

    A[2][13]=218;
    A[2][19]=191;
    A[3][15]='X';
    A[3][17]='X';
    A[5][16]='O';
    A[6][13]=192;
    A[6][19]=217;

    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void corpo(void)
{

    for(i=7; i<12; i++)
        A[i][16]=179;
    A[6][16]=194;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void bracod(void)
{
    A[8][17]=92;
    A[9][18]=92;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void bracoe(void)
{
    A[8][15]=47;
    A[9][14]=47;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void pernad(void)
{
    A[12][17]=92;
    A[13][18]=92;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}

void pernae()
{
    A[12][15]=47;
    A[13][14]=47;
    for(i=0; i<20; i++)
    {
        for(j=0; j<20; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }
}


#endif

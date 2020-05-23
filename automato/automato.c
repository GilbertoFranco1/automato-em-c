#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ncurses.h>
//#include<conio.h>  caso voce utilize windows descomente essa linha e comente a de cima e acesse o README anexado ao codigo
#include <string.h>



int recebeVetor(char nomearq[], int tamanho);

int selectCaractere(char nomearq[], int tamanho);

int main(){	
	setlocale(LC_ALL,"portuguese");
	int opcao = 0, j = 0;
	FILE *arquivo;
	char nomeArquivo[50], guarda[50], vetorAux[50];
	char c;

	printf("x---------------------------------------------------------x\n");
	printf("|               UNVERSIDADE FEDERAL DO PARÁ               |\n");
	printf("|              PROGRAMA GERADOR DE AUTOMATOS              |\n");
	printf("|                                                         |\n");
	printf("|desenvolvido em 03 de março de 2019                      |\n");
	printf("|       pressione qualquer tecla para continuar..         |\n");
	printf("x---------------------------------------------------------x\n");
	getchar();
	system("clear");

//menu de opções do automato
	do{
		printf("x---------------------------------------------------------x\n");
		printf("|                          MENU                           |\n");
		printf("|                                                         |\n");
		printf("|[1] AUTOMATO FINITO DETERMINISTICO                       |\n");
		printf("|[2] AUTOMATO FINITO NAO DETERMINISTICO                   |\n");
		printf("|[3] SAIR                                                 |\n");
		printf("x---------------------------------------------------------x\n");
		scanf("%i", &opcao);
		getchar();
		system("clear");
		if (opcao != 1 && opcao != 2 && opcao != 3){
			printf (" OPCAO %i INVALIDA, PRESSIONE ENTER PARA RETORNAR AO MENU..", opcao);
			getchar();
			system("clear");
		}
		if (opcao == 3){
			printf ("PROGRAMA FINALIZADO! \n");
			exit(0);
		}
	}while(opcao != 1 && opcao != 2 && opcao != 3);


//informa o nome do arquivo dentro de um laço do-while (sem o laco ocorre um erro de falha
//de segmentação pois a variavel tenta buscar um endereço na memoria que nao existe e encerra o programa, no caso
//se houver erro de digitação por parte do usuario a funcao continua até o endereço na memoria ser encontrado.

	do{
		printf ("Insira o nome do arquivo, ex.(arquivo.txt): \n");
		scanf("%s", nomeArquivo);
		getchar();
		system("clear");

		arquivo = fopen(nomeArquivo, "r");

		if (arquivo == NULL){
			printf ("arquivo nao encontrado, pressione enter para voltar.. \n");
			getchar();
			system("clear");
		}
	}while(arquivo == NULL);


//aqui ocorre a varredura no arquivo, compara caractere por caractere ate encontrar a cte
//FEOF e guarda em um novo vetor que sera mandado por referencia para uma funcao

	c = fgetc(arquivo);
	while(!feof(arquivo)){
		guarda[j] = c;
		c = fgetc(arquivo);
		j++;
	}


//atraves da opcao inserida pelo usuario, ela escolhe qual funcao vai ser enviada os dados dos caracateres 
//ou propriamente finaliza-la

	switch (opcao){
		case 1:
		recebeVetor(guarda,j);
		break;

		case 2:
		selectCaractere(guarda,j);
		break;
	}



	printf("\nPROGRAMA FINALIZADO!\n");

	fclose (arquivo);

}







//----------------------------------------------------------------------------------------
//menu 1 - automato finito deterministico
int recebeVetor(char nomearq[], int tamanho){
	char mostrar[50];
	int i,j=0;
	for(i = 0; i <= tamanho; i++){
		mostrar[i] = nomearq[i];
		if(mostrar[i] == '\n'){
			break;
		}		
		printf ("%c",mostrar[i]);
	}
	
	
}



int selectCaractere(char guarda[], int tamanho){
	char vet[50];
	int i;
	
	for(i = 0; i < strlen(guarda); i++){
		vet[i] = guarda[i];
		printf("%c", vet[i]);
	}
	printf ("\n");	
    return 0;
}

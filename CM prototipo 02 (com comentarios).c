#include<stdlib.h> // Ol�, iniciaremos nosso c�digo comentado sobre o jogo Campo Minado!
#include<stdio.h>	// Para come�armos, temos que incluir todas as bibliotecas que precisaremos para que o c�digo funcione perfeitamente;
#include<conio.h>
#include<time.h>
#include<locale.h>
#include<string.h> // Incluindo todas as bibliotecas que usamos no c�digo;


int** GetMatrizBomba(int tamanho); // Ponteiro de ponteiro na fun��o int que trata da bomba (um ponteiro pra linha, e outro pra coluna);
char** GetMatrizPlay(int tamanho); // Ponteiro de ponteiro com o mesmo objetivo da anterior, s� que numa fun��o char que trata da jogabilidade;
int play(); // A maior fun��o do codigo, onde tem inicio, meio e fim de cada fase do campo;
int menu(); // Fun��o que refere-se ao menu do jogo (Onde voc� entra e seleciona a fase que deseja jogar);


int main() {
	setlocale(LC_ALL,""); // Locale sem lingua para poder colocar quaisquer coisas;
	menu();
	return 0;
}



int** GetMatrizBomba(int tamanho) { // Fun��o int para determinar a randomiza��o e n�mero de bombas;
	int i,j,l,c;
	int **matrizbomba = (int**)malloc(tamanho * sizeof(int*)); // Formula para definir o numero de bombas de acordo com o tamanho da matriz (campo);
	for(i = 0; i < tamanho; i++) {
		matrizbomba[i] = (int*)malloc(tamanho * sizeof(int));
		for(j = 0; j < tamanho; j++) {
			matrizbomba[i][j] = 0;
		}
	} // Agora randomizando onde a bomba estar� na matriz (tamb�m de acordo com o tamanho):
	srand(time(NULL));// O tamanho � definido pela sele��o de fase do jogador, e cada tamanho � ele ao quadrado, ou seja, tamanho = 5 tem 25 casas;
	if(tamanho == 5) { // Um FOR para tamanho = 5 (ou fase 1);
		for(i=0; i<5; i++) { // As bombas s�o definidas no for por padr�o, por�m em coordenadas aleat�rias a cada partida. Na primeira fase 5 bombas pra 25 casas;
			l = rand()%tamanho;
			c = rand()%tamanho;
			if(matrizbomba[l][c] == 0) {
				matrizbomba[l][c] = 1;
			} else {
				i--;
			}
		}
		return matrizbomba; // Retornar a matriz (intitulada matrizbomba) para a fun��o;
	} else if(tamanho == 10) { // FOR para tamanho = 10 (fase 2);
		for(i=0; i<20; i++) { // Na segunda fase temos 20 bombas pra 100 casas;
			l = rand()%tamanho;
			c = rand()%tamanho;
			if(matrizbomba[l][c] == 0) {
				matrizbomba[l][c] = 1;
			} else {
				i--;
			}
		}
		return matrizbomba;
	} else if(tamanho == 15) { // FOR para tamanho = 15 (fase 3);
		for(i=0; i<150; i++) { // Na terceira fase temos 150 bombas para 225 casas;
			l = rand()%tamanho;
			c = rand()%tamanho;
			if(matrizbomba[l][c] == 0) {
				matrizbomba[l][c] = 1;
			} else {
				i--;
			}
		}
		return matrizbomba;
	} else if(tamanho == 20) { //FOR para tamanho = 20 (fase 4);
		for(i=0; i<200; i++) { // Na ultima fase temos 200 bombas pra 400 casas;
			l = rand()%tamanho;
			c = rand()%tamanho;
			if(matrizbomba[l][c] == 0) {
				matrizbomba[l][c] = 1;
			} else {
				i--;
			}
		}
		return matrizbomba;
	}
}

char** GetMatrizPlay(int tamanho) { // Fun��o para 'estilizar' a matriz de campo alter�vel;
	int i,j;
	char **matrizplay = (char**)malloc (tamanho * sizeof(char*)); //Como na "GetMatrizBomba", f�rmula para alocar um espa�o para a matriz;
	for(i = 0; i < tamanho; i++) {
		matrizplay[i] = (char*)malloc(tamanho * sizeof(char));
		for(j = 0; j < tamanho; j++) {
			matrizplay[i][j] = '#'; // Ap�s os FOR para alocar as linhas e colunas, o estilo da matriz no CMD ser� visto como '#' (Jogo da velha, ou hashtag);
		}								//obs: ap�s selecionar uma coordenada, obviamente ela deixar� de ser mostrada como '#';
	}
	return matrizplay;
}

int menu() { // Fun��o para o menu principal do jogo;
	char opcao;
	int tamanho;
	do { // Opera��o para a primeira pagina do menu principal;
		system("cls"); // Usado para limpar tudo que antes foi "escrito", con fins de organizar melhor o CMD e deixar sem polui��es visuais;
		system("color 0B");
		printf("=========================================================================\n");
		printf("|                                                                       |\n");
		printf("|                                                                       |\n");
		printf("|                                                                       |\n");	// PRIMEIRA P�GINA DO MENU;
		printf("|                      Bem vindo ao campo minado!                       |\n");
		printf("|                             1 - Jogar                                 |\n");
		printf("|                             2 - Sair                                  |\n");
		printf("|                                                                       |\n");
		printf("|                                                                       |\n");
		printf("|                                                                       |\n");
		printf("=========================================================================\n");
		scanf("%c",&opcao); // Scanf para ler a dificuldade escolhida;
		fflush(stdin);
	} while(opcao != '1' && opcao != '2'); // Tudo isso feito num "DO... WHILE", ou seja, enquanto a op��o for 1 ou 2, o programa ir� fazer dois comandos, separados;
	switch(opcao) { // Switch para separar as opera��es feitas em cada op��o (que no caso s�o duas);
		case '1': //caso JOGAR;
			do {
				system("cls");
				printf("=========================================================================\n");
				printf("|                                                                       |\n");
				printf("|                                                                       |\n");
				printf("|                                                                       |\n");
				printf("|                     Selecione a dificuldade!                          |\n");		//SEGUNDA P�GINA DO MENU (CASO TENHA ESCOLHIDO A OP��O JOGAR);
				printf("|                          1 - Facil                                    |\n");
				printf("|                          2 - Medio                                    |\n");
				printf("|                          3 - Dificil                                  |\n");
				printf("|                          4 - Melhor nem tentar                        |\n");
				printf("|                                                                       |\n");
				printf("|                                                                       |\n");
				printf("|                                                                       |\n");
				printf("=========================================================================\n");
				scanf("%c",&opcao); // Scanf para ler a dificuldade escolhida;
				fflush(stdin);
			} while(opcao != '1' && opcao != '2' && opcao != '3' && opcao != '4');
			if(opcao == '1') { // Cada if executar� uma matriz, de tamanhos que j� foram escolhidos anteriormente;
				tamanho = 5;
			} else if(opcao == '2') {
				tamanho = 10;
			} else if(opcao == '3') {
				tamanho = 15;
			} else if(opcao == '4') {
				tamanho = 20;
			}
			play(tamanho);
		case '2': // Caso o jogador escolha a op��o 2 (sair) o jogo se encerrar� e o cmd fechar�;
			break;
	}
}

int play(int tamanho) { // Fun��o para as mec�nicas, jogabilidade e o jogo em si (praticamente um 'int main(){');
	int i,j,achoubomba=1,chance=0,x=0,y=0;
	int rep=0,invalido=0,aberto=0,jogada=0,cont=0,cont_bomba=0,inteiro; // vari�veis utilizadas no jogo, tais como op��o, replay, coords invalidas, etc.;
	char caractere,opcao;
	char cNumX[] = {0};
	char cNumY[] = {0};
	do {
		char** matrizplay = GetMatrizPlay(tamanho); // Direcionando as outras fun��es fora a do menu para a fun��o principal;
		int** matrizbomba = GetMatrizBomba(tamanho);
		do {
			system("cls");
			if(tamanho == 5) {
				printf("=========================================================================\n");
				printf("|        Nesse modo o campo � 5x5 e tem 5 bombas, Boa sorte!            |\n"); // A parte de cima da matriz, que mudar� de acordo com o n�vel;
				printf("|                                                                       |\n");
			} else if(tamanho == 10) {
				printf("=========================================================================\n");
				printf("|        Nesse modo o campo � 10x10 e tem 20 bombas, Boa sorte!         |\n");
				printf("|                                                                       |\n");
			} else if(tamanho == 15) {
				printf("=========================================================================\n");
				printf("|        Nesse modo o campo � 15x15 e tem 150 bombas, Boa sorte!        |\n");
				printf("|                                                                       |\n");
			} else if(tamanho == 20) {
				printf("=========================================================================\n");
				printf("|        Nesse modo o campo � 20x20 e tem 200 bombas, Boa sorte!        |\n");
				printf("|                                                                       |\n");
			}
			if(rep != 0) {
				printf("|                                                                       |\n");
				printf("|           Esse campo ja foi selecionado, informe outro!               |\n"); // F�rmula para caso repita coordenada;
				printf("|                                                                       |\n");
			}
			if(aberto != 0) {
				printf("|                                                                       |\n");
				printf("|             Esse campo ja foi aberto, informe outro!                  |\n"); //Mensagem mostrada caso o jogador selecione um campo que foi aberto por consequ�ncia de uma escolha anterior
				printf("|                                                                       |\n");
			}
			if(invalido != 0) {
				printf("|                                                                       |\n");
				printf("|                     Coordenadas invalidas!                            |\n");	// F�rmula para caso o jogador digite coordenadas que n�o existem dentro do tamanho da matriz;
				printf("|                                                                       |\n");
			}
			printf("|                                                                       |\n");
			for(i=0; i<tamanho; i++) { // Pura est�tica, para deixar devidamente organizado;
				if(tamanho == 5) {
					printf("|                            ");
				} else if(tamanho == 10) {
					printf("|                         ");
				} else if(tamanho == 15) {
					printf("|                     ");
				} else if(tamanho == 20) {
					printf("|                 ");
				}
				for(j=0; j<tamanho; j++) {
					printf("%c ",matrizplay[i][j]);
				}
				if(tamanho == 5) {
					printf("                                 |");
				} else if(tamanho == 10) {
					printf("                          |");
				} else if(tamanho == 15) {
					printf("                    |");
				} else if(tamanho == 20) {
					printf("              |");
				}
				printf("\n");
			}
			//printf("\n");
			//for(i=0; i<tamanho; i++) {
			//for(j=0; j<tamanho; j++) {
			//printf("%d ",matrizbomba[i][j]);
			//}
			//printf("\n");
			//}
			cont = 0;
			for(i=0; i<tamanho; i++) {	// FOR para determinar o contador que ser� usado abaixo;
				for(j=0; j<tamanho; j++) {
					if(matrizplay[i][j] == '#') {
						cont++;
					}
				}
			}
			printf("|                                                                       |\n");
			printf("|                                                                       |\n");
			printf("|          Vit�ria quando [%d] for igual ao n�mero de bombas!          |\n",cont);  // Parte de baixo do campo, onde o jogo diz quantas bombas precisam para a vit�ria (dependendo da dificuldade);
			printf("|                                                                       |\n");
			printf("=========================================================================\n");
			if(cont == 5 && tamanho == 5) { // A cada jogada o o contador diminui, variando de acordo com o tamanho;
				achoubomba = 0;
				chance = 1;
			} else if(cont == 20 && tamanho == 10) {
				achoubomba = 0;
				chance = 1;
			} else if(cont == 150 && tamanho == 15) {
				achoubomba = 0;
				chance = 1;
			} else if(cont == 200 && tamanho == 20) {
				achoubomba = 0;
				chance = 1;
			} else { // A jogada principal do campo minado: informar a coordenada desejada;
				printf("Informe a linha: ");
				scanf("%s%*c",&cNumX);
				x = strtol(cNumX, NULL, 10);
				printf("Informe a coluna: ");
				scanf("%s%*c",&cNumY);
				y = strtol(cNumY, NULL, 10);
				x = x-1;
				y = y-1;
				if(x >= tamanho || y >= tamanho || x < 0 || y < 0) { // Um if para dizer se a jogada foi invalida ou n�o (ex tamanho 5 o jogador procurar na coluna 6);
					invalido = 1;
					rep = 0;
					aberto = 0;
				} else if(matrizbomba[x][y] == 1) { // Else if para assim que achar uma bomba, ser digitado na matriz o s�mbolo dela, que no caso � 'B';
					matrizplay[x][y] = 'B';
					achoubomba = 0;
					chance = 2;
					invalido = 0;
					rep = 0;
					aberto = 0;
					jogada = 0;
				} else if(matrizplay[x][y] == caractere) { // Caso o jogador escreva um caractere ao inv�s de um n�mero nas coordenadas, o jogo avisar� que s�o inv�lidas;
					rep = 1;
					invalido = 0;
					aberto = 0;
				} else if(matrizplay[x][y] != '#') { // Para abrir a matriz normal, com o s�mbolo que usamos ('#');
					rep = 0;
					aberto = 1;
					invalido = 0;
				} else {  //Caso as coordendadas estiverem certas, e, voc� n�o achar uma bomba ele abre o espa�o do '#' para um 'X';
					matrizplay[x][y] = 'X';
					jogada++;
					achoubomba = 1;
					rep = 0;
					invalido = 0;
					aberto = 0;
					if(jogada == 1 || jogada % 3 == 0) { //Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhidas
						if(x>0 && y>0 && y<(tamanho-1) && x<(tamanho-1)) { // A partir daqui, as cadeias de ifs ir�o abrir o campo para as dire��es que ser�o verificadas se h� espa�o;
							if(matrizbomba[x][y+1] != 1 && matrizplay[x][y+1] == '#') {
								matrizplay[x][y+1] = '+'; //caso nenhuma bomba seja encontrada o campo que foi aberto ser� marcado com o caractere "+"
							} else {
								if(matrizbomba[x][y+1] == 1 && matrizplay[x][y+1] != caractere) { //ir� verificar a casa da direita em rela��o a selecionada
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x][y-1] !=1 && matrizplay[x][y-1] == '#') {
								matrizplay[x][y-1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto ser� marcado com o caractere "+"
							} else {
								if(matrizbomba[x][y-1] == 1 && matrizplay[x][y-1] != caractere) { //ir� verificar a casa da esquerda em rela��o a selecionada
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x+1][y] != 1 && matrizplay[x+1][y] == '#') {
								matrizplay[x+1][y] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto ser� marcado com o caractere "+"
							} else {
								if(matrizbomba[x+1][y] == 1 && matrizplay[x+1][y] != caractere) {  //ir� verificar a casa embaixo da selecionada
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x-1][y] != 1 && matrizplay[x-1][y] == '#') {  //ir� verificar a casa acima da selecionada
								matrizplay[x-1][y] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto ser� marcado com o caractere "+"
							} else {
								if(matrizbomba[x-1][y] == 1 && matrizplay[x-1][y] != caractere) {
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x-1][y+1] != 1 && matrizplay[x-1][y+1] == '#') {
								matrizplay[x-1][y+1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto ser� marcado com o caractere "+"
							} else {
								if(matrizbomba[x-1][y+1] == 1 && matrizplay[x-1][y+1] != caractere) { //ir� verificar a casa da diagonal superior direita em rela��o a selecionada
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x-1][y-1] != 1 && matrizplay[x-1][y-1] == '#') { //ir� verficar a casa da diagonal inferior direita em rela��o a selecionada 
								matrizplay[x-1][y-1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto ser� marcado com o caractere "+"
							} else {
								if(matrizbomba[x-1][y-1] == 1 && matrizplay[x-1][y-1] != caractere) {
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x+1][y+1] != 1 && matrizplay[x+1][y+1] == '#') { //ir� verificar a casa da diagonal inferior esquerda em rela��o a selecionada
								matrizplay[x+1][y+1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto ser� marcado com o caractere "+"
							} else {
								if(matrizbomba[x+1][y+1] == 1 && matrizplay[x+1][y+1] != caractere) {
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x+1][y-1] != 1 && matrizplay[x+1][y-1] == '#') { //ir� verificar a casa da diagonal inferior esquerda em rela��o a selecionada
								matrizplay[x+1][y-1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto ser� marcado com o caractere "+"
							} else {
								if(matrizbomba[x+1][y-1] == 1 && matrizplay[x+1][y-1] != caractere) {
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizplay[x][y] == 'X') { //Aqui ocorre uma outra verifica��o em rela��o a casa selecionada se esta for livre de bombas
								inteiro = cont_bomba; //Aqui a quantidade de bombas contabilizadas � passada para uma variavel inteira
								caractere = inteiro+'0';//Aqui a variavel anterior � convertida para caractere junto a quantidade de bombas verificadas com inteiro
								matrizplay[x][y] = caractere;//aqui o caractere � passado para a matriz de exibi��o
							}
							cont_bomba=0; // Ap�s todo o c�lculo, � necessario zerar o contador;
						}
						if(x==0 && y==0) {//Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhidas'/neste caso, canto superior esquerdo
							if(matrizbomba[x][y+1] != 1 && matrizplay[x][y+1] == '#') {
								matrizplay[x][y+1] = '+';
							} else {
								if(matrizbomba[x][y+1] == 1 && matrizplay[x][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y] != 1 && matrizplay[x+1][y] == '#') {
								matrizplay[x+1][y] = '+';
							} else {
								if(matrizbomba[x+1][y] == 1 && matrizplay[x+1][y] != caractere) {  
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y+1] != 1 && matrizplay[x+1][y+1] == '#') {
								matrizplay[x+1][y+1] = '+';
							} else {
								if(matrizbomba[x+1][y+1] == 1 && matrizplay[x+1][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x==0 && y==(tamanho-1)) {//Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhidas/neste caso, quando a linha selecionada for a primeira 
							if(matrizbomba[x][y-1] != 1 && matrizplay[x][y-1] == '#') {
								matrizplay[x][y-1] = '+';
							} else {
								if(matrizbomba[x][y-1] == 1 && matrizplay[x][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y] != 1 && matrizplay[x+1][y] == '#') {
								matrizplay[x+1][y] = '+';
							} else {
								if(matrizbomba[x+1][y] == 1 && matrizplay[x+1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y-1] != 1 && matrizplay[x+1][y-1] == '#') {
								matrizplay[x+1][y-1] = '+';
							} else {
								if(matrizbomba[x+1][y-1] == 1 && matrizplay[x+1][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y==0 && x<(tamanho-1)) {//Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhidas/ neste caso, linha em qualquer posi��o, coluna sendo a primeira 
							if(matrizbomba[x][y+1] != 1 && matrizplay[x][y+1] == '#') {
								matrizplay[x][y+1] = '+';
							} else {
								if(matrizbomba[x][y+1] == 1 && matrizplay[x][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y] != 1 && matrizplay[x+1][y] == '#') {
								matrizplay[x+1][y] = '+';
							} else {
								if(matrizbomba[x+1][y] == 1 && matrizplay[x+1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y] != 1 && matrizplay[x-1][y] == '#') {
								matrizplay[x-1][y] = '+';
							} else {
								if(matrizbomba[x-1][y] == 1 && matrizplay[x-1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y+1] != 1 && matrizplay[x-1][y+1] == '#') {
								matrizplay[x-1][y+1] = '+';
							} else {
								if(matrizbomba[x-1][y+1] == 1 && matrizplay[x-1][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y+1] != 1 && matrizplay[x+1][y+1] == '#') {
								matrizplay[x+1][y+1] = '+';
							} else {
								if(matrizbomba[x+1][y+1] == 1 && matrizplay[x+1][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y==0 && x==(tamanho-1)) {//Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhidas/neste caso, primeira coluna, linha no meio
							if(matrizbomba[x][y+1] != 1 && matrizplay[x][y+1] == '#') {
								matrizplay[x][y+1] = '+';
							} else {
								if(matrizbomba[x][y+1] == 1 && matrizplay[x][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y] != 1 && matrizplay[x-1][y] == '#') {
								matrizplay[x-1][y] = '+';
							} else {
								if(matrizbomba[x-1][y] == 1 && matrizplay[x-1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y+1] != 1 && matrizplay[x-1][y+1] == '#') {
								matrizplay[x-1][y+1] = '+';
							} else {
								if(matrizbomba[x-1][y+1] == 1 && matrizplay[x-1][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y>0 && x==(tamanho-1) && y==(tamanho-1)) {//Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhida/neste caso, linha em uma posi��o maior que a primeira, coluna em uma posi��o maior que a primeira
							if(matrizbomba[x][y-1] != 1 && matrizplay[x][y-1] == '#') {
								matrizplay[x][y-1] = '+';
							} else {
								if(matrizbomba[x][y-1] == 1 && matrizplay[x][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y] != 1 && matrizplay[x-1][y] == '#') {
								matrizplay[x-1][y] = '+';
							} else {
								if(matrizbomba[x-1][y] == 1 && matrizplay[x-1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y-1] != 1 && matrizplay[x-1][y-1] == '#') {
								matrizplay[x-1][y-1] = '+';
							} else {
								if(matrizbomba[x-1][y-1] == 1 && matrizplay[x-1][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x==0 && y>0 && y<(tamanho-1)) {//Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhidas/neste caso, primeira linha e coluna no meio
							if(matrizbomba[x][y-1] != 1 && matrizplay[x][y-1] == '#') {
								matrizplay[x][y-1] = '+';
							} else {
								if(matrizbomba[x][y-1] == 1 && matrizplay[x][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x][y+1] != 1 && matrizplay[x][y+1] == '#') {
								matrizplay[x][y+1] = '+';
							} else {
								if(matrizbomba[x][y+1] == 1 && matrizplay[x][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y] != 1 && matrizplay[x+1][y] == '#') {
								matrizplay[x+1][y] = '+';
							} else {
								if(matrizbomba[x+1][y] == 1 && matrizplay[x+1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y+1] != 1 && matrizplay[x+1][y+1] == '#') {
								matrizplay[x+1][y+1] = '+';
							} else {
								if(matrizbomba[x+1][y+1] == 1 && matrizplay[x+1][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y-1] != 1 && matrizplay[x+1][y-1] == '#') {
								matrizplay[x+1][y-1] = '+';
							} else {
								if(matrizbomba[x+1][y-1] == 1 && matrizplay[x+1][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y>0 && y==(tamanho-1) && x<(tamanho-1)) {//Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhidas/neste caso linha e coluna no meio
							if(matrizbomba[x-1][y] != 1 && matrizplay[x-1][y] == '#') {
								matrizplay[x-1][y] = '+';
							} else {
								if(matrizbomba[x-1][y] == 1 && matrizplay[x-1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y] != 1 && matrizplay[x+1][y] == '#') {
								matrizplay[x+1][y] = '+';
							} else {
								if(matrizbomba[x+1][y] == 1 && matrizplay[x+1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x][y-1] != 1 && matrizplay[x][y-1] == '#') {
								matrizplay[x][y-1] = '+';
							} else {
								if(matrizbomba[x][y-1] == 1 && matrizplay[x][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x+1][y-1] != 1 && matrizplay[x+1][y-1] == '#') {
								matrizplay[x+1][y-1] = '+';
							} else {
								if(matrizbomba[x+1][y-1] == 1 && matrizplay[x+1][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y-1] != 1 && matrizplay[x-1][y-1] == '#') {
								matrizplay[x-1][y-1] = '+';
							} else {
								if(matrizbomba[x-1][y-1] == 1 && matrizplay[x-1][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y>0 && x==(tamanho-1) && y<(tamanho-1)) {//Verifica��o da posi��o do campo para abrir uma quantidade de casas harmoniosas com a posi��o escolhidas/neste caso linha em qualquer posi��o, coluna mais para a esquerda do tabuleiro
							if(matrizbomba[x][y-1] != 1 && matrizplay[x][y-1] == '#') {
								matrizplay[x][y-1] = '+';
							} else {
								if(matrizbomba[x][y-1] == 1 && matrizplay[x][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x][y+1] != 1 && matrizplay[x][y+1] == '#') {
								matrizplay[x][y+1] = '+';
							} else {
								if(matrizbomba[x][y+1] == 1 && matrizplay[x][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y] != 1 && matrizplay[x-1][y] == '#') {
								matrizplay[x-1][y] = '+';
							} else {
								if(matrizbomba[x-1][y] == 1 && matrizplay[x-1][y] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y-1] != 1 && matrizplay[x-1][y-1] == '#') {
								matrizplay[x-1][y-1] = '+';
							} else {
								if(matrizbomba[x-1][y-1] == 1 && matrizplay[x-1][y-1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizbomba[x-1][y+1] != 1 && matrizplay[x-1][y+1] == '#') {
								matrizplay[x-1][y+1] = '+';
							} else {
								if(matrizbomba[x-1][y+1] == 1 && matrizplay[x-1][y+1] != caractere) {
									cont_bomba++;
								}
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
					} else { // Nessa sequ�ncia, o programa dever� verificar se nos espa�os abertos tem bomba ou n�o, em quaisquer dire��es adjacentes � coordenada selecionada pelo jogador;
						if(x>0 && y<(tamanho-1) && x<(tamanho-1)) {
							if(matrizbomba[x][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y] == 1) {   //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha n�o � a primeira  e a coluna est� proxima a esquerda
								cont_bomba++;
							}
							if(matrizbomba[x-1][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere; // Substituindo o n�mero de bombas para facilitar a jogabilidade;
							}
							cont_bomba=0;
						}
						if(x==0 && y==0) {
							if(matrizbomba[x][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a primeira coluna e a primeira linha � selecionada
								cont_bomba++;
							}
							if(matrizbomba[x+1][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x==0 && y==(tamanho-1)) {
							if(matrizbomba[x][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha � a primeira e a coluna estiver em qualquer outra posi��o possivel
								cont_bomba++;
							}
							if(matrizbomba[x+1][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y==0 && x==(tamanho-1)) {
							if(matrizbomba[x][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha e a coluna estiverem no meio
								cont_bomba++;
							}
							if(matrizbomba[x-1][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y==0 && x<(tamanho-1)) {
							if(matrizbomba[x][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando quando a coluna for a primeira e a linha estiver na parte superior do mapa
								cont_bomba++;
							}
							if(matrizbomba[x-1][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}

						if(x>0 && y>0 && x==(tamanho-1) && y==(tamanho-1)) {
							if(matrizbomba[x][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y-1] == 1) {  //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando quando a linha e a coluna estiverem no meio
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x==0 && y>0 && y<(tamanho-1)) {
							if(matrizbomba[x][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha for a primeira e a coluna estiver pr�ximo a esquerda, exceto a primeira coluna
								cont_bomba++;
							}
							if(matrizbomba[x+1][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y>0 && y==(tamanho-1) && x<(tamanho-1)) {
							if(matrizbomba[x-1][y] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x][y-1] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando linha e coluna for diferente de zero sendo a linha proxima a parte superior do tabuleiro
								cont_bomba++;
							}
							if(matrizbomba[x+1][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
						if(x>0 && y>0 && x==(tamanho-1) && y<(tamanho-1)) {
							if(matrizbomba[x][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha e a coluna forem maior que zero com a coluna mais pr�xima da esquerda 
								cont_bomba++;
							}
							if(matrizbomba[x-1][y-1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x-1][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizplay[x][y] == 'X') {
								inteiro = cont_bomba;
								caractere = inteiro+'0';
								matrizplay[x][y] = caractere;
							}
							cont_bomba=0;
						}
					}
				}
			}
		} while(achoubomba != 0); // Enquanto a vari�vel destinada para se o jogador encontrar uma bomba for diferente de 0 (ou seja, achou uma bomba);
		system("cls");
		if(chance==2) { // Caso voc� perca, ter� uma op��o para jogar novamente (ou n�o);
			printf("=========================================================================\n");
			printf("|                                                                       |\n");
			printf("|                                                                       |\n");
			for(i=0; i<tamanho; i++) {
				for(j=0; j<tamanho; j++) {
					if(matrizbomba[i][j] == 1 && matrizplay[i][j] != 'X' && matrizplay[i][j] == '#' && matrizplay[i][j] != '+') { // A sua matriz finalizada, antes da derrota;
						matrizplay[i][j] = 'B';
					}
				}
			}
			for(i=0; i<tamanho; i++) {
				if(tamanho == 5) {
					printf("|                            ");
				} else if(tamanho == 10) {
					printf("|                         ");
				} else if(tamanho == 15) {
					printf("|                     ");
				} else if(tamanho == 20) {
					printf("|                 ");
				}
				for(j=0; j<tamanho; j++) {
					printf("%c ",matrizplay[i][j]);
				}
				if(tamanho == 5) {
					printf("                                 |");
				} else if(tamanho == 10) {
					printf("                          |");
				} else if(tamanho == 15) {
					printf("                    |");
				} else if(tamanho == 20) {
					printf("              |");
				}
				printf("\n");
			}
			printf("|                                                                       |\n");
			printf("|                                                                       |\n");
			printf("=========================================================================\n");
			chance=0;
			do {
				fflush(stdin);
				printf("=========================================================================\n");
				printf("|                                                                       |\n");
				printf("|                       Voce achou uma bomba!                           |\n"); // As op��es;
				printf("|                       Quer jogar novamente?                           |\n");
				printf("|                       1 - Sim                                         |\n");
				printf("|                       2 - Nao                                         |\n");
				printf("|                                                                       |\n");
				printf("=========================================================================\n");
				scanf("%c",&opcao);
				fflush(stdin);
				system("cls");
			} while(opcao != '2' && opcao != '1');
		} else if(chance==1) { // Caso voc� ganhe, aparecer� isto na tela/ o calculo � feito verificando a quantidade de casas restantes no mapa ecom a quantidade de bombas
			printf("=========================================================================\n");
			printf("|                                                                       |\n");
			printf("|                                                                       |\n");
			for(i=0; i<tamanho; i++) {
				for(j=0; j<tamanho; j++) {
					if(matrizbomba[i][j] == 1 && matrizplay[i][j] != 'X' && matrizplay[i][j] == '#' && matrizplay[i][j] != '+') { // A sua matriz finalizada, antes da vit�ria;
						matrizplay[i][j] = 'B';
					}
				}
			}
			for(i=0; i<tamanho; i++) {
				if(tamanho == 5) {
					printf("|                            ");
				} else if(tamanho == 10) {
					printf("|                         ");
				} else if(tamanho == 15) {
					printf("|                     ");
				} else if(tamanho == 20) {
					printf("|                 ");
				}
				for(j=0; j<tamanho; j++) {
					printf("%c ",matrizplay[i][j]);
				}
				if(tamanho == 5) {
					printf("                                 |");
				} else if(tamanho == 10) {
					printf("                          |");
				} else if(tamanho == 15) {
					printf("                    |");
				} else if(tamanho == 20) {
					printf("              |");
				}
				printf("\n");
			}
			printf("|                                                                       |\n");
			printf("|                                                                       |\n");
			printf("=========================================================================\n");
			chance=0;
			do {
				fflush(stdin);
				printf("=========================================================================\n");
				printf("|                                                                       |\n");
				printf("|                       Voce ganhou!                                    |\n"); // As op��es;
				printf("|                       Quer jogar novamente?                           |\n");
				printf("|                       1 - Sim                                         |\n");
				printf("|                       2 - Nao                                         |\n");
				printf("|                                                                       |\n");
				printf("=========================================================================\n");
				scanf("%c",&opcao);
				fflush(stdin);
				system("cls");
			} while(opcao != '1' && opcao != '2'); // Caso a op��o seja 1, a matriz reiniciar�, assim iniciando um novo jogo;
		}
	} while(opcao != '2');// E caso seja 2, voc� ser� redirecionado para a fun��o 'menu()' ou menu principal;
	menu();
}// E, com isso, finalizamos nosso c�digo. Espero que tenha curtido a viagem que � ser um programador!

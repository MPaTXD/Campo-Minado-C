#include<stdlib.h> // Olá, iniciaremos nosso código comentado sobre o jogo Campo Minado!
#include<stdio.h>	// Para começarmos, temos que incluir todas as bibliotecas que precisaremos para que o código funcione perfeitamente;
#include<conio.h>
#include<time.h>
#include<locale.h>
#include<string.h> // Incluindo todas as bibliotecas que usamos no código;


int** GetMatrizBomba(int tamanho); // Ponteiro de ponteiro na função int que trata da bomba (um ponteiro pra linha, e outro pra coluna);
char** GetMatrizPlay(int tamanho); // Ponteiro de ponteiro com o mesmo objetivo da anterior, só que numa função char que trata da jogabilidade;
int play(); // A maior função do codigo, onde tem inicio, meio e fim de cada fase do campo;
int menu(); // Função que refere-se ao menu do jogo (Onde você entra e seleciona a fase que deseja jogar);


int main() {
	setlocale(LC_ALL,""); // Locale sem lingua para poder colocar quaisquer coisas;
	menu();
	return 0;
}



int** GetMatrizBomba(int tamanho) { // Função int para determinar a randomização e número de bombas;
	int i,j,l,c;
	int **matrizbomba = (int**)malloc(tamanho * sizeof(int*)); // Formula para definir o numero de bombas de acordo com o tamanho da matriz (campo);
	for(i = 0; i < tamanho; i++) {
		matrizbomba[i] = (int*)malloc(tamanho * sizeof(int));
		for(j = 0; j < tamanho; j++) {
			matrizbomba[i][j] = 0;
		}
	} // Agora randomizando onde a bomba estará na matriz (também de acordo com o tamanho):
	srand(time(NULL));// O tamanho é definido pela seleção de fase do jogador, e cada tamanho é ele ao quadrado, ou seja, tamanho = 5 tem 25 casas;
	if(tamanho == 5) { // Um FOR para tamanho = 5 (ou fase 1);
		for(i=0; i<5; i++) { // As bombas são definidas no for por padrão, porém em coordenadas aleatórias a cada partida. Na primeira fase 5 bombas pra 25 casas;
			l = rand()%tamanho;
			c = rand()%tamanho;
			if(matrizbomba[l][c] == 0) {
				matrizbomba[l][c] = 1;
			} else {
				i--;
			}
		}
		return matrizbomba; // Retornar a matriz (intitulada matrizbomba) para a função;
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

char** GetMatrizPlay(int tamanho) { // Função para 'estilizar' a matriz de campo alterável;
	int i,j;
	char **matrizplay = (char**)malloc (tamanho * sizeof(char*)); //Como na "GetMatrizBomba", fórmula para alocar um espaço para a matriz;
	for(i = 0; i < tamanho; i++) {
		matrizplay[i] = (char*)malloc(tamanho * sizeof(char));
		for(j = 0; j < tamanho; j++) {
			matrizplay[i][j] = '#'; // Após os FOR para alocar as linhas e colunas, o estilo da matriz no CMD será visto como '#' (Jogo da velha, ou hashtag);
		}								//obs: após selecionar uma coordenada, obviamente ela deixará de ser mostrada como '#';
	}
	return matrizplay;
}

int menu() { // Função para o menu principal do jogo;
	char opcao;
	int tamanho;
	do { // Operação para a primeira pagina do menu principal;
		system("cls"); // Usado para limpar tudo que antes foi "escrito", con fins de organizar melhor o CMD e deixar sem poluições visuais;
		system("color 0B");
		printf("=========================================================================\n");
		printf("|                                                                       |\n");
		printf("|                                                                       |\n");
		printf("|                                                                       |\n");	// PRIMEIRA PÁGINA DO MENU;
		printf("|                      Bem vindo ao campo minado!                       |\n");
		printf("|                             1 - Jogar                                 |\n");
		printf("|                             2 - Sair                                  |\n");
		printf("|                                                                       |\n");
		printf("|                                                                       |\n");
		printf("|                                                                       |\n");
		printf("=========================================================================\n");
		scanf("%c",&opcao); // Scanf para ler a dificuldade escolhida;
		fflush(stdin);
	} while(opcao != '1' && opcao != '2'); // Tudo isso feito num "DO... WHILE", ou seja, enquanto a opção for 1 ou 2, o programa irá fazer dois comandos, separados;
	switch(opcao) { // Switch para separar as operações feitas em cada opção (que no caso são duas);
		case '1': //caso JOGAR;
			do {
				system("cls");
				printf("=========================================================================\n");
				printf("|                                                                       |\n");
				printf("|                                                                       |\n");
				printf("|                                                                       |\n");
				printf("|                     Selecione a dificuldade!                          |\n");		//SEGUNDA PÁGINA DO MENU (CASO TENHA ESCOLHIDO A OPÇÃO JOGAR);
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
			if(opcao == '1') { // Cada if executará uma matriz, de tamanhos que já foram escolhidos anteriormente;
				tamanho = 5;
			} else if(opcao == '2') {
				tamanho = 10;
			} else if(opcao == '3') {
				tamanho = 15;
			} else if(opcao == '4') {
				tamanho = 20;
			}
			play(tamanho);
		case '2': // Caso o jogador escolha a opção 2 (sair) o jogo se encerrará e o cmd fechará;
			break;
	}
}

int play(int tamanho) { // Função para as mecânicas, jogabilidade e o jogo em si (praticamente um 'int main(){');
	int i,j,achoubomba=1,chance=0,x=0,y=0;
	int rep=0,invalido=0,aberto=0,jogada=0,cont=0,cont_bomba=0,inteiro; // variáveis utilizadas no jogo, tais como opção, replay, coords invalidas, etc.;
	char caractere,opcao;
	char cNumX[] = {0};
	char cNumY[] = {0};
	do {
		char** matrizplay = GetMatrizPlay(tamanho); // Direcionando as outras funções fora a do menu para a função principal;
		int** matrizbomba = GetMatrizBomba(tamanho);
		do {
			system("cls");
			if(tamanho == 5) {
				printf("=========================================================================\n");
				printf("|        Nesse modo o campo é 5x5 e tem 5 bombas, Boa sorte!            |\n"); // A parte de cima da matriz, que mudará de acordo com o nível;
				printf("|                                                                       |\n");
			} else if(tamanho == 10) {
				printf("=========================================================================\n");
				printf("|        Nesse modo o campo é 10x10 e tem 20 bombas, Boa sorte!         |\n");
				printf("|                                                                       |\n");
			} else if(tamanho == 15) {
				printf("=========================================================================\n");
				printf("|        Nesse modo o campo é 15x15 e tem 150 bombas, Boa sorte!        |\n");
				printf("|                                                                       |\n");
			} else if(tamanho == 20) {
				printf("=========================================================================\n");
				printf("|        Nesse modo o campo é 20x20 e tem 200 bombas, Boa sorte!        |\n");
				printf("|                                                                       |\n");
			}
			if(rep != 0) {
				printf("|                                                                       |\n");
				printf("|           Esse campo ja foi selecionado, informe outro!               |\n"); // Fórmula para caso repita coordenada;
				printf("|                                                                       |\n");
			}
			if(aberto != 0) {
				printf("|                                                                       |\n");
				printf("|             Esse campo ja foi aberto, informe outro!                  |\n"); //Mensagem mostrada caso o jogador selecione um campo que foi aberto por consequência de uma escolha anterior
				printf("|                                                                       |\n");
			}
			if(invalido != 0) {
				printf("|                                                                       |\n");
				printf("|                     Coordenadas invalidas!                            |\n");	// Fórmula para caso o jogador digite coordenadas que não existem dentro do tamanho da matriz;
				printf("|                                                                       |\n");
			}
			printf("|                                                                       |\n");
			for(i=0; i<tamanho; i++) { // Pura estética, para deixar devidamente organizado;
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
			for(i=0; i<tamanho; i++) {	// FOR para determinar o contador que será usado abaixo;
				for(j=0; j<tamanho; j++) {
					if(matrizplay[i][j] == '#') {
						cont++;
					}
				}
			}
			printf("|                                                                       |\n");
			printf("|                                                                       |\n");
			printf("|          Vitória quando [%d] for igual ao número de bombas!          |\n",cont);  // Parte de baixo do campo, onde o jogo diz quantas bombas precisam para a vitória (dependendo da dificuldade);
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
				if(x >= tamanho || y >= tamanho || x < 0 || y < 0) { // Um if para dizer se a jogada foi invalida ou não (ex tamanho 5 o jogador procurar na coluna 6);
					invalido = 1;
					rep = 0;
					aberto = 0;
				} else if(matrizbomba[x][y] == 1) { // Else if para assim que achar uma bomba, ser digitado na matriz o símbolo dela, que no caso é 'B';
					matrizplay[x][y] = 'B';
					achoubomba = 0;
					chance = 2;
					invalido = 0;
					rep = 0;
					aberto = 0;
					jogada = 0;
				} else if(matrizplay[x][y] == caractere) { // Caso o jogador escreva um caractere ao invés de um número nas coordenadas, o jogo avisará que são inválidas;
					rep = 1;
					invalido = 0;
					aberto = 0;
				} else if(matrizplay[x][y] != '#') { // Para abrir a matriz normal, com o símbolo que usamos ('#');
					rep = 0;
					aberto = 1;
					invalido = 0;
				} else {  //Caso as coordendadas estiverem certas, e, você não achar uma bomba ele abre o espaço do '#' para um 'X';
					matrizplay[x][y] = 'X';
					jogada++;
					achoubomba = 1;
					rep = 0;
					invalido = 0;
					aberto = 0;
					if(jogada == 1 || jogada % 3 == 0) { //Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhidas
						if(x>0 && y>0 && y<(tamanho-1) && x<(tamanho-1)) { // A partir daqui, as cadeias de ifs irão abrir o campo para as direções que serão verificadas se há espaço;
							if(matrizbomba[x][y+1] != 1 && matrizplay[x][y+1] == '#') {
								matrizplay[x][y+1] = '+'; //caso nenhuma bomba seja encontrada o campo que foi aberto será marcado com o caractere "+"
							} else {
								if(matrizbomba[x][y+1] == 1 && matrizplay[x][y+1] != caractere) { //irá verificar a casa da direita em relação a selecionada
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x][y-1] !=1 && matrizplay[x][y-1] == '#') {
								matrizplay[x][y-1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto será marcado com o caractere "+"
							} else {
								if(matrizbomba[x][y-1] == 1 && matrizplay[x][y-1] != caractere) { //irá verificar a casa da esquerda em relação a selecionada
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x+1][y] != 1 && matrizplay[x+1][y] == '#') {
								matrizplay[x+1][y] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto será marcado com o caractere "+"
							} else {
								if(matrizbomba[x+1][y] == 1 && matrizplay[x+1][y] != caractere) {  //irá verificar a casa embaixo da selecionada
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x-1][y] != 1 && matrizplay[x-1][y] == '#') {  //irá verificar a casa acima da selecionada
								matrizplay[x-1][y] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto será marcado com o caractere "+"
							} else {
								if(matrizbomba[x-1][y] == 1 && matrizplay[x-1][y] != caractere) {
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x-1][y+1] != 1 && matrizplay[x-1][y+1] == '#') {
								matrizplay[x-1][y+1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto será marcado com o caractere "+"
							} else {
								if(matrizbomba[x-1][y+1] == 1 && matrizplay[x-1][y+1] != caractere) { //irá verificar a casa da diagonal superior direita em relação a selecionada
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x-1][y-1] != 1 && matrizplay[x-1][y-1] == '#') { //irá verficar a casa da diagonal inferior direita em relação a selecionada 
								matrizplay[x-1][y-1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto será marcado com o caractere "+"
							} else {
								if(matrizbomba[x-1][y-1] == 1 && matrizplay[x-1][y-1] != caractere) {
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x+1][y+1] != 1 && matrizplay[x+1][y+1] == '#') { //irá verificar a casa da diagonal inferior esquerda em relação a selecionada
								matrizplay[x+1][y+1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto será marcado com o caractere "+"
							} else {
								if(matrizbomba[x+1][y+1] == 1 && matrizplay[x+1][y+1] != caractere) {
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizbomba[x+1][y-1] != 1 && matrizplay[x+1][y-1] == '#') { //irá verificar a casa da diagonal inferior esquerda em relação a selecionada
								matrizplay[x+1][y-1] = '+';//caso nenhuma bomba seja encontrada o campo que foi aberto será marcado com o caractere "+"
							} else {
								if(matrizbomba[x+1][y-1] == 1 && matrizplay[x+1][y-1] != caractere) {
									cont_bomba++;//caso uma bomba seja encontrada ele incrementa o contador de bombas para gerar as dicas
								}
							}
							if(matrizplay[x][y] == 'X') { //Aqui ocorre uma outra verificação em relação a casa selecionada se esta for livre de bombas
								inteiro = cont_bomba; //Aqui a quantidade de bombas contabilizadas é passada para uma variavel inteira
								caractere = inteiro+'0';//Aqui a variavel anterior é convertida para caractere junto a quantidade de bombas verificadas com inteiro
								matrizplay[x][y] = caractere;//aqui o caractere é passado para a matriz de exibição
							}
							cont_bomba=0; // Após todo o cálculo, é necessario zerar o contador;
						}
						if(x==0 && y==0) {//Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhidas'/neste caso, canto superior esquerdo
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
						if(x==0 && y==(tamanho-1)) {//Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhidas/neste caso, quando a linha selecionada for a primeira 
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
						if(x>0 && y==0 && x<(tamanho-1)) {//Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhidas/ neste caso, linha em qualquer posição, coluna sendo a primeira 
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
						if(x>0 && y==0 && x==(tamanho-1)) {//Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhidas/neste caso, primeira coluna, linha no meio
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
						if(x>0 && y>0 && x==(tamanho-1) && y==(tamanho-1)) {//Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhida/neste caso, linha em uma posição maior que a primeira, coluna em uma posição maior que a primeira
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
						if(x==0 && y>0 && y<(tamanho-1)) {//Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhidas/neste caso, primeira linha e coluna no meio
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
						if(x>0 && y>0 && y==(tamanho-1) && x<(tamanho-1)) {//Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhidas/neste caso linha e coluna no meio
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
						if(x>0 && y>0 && x==(tamanho-1) && y<(tamanho-1)) {//Verificação da posição do campo para abrir uma quantidade de casas harmoniosas com a posição escolhidas/neste caso linha em qualquer posição, coluna mais para a esquerda do tabuleiro
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
					} else { // Nessa sequência, o programa deverá verificar se nos espaços abertos tem bomba ou não, em quaisquer direções adjacentes à coordenada selecionada pelo jogador;
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
							if(matrizbomba[x-1][y] == 1) {   //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha não é a primeira  e a coluna está proxima a esquerda
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
								matrizplay[x][y] = caractere; // Substituindo o número de bombas para facilitar a jogabilidade;
							}
							cont_bomba=0;
						}
						if(x==0 && y==0) {
							if(matrizbomba[x][y+1] == 1) {
								cont_bomba++;
							}
							if(matrizbomba[x+1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a primeira coluna e a primeira linha é selecionada
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
							if(matrizbomba[x+1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha é a primeira e a coluna estiver em qualquer outra posição possivel
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
							if(matrizbomba[x+1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha for a primeira e a coluna estiver próximo a esquerda, exceto a primeira coluna
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
							if(matrizbomba[x-1][y] == 1) { //essa cadeia de if serve para verificar a quantidade de bombas ao redor quando a linha e a coluna forem maior que zero com a coluna mais próxima da esquerda 
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
		} while(achoubomba != 0); // Enquanto a variável destinada para se o jogador encontrar uma bomba for diferente de 0 (ou seja, achou uma bomba);
		system("cls");
		if(chance==2) { // Caso você perca, terá uma opção para jogar novamente (ou não);
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
				printf("|                       Voce achou uma bomba!                           |\n"); // As opções;
				printf("|                       Quer jogar novamente?                           |\n");
				printf("|                       1 - Sim                                         |\n");
				printf("|                       2 - Nao                                         |\n");
				printf("|                                                                       |\n");
				printf("=========================================================================\n");
				scanf("%c",&opcao);
				fflush(stdin);
				system("cls");
			} while(opcao != '2' && opcao != '1');
		} else if(chance==1) { // Caso você ganhe, aparecerá isto na tela/ o calculo é feito verificando a quantidade de casas restantes no mapa ecom a quantidade de bombas
			printf("=========================================================================\n");
			printf("|                                                                       |\n");
			printf("|                                                                       |\n");
			for(i=0; i<tamanho; i++) {
				for(j=0; j<tamanho; j++) {
					if(matrizbomba[i][j] == 1 && matrizplay[i][j] != 'X' && matrizplay[i][j] == '#' && matrizplay[i][j] != '+') { // A sua matriz finalizada, antes da vitória;
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
				printf("|                       Voce ganhou!                                    |\n"); // As opções;
				printf("|                       Quer jogar novamente?                           |\n");
				printf("|                       1 - Sim                                         |\n");
				printf("|                       2 - Nao                                         |\n");
				printf("|                                                                       |\n");
				printf("=========================================================================\n");
				scanf("%c",&opcao);
				fflush(stdin);
				system("cls");
			} while(opcao != '1' && opcao != '2'); // Caso a opção seja 1, a matriz reiniciará, assim iniciando um novo jogo;
		}
	} while(opcao != '2');// E caso seja 2, você será redirecionado para a função 'menu()' ou menu principal;
	menu();
}// E, com isso, finalizamos nosso código. Espero que tenha curtido a viagem que é ser um programador!

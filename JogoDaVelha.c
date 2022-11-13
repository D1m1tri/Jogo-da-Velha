#include<stdio.h>
#include<stdlib.h>
int jogadas[3][3];
int turno = 1;
int sair = 0;
int menu =1;
int multiplayer = 1;
char playerOne[5][8] = {
	{'x','x','x',' ',' ','x','x','x'},
	{' ','x','x','x','x','x','x',' '},
	{' ',' ','x','x','x','x',' ',' '},
	{' ','x','x','x','x','x','x',' '},
	{'x','x','x',' ',' ','x','x','x'}
};
char playerTwo[5][8] = {
	{' ','o','o','o','o','o','o',' '},
	{'o','o','o',' ',' ','o','o','o'},
	{'o','o','o',' ',' ','o','o','o'},
	{'o','o','o',' ',' ','o','o','o'},
	{' ','o','o','o','o','o','o',' '}
};
void reset(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			jogadas[i][j] = 0;
		}
	}
}
int MainMenu(){
	system("clear");
	printf("\x1b[35m""\n -------======= Jogo Da Velha =======------\n\n\n\n\n""\x1b[0m");
	printf("                (1) 2 Players           \n");
	printf("\x1b[31m""                  (q) quit              \n""\x1b[0m");
	system ("/bin/stty raw");
	char c = getchar();
	system ("/bin/stty cooked");
	switch (c){
		case '1':
			return 1;
			break;
		case 'q':
			return -1;
			break;
		default:
			return 0;
	}
}
void printBoard(){
	system ("clear");
	printf("\n");
	for(int i=0;i<3;i++){
		for (int g=0;g<5;g++){
			printf("  ");
			for(int j=0;j<3;j++){
				if(jogadas[i][j] == 1){
					for(int c=0;c<8;c++){
						printf("\033[0;31m");
						printf("%c",playerOne[g][c]);
						printf("\033[0;0m");
					}
				}
				else {
					if(jogadas[i][j] == 2){
						for(int c=0;c<8;c++){
							printf("\033[0;34m");
							printf("%c",playerTwo[g][c]);
							printf("\033[0;0m");
						}
					}
					else{
						printf("        ");
					}
				}
				if(j!=2){
					printf(" | ");
				}
			}
			printf("\n");
		}
		if(i!=2){
			printf(" ----------+----------+----------\n");
		}
	}
	printf("\n\n");
	printf("\x1b[31m");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(jogadas[i][j] == 0){
				printf("%i ",3*i+j+1);
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("\x1b[0m");
}
void jogo(){
	if (turno == 1){
		for(int saida = 0; saida == 0;){
			system ("/bin/stty raw");
			char c = getchar();
			system ("/bin/stty cooked");
			switch (c){
				case '1':
					if (jogadas[0][0] == 0){
						jogadas[0][0] = 1;
						saida = 1;
					}
					break;
				case '2':
					if (jogadas[0][1] == 0){
						jogadas[0][1] = 1;
						saida = 1;
					}
					break;
				case '3':
					if (jogadas[0][2] == 0){
						jogadas[0][2] = 1;
						saida = 1;
					}
					break;
				case '4':
					if (jogadas[1][0] == 0){
						jogadas[1][0] = 1;
						saida = 1;
					}
					break;
				case '5':
					if (jogadas[1][1] == 0){
						jogadas[1][1] = 1;
						saida = 1;
					}
					break;
				case '6':
					if (jogadas[1][2] == 0){
						jogadas[1][2] = 1;
						saida = 1;
					}
					break;
				case '7':
					if (jogadas[2][0] == 0){
						jogadas[2][0] = 1;
						saida = 1;
					}
					break;
				case '8':
					if (jogadas[2][1] == 0){
						jogadas[2][1] = 1;
						saida = 1;
					}
					break;
				case '9':
					if (jogadas[2][2] == 0){
						jogadas[2][2] = 1;
						saida=1;
					}
					break;
				case 'q':
					sair = 1;
					saida = 1;
			}
		}
		turno = 0;
	}
	else{
		if(turno == 0 && multiplayer == 1){
			for(int saida = 0; saida == 0;){
				system ("/bin/stty raw");
				char c = getchar();
				system ("/bin/stty cooked");
				switch (c){
					case '1':
						if (jogadas[0][0] == 0){
							jogadas[0][0] = 2;
							saida = 1;
						}
						break;
					case '2':
						if (jogadas[0][1] == 0){
							jogadas[0][1] = 2;
							saida = 1;
						}
						break;
					case '3':
						if (jogadas[0][2] == 0){
							jogadas[0][2] = 2;
							saida = 1;
						}
						break;
					case '4':
						if (jogadas[1][0] == 0){
							jogadas[1][0] = 2;
							saida = 1;
						}
						break;
					case '5':
						if (jogadas[1][1] == 0){
							jogadas[1][1] = 2;
							saida = 1;
						}
						break;
					case '6':
						if (jogadas[1][2] == 0){
							jogadas[1][2] = 2;
							saida = 1;
						}
						break;
					case '7':
						if (jogadas[2][0] == 0){
							jogadas[2][0] = 2;
							saida = 1;
						}
						break;
					case '8':
						if (jogadas[2][1] == 0){
							jogadas[2][1] = 2;
							saida = 1;
						}
						break;
					case '9':
						if (jogadas[2][2] == 0){
							jogadas[2][2] = 2;
							saida=1;
						}
						break;
					case 'q':
						sair = 1;
						saida = 1;
				}
			}
			turno = 1;
		}
	}
}
int verificar(){	//retorna 0 se ninguem venceu ainda, 1 se o jogador 1 venceu, 2 se o jogador 2 venceu e 3 se deu velha.
	for(int i = 0;i<3;i++){
		if(jogadas[i][0] == 1 && jogadas[i][1] == 1 && jogadas[i][2] == 1){	//checagem de linhas
			return 1;
		}
		if(jogadas[i][0] == 2 && jogadas[i][1] == 2 && jogadas[i][2] == 2){
			return 2;
		}
		if(jogadas[0][i] == 1 && jogadas[1][i] == 1 && jogadas[2][i] == 1){	//checagem de colunas
			return 1;
		}
		if(jogadas[0][i] == 2 && jogadas[1][i] == 2 && jogadas[2][i] == 2){
			return 2;
		}
	}
	if(jogadas[0][0] == 1 && jogadas[1][1] == 1 && jogadas[2][2] == 1 || jogadas[2][0] == 1 && jogadas[1][1] == 1 && jogadas[0][2] == 1){
		return 1;
	}
	if(jogadas[0][0] == 2 && jogadas[1][1] == 2 && jogadas[2][2] == 2 || jogadas[2][0] == 2 && jogadas[1][1] == 2 && jogadas[0][2] == 2){
		return 2;
	}
	int v = 0;
	for(int i=0; i<3; i++){
		for(int j=0;j<3;j++){
			if(jogadas[i][j] == 0){
				v=1;
			}
		}
	}
	if(v==0){
		return 3;
	}
	return 0;
}
int main(){
	while(1==1){
		if (menu){
			int i = MainMenu();
			if(i==-1){
				return 0;
			}
			if(i==1){
				menu = 0;
				reset();
			}
			
		}
		else{
			printBoard();
			while(menu==0){
				jogo();
				if(sair == 1){
					break;
				}
				printBoard();
				int v = verificar();
				if(v == 1){
					printBoard();
					printf("\nX venceu!\n");
					for(int i=0; i<999999999;i++){}
					menu = 1;
				}
				if(v == 2){
					printBoard();
					printf("\nO venceu!\n");
					for(int i=0; i<999999999;i++){}
					menu = 1;
				}
				if(v == 3){
					printBoard();
					printf("\nDeu Velha!\n");
					for(int i=0; i<999999999;i++){}
					menu = 1;
				}
			}
		}
		if(sair == 1){
			break;
		}
	}
}

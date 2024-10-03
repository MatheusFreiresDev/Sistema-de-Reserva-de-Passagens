#include <stdio.h>
#include <stdbool.h>

int main() {
	char poltrona; // Para armazenar a letra da poltrona
	int col, lin, fileira; // Variaveis para colunas, linhas e fileiras
	char tipo_passagem; // Para armazenar o tipo de passagem

	// Inicializa a matriz de reservas 
	bool reservas[10][6] = {0}; 

	while (true) {

		printf("Digite o tipo de passagem (E - Economico, X - Executivo): ");
		scanf(" %c", &tipo_passagem);

		// Valida o tipo de passagem
		if (tipo_passagem != 'E' && tipo_passagem != 'e' && tipo_passagem != 'X' && tipo_passagem != 'x') {
			printf("Tipo de passagem invalido. Tente novamente.\n");
			continue; // Pede nova entrada se o tipo de passagem for invalido
		}

	
		printf("Digite a fileira (1 a 10): ");
		scanf("%d", &fileira);

		// Valida a fileira
		if (fileira < 1 || fileira > 10) {
			printf("Fileira invalida. Tente novamente.\n");
			continue; // Pede nova entrada se a fileira for invalida
		}

		// Solicita a poltrona ao usuario
		printf("Digite a poltrona (A-F): ");
		scanf(" %c", &poltrona); 

		// Define a coluna com base na letra da poltrona
		switch (poltrona) {
		case 'A': 
		case 'a': 
			col = 0;
			break;
		case 'B': 
		case 'b': 
			col = 1;
			break;
		case 'C': 
		case 'c': 
			col = 2;
			break;
		case 'D': 
		case 'd': 
			col = 3;
			break;
		case 'E': 
		case 'e': 
			col = 4;
			break;
		case 'F': 
		case 'f': 
			col = 5;
			break;
		default:
			printf("Poltrona invalida. Tente novamente.\n");
			continue; // verificar
		}

		lin = fileira - 1; 

		// Verifica se o tipo de passagem
		if (tipo_passagem == 'E' || tipo_passagem == 'e') {
			// NC#o permite reservar as poltronas A e F
			if (col == 0 || col == 5) {
				printf("Assentos nas poltronas A e F não estão disponiveis para passagem Economica.\n");
				continue; // verificação
			}
		}

		// Verifica se o assento ja esta reservado
		if (reservas[lin][col]) {
			printf("Esse assento ja esta reservado. Por favor, escolha outro.\n");
			continue; // Pede nova entrada se o assento ja estiver reservado
		}

		// Se o tipo de passagem for Executivo e o assento nao for A ou F
		if ((tipo_passagem == 'X' || tipo_passagem == 'x') && (col != 0 && col != 5)) {
			printf("Recomendamos as poltronas A e F para sua reserva.\n");
		}

		// Reserva o assento
		reservas[lin][col] = 1;

		// Imprimir na tela as poltronas
		printf("\n\t\t\t\tA B C D E F\n");
		for (int l = 0; l < 10; l++) { 
			printf("\t\t\t%d\t", l + 1); 
			for (int c = 0; c < 6; c++) { 
				// Imprime [X] se reservado, [ ] 
				if (reservas[l][c]) {
					printf("[X] "); 
				} else {
					printf("[ ] ");
				}
			}
			printf("\n"); 
		}

		// Pergunta se deseja realizar outra reserva
		char continuar;
		printf("Deseja realizar outra reserva? (s/n): ");
		scanf(" %c", &continuar);

		if (continuar == 'n' || continuar == 'N') {
			printf("Encerrando o sistema de reservas...\n");
			break; // Encerra o loop
		}
	}

	return 0; 
}

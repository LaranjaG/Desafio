#include<stdio.h>
#include <stdlib.h>

//Notas disponivel no caixa
// int notasCemC = 10, notasCinquentaC = 20, notasVinteC = 30, notasDezC = 200, notasCincoC = 40, notasDoisC = 100;

int qtdNotas[6] = {100, 40, 200, 30, 20, 10}; //notas de 2, 5, 10, 20, 50 e 100 disponiveis no caixa

int decontarValor(int desconto, int valor){
	return valor - desconto;
}

void saqueNotasMaioresParaMenores(int valor){
	int notaCem = 0, 
		notaCinquenta = 0, 
		notaVinte = 0, 
		notaDez = 0, 
		notaCinco = 0, 
		notaDois = 0;
	
	while(valor != 0){
		if(valor >= 100 && qtdNotas[5] != 0){
			notaCem++;
			qtdNotas[5]--;
			valor = decontarValor(100, valor);
		} else if(valor >= 50 && qtdNotas[4] != 0){
			notaCinquenta++;
			qtdNotas[4]--;
			valor = decontarValor(50, valor);
		} else if(valor >= 20 && qtdNotas[3] != 0){
			notaVinte++;
			qtdNotas[3]--;
			valor = decontarValor(20, valor);
		} else if(valor >= 10 && qtdNotas[2] != 0){
			notaDez++;
			qtdNotas[2]--;
			valor = decontarValor(10, valor);
		} else if(valor >= 5 && qtdNotas[1] != 0){	
			notaCinco++;
			qtdNotas[1]--;
			valor = decontarValor(5, valor);
		} else if(qtdNotas[0] != 0){
			notaDois++;
			qtdNotas[0]--;
			valor = decontarValor(2, valor);
		}
	}
	
	if(notaCem != 0){
		printf("\nNotas de 100: %d", notaCem);
	}
	if(notaCinquenta != 0){
		printf("\nNotas de 50: %d", notaCinquenta);
	}
	if(notaVinte != 0){
		printf("\nNotas de 20: %d", notaVinte);
	}
	if(notaDez != 0){
		printf("\nNotas de 10: %d", notaDez);
	}
	if(notaCinco != 0){
		printf("\nNotas de 5: %d", notaCinco);
	}
	if(notaDois != 0){
		printf("\nNotas de 2: %d", notaDois);
	}
}

int qtdNotasUnicas(int nota, int valor){
	int qtd = 0;
	
	while(valor != 0){
		valor -= nota;
		qtd++;
	}
	
	return qtd;
}

void saqueNotasUnicas(int valor){
	int qtd = 0;
	
	if(valor % 100 == 0){
		qtd = qtdNotasUnicas(100, valor);
		if(qtdNotas[5] >= qtd){
			printf("\nQuantidade de notas de 100: %d", qtd);	
			qtdNotas[5] -= qtd;
		} else qtd = 0;
	} else if(valor % 50 == 0){
		qtd = qtdNotasUnicas(50, valor);
		if(qtdNotas[4] >= qtd){
			printf("\nQuantidade de notas de 50: %d", qtd);		
			qtdNotas[4] -= qtd;
		} else qtd = 0;
	} else if(valor % 20 == 0){
		qtd = qtdNotasUnicas(20, valor);
		if(qtdNotas[3] >= qtd){
			printf("\nQuantidade de notas de 20: %d", qtd);		
			qtdNotas[3] -= qtd;
		} else qtd = 0;
	} else if(valor % 10 == 0){
		qtd = qtdNotasUnicas(10, valor);
		if(qtdNotas[2] >= qtd){
			printf("\nQuantidade de notas de 10: %d", qtd);		
			qtdNotas[2] -= qtd;
		} else qtd = 0;
	} else if(valor % 5 == 0){
		qtd = qtdNotasUnicas(5, valor);
		if(qtdNotas[1] >= qtd){
			printf("\nQuantidade de notas de 5: %d", qtd);		
			qtdNotas[1] -= qtd;
		} else qtd = 0;
	} else {
		qtd = qtdNotasUnicas(2, valor);
		if(qtdNotas[0] >= qtd){
			printf("\nQuantidade de notas de 2: %d", qtd);		
			qtdNotas[0] -= qtd;
		} else qtd = 0;
	}
	
	if(qtd == 0){
		printf("\nNao se tem a quantidade de notas unicas disponiveis para fazer esse saque! Iniciar a operacao novamente e tente outra forma de saque!");
	}
}

void saqueNotasAleatorias(int valor){
	
	/**
	* Está opção como é utilizado um valor random para sua execussão pode gerar longos loops
	*/
	
	int notaCem = 0, 
		notaCinquenta = 0, 
		notaVinte = 0, 
		notaDez = 0, 
		notaCinco = 0, 
		notaDois = 0;
		
	int notas[6] = {2, 5, 10, 20, 50, 100}; 
	
	while(valor != 0){
		int index = rand() % 6;
		int notaSaque = notas[index];
		
//		printf("\n%d", notaSaque);
		
		if(valor % notaSaque == 0 && qtdNotas[index] != 0){
			switch(index){
				case 0: notaDois++; break;
				case 1: notaCinco++; break;
				case 2: notaDez++; break;
				case 3: notaVinte++; break;
				case 4: notaCinquenta++; break;
				case 5: notaCem++; break;
				default: printf("Random não deveria ter gerado esse index!"); break;
			}
			
			qtdNotas[index]--;
			valor = decontarValor(notaSaque, valor);
		} else continue;
	}
	
	if(notaCem != 0){
		printf("\nNotas de 100: %d", notaCem);
	}
	if(notaCinquenta != 0){
		printf("\nNotas de 50: %d", notaCinquenta);
	}
	if(notaVinte != 0){
		printf("\nNotas de 20: %d", notaVinte);
	}
	if(notaDez != 0){
		printf("\nNotas de 10: %d", notaDez);
	}
	if(notaCinco != 0){
		printf("\nNotas de 5: %d", notaCinco);
	}
	if(notaDois != 0){
		printf("\nNotas de 2: %d", notaDois);
	}
}

int main(void){
	
	/** 
	 * o usuário pode sacar valores divisiveis por 5 ou 2, já que o caixa não disponibiliza notas de 1
	 */
	int valorSaque = 0;
	int montanteDinheiro = 5000; // Total de dinheiro disponivel no caixa
	printf("\n-------------Antes do Saque:-------------\n");
	printf("Montante disponivel no caixa: %d\n", montanteDinheiro);
	printf("\nNotas disponiveis: 2, 5, 10, 20, 50 e 100");
	
	for(int i = 0; i < 6; i++){
		printf("\n%d", qtdNotas[i]);
	}
	
	printf("\n-------------Saque:-------------\n");
	printf("Valor que deseja sacar (um valor inteiro e divisivel por 2 ou 5): ");
	scanf("%d", &valorSaque);
	
	//Formas de saque
	if(valorSaque > 0 && montanteDinheiro >= valorSaque){	
		if(valorSaque % 2 == 0 || valorSaque % 5 == 0){
			montanteDinheiro -= valorSaque; //Desconta o valor sacado do dinheiro do caixa
				
			int opcao;
			printf("Opcoes de saque:" 
				   "\n1 - Saque das maiores notas para menores"
				   "\n2 - Saque de notas de um mesmo valor para a quantia desejada"
				   "\n3 - Saque de notas aleatorias"
				   "\nOpção: ");
					scanf("%d", &opcao);
			
			switch(opcao){
				case 1:
					saqueNotasMaioresParaMenores(valorSaque);
					break;
				case 2:
					saqueNotasUnicas(valorSaque);
					break;	
				case 3: 
					saqueNotasAleatorias(valorSaque);
					break;
				default:
					printf("Opção inválida!");
					break;
			}
			printf("\n-------------Apos o Saque:-------------");
			
			printf("\nNotas disponiveis apos o saque: 2, 5, 10, 20, 50 e 100\n");
			for(int i = 0; i < 6; i++){
				printf("\n%d", qtdNotas[i]);
			}
			
			printf("\nMontante disponivel no caixa apos saque: %d", montanteDinheiro);
		} else{
			printf("O valor nao pode ser sacado! Entre com um valor divisivel por 5 ou 2 para realizar o saque!");
		}
	} else{
		printf((montanteDinheiro < valorSaque) ? "Caixa nao possui dinheiro para sacar esta quantia!" : "Para sacar o valor deve ser maior que 0!");
	}
	
	return 0;
}

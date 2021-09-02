#include<stdio.h>
#include <stdlib.h>

//Variaveis globais
int notaCem = 0, 
	notaCinquenta = 0, 
	notaVinte = 0, 
	notaDez = 0, 
	notaCinco = 0, 
	notaDois = 0;

void mostrar(){
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

void saqueNotasMaioresParaMenores(int valor){
	
	while(valor >= 0){
		if(valor >= 100){
			notaCem++;
			valor -= 100;
		} else if(valor >= 50){
			notaCinquenta++;
			valor -= 50;
		} else if(valor >= 20){
			notaVinte++;
			valor -= 20;
		} else if(valor >= 10){
			notaDez++;
			valor -= 10;
		} else if(valor >= 5){	
			notaCinco++;
			valor -= 5;
		} else {
			notaDois++;
			valor -= 2;
		}
	}
	
	mostrar();
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
	if(valor % 100 == 0){
		printf("\nQuantidade de notas de 100: %d", qtdNotasUnicas(100, valor));
	} else if(valor % 50 == 0){
		printf("\nQuantidade de notas de 50: %d", qtdNotasUnicas(50, valor));	
	} else if(valor % 20 == 0){
		printf("\nQuantidade de notas de 20: %d", qtdNotasUnicas(20, valor));
	} else if(valor % 10 == 0){
		printf("\nQuantidade de notas de 10: %d", qtdNotasUnicas(10, valor));
	} else if(valor % 5 == 0){
		printf("\nQuantidade de notas de 5: %d", qtdNotasUnicas(5, valor));
	} else {
		printf("\nQuantidade de notas de 2: %d", qtdNotasUnicas(2, valor));
	}
}

void saqueNotasAleatorias(int valor){
	
	/**
	* Está opção como é utilizado um valor random para sua execussão pode gerar longos loops
	*/
		
	int notas[6] = {2, 5, 10, 20, 50, 100}; 
	
	while(valor >= 0){
		int index = rand() % 6;
		int notaSaque = notas[index];
		
		int proximoValor = valor - notaSaque;

		if(((valor % notaSaque == 0) || (valor >= notaSaque))){
			
			if((proximoValor > 3) || ((proximoValor % 2) == 0) || (proximoValor == 0)){
				switch(index){
					case 0: notaDois++; break;
					case 1: notaCinco++; break;
					case 2: notaDez++; break;
					case 3: notaVinte++; break;
					case 4: notaCinquenta++; break;
					case 5: notaCem++; break;
					default: printf("Random não deveria ter gerado esse index!"); break;
				}
				
				valor -= notaSaque;
			} else continue;
		} else continue;
	}
	
	mostrar();
}

int main(void){
	
	/** 
	 * O usuário pode sacar valores diferentes de 1 e 3
	 */
	int valorSaque = 0;
	int montanteDinheiro = 5000; // Total de dinheiro disponivel no caixa
	
	printf("Montante disponivel no caixa: %d\n", montanteDinheiro);
	
	printf("Valor que deseja sacar (um valor inteiro e divisivel por 2 ou 5 se for menor que 3): ");
	scanf("%d", &valorSaque);
	
	bool executarSaque = (valorSaque % 2 == 0 || valorSaque % 5 == 0);
	
	//Formas de saque
	if(valorSaque > 0 && montanteDinheiro >= valorSaque){	
		if(executarSaque || valorSaque > 3){
			montanteDinheiro -= valorSaque; //Desconta o valor sacado do dinheiro do caixa
				
			int opcao;
			printf("Opcoes de saque:" 
				   "\n1 - Saque das maiores notas para menores"
				   "\n2 - Saque de notas aleatorias"
				   "%s"
				   "\nOpção: ", 
				   (executarSaque ? "\n3 - Saque de notas de um mesmo valor para a quantia desejada" : ""));
					scanf("%d", &opcao);
			
			printf("\nSaque:");
			switch(opcao){
				case 1:
					saqueNotasMaioresParaMenores(valorSaque);
					break;	
				case 2: 
					saqueNotasAleatorias(valorSaque);
					break;
				case 3:
					if (executarSaque)
						saqueNotasUnicas(valorSaque);
					else
						printf("Não é possivel realizar o saque de notas únicas com esse valor!");
					break;
				default:
					printf("Opção inválida!");
					break;
			}
			
			printf("\nMontante disponivel no caixa apos saque: %d\n", montanteDinheiro);
		} else{
			printf("O valor nao pode ser sacado! Entre com um valor divisivel por 5 ou 2 para realizar o saque ou maior que 3!");
		}
	} else{
		printf((montanteDinheiro < valorSaque) ? "Caixa nao possui dinheiro para sacar esta quantia!" : "Para sacar o valor deve ser maior que 0!");
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

FILE * criarArquivo (char nome[]) {
    FILE * arq;
    arq = fopen (nome, "r+b");
    if (arq == NULL) {
        arq = fopen (nome, "w+b");
    }
    return arq;
}

void manutencao (FILE * arq, char nome[]) {
	int status;
	TCliente c;
	FILE * aux;
	aux = fopen ("auxiliar", "w+b");
	if (aux == NULL) {
		printf ("Erro ao executar o processo de manutenção do arquivo \n");
		fclose (arq);
	}
	else {
	    fseek (arq, 0, 0);
	    while (1) {
		     status = fread (&c, sizeof (TCliente), 1, arq);
		     if (status != 1) {
			      if (!feof(arq)) {
			            printf ("Erro ao executar o processo de manutenção do arquivo \n");
						fclose (arq);
						fclose (aux);
						remove ("auxiliar");
						return;
				  }
				  else // fim de arquivo
			            break;
		    }
		    else {
			    if (c.status == 1) {
				     status = fwrite (&c, sizeof (TCliente), 1, aux);
				     if (status != 1) {
					    printf ("Erro ao executar o processo de manutenção do arquivo \n");
					    fclose (arq);
					    fclose (aux);
					    remove ("auxiliar");
					    return;
				     }
			   }
		   }
	    } // fim while
           fclose (arq);
	    fclose (aux);
	    remove (nome);
	    rename ("auxiliar", nome);
   }
}


int main() {
    FILE * arqCliente, * arqVoo, * arqPass;
    char cliente[] = "clientes.dat", voo[] = "voo.dat", pass[] = "passagens.dat";
    int op;
    arqCliente = criarArquivo(cliente);
    arqVoo = criarArquivo(voo);
    arqPass = criarArquivo(pass);

    do{
        system("cls");
        printf("Bem-Vindo a Brasil Linhas Aereas! Escolha seu servico:\n\n1 - Modulo de Clientes.\n2 - Modulo de Voos.\n3 - Modulo de Cadastro de Voos.\n\n9 - Sair.\nEscolha: ");
        scanf("%i", &op);
        switch(op){
        case 1:
            moduloCliente(arqCliente);
            break;
        case 2:
            moduloVoos();
            break;
        case 3:
            moduloVendaPassagem();
            break;
        case 9:
            manutencao(arqCliente, cliente);
            manutencao(arqVoo, voo);
            manutencao(arqPass, pass);
        default:
            if(op != 1 && op != 2 && op != 3 && op != 9){
                printf("Opcao invalida, digite novamente: ");
            }
        }
    }while(op != 9);
    return 0;
}



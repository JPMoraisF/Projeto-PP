#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "types.h"
#define TAM 100
#define TAMF 11


/*
getCPF FECHADA


*/


void moduloCliente(FILE * arq) {
    system("cls");
    int op, status;
    char cpf[14];
    do {
        printf("Escolha uma opcao abaixo:\n\n1 - Cadastrar um novo cliente.\n2 - Alterar dados de um cliente.\n3 - Exibir dados de um cliente.\n4 - Remover um cliente.\n\n0 - Voltar ao menu principal.\n\nEscolha: ");
        scanf("%i", &op);
        switch(op) {
        case 1:
            cadastroCliente(arq);
            break;
        case 2:
            /*
            getCPF(&cpf);
            status = validaCPF(&cpf);
            if(status != 1){
                printf("O CPF digitado e invalido!\n");
            }
            else{
                alterarCliente(arq, cpf);
            }
            */
            break;
        case 3:
            exibirTudo(arq);
            break;
        case 4:
            break;
        default:
            if(op != 1 && op != 2 && op != 3 && op != 4 && op != 0) {
                printf("Opcao Invalida, tente novamente: ");
                break;
            }
        }
    } while(op != 0);
}

void getCPF(char * cpf) {
    int i = 0;
    char aux;
    printf("Digite o CPF: ");
    while(i < 11) {
        aux = getche();
        cpf[i] = aux;
        i++;
    }
    if(i == 11) {
        cpf[i] = '\0';
    }
}

int validaCPF(char * cpf) {
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11) {
        printf("!= 11"); // se tamanho do cpf != 11 digitos
        return 0;
    } else if ((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
               (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
               (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
               (strcmp(cpf,"99999999999") == 0)) {
        return 0;
    } else {
        for(i=0; cpf[i] != '\0'; i++) {
            if(isdigit(cpf[i]) != 1) {
                return 0;
            }
        }
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                digito2 += (cpf[i]-48) * j;
            digito2 %= 11;
            if(digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if((cpf[10]-48) != digito2)
                return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}

void formataCPF(char * cpf){
    char cpfaux[14];
    int i, j = 0;
    for(i=0; i < 11; i++){
        if(i == 3 || i == 6){
            cpfaux[j] = '.';
            j++;
        }
        else{
            cpfaux[j] = cpf[i];
        }
    }
    cpf = cpfaux;
}

void getNome(char * nome) {
    int i = 0;
    char aux;
    printf("\nDigite o seu nome: ");
    while(i < TAM - 1) {
        aux = getche();
        if(aux == 13) {
            nome[i] = '\0';
            break;
        } else {
            nome[i] = aux;
            i++;
        }
    }
    if(i == TAM - 1) {
        nome[i] = '\0';
    }
}

int validaNome(char * nome) {
    int i, j;
    j = strlen(nome);
    for(i=0; i < j; i++) {
        if(isalpha(nome[i]) == 0 && (isspace(nome[i])) == 0) {
            return 0;
        }
    }
    return 1;
}

void formataNome(char * nome) {
    int j = 0;
    int i = 0;
    while(nome[i] == ' ') {
        i++;
    }
    for(i; nome[i] != '\0'; i++) {
        if(nome[i] != ' ') {
            nome[j] = nome[i];
            j++;
        } else {
            if(nome[i+1] != ' ') {
                nome[j] = ' ';
                j++;
            }
        }
    }
    nome[j] = '\0';
    nome[0] = toupper(nome[0]);
    for(i = 1; nome[i] != '\0'; i++) {
        if(nome[i] == ' ') {
            nome[i+1] = toupper(nome[i+1]);
        }
    }
}

void getFone(char * fone) {
    int i = 0;
    char aux;
    printf("Digite o Telefone de contato: ");
    while(i < TAMF) {
        aux = getche();
        if(isdigit(aux) != 1) {
            fone[i] = '\0';
            return;
        } else if(aux == 13) {
            fone[i] = '\0';
            break;
        } else {
            fone[i] = aux;
            i++;
        }
    }
    if(i == TAMF) {
        fone[i] = '\0';
    }
}

int validaFone(char * fone) {
    int i;
    for(i = 0; fone[i] != '\0'; i++) {
        if(isdigit(fone[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

void exibirTudo(FILE * arq) {
    TCliente aux;
    fread(&aux, sizeof(TCliente), 1, arq);
    while(!(feof(arq))) {
        printf("\nNome: %s\n", aux.nome);
        printf("CPF: %s\n", aux.cpf);
        printf("E-Mail: %s\n", aux.email);
        printf("Telefone: %s\n\n", aux.fone);
        fread(&aux, sizeof(TCliente), 1, arq);
    }
}

void cadastroCliente(FILE * arq) {
    char nome[TAM], cpf[14], fone[TAMF], email[TAM];
    TCliente aux, novo;
    int status = 0, result;
    if (arq == NULL)
        printf ("Erro ao tentar criar/abrir arquivo \n");
    else {
        do {
            getCPF(&cpf);
            result = validaCPF(&cpf);
            if(result != 1) {
                printf("\nO CPF digitado e invalido! Digite novamente: ");
                status = 0;
            } else {
                fread(&aux, sizeof(TCliente), 1, arq);
                while(!(feof(arq))) {
                    if(strcmp(cpf, aux.cpf) == 0) {
                        printf("CPF ja cadastrado! ");
                        fclose(arq);
                        return;
                    } else {
                        fread(&aux, sizeof(TCliente), 1, arq);
                    }
                }
                formataCPF(&cpf);
                status = 1;
           }
        } while(status != 1);
        do {
            getNome(&nome);
            result = validaNome(&nome);
            if(result != 1) {
                printf("O nome digitado e invalido! Digite novamente: ");
                status == 0;
            } else {
                formataNome(&nome);
                status = 1;
            }
        } while(status  != 1);
        do {
            getFone(&fone);
            result = validaFone(&fone);
            if(result != 1){
                printf("O Telefone digitado e invalido! Digite novamente: ");
                status = 0;
            }
            else{
                status = 1;
            }
        } while(status != 1);
        do{
            getEmail(&email);
            status = validaEmail(&email);
            if(status != 1){
                printf("E-Mail digitado invalido! Digte novamente: ");
            }
            else{
                status = 1;
            }
        }while(status != 1);
        printf("%s", fone);
        strcpy(novo.cpf, cpf);
        strcpy(novo.nome, nome);
        strcpy(novo.fone, fone);
        novo.status = 1;
        status = fwrite(&novo, sizeof(TCliente), 1, arq);
        if(status != 1){
            printf("Erro ap registrar usuario!\n");
        }
        else{
            printf("Usuario regisrado com sucesso!\n");
        }
    }
}

void getEmail(char * email){
    int i = 0;
    char aux;
    printf("\nDigite o E-Mail do cliente: ");
    while(i < TAM - 1){
        aux = getche();
        if(aux == 13){
            email[i] = '\0';
        }
        else{
            email[i] = aux;
        }
    }
}

int validaEmail(char * email){
    int i, flag = 0;
    for(i=0; email[i] != '\0'; i++){
        if(isspace(email[i]) == 1 || isalnum(email[i]) != 1 || email[i] != '.'){
            return 0;
        }
        if(email[i] == '@'){
            flag ++;
        }
    }
    if(flag != 1){
        return 0;
    }
    else{
        return 1;
    }
}

void exibirCliente(FILE * arq, char cpf[]){
    int i;
    TCliente c;
    fread(&c, sizeof(TCliente), 1, arq);
    while(!(feof(arq))){
        if(strcmp(c.cpf, cpf) == 0){
            printf("Nome do cliente: %s\n", c.nome);
            printf("Telefone do cliente: %s\n", c.fone);
            printf("CPF do cliente: %s\n", c.cpf);
            printf("E-Mail do cliente: %s\n", c.email);
        }
        else{
            fread(&c, sizeof(TCliente), 1,arq);
        }
    }
    printf("Cliente nao encontrado!\n");
}

void alterarUsuario(FILE * arq){
    int i;
}

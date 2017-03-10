#include <stdio.h>

void getNome(char * nome);
int validaNome(char * nome);
void formatacao(char * nome);
void getCPF(char * cpf);
int validaCPF(char * cpf);
void getFone(char * fone);
int validaFone(char * fone);

void cadastroCliente(FILE * arq);


void moduloCliente(FILE * arq);
void moduloVoos();
void moduloVendaPassagem();

void manutencao (FILE * arq);

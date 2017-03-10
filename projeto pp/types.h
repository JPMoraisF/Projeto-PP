#ifndef ESTRUTURAS
#define ESTRUTURAS
typedef struct Cliente {
	char nome [100];
	char fone [12];
	char email [50];
	char cpf[11];
    int status;
} TCliente;


typedef struct Voo{
    int codigo;
    char origem[51];
    char desino[51];
    char dataPartida[9];
    char horarioPartida[5];
    int poltronaExist;
    int poltronaDisp;
    int mapaPoltrona[6][6];
    float valorPassagem;
    int status;
}TVoo;

typedef struct Passgem{
    int codigoReserva;
    char cpf[11];
    int codigoVoo;
    int numeroPoltrona;
    int status;
}TPassagem;
#endif

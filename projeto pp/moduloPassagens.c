void moduloVendaPassagem() {
    system("cls");
    int op;
    do {
        printf("Escolha uma opcao abaixo:\n\n1 - Vender uma passagem.\n2 - Consultar passagem de um cliente.\n3 - Cancelar passagem de um cliente.\n4 - Consultar passageiros de um voo.\n\n0 - Voltar ao menu principal.\n\nEscolha: ");
        scanf("%i", &op);
        if(op == 0) {
            return;
        }
    } while(op != 0);
}


void moduloVoos() {
    system("cls");
    int op;
    do {
        printf("Escolha uma opcao abaixo:\n\n1 - Cadastrar um novo voo.\n2 - Procurar um voo.\n3 - Alterar o valor de uma passagem.\n4 - Cancelar um voo.\n\n0 - Voltar ao menu principal.\n\nEscolha: ");
        scanf("%i", &op);
        if(op == 0) {
            return;
        }
    } while(op != 0);
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro() {
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    strcpy(arquivo, cpf); // Nome do arquivo ser� o CPF

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    fprintf(file, "%s,", cpf);
    fclose(file);

    printf("Digite o Nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", nome);
    fclose(file);

    printf("Digite o Sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s,", sobrenome);
    fclose(file);

    printf("Digite o Cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("Cadastro realizado com sucesso!\n");
    system("pause");
    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("N�o foi poss�vel abrir o arquivo. CPF n�o encontrado.\n");
        system("pause");
        return 1;
    }

    printf("\nInforma��es do usu�rio:\n");

    while (fgets(conteudo, sizeof(conteudo), file) != NULL) {
        printf("%s\n", conteudo);
    }

    fclose(file);
    system("pause");
    return 0;
}

int deletar() {
    char cpf[40];

    printf("Digite o CPF do usu�rio a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("Usu�rio deletado com sucesso!\n");
    } else {
        printf("Erro ao deletar. Usu�rio n�o encontrado.\n");
    }

    system("pause");
    return 0;
}

int main() {
    int opcao = 0;

    while (1) {
        system("cls");
        setlocale(LC_ALL, "Portuguese");

        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nome\n");
        printf("\t2 - Consultar nome\n");
        printf("\t3 - Deletar nome\n");
        printf("\t4 - Sair do sistema\n");
        printf("Esse software � de livre uso dos alunos\n");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;	
            default:
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause");
                break;
        }
    }
}


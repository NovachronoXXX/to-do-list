    #include <stdio.h>
    #include <stdlib.h>
    #include <locale.h>

    void menu_principal() ///Função do menu principal.
    {
        setlocale(LC_ALL, "Portuguese"); //Permite a acentuação de caracteres.
        int opcao;
        char buffer[100];
        int sair = 0; // Variável de controle para sair do loop.

        do { //Loop para voltar ao menu.
            limpar_tela(); //Chama a função de limpar a tela.

            //Menu principal
            printf("============================================\n");
            printf("||               TO DO LIST               ||\n");
            printf("============================================\n");
            printf("\n");
            printf("Seja bem-vindo a sua lista de tarefas!!\n");
            printf("\n");
            printf("1 - Acessar as minhas listas de tarefas.\n");
            printf("2 - Limpar a minha lista de tarefas\n");
            printf("3 - Adicionar itens a lista de tarefas\n");
            printf("4 - Sair\n");
            printf("\n");
            printf("Digite sua escolha: ");

            if (fgets(buffer, sizeof(buffer), stdin) == NULL) // Lê a entrada com fgets.
            {
                printf("Erro ao ler entrada.\n");
                continue; // Volta ao início do loop.
            }

            if (sscanf(buffer, "%d", &opcao) != 1) // Tenta extrair um número com sscanf.
            {
                printf("Erro: Digite apenas números!\n");
                printf("Pressione Enter para continuar...");
                limpar_buffer(); // Limpa o buffer de entrada.
                getchar(); // Espera o Enter.
                continue;
            }

            if (opcao < 1 || opcao > 4) // Verifica se a opção é válida (1-4)
            {
                printf("Erro: Opção inválida! Digite 1-4.\n");
                printf("Pressione Enter para continuar...");
                limpar_buffer(); // Limpa o buffer de entrada.
                getchar(); // Espera o Enter.
                continue;
            }

            switch (opcao) // Processa a opção com switch/case.
            {
            case 1:
                mostrar_tarefas(); //Chama a função para mostrar as tarefas dentro do arquivo de texto.
                break;
            case 2:
                limpar_lista(); //Chama a função para limpar o arquivo de texto.
                break;
            case 3:
                add_tarefa(); //Chama a função para adicionar um conteudo ao arquivo de texto.
                break;
            case 4:
                printf("Saindo...\n");
                sair = 1; // Ativa a flag para sair do loop.
                break;
            default:
                printf("Erro: Opção inválida!\n");
            }

            if (!sair) // Pausa antes de limpar a tela (exceto quando sair).
            {
                printf("Pressione Enter para continuar...");
                while (getchar() != '\n'); // Limpa o buffer de entrada.
                getchar(); // Espera o Enter.
            }

        } while (!sair); // Continua até que sair seja 1.
    }

    void mostrar_tarefas() ///Função para mostrar as tarefas.
    {
        setlocale(LC_ALL, "Portuguese"); //Permite a acentuação de caracteres.
        FILE *fptr;

        limpar_tela(); //Chama a função de limpar a tela.

        fptr = fopen("filename.txt", "r"); //Abre o arquivo para leitura.

        char ler_tarefa[100]; //Guarda o texto/tarefa que o usuário digitou
        int contador = 1;

        printf("Lista de Tarefas:\n");
        printf("\n");

        while(fgets(ler_tarefa, 100, fptr)) // Lê e imprime cada linha com numeração
        {
            printf("%d - %s", contador, ler_tarefa);
            contador++; // Incrementa o contador
        }

        fclose(fptr); //Fecha o arquivo.

        printf("\nPressione Enter para voltar ao menu...");
        getchar(); // Espera o usuário apertar Enter

        limpar_buffer(); //Limpa o buffer de entrada.
        menu_principal(); //Volta para o menu principal.
    }

    void limpar_lista() ///Função para limpar o arquivo de texto.
    {
        setlocale(LC_ALL, "Portuguese"); //Permite a acentuação de caracteres.
        FILE *fptr;
        char ler_tarefa[100];
        int caractere;
        int contador = 0;

        fptr = fopen("filename.txt", "r"); //Abre o arquivo para leitura.

        while ((caractere = fgetc(fptr)) != EOF) // Lê o arquivo caractere por caractere.
        {
            if (isalpha(caractere)) // Verifica se é uma letra (maiúscula ou minúscula).
            {
                contador++;
            }
        }

        if (contador < 1) //Verifica se o arquivo está em branco.
        {
            printf("Erro ao limpar arquivo!\n");
            return 1;
        }
        else //Se estiver tudo certo, limpa o arquivo de texto.
        {
            fptr = fopen("filename.txt", "w"); // Abrir no modo "w" apaga o conteúdo existente.

            printf("Lista limpa com sucesso!\n");
        }

        fclose(fptr); //Fecha o arquivo.

        menu_principal(); //Volta para o menu principal.
    }

    void add_tarefa() ///Função para adicionar um texto ao arquivo.
    {
        setlocale(LC_ALL, "Portuguese"); //Permite a acentuação de caracteres.
        FILE *fptr;
        char tarefa[100]; //Váriavel para guardar o texto
        char continuar;

        do
        {
            limpar_tela(); //Chama a função de limpar a tela.

            printf("Digite sua tarefa: ");
            fgets(tarefa, sizeof(tarefa), stdin); //Guarda o texto dentro da variavel "tarefa".

            tarefa[strcspn(tarefa, "\n")] = '\0'; // Remove a quebra de linha que o fgets inclui

            fptr = fopen("filename.txt", "a"); //Abre o arquivo para adicionar texto.
            if (fptr == NULL) //Verifica se conseguiu abrir o arquivo.
            {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            fprintf(fptr, "%s\n", tarefa); //Imprimi o texto dentro do arquivo

            fclose(fptr); //Fecha o arquivo de texto.

            printf("Deseja adicionar mais itens à lista? (Y/N)\n");
            scanf(" %c", &continuar);
            limpar_buffer(); // Limpa o buffer após o scanf.

            continuar = tolower(continuar);

            while(continuar != 'y' && continuar != 'n') //Loop para validar a resposta do usuario, se sim continua, se não, volta para o menu principal.
            {
                printf("Opção inválida. Digite Y para sim ou N para não: ");
                scanf(" %c", &continuar); // Espaço antes do %c para ignorar whitespaces
                limpar_buffer(); // Limpa o buffer após o scanf.
                continuar = tolower(continuar);
            }

        }
        while(continuar == 'y'); //Repete o loop enquanto a resposta for sim.

        menu_principal(); //Volta para o menu principal.

    }

    void limpar_tela() ///Função para limpar a tela do terminal.
    {
        system("clear"); //Limpa a tela do Terminal.
    }

    void limpar_buffer() ///Função para limpar o buffer.
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {} //Limpa o buffer
    }

    int main() ///Inicio
    {
        menu_principal(); //Exibe o menu principal
    }

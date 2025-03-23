#include "biblioteca.h"  // Inclui o arquivo de cabeçalho "biblioteca.h", onde provavelmente estão definidas variáveis e funções utilizadas no código.

void mostrarInfo(int operacao){
    puts("\n---INFORMACOES DETALHADAS---\n"); // Imprime uma linha de título com informações detalhadas sobre a operação.

    // Exibe o nível de dificuldade do jogo (definido na estrutura `calcular`).
    printf("Dificuldade: %d\n", calcular.dificuldade);  
    // Exibe os valores envolvidos na operação (armazenados na estrutura `calcular`).
    printf("Valores: %d e %d\n", calcular.valor1, calcular.valor2); 
    
    // Verifica o tipo de operação e exibe a operação correspondente.
    if(operacao == 1){
        printf("Tipo de Operacao: Soma\n"); // Se a operação for 1, imprime "Soma".
    } else if (operacao == 2){
        printf("Tipo de Operacao: Subtracao\n"); // Se a operação for 2, imprime "Subtração".
    } else{
        printf("Tipo de Operacao: Multiplicacao\n"); // Se a operação for 3, imprime "Multiplicação".
    }
}

int numInfinito(int num) {
    int total = 1; // Inicializa uma variável `total` com o valor 1.
    
    // Multiplica `total` por 10, `num` vezes (gera 10^num).
    for (int i = 0; i < num; i++) {
        total *= 10; 
    }
    return total; // Retorna o valor gerado, que será uma potência de 10 (10^num).
}

int gerarNumAleatorio()
{
    // Gera um número aleatório entre 0 e 10^dificuldade - 1, utilizando a função `numInfinito` para definir o limite superior.
    return rand() % numInfinito(calcular.dificuldade); 
}

int gerarOperacao(int opcao)
{
    int continuar; // Variável que controla o fluxo de repetição no jogo (se o jogador acerta ou erra).

    // Se a opção for 5 (modo "Infinito"), reinicia a dificuldade para 1.
    if  (opcao == 5) calcular.dificuldade = 1; 

    do
    {
        // Gera aleatoriamente uma operação: 1 para soma, 2 para subtração e 3 para multiplicação.
        int operacao = (rand() % 3) + 1; 
        int entrada;  // Variável para armazenar a resposta do jogador.

        // Switch que define qual operação será realizada com base no valor de `operacao`.
        switch (operacao)
        {
        case 1:
            // Caso de soma.
            calcular.valor1 = gerarNumAleatorio(); // Gera o primeiro valor aleatório.
            calcular.valor2 = gerarNumAleatorio(); // Gera o segundo valor aleatório.
            mostrarInfo(operacao);  // Mostra as informações detalhadas sobre a operação.
            printf("%d + %d= ", calcular.valor1, calcular.valor2); // Solicita a soma ao jogador.
            scanf("%d", &entrada); // Lê a entrada do jogador.

            if (somar(entrada))  // Verifica se a resposta do jogador está correta.
            {
                continuar = 1; // Se estiver correta, o jogo continua.
                calcular.pontuacao+=calcular.dificuldade*10; // Aumenta a pontuação conforme a dificuldade.
            }
            else
            {
                continuar = 0; // Se estiver errada, o jogo termina.
            }
            break;

        case 2:
            // Caso de subtração.
            calcular.valor1 = gerarNumAleatorio();
            calcular.valor2 = gerarNumAleatorio();
            mostrarInfo(operacao);
            printf("%d - %d = ", calcular.valor1, calcular.valor2);
            scanf("%d", &entrada);
            
            if (diminuir(entrada))  // Verifica a resposta para a operação de subtração.
            {
                continuar = 1;
                calcular.pontuacao+=calcular.dificuldade*10;
            }
            else
            {
                continuar = 0;
            }
            break;

        case 3:
            // Caso de multiplicação.
            calcular.valor1 = gerarNumAleatorio();
            calcular.valor2 = gerarNumAleatorio();
            mostrarInfo(operacao);
            printf("%d*%d= ", calcular.valor1, calcular.valor2);
            scanf("%d", &entrada);
            
            if (multiplicar(entrada))  // Verifica a resposta para a operação de multiplicação.
            {
                continuar = 1;
                calcular.pontuacao+=calcular.dificuldade*10;
            }
            else
            {
                continuar = 0;
            }
            break;

        default:
            break;  // Caso o valor de `operacao` não seja válido, o código não faz nada.
        }

        // Se a opção for 5 (modo "Infinito"), aumenta a dificuldade a cada rodada.
        if (opcao == 5) {
            calcular.dificuldade++; 
        }
    } while (continuar == 1);  // Continua o jogo enquanto o jogador acertar.

    // Quando o jogador errar, exibe a pontuação final.
    printf("Voce errou!! Sua pontuacao foi:%d", calcular.pontuacao);
}

void jogar()
{
    int opcao; // Variável que armazena a opção de dificuldade escolhida pelo jogador.
    
    do
    {
        calcular.pontuacao = 0;  // Reseta a pontuação a cada nova partida.
        // Exibe as opções de dificuldade para o jogador.
        printf("\nDigite um valor de 1 ate 4 para escolher a dificuldade do jogo:\n");
        printf("1 - Facil\n");
        printf("2 - Medio\n");
        printf("3 - Dificil\n");
        printf("4 - Insano\n");
        printf("5 - Infinito\n");
        printf("0 - Sair\n");
        printf("-> \n");
        scanf("%d", &opcao);  // Lê a escolha do jogador.

        // Switch que executa a operação correspondente à dificuldade escolhida.
        switch (opcao)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            calcular.dificuldade = opcao;  // Define a dificuldade de acordo com a escolha.
            gerarOperacao(opcao);  // Gera e executa a operação de acordo com a dificuldade.
            break;
        case 0:
            printf("Saindo...");  // Caso o jogador queira sair.
            return 0;
            break;
        default:
            printf("Opcao invalida!!");  // Caso o jogador digite uma opção inválida.
            break;
        }
    } while (opcao != 0);  // Continua o loop até o jogador escolher sair (opção 0).
}

int somar(int entrada)
{
    calcular.resultado = calcular.valor1 + calcular.valor2;  // Calcula a soma dos dois valores.
    if (entrada == calcular.resultado)  // Verifica se a entrada do jogador é igual ao resultado correto.
    {
        return 1;  // Retorna 1 se o jogador acertou.
    }
    else
    {
        return 0;  // Retorna 0 se o jogador errou.
    }
}

int diminuir(int entrada)
{
    calcular.resultado = calcular.valor1 - calcular.valor2;  // Calcula a subtração dos dois valores.
    if (entrada == calcular.resultado)  // Verifica se a entrada do jogador é igual ao resultado correto.
    {
        return 1;  // Retorna 1 se o jogador acertou.
    }
    else
    {
        return 0;  // Retorna 0 se o jogador errou.
    }
}

int multiplicar(int entrada)
{
    calcular.resultado = calcular.valor1 * calcular.valor2;  // Calcula a multiplicação dos dois valores.
    if (entrada == calcular.resultado)  // Verifica se a entrada do jogador é igual ao resultado correto.
    {
        return 1;  // Retorna 1 se o jogador acertou.
    }
    else
    {
        return 0;  // Retorna 0 se o jogador errou.
    }
}
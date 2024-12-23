#include <stdio.h>
#include <string.h>

int main(void) {
  // Declaração das variáveis
  float valorTotal[5];
  int codigoVenda[5];
  int qtdCamisas[5];
  char tamanho[5];
  int tipoVenda[5];

  // Variáveis para armazenar as estatísticas
  int qtdAcimaC = 0;
  int qtdCamisaG = 0;
  int qtdCamisasVendidas = 0;
  float valorVendaCamisaP = 0;
  float valorMedioVenda = 0;
  int tipoMaisVendido = 0; 
  float valorVendaImpar = 0;
  int qtdTipo[5] = {0, 0, 0, 0, 0};
  int qtdTipoMaisVendido = 0;
  int menorQueValorDado = 0;
  float valorDado;

  printf("Cadastro das Vendas:\n");

  // Cadastro das vendas
  for (int i = 0; i < 5; i++) {
    printf("\nCadastro da venda %d:\n", i + 1);

    // Leitura do valor total da venda
    do {
      printf("Valor total da venda: R$ ");
      scanf("%f", &valorTotal[i]);
      if (valorTotal[i] < 0) {
        printf("ERRO!!! O cadastro de valores não pode ser negativo!\n");
      }
    } while (valorTotal[i] < 0);

    // Leitura do código da venda
    int codigoValido;
    do {
      codigoValido = 1;
      printf("Informe o código da venda (1 a 5): ");
      scanf("%d", &codigoVenda[i]);
      if (codigoVenda[i] < 1 || codigoVenda[i] > 5) {
        printf("ERRO!!! Esse tipo de venda é inválido!\n");
        codigoValido = 0;
      } else {
        for (int j = 0; j < i; j++) {
          if (codigoVenda[i] == codigoVenda[j]) {
            printf("ERRO!!! Código da venda já cadastrado!\n");
            codigoValido = 0;
            break;
          }
        }
      }
    } while (codigoValido == 0);

    // Leitura da quantidade de camisas
    do {
      printf("Qtd. de camisas: ");
      scanf("%d", &qtdCamisas[i]);
      if (qtdCamisas[i] <= 0) {
        printf("ERRO!!! Qtd. de camisas não pode ser negativa ou zero!\n");
      }
    } while (qtdCamisas[i] <= 0);
    qtdCamisasVendidas += qtdCamisas[i];

    // Leitura do tamanho da camisa
    do {
      printf("Digite o tamanho da camisa (P, M ou G): ");
      scanf(" %c", &tamanho[i]);
      if (tamanho[i] != 'P' && tamanho[i] != 'M' && tamanho[i] != 'G') {
        printf("ERRO!!! Tamanho da camisa inválido!\n");
      }
    } while (tamanho[i] != 'P' && tamanho[i] != 'M' && tamanho[i] != 'G');

    if (tamanho[i] == 'P') {
      valorVendaCamisaP += valorTotal[i];
    } else if (tamanho[i] == 'G') {
      qtdCamisaG += qtdCamisas[i];
    }

    // Leitura do tipo de venda
    int tipoValido;
    do {
      tipoValido = 1;
      printf("Informe o tipo de venda (1 a 5): ");
      scanf("%d", &tipoVenda[i]);
      if (tipoVenda[i] < 1 || tipoVenda[i] > 5) {
        printf("ERRO!!! Esse tipo de venda é inválido!\n");
        tipoValido = 0;
      }
    } while (tipoValido == 0);

    qtdTipo[tipoVenda[i] - 1]++;
    if (tipoVenda[i] % 2 != 0) {
      valorVendaImpar += valorTotal[i];
    }

    if (valorTotal[i] > 100) {
      qtdAcimaC++;
    }

    printf("Código de venda cadastrado com sucesso.\n");
  }

  // Calcula o valor médio das vendas
  for (int i = 0; i < 5; i++) {
    valorMedioVenda += valorTotal[i];
  }
  valorMedioVenda /= 5;

  // Determina o tipo de venda mais vendido
  for (int i = 0; i < 5; i++) {
    if (qtdTipo[i] > qtdTipoMaisVendido) {
      qtdTipoMaisVendido = qtdTipo[i];
      tipoMaisVendido = i + 1;
    }
  }

  // Menu principal
  int opcao;
  do {
    printf("\nMenu principal:\n");
    printf("1. Ver informação das vendas por código\n");
    printf("2. Ver informação de todos os pedidos cadastrados\n");
    printf("0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1: {
        int codigoPesquisa;
        printf("\nDigite o código único que deseja pesquisar: ");
        scanf("%d", &codigoPesquisa);

        int encontrado = 0;
        for (int i = 0; i < 5; i++) {
          if (codigoVenda[i] == codigoPesquisa) {
            printf("Venda %d:\n", i + 1);
            printf("Valor total: R$ %.2f\n", valorTotal[i]);
            printf("Qtd. de camisas: %d\n", qtdCamisas[i]);
            printf("Tamanho da camisa: %c\n", tamanho[i]);
            printf("Tipo de venda: %d\n", tipoVenda[i]);
            encontrado = 1;
            break;
          }
        }
        if (encontrado == 0) {
          printf("Não há vendas com aquele código.\n");
        }
        break;
      }

      case 2: {
        printf("\nDigite um valor para comparação: R$ ");
        scanf("%f", &valorDado);

        menorQueValorDado = 0;
        for (int i = 0; i < 5; i++) {
          if (valorTotal[i] < valorDado) {
            menorQueValorDado++;
          }
        }
        printf("Qtd. de vendas abaixo de R$ %.2f: %d\n", valorDado, menorQueValorDado);
        printf("Qtd. de vendas acima de R$ 100: %d\n", qtdAcimaC);
        printf("Qtd. vendida de camisas tamanho G: %d\n", qtdCamisaG);
        printf("Valor total vendido de camisas tamanho P: R$ %.2f\n", valorVendaCamisaP);
        printf("Valor médio de uma venda: R$ %.2f\n", valorMedioVenda);
        printf("Qtd. total de camisas vendidas: %d\n", qtdCamisasVendidas);
        printf("Valor total de vendas quando o tipo de venda for ímpar: R$ %.2f\n", valorVendaImpar);
        printf("Tipo de venda mais vendido: %d\n", tipoMaisVendido);
        break;
      }

      case 0:
        printf("Encerrando o programa.\n");
        break;

      default:
        printf("Opção inválida!\n");
    }
  } while (opcao != 0);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <strings.h>


char usuario[100][10], senha[100][20], usuario1[10], senha1[20],checarsejatemcadastro[100][20], loki[100][20],escolhaProdutos[100][20], EnderecoEntrega[4][30], numero[100];
int attempts=0, totalUsuarios=0, unidadeCoxinha=0, unidadePaodeQueijo=0, unidadeRocambole=0, unidadeBatataFrita=0, unidadeHamburguer=0, unidadeRefrigerante=0, unidadeSuco=0, escolhapagamento;
float precoTotal=0, valordotroco, vtroco;



void menu()
{
    printf("\n\t\t\t******Seja Bem vindo(a)******\n\n\t\t\t-DIGITE 1 PARA CADASTRAR USUÁRIO\n\t\t\t-DIGITE 2 PARA FAZER LOGIN\n\t\t\t-DIGITE SAIR PARA ENCERRAR O PROGRAMA.\n\n");
    fflush(stdin);
    scanf("%[^\n]", numero);
    int sexo=1;
    while(sexo==1)
    {if(strcmp(numero,"1")==0)
        {cadastrar();
        return;
        }

    else if(strcmp(numero,"2")==0)
        {login();
        return;
        }

    else if(stricmp(numero,"sair")==0)
        {printf("\nPROGRAMA ENCERRADO\n");
        break;
        }

    else
        {printf("\nCOMANDO INVÁLIDO, DIGITE NOVAMENTE\n");
         fflush(stdin);
         scanf("%[^\n]", numero);
        }

    }

}

void cadastrar()
{int loop=0;
    while (loop==0)
    {
        printf("\nDigite um nome de usuário para criar seu Login (sem espaços):\n\n");
        scanf(" %[^\n]", usuario[totalUsuarios]);

        if (strchr(usuario[totalUsuarios], ' ') != NULL)
        {
            printf("\nNome do usuário não pode conter espaços...\n\n");
        }
        else
        {
            int duplicate = 0;

            for (int i = 0; i < totalUsuarios; i++)
            {
                if (strcmp(usuario[totalUsuarios], usuario[i]) == 0)
                {
                    printf("\nUsuário já cadastrado...\n\n");
                    duplicate = 1;
                    break;
                }
            }

            if (duplicate==0)
            {
                break;
            }
        }
    }
    printf("\nAgora digite uma senha:\n\n");
    scanf("%s", senha[totalUsuarios]);
    totalUsuarios++;

    printf("\nMuito Bem! Usuário e senha cadastrados com sucesso!\n\n");
    printf("Pressione uma tecla para voltar ao menu...");
    getch();
    system("cls");
    menu();
}

void login()
{
    printf("\nPara entrar digite o seu usuário:\n\n");
    scanf("%s", usuario1);

    int achou=0;
    int indexUsuario;
    while (achou==0) {
        for (int i = 0; i < totalUsuarios; i++) {
            if (strcmp(usuario1,usuario[i])==0) {
                achou = 1;
                indexUsuario = i;
                break;
            }
        }

        if (achou==0) {
            printf("\nUsuario não cadastrado, digite um usuário válido, ou pressione 3 para voltar ao menu:\n\n");
            scanf("%s", usuario1);
            if(strcmp(usuario1, "3")==0) {
                system("cls");
                menu();
                return;
            }
        }
    }

    printf("\nDigite a senha:\n\n");
    scanf("%s", senha1);

        while (strcmp(senha[indexUsuario], senha1) != 0)
        {
            attempts++;
            if (attempts == 1)
            {
                printf("\nACESSO NEGADO, TENTE NOVAMENTE, 3 tentativas restantes:\n\n");
                scanf("%s", senha1);
            }
            else if (attempts == 2)
            {
                printf("\nACESSO NEGADO, TENTE NOVAMENTE, 2 tentativas restantes:\n\n");
                scanf("%s", senha1);
            }
            else if (attempts == 3)
            {
                printf("\nACESSO NEGADO, TENTE NOVAMENTE, 1 tentativa restante:\n\n");
                scanf("%s", senha1);
            }
            else if (attempts == 4)
            {
                printf("\nACESSO BLOQUEADO\n\n");
                return 0;
            }
        }


        printf("\nACESSO GARANTIDO!\n\n");
        printf("Pressione qualquer tecla para acessar a LANCHONETE...");
        getch();
        menulanchonete();


}


void menulanchonete()
{
    system("cls");
    printf("\n\t******Seja Bem-vindo à Lanchonete Virtual******\n\n");

    printf(" 1.Coxinha---------R$5,00\n");
    printf(" 2.Pão de Queijo---R$4,00\n");
    printf(" 3.Rocambole-------R$5,50\n");
    printf(" 4.Batata Frita----R$6,00\n");
    printf(" 5.Hambúrguer------R$5,00\n");
    printf(" 6.Refrigerante----R$3,50\n");
    printf(" 7.Suco------------R$3,00\n\n");

    printf("Digite o seu pedido, item por item (máx 20 itens), digite 0 para encerrar o seu pedido e ir para a forma de Pagamento, digite 'voltar' para voltar para o menu principal:\n\n");

    for(int i=1; i<=100;i++)
    {
        fflush(stdin);
        scanf("%[^\n]", escolhaProdutos);
        if(strcmp(escolhaProdutos,"0")==0)
         {carrinho();
         return;
         }
         if(stricmp(escolhaProdutos,"coxinha")==0 || strcmp(escolhaProdutos,"1")==0)
           {precoTotal+=5;
           unidadeCoxinha++;
           }
         else if(stricmp(escolhaProdutos,"pão de queijo")==0 || strcmp(escolhaProdutos,"2")==0)
         {precoTotal+=4;
         unidadePaodeQueijo++;
         }
        else if(stricmp(escolhaProdutos,"rocambole")==0 || strcmp(escolhaProdutos,"3")==0)
           {precoTotal+=5.5;
            unidadeRocambole++;
           }
        else if(stricmp(escolhaProdutos,"batata frita")==0 || strcmp(escolhaProdutos,"4")==0)
         {precoTotal+=6;
         unidadeBatataFrita++;
         }
        else if(stricmp(escolhaProdutos,"hambúrguer")==0 || strcmp(escolhaProdutos,"5")==0)
           {precoTotal+=5;
            unidadeHamburguer++;
           }
        else if(stricmp(escolhaProdutos,"refrigerante")==0 || strcmp(escolhaProdutos,"6")==0)
         {precoTotal+=3.5;
          unidadeRefrigerante++;
         }
        else if(stricmp(escolhaProdutos,"suco")==0 || strcmp(escolhaProdutos,"7")==0)
           {precoTotal+=3;
           unidadeSuco++;
           }
        else if (stricmp(escolhaProdutos,"voltar")==0)
        {
          system("cls");
          menu();
        }
        else
        {
        printf("\nItem não cadastrado, digite novamente:\n\n");
        }

      }

    }

void carrinho()
{
     if(unidadeCoxinha==0 && unidadePaodeQueijo==0 && unidadeRocambole==0 && unidadeBatataFrita==0 && unidadeHamburguer==0 && unidadeRefrigerante==0 && unidadeSuco==0)
        {
         system("cls");
         printf("\nEscolha pelo menos 1 item para continuar para o carrinho:\n\n");
         printf("Pressione qualquer tecla para voltar ao cardápio...");
         getch();
         menulanchonete();


        }
    system("cls");
    printf("\n**CARRINHO**\n");

    if(unidadeCoxinha==1)
        printf("--%d Coxinha\n", unidadeCoxinha);
        else if(unidadeCoxinha>1)
        printf("--%d Coxinhas\n", unidadeCoxinha);

     if(unidadePaodeQueijo==1)
        printf("--%d Pão de Queijo\n", unidadePaodeQueijo);
        else if(unidadePaodeQueijo>1)
        printf("--%d Pães de Queijo\n", unidadePaodeQueijo);

     if(unidadeRocambole==1)
        printf("--%d Rocambole\n", unidadeRocambole);
        else if(unidadeRocambole>1)
        printf("--%d Rocamboles\n", unidadeRocambole);

     if(unidadeBatataFrita==1)
        printf("--%d Batata Frita\n", unidadeBatataFrita);
        else if(unidadeBatataFrita>1)
        printf("--%d Batatas Fritas\n", unidadeBatataFrita);

     if(unidadeHamburguer==1)
        printf("--%d Hambúrguer\n", unidadeHamburguer);
        else if(unidadeHamburguer>1)
        printf("--%d Hambúrgueres\n", unidadeHamburguer);

     if(unidadeRefrigerante==1)
        printf("--%d Refrigerante\n", unidadeRefrigerante);
        else if(unidadeRefrigerante>1)
        printf("--%d Refrigerantes\n", unidadeRefrigerante);

     if(unidadeSuco==1)
        printf("--%d Suco\n", unidadeSuco);
        else if(unidadeSuco>1)
        printf("--%d Sucos\n", unidadeSuco);


        printf("\nTotal a pagar: R$%.1f", precoTotal);
        printf("\n\n\nQual a forma de pagamento:\n\n");
        printf("1-Dinheiro\n2-Cartão de Crédito\n3-Cartão de Débito\n\n");
        scanf("%d", &escolhapagamento);
        while(escolhapagamento<1 || escolhapagamento>3)
        {
            printf("\nComando Inválido, escolha um número equivalente a sua forma de pagamento:\n\n");
            printf("1-Dinheiro\n2-Cartão de Crédito\n3-Cartão de Débito\n\n");
            scanf("%d", &escolhapagamento);

        }
        int troco;
        if(escolhapagamento==1)
        {  int loop=1;
             while(loop==1)
            {printf("\n1- Troco\n2- Sem Troco\n\n");
             scanf("%d", &troco);
             if(troco==1)
             {
             printf("\nTroco para quanto?\n");
              scanf("%f", &vtroco);
              while(vtroco<precoTotal)
              {
                  printf("\nDinheiro Insuficiente, digite outro valor:\n");
                  scanf("%f", &vtroco);
              }
              valordotroco=vtroco-precoTotal;
              printf("\nTroco: %.2f\n", valordotroco);
              PedirEndereco();
              return;
             }
             if(troco==2)
                  {
                   PedirEndereco();
                   return;
                  }
             else
                printf("\nCOMANDO INVÁLIDO, DIGITE NOVAMENTE\n");

             }

          }

        PedirEndereco();


        }

void PedirEndereco()
{
    printf("\nDigite o seu endereço para entrega:\n");
    printf("\nCIDADE: ");
    fflush(stdin);
    scanf("%[^\n]", EnderecoEntrega[0]);
    printf("BAIRRO: ");
    fflush(stdin);
    scanf("%[^\n]", EnderecoEntrega[1]);
    printf("NOME DA RUA: ");
    fflush(stdin);
    scanf("%[^\n]", EnderecoEntrega[2]);
    printf("NÚMERO DA CASA: ");
    fflush(stdin);
    scanf("%[^\n]", EnderecoEntrega[3]);

    system("cls");

    printf("\nPEDIDO REALIZADO!\n\n");
    printf("**Resumo do pedido**\n");
    if(unidadeCoxinha==1)
        printf("--%d Coxinha\n", unidadeCoxinha);
        else if(unidadeCoxinha>1)
        printf("--%d Coxinhas\n", unidadeCoxinha);

     if(unidadePaodeQueijo==1)
        printf("--%d Pão de Queijo\n", unidadePaodeQueijo);
        else if(unidadePaodeQueijo>1)
        printf("--%d Pães de Queijo\n", unidadePaodeQueijo);

     if(unidadeRocambole==1)
        printf("--%d Rocambole\n", unidadeRocambole);
        else if(unidadeRocambole>1)
        printf("--%d Rocamboles\n", unidadeRocambole);

     if(unidadeBatataFrita==1)
        printf("--%d Batata Frita\n", unidadeBatataFrita);
        else if(unidadeBatataFrita>1)
        printf("--%d Batatas Fritas\n", unidadeBatataFrita);

     if(unidadeHamburguer==1)
        printf("--%d Hambúrguer\n", unidadeHamburguer);
        else if(unidadeHamburguer>1)
        printf("--%d Hambúrgueres\n", unidadeHamburguer);

     if(unidadeRefrigerante==1)
        printf("--%d Refrigerante\n", unidadeRefrigerante);
        else if(unidadeRefrigerante>1)
        printf("--%d Refrigerantes\n", unidadeRefrigerante);

     if(unidadeSuco==1)
        printf("--%d Suco\n", unidadeSuco);
        else if(unidadeSuco>1)
        printf("--%d Sucos\n", unidadeSuco);

printf("\nForma de pagamento:\n");
if(escolhapagamento==1)
    printf("--Dinheiro");
else if(escolhapagamento==2)
    printf("--Cartão de Crédito");
else if(escolhapagamento==3)
    printf("--Cartão de Débito");
if(valordotroco>0)
    printf("\nTroco: %.2f", valordotroco);

printf("\n\nEndereço: %s, %s, %s, %s.\n\n", EnderecoEntrega[0], EnderecoEntrega[1], EnderecoEntrega[2], EnderecoEntrega[3]);

}

int main()

{
    setlocale(LC_ALL,"");

    menu();


}

